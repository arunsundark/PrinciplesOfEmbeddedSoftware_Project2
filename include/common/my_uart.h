/**
*@file my_uart.h
*@brief UART usage functions for KL25Z
*@Author Aakash Kumar
*@date Oct 10 2017

*/
#ifndef MY_UART
#define MY_UART

#include<stdint.h>

#define BAUD_RATE 115200


void UART_configure(void);
/*
@brief Configures the UART to given settings 
@param 
@param TBD
@return  TBD

*/

void UART_Send(uint8_t * data);
/*
@brief Configures the UART to given settings 
@param *data byte pointer to location of data to be transmitted
@return  None

*/

void UART_send_n(uint8_t * src, size_t length);
/*
@brief Configures the UART to given settings 
@param *src byte pointer to start location of memory block to be transmitted
@param length of memory block to be transmitted
@return  None

*/

uint8_t * UART_receive(uint8_t * dst);
/*
@brief Configures the UART to given settings 
@param *data byte pointer to location where received data is stored
@return  None

*/

uint8_t * UART_receive_n(uint8_t * dst, size_t length);
/*
@brief Configures the UART to given settings 
@param *dst byte pointer to start location of memory block where received data is stored
@param length of memory block received
@return  TBD

*/

void UART_IRQHandler();
/*
@brief Interrupt handler for UART send and receive. Handles send and receive interrupts.
Clears associated flags once the interrupt is serviced.

@return none

*/


#endif MY_UART // End of my uart.h