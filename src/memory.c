/**
*@file memory.c
*@brief Memory Manipulation functions
*@Author Aakash Kumar
*@date Sept 24 2017
*/
#include"debug.h"
#include"memory.h"

int i=0;// index used in for loops

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
	 
	mem_buffer= (uint8_t*)reserve_words(length); // setup a seperate buffer variable to prevent copy over
	 
	 // copy the source location into the buffer
	for(i=0;i<length;i++)
	{
		 *(mem_buffer+i)=*(src+i);
	}
	// copy buffer into destination location
	for(i=0;i<length;i++)
	{
		*(dst+i)=*(mem_buffer+i);
	}
		
	free_words( (uint32_t*)mem_buffer );	
	
return dst;
}

uint8_t * my_memcpy(uint8_t * src, uint8_t *dst, size_t length){
	
	//copy directly from source to destination as overwrite does not have to be taken care of
	for(i=0;i<length;i++)
	{
		 *(dst+i)=*(src+i);
	}
return dst;
}

uint8_t *  my_memset(uint8_t  *  src,  size_t  length,  uint8_t  value){
	
	// set locations to the passed value
	for(i=0;i<length;i++)
	{
		 *(src+i)=value;
	}
return src;
}

uint8_t *  my_memzero(uint8_t  *  src,  size_t  length){
	
	//set all values to 0
	for(i=0;i<length;i++)
	{
		 *(src+i)=ZERO;
	}
return src;
}


uint8_t *  my_reverse(uint8_t  *  src,  size_t  length){
	
	// reverse the array , same logic as in HW3
	for(i=0;i<(length/TWO);i++)
	{
		temp=*(src+i);
		*(src+i)=*(src+length-ONE-i);
		*(src+length-ONE-i)=temp;
	}
	
return src;
}


int32_t *  reserve_words(size_t  length){
	
	//allocate memory of length of highest variable possible
	return malloc(sizeof(uint32_t)*length);
}

void free_words(uint32_t  *  src){
	
	//freeing data of memory block passed 
	free(src);
}

