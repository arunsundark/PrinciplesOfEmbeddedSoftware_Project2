/**
*@file my_circularbuffer.h
*@brief circularbuffer usage functions
*@Author Arunsundar Kannan
*@date Oct 10 2017

*/
#ifndef MY_UART
#define MY_UART

#include<stdint.h>

CB_status CB_buffer_add_item(uint8_t* source_buffer, uint8_t data)
/*
@brief Add a new data to the circular buffer 
@param uint8_t* source_buffer the input buffer to which the data is to be added
@param data data to be added to the buffer
@return  CB_status status of the operation

*/


CB_status CB_buffer_remove_item(uint8_t* source_buffer, uint8_t data)
/*
@brief remove a new data to the circular buffer 
@param uint8_t* source_buffer the input buffer from which the data is to be removed
@param data variable to store the data to be removed from the buffer
@return  CB_status status of the operation

*/
CB_status CB_is_full(uint8_t* source_buffer)
/*
@brief checks if the buffer is full
@param uint8_t* source_buffer the input buffer which is to be checked
@return  CB_status status of the operation or an error code

*/

CB_status CB_is_empty(uint8_t* source_buffer)
/*
@brief checks if the buffer is empty
@param uint8_t* source_buffer the input buffer which is to be checked
@return  CB_status status of the operation or an error code

*/



CB_status CB_peek(uint8_t* source_buffer, uint8_t position_peek)
/*
@brief peeks at a particuluar position in the buffer 
@param uint8_t* source_buffer the input buffer which is to be poked at
@param position_peek position to peek in the circular buffer
@return  CB_status status of the operation

*/


CB_status CB_init(uint8_t* source_buffer, uint8_t length)
/*
@brief reserves some memory for circular buffer 
@param uint8_t* source_buffer the pointer to the buffer which is initialised 
@param length number of elements to allocated memory in the circular buffer
@return  CB_status status of the operation

*/


CB_status CB_init(uint8_t* source_buffer, uint8_t length)
/*
@brief reserves some memory for circular buffer 
@param uint8_t* source_buffer the pointer to the buffer which is initialised 
@param length number of elements to allocated memory in the circular buffer
@return  CB_status status of the operation

*/



#endif MY_CIRCULARBUFFER // End of my_circularbuffer.h


