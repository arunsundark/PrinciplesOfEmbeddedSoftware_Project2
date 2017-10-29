#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <string.h>

#include "conversion.h"

//****** big_to_little tests
/***
TEST 1
Check for NULL pointer
**/
static void big_to_little32_test_null(void** state)
{
		size_t testLength=10;
		
		uint32_t * big_to_little32_data=NULL;
		
		// Testing 
		assert_int_equal(big_to_little32(big_to_little32_data,testLength),99) ;
}

/***
TEST 2
Check for Valid Conversion
**/
static void big_to_little32_test_conversion(void** state)
{
		size_t testLength=1;
		
		uint32_t * big_to_little32_TestData=malloc(sizeof(uint32_t)*testLength),* big_to_little32_ReturnData=malloc(sizeof(uint32_t)*testLength);
		* big_to_little32_TestData=0xab12cd34;
		* big_to_little32_ReturnData=0x34cd12ab;
		big_to_little32(big_to_little32_TestData,testLength);// running big to little to change the endianess
		
		// Testing if the changed endianess matches with the preset test value
		assert_memory_equal(big_to_little32_TestData,big_to_little32_ReturnData,testLength) ;
}


//****** little_to_big tests
/***
TEST 1
Check for NULL pointer
**/
static void little_to_big32_test_null(void** state)
{
		size_t testLength=10;
		
		uint32_t * little_to_big32_data=NULL;
		
		// Testing 
		assert_int_equal(little_to_big32(little_to_big32_data,testLength),99) ;
}

/***
TEST 2
Check for Valid Conversion
**/
static void little_to_big32_test_conversion(void** state)
{
		size_t testLength=1;
		
		uint32_t * little_to_big32_TestData=malloc(sizeof(uint32_t)*testLength),* little_to_big32_ReturnData=malloc(sizeof(uint32_t)*testLength);
		* little_to_big32_TestData=0xab12cd34;
		* little_to_big32_ReturnData=0x34cd12ab;
		little_to_big32(little_to_big32_TestData,testLength);// running little to big to change the endianess
		
		// Testing if the changed endianess matches with the preset test value
		assert_memory_equal(little_to_big32_TestData,little_to_big32_ReturnData,testLength) ;
}

int main (void)
{
	const struct CMUnitTest tests[] =
	{
		cmocka_unit_test(big_to_little32_test_null),
		cmocka_unit_test(big_to_little32_test_conversion),
		cmocka_unit_test(little_to_big32_test_null),
		cmocka_unit_test(little_to_big32_test_conversion),
	};
	
	return cmocka_run_group_tests(tests,NULL,NULL);

}