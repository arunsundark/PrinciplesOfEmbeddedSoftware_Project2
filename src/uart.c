/**
*@file my_uart.c
*@brief UART usage functions for KL25Z
*@Author Aakash Kumar/ArunSundar
*@date Oct 16 2017

*/

#include "uart.h"

// Uses UART0 on the FRDM Board

int i=0;// index used in for loops

/**
@brief Configures the UART to given settings 
@param 
@param TBD
@return  TBD
*/
void UART_configure(void)
{

	SIM_SCGC4|=	SIM_SCGC4_UART0_MASK; // Enable clock gate to UARTO in System Clock Gating Control Register

	UART0_C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK); // Ensure UART0 is disabled before changing registers

    SIM_SCGC5 |= SIM_SCGC5_PORTA(1) ;// Enable port clock for portA

    // Enable the pins for the selected UART
	PORTA_PCR1 = PORT_PCR_MUX(0x2); // Enable the UART_TXD function on PTA1

	PORTA_PCR2 = PORT_PCR_MUX(0x2); //Enable the UART_TXD function on PTA2

	SIM_SOPT2 |= SIM_SOPT2_UART0SRC(1); // select the PLLFLLCLK as UART0 clock source

    SIM_SOPT2 &= ~SIM_SOPT2_PLLFLLSEL_MASK; // clear PLLFLLSEL to select the FLL for this clock source

    UART0_BDL=(0x20 & UART_BDL_SBR_MASK);// set BDL to 32 for 38400 baud : TODO change to macro
	
    UART0_C2 |= UART_C2_RIE_MASK;// Enable UART0 receive interrupt

    UART0_C2 |= (UART0_C2_TE_MASK| UART0_C2_RE_MASK );// Enable receiver and transmitter
}


/**
@brief Sends a single byte of data to UART
@param *data byte pointer to location of data to be transmitted
@return	None

*/
void UART_send(uint8_t * data)
{
	if(data !=NULL) 
	{
      while(!(UART0_S1 & UART0_S1_TDRE_MASK));// Wait until TDRE is 1, ie data buffer is empty  
		//The while loop does not exit until TDRE is 1.
		
      UART0_D = *data; // Write data to UART Data register to transmit the data once buffer is empty
	}

}

/**
@brief Sends a block of data to the UART
@param *src byte pointer to start location of memory block to be transmitted
@param length of memory block to be transmitted
@return  None

*/
void UART_send_n(uint8_t * src, size_t length)
{
	if(src!=NULL && length >0)
	{
		
		for(i=0;i<length;i++)
		{
			UART_send((src+i)); // Send one character at a time from the block of data
			// The UART_Send function will take care of not writing when the buffer is not empty.
		}
	}

}

/**
@brief Receives a byte of data from the UART 
@param *dst byte pointer to location where received data is stored
@return  None

*/
uint8_t * UART_receive(uint8_t * dst)
{
	if(dst!=NULL)
	{
		
		while (!(UART0_S1 & UART0_S1_RDRF_MASK)); // Wait until RDRF flag is set, indicating data in buffer.
		// While loop does not exit until RDRF is 1
	  
		*dst = UART0_D; // Read data from buffer when available
		return dst; // Return pointer to received data
	}
	else return 0;
}

/**
@brief Receives a block of data from the UART
@param *dst byte pointer to start location of memory block where received data is stored
@param length of memory block received
@return * byte pointer to received data

*/
uint8_t * UART_receive_n(uint8_t * dst, size_t length)
{
	if(dst!=NULL && length >0)
	{
		for(int i=0;i<length;i++)
		{
			UART_receive((dst+i));
		}
		return dst;
	}
	else return 0;
}

/**
@brief Interrupt handler for UART send and receive. Handles send and receive interrupts.
Clears associated flags once the interrupt is serviced.

@return none

*/
void UART0_IRQHandler()
{
	uint8_t b;

	if (UART0_S1&UART_S1_RDRF_MASK) // If data is received send it back after incrementing
	  {
		b=(UART0_D)+1;
		UART_send(&b);
	  }
}
