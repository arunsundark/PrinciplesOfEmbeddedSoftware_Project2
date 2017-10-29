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
Check for NULL pointer
**/
static void my_memmove_test_null_1(void** state)
{
		size_t testLength=10;
		
		uint8_t * memmove_src=NULL,* memmove_dst= malloc(sizeof(uint8_t)*testLength); 
		
		// Testing 
		assert_int_equal(my_memmove(memmove_src,memmove_dst,testLength),0) ;
		free(memmove_dst);
}



//***  my_memset tests ********* 
/***
TEST 1
Check for NULL pointer
**/

static void my_memset_test_null(void** state)
{
		size_t testLength=10;
		uint8_t setValue=55;
		uint8_t * memset_data=NULL; 
		
		
		// Testing 
		assert_int_equal(my_memset(memset_data,testLength,setValue),0) ;

}

/***
TEST 2
Check if the values are set properly
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
Check for NULL pointer
**/

static void my_memzero_test_null(void** state)
{
		size_t testLength=10;
		uint8_t * memzero_data=NULL; 
		
		// Testing 
		assert_int_equal(my_memzero(memzero_data,testLength),0) ;
		
}

/***
TEST 2
Check if the values are set properly
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
test for NULL pointer
*/

static void my_reverse_test_null(void** state)
{
		size_t testLength=10;
		uint8_t * reverse_data=NULL; 
		
		// Testing 
		assert_int_equal(my_reverse(reverse_data,testLength),0) ;
		
}

/**
TEST 2
test for odd number of characters
*/

static void my_reverse_test_odd(void** state)
{
		size_t testLength=11;
		char testdata[]="abcde\n54321";
		char resultdata[]="12345\nedcba" ;
		
		// Testing 
		assert_memory_equal((uint8_t*)my_reverse((uint8_t*)testdata,testLength),resultdata,testLength) ;

}

/**
TEST 3
test even number of characters
*/

static void my_reverse_test_even(void** state)
{
		size_t testLength=10;
		char testdata[]="abcd\n54321";
		char resultdata[]="12345\ndcba" ;
		
		// Testing 
		assert_memory_equal((uint8_t*)my_reverse((uint8_t*)testdata,testLength),resultdata,testLength) ;

}

/**
TEST 4
test for all charcters from 0 to 255
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



