/**
*@file test_memory.c
*@brief Testing functions for circularbuffer usage functions 
*@Author Aakash Kumar/ArunSundar
*@date Oct 28 2017

*/



#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <string.h>

#include "memory.h"

//****** memmove tests
/***
TEST 1
@brief Check for NULL pointer
@description checks how the function responds if the input is a null pointer

**/
static void my_memmove_test_null_1(void** state)
{
		size_t testLength=10;
		
		uint8_t * memmove_src=NULL,* memmove_dst= malloc(sizeof(uint8_t)*testLength); 
		
		// Testing if memmove function return 0 if a null pointer is given as the input 
		assert_int_equal(my_memmove(memmove_src,memmove_dst,testLength),0) ;
		free(memmove_dst);
}
/*TEST 2
@brief Checks if the function works in nooverlap condition
@description checks how the function responds if the input pointers dont overlap

**/

static void my_memmove_test_no_overlap(void** state)
{
		size_t testLength=10;
		uint8_t * memmove_src=malloc(sizeof(uint8_t)*testlength),* memmove_dst= malloc(sizeof(uint8_t)*testLength);
		uint8_t index;
		/* initialising the source buffer */
		for(index=0;index<10;index++)
		{
		*(memmove_src+index)=index;
		}
		my_memmove(memmove_src,memmove_dst,testLength);
		
		/* checking if the source and destination pointers are dereferenced to the same value*/
		for(index=0;index<10;index++)
		{
		
		assert_int_equal(*(memmove_src+index),(*memmove_dst+index));
		
		}
		free(memmove_src);
		free(memmove_dst);
}

/*TEST 3
@brief Checks if the function works in overlap condition
@description checks how the function responds if the source pointer overlaps 
	     in the destination pointer region

**/


		
static void my_memmove_test_no_overlap(void** state)
{
		size_t testLength=10;
		uint8_t * memmove_dst= malloc(sizeof(uint8_t)*testLength);
		uint8_t * memmove_src= memove_dst + 5;
		uint8_t index;
		/* initialising the source buffer */
		for(index=0;index<10;index++)
		{
		*(memmove_src+index)=index;
		}
		my_memmove(memmove_src,memmove_dst,testLength);
		
		/* checking if the source and destination pointers are dereferenced to the same value*/
		for(index=0;index<10;index++)
		{
		
		assert_int_equal(*(memmove_src+index),(*memmove_dst+index));
		
		}
		//free(memmove_src);
		free(memmove_dst);
}
		

/*TEST 3
@brief Checks if the function works in overlap condition
@description checks how the function responds if the destination pointer overlaps 
	     in the source pointer region

**/


		
static void my_memmove_test_no_overlap(void** state)
{
		size_t testLength=10;
		uint8_t * memmove_src= malloc(sizeof(uint8_t)*testLength);
		uint8_t * memmove_dst= memove_src + 5;
		uint8_t index;
		/* initialising the source buffer */
		for(index=0;index<10;index++)
		{
		*(memmove_src+index)=index;
		}
		my_memmove(memmove_src,memmove_dst,testLength);
		
		/* checking if the source and destination pointers are dereferenced to the same value*/
		for(index=0;index<10;index++)
		{
		
		assert_int_equal(*(memmove_src+index),(*memmove_dst+index));
		
		}
		free(memmove_src);
		//free(memmove_dst);
}





//***  my_memset tests ********* 
/***
TEST 1
@ brief Check for NULL pointer
@description checks how the function responds if the input is a null pointer

**/

static void my_memset_test_null(void** state)
{
		size_t testLength=10;
		uint8_t setValue=55;
		uint8_t * memset_data=NULL; 
		
		
		// Testing if memset function return 0 if a null pointer is given as the input 
		assert_int_equal(my_memset(memset_data,testLength,setValue),0) ;

}

/***
TEST 2
@brief Check if the values are set properly
@description Checks if the all the memory location are set with the given value
**/

static void my_memset_test(void** state)
{
		size_t testLength=10;
		uint8_t setValue=55;
		uint8_t * memset_data=malloc(sizeof(uint8_t)*testLength),* test_data=malloc(sizeof(uint8_t)*testLength); 
		
		
		// Testing my_memset by verifying its results with memset function from string.h
		assert_memory_equal((uint8_t*)memset(test_data,setValue,testLength),my_memset(memset_data,testLength,setValue),testLength) ;

		free(memset_data);
		free(test_data);
}

// *** my_memzero tests ***** 
/***
TEST 1
@brief Check for NULL pointer
@description Checks how the function responds if a null pointer is given as an input
**/

static void my_memzero_test_null(void** state)
{
		size_t testLength=10;
		uint8_t * memzero_data=NULL; 
		
		// Testing if the memzero function throws error if the null pointer is given as input
		assert_int_equal(my_memzero(memzero_data,testLength),0) ;
		
}

/***
TEST 2
@brief Check if the values are set properly
@description Checks if the all the memory location are set with the given zero
**/

static void my_memzero_test(void** state)
{
		size_t testLength=10;
		uint8_t * memzero_data=malloc(sizeof(uint32_t)*testLength),* test_data=malloc(sizeof(uint32_t)*testLength); 
		
		// Testing my_memzero by verifying its results with memset function from string.h
		assert_memory_equal((uint8_t*)memset(test_data,0,testLength),my_memzero(memzero_data,testLength),testLength) ;

		free(memzero_data);
		free(test_data);
}

// tests for my_reverse 
/**
TEST 1
@brief test for NULL pointer
@description Checks how the function responds if a null pointer is given as an input
*/

static void my_reverse_test_null(void** state)
{
		size_t testLength=10;
		uint8_t * reverse_data=NULL; 
		
		// Testing if the function throws error if a null pointer is given as an input
		assert_int_equal(my_reverse(reverse_data,testLength),0) ;
		
}

/**
TEST 2
@brief test for odd number of characters
@description This function tests if the function reverses properly 
	if it is fed with odd number of characters in the input stream 
*/

static void my_reverse_test_odd(void** state)
{
		size_t testLength=11;
		char testdata[]="abcde\n54321";
		char resultdata[]="12345\nedcba" ;
		
		// Testing if the function reverses properly  a raw data input if the length is an odd number
		assert_memory_equal((uint8_t*)my_reverse((uint8_t*)testdata,testLength),resultdata,testLength) ;

}

/**
TEST 3
@ brief test even number of characters
@description This function tests if the function reverses properly 
	if it is fed with even number of characters in the input stream 
*/

static void my_reverse_test_even(void** state)
{
		size_t testLength=10;
		char testdata[]="abcd\n54321";
		char resultdata[]="12345\ndcba" ;
		
		// Testing if the function reverses properly  a raw data input if the length is an even number
		
		assert_memory_equal((uint8_t*)my_reverse((uint8_t*)testdata,testLength),resultdata,testLength) ;

}

/**
TEST 4
@brief test for all charcters from 0 to 255
@description This function tests if the function reverses properly 
	if it is fed with ascii characters other than numbers and alphabets
	in the input stream 
*/

static void my_reverse_test_all_characters(void** state)
{
		size_t testLength=256;
		char testdata[256],resultdata[256];
		int i;
		
		for(i=0;i<256;i++)
		{
			*(testdata+i)=i;
			*(resultdata+i)=255-i;
		}
		
		// Testing that the values starting from location testdata after reversal are same as in resultdata which was originally setup to be in reverse
		assert_memory_equal((uint8_t*)my_reverse((uint8_t*)testdata,testLength),resultdata,testLength) ;

}

int main (void)
{
	const struct CMUnitTest tests[] =
	{
		cmocka_unit_test(my_memmove_test_null_1),
		cmocka_unit_test(my_memset_test_null),
		cmocka_unit_test(my_memset_test),
		cmocka_unit_test(my_memzero_test_null),
		cmocka_unit_test(my_memzero_test),
		cmocka_unit_test(my_reverse_test_null),
		cmocka_unit_test(my_reverse_test_odd),
		cmocka_unit_test(my_reverse_test_even),
		cmocka_unit_test(my_reverse_test_all_characters),
		
	};
	
	return cmocka_run_group_tests(tests,NULL,NULL);

}



