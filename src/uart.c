/**
*@file my_uart.c
*@brief UART usage functions for KL25Z
*@Author Aakash Kumar/ArunSundar
*@date Oct 16 2017

*/

/**
For reference here only, this is already defined in MKL25Z.h
#define UART0_BDH                                UART0_BDH_REG(UART0)
#define UART0_BDL                                UART0_BDL_REG(UART0)
#define UART0_C1                                 UART0_C1_REG(UART0)
#define UART0_C2                                 UART0_C2_REG(UART0)
#define UART0_S1                                 UART0_S1_REG(UART0)
#define UART0_S2                                 UART0_S2_REG(UART0)
#define UART0_C3                                 UART0_C3_REG(UART0)
#define UART0_D                                  UART0_D_REG(UART0)
#define UART0_MA1                                UART0_MA1_REG(UART0)
#define UART0_MA2                                UART0_MA2_REG(UART0)
#define UART0_C4                                 UART0_C4_REG(UART0)
#define UART0_C5 
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
	/* Enable the pins for the selected UART */
	/* Enable the UART_TXD function on PTA1 */
	PORTA_PCR1 = PORT_PCR_MUX(0x2);
	/* Enable the UART_TXD function on PTA2 */
	PORTA_PCR2 = PORT_PCR_MUX(0x2);
	SIM_SOPT2 |= SIM_SOPT2_UART0SRC(1); // select the PLLFLLCLK as UART0 clock source
	
	mcg_clk_hz = 21000000; //FEI mode
    SIM_SOPT2 &= ~SIM_SOPT2_PLLFLLSEL_MASK; // clear PLLFLLSEL to select the FLL for this clock source
    uart0_clk_khz = (mcg_clk_hz / 1000); // the uart0 clock frequency will equal the FLL frequency
	uart0_clk_khz = ((mcg_clk_hz / 2) / 1000); // UART0 clock frequency will equal half the PLL frequency
	
	
	
	
	/* Enable receiver and transmitter */
    UART0_C2 |= (UART0_C2_TE_MASK
                    | UART0_C2_RE_MASK );
}


/**
@brief Sends a single byte of data to UART
@param *data byte pointer to location of data to be transmitted
@return	None

*/
void UART_Send(uint8_t * data)
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
	if(src!=NULL and length >0)
	{
		
		for(i=0;i<length;i++)
		{
			UART_Send(*(src+i)); // Send one character at a time from the block of data
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
	  
		*dst = UART0_D_REG(channel); // Read data from buffer when available
		return dst; // Return pointer to received data
	}
}

/**
@brief Receives a block of data from the UART
@param *dst byte pointer to start location of memory block where received data is stored
@param length of memory block received
@return * byte pointer to received data

*/
uint8_t * UART_receive_n(uint8_t * dst, size_t length)
{
	if(dst!=NULL and length >0)
	{
		for(int i=0;i<length;i++)
		{
			UART_receive(*(dst+i));
		}
		return dst;
	}
}

/**
@brief Interrupt handler for UART send and receive. Handles send and receive interrupts.
Clears associated flags once the interrupt is serviced.

@return none

*/
void UART_IRQHandler()
{
}
