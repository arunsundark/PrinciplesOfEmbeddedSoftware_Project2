#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <string.h>

#include "memory.h"

static void test_my_memset(void** state)
{
		size_t testLength=10;
		uint8_t setValue=55;
		uint8_t * memset_data=malloc(sizeof(uint32_t)*testLength),* test_data=malloc(sizeof(uint32_t)*testLength); 
		
		
		// Testing my_memset by verifying its results with memset function from string.h
		assert_memory_equal((uint8_t*)memset(test_data,setValue,testLength),my_memset(memset_data,testLength,setValue),testLength) ;

		free(memset_data);
		free(test_data);
}

static void test_my_memzero(void** state)
{
		size_t testLength=10;
		uint8_t * memzero_data=malloc(sizeof(uint32_t)*testLength),* test_data=malloc(sizeof(uint32_t)*testLength); 
		
		// Testing my_memzero by verifying its results with memset function from string.h
		assert_memory_equal((uint8_t*)memset(test_data,0,testLength),my_memzero(memzero_data,testLength),testLength) ;

		free(memzero_data);
		free(test_data);
}


int main (void)
{
	const struct CMUnitTest tests[] =
	{
		cmocka_unit_test(test_my_memset),
		cmocka_unit_test(test_my_memzero),
	};
	
	return cmocka_run_group_tests(tests,NULL,NULL);

}