
/**
*@file test_circularbuffer.c
*@brief Testing functions for circularbuffer usage functions 
*@Author Aakash Kumar/ArunSundar
*@date Oct 28 2017

*/





#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include<stdlib.h>
#include <string.h>

#include"circularbuffer.h"

/*
Test1
@brief This function checks if the circular buffer is alloted memory 
	and freed when the corresponding function are called

@ description This function calls the CB_init and CB_destroy functions 
		and testtheir retun values using assert_int_equal
*/	


static void my_circularbuffer_test_allocatefree_1(void** state)
{
CB_t* source_ptr=malloc(sizeof(CB_t));
uint8_t length=10;
/* testing if the init function is properly allocating memory or not*/
/* function returns 2 if the operation is successful */
assert_int_equal(CB_init(source_ptr,length),2);
/* testing if the destroy function is properly deallocating memory or not*/
/* function returns 2 if the operation is successful */
assert_int_equal(CB_destroy(source_ptr),2);

}

/*
Test2
@brief This function checks if the circular buffer function CB_init responds when
	a NULL pointer is sent as the input

@ description This function calls the CB_init functions 
		and test their return values using assert_int_equal
*/	



static void my_circularbuffer_test_null(void** state)
{
		uint8_t length=10;
		
		CB_t * source_ptr=NULL; 
		
		
		/* Testing if the init function prompts error 
		   if a NULL pointer is sent */	
		assert_int_equal(CB_init(source_ptr,length),3);
}

/*
Test3
@brief This function checks if the circular buffer elements are initialised
	properly with 0

@ description This function calls the CB_init and CB_peek functions 
		to test if they are initialised to zero using assert_int_equal
*/	

static void my_circularbuffer_test_initialized(void** state)
{
		uint8_t length=10;
		uint8_t position=1;
 		uint8_t* peeked_ptr=malloc(sizeof(uint8_t)*10);
		CB_t* source_ptr=malloc(sizeof(CB_t)); 
		CB_init(source_ptr,length);
		
		
		// Testing if the buffer is initialized with zero
	uint8_t i; 
		/* peeking in all the indices of the buffer and checking their value */
		for(i=0;i<length;i++)
		{CB_peek(source_ptr,position,peeked_ptr+i);
		assert_int_equal(*(peeked_ptr+i),0);
		}
}

/*
Test4
@brief This function checks if the circular buffer elements are added and 
	removed properly

@ description This function calls the CB_buffer_add_item and CB_buffer_remove_item 
		functions to add an item and remove the same and test if they are equal 
		 using assert_int_equal
*/	





static void my_circularbuffer_test_addremove(void** state)
{

		uint8_t length=10;
		uint8_t value=7;
		
 		uint8_t* removed_ptr=malloc(sizeof(uint8_t));
		CB_t* source_ptr=malloc(sizeof(CB_t)); 
		CB_init(source_ptr,length);
		/* adding an element to buffer*/
		CB_buffer_add_item(source_ptr,value);
		/* removing the element added */
		CB_buffer_remove_item(source_ptr,removed_ptr);
		/* testing if both are equal */		
		assert_int_equal(*(removed_ptr),value);
		
}

/*
Test5
@brief This function checks if the circular buffer full function returns
	buffer_empty when completely filled
 
@ description This function calls the CB_buffer_add_item and adds to it capacity and calls 
		 CB_full to check if it returns buffer_full using assert_int_equal
*/

static void my_circularbuffer_test_full(void** state)
{
		uint8_t length=3;
		uint8_t value=7;
		CB_t * source_ptr=malloc(sizeof(CB_t));  
		CB_init(source_ptr,length);
		CB_buffer_add_item(source_ptr,value);
	        CB_buffer_add_item(source_ptr,value);
		CB_buffer_add_item(source_ptr,value);
		
		/* sending a fully filled buffer to test 
	           the buffer_full function */
		assert_int_equal(CB_is_full(source_ptr),1);
}


/*
Test6
@brief This function checks if the circular buffer empty function returns
	buffer_empty when it is empty
 
@ description This function calls the CB_empty to check if it returns 
		buffer_empty using assert_int_equal
*/	





static void my_circularbuffer_test_empty(void** state)
{
		uint8_t length=3;
		
		CB_t * source_ptr=malloc(sizeof(CB_t));  
		CB_init(source_ptr,length);
		
		/* sending a empty buffer to test buffer_empty function */ 
		assert_int_equal(CB_is_empty(source_ptr),0);
}

/*
Test7
@ brief This function tests if the CB_buffer_add_item function wraps around for
	the corner cases while adding elements to the buffer
@ description In this function, the buffer is filled to its capacity and and one more 
		element is removed and one more is added. If the element is added in 
		the base address of the pointer to buffer, then it will show circular buffer 
		wraps around for corner cases
*/

 
static void my_circularbuffer_test_wrapadd(void** state)
{		uint8_t* removed_ptr=malloc(sizeof(uint8_t));
		uint8_t length=3;
		
		uint8_t value=7;
		
		CB_t * source_ptr=malloc(sizeof(CB_t));  
		CB_init(source_ptr,length);
		/* trying to add to full buffer capacity */
		CB_buffer_add_item(source_ptr,value);
	        CB_buffer_add_item(source_ptr,value);
		CB_buffer_add_item(source_ptr,value);
		/*removing oldest item*/

		CB_buffer_remove_item(source_ptr,removed_ptr);
		
		/* if *source_ptr is equal to 8, the previously loaded value, 
		   it shows the add function wraps around at corner */

		CB_buffer_add_item(source_ptr,8);
		
		
		
		assert_ptr_equal(*source_ptr->data,8);	
}

/*
Test8
@ brief This function tests if the CB_buffer_remove_item function wraps around for
	the corner cases while removing elements from the buffer
@ description In this function, the buffer is filled to its capacity and and elements 
		are removed one by one till the corner and again one more element is added. 
		In the next call to remove function, if the element is removed from 
		the base address of the pointer to buffer, it will show that circular buffer 
		 remove function wraps around for corner cases
*/




static void my_circularbuffer_test_wrapremove(void** state)
{		uint8_t* removed_ptr=malloc(sizeof(uint8_t));
		uint8_t length=3;
		uint8_t value=7;
		
		CB_t * source_ptr=malloc(sizeof(CB_t));  
		CB_init(source_ptr,length);
		/* trying to add to full buffer capacity */
		CB_buffer_add_item(source_ptr,value);
	        CB_buffer_add_item(source_ptr,value);
		CB_buffer_add_item(source_ptr,value);
		/*removing oldest item*/

		CB_buffer_remove_item(source_ptr,removed_ptr);
		/* adding an element again */
		CB_buffer_add_item(source_ptr,8);
		CB_buffer_remove_item(source_ptr,removed_ptr);
		CB_buffer_remove_item(source_ptr,removed_ptr);
		CB_buffer_remove_item(source_ptr,removed_ptr);
		/* removing everything will store the previously added variable*/
		/* if *removed_ptr is equal to 8, the previously loaded value, 
		   it shows the remove function wraps around at corner */
		assert_int_equal(*(removed_ptr),8);

}

/*
Test9
@brief This function detects if the add function prompts buffer_full error 
	when more elements are tried to be added when the buffer is full
@ description In this function, the buffer is added with more number of 
		of elements. When one more element is added
		which will exceed the buffer length, the function show throw a
		buffer_full error
*/



  

static void my_circularbuffer_test_overfill(void** state)
{
	uint8_t length=3;
	uint8_t value=7;
	CB_t * source_ptr=malloc(sizeof(CB_t));  
	CB_init(source_ptr,length);
	CB_status s1=CB_buffer_add_item(source_ptr,value);
	s1=CB_buffer_add_item(source_ptr,value);
	s1=CB_buffer_add_item(source_ptr,value);
	/* trying to add to a full empty buffer */
		/* should throw a buffer_full error */
	s1=CB_buffer_add_item(source_ptr,8);
	assert_int_equal(s1,1);
}

/*
Test10
@brief This function detects if the remove function prompts buffer_empty error 
	when elements are tried to be removed when buffer is empty
@ description In this function, the buffer is tried to be removed with more number of 
		of elements than what is present,the function show throw a
		buffer_full error, which is verified using assert_int_equal() function
*/



static void my_circularbuffer_test_overemove(void** state)
{		uint8_t* removed_ptr=malloc(sizeof(uint8_t));
		uint8_t length=3;
		
		CB_t * source_ptr=malloc(sizeof(CB_t));  
		CB_init(source_ptr,length);
		/* trying to remove from an empty buffer */
		/* should throw a buffer_empty error */
		CB_status s1=CB_buffer_remove_item(source_ptr,removed_ptr);

		assert_int_equal(s1,0);
}


int main (void)
{
	const struct CMUnitTest tests[] =
	{
		cmocka_unit_test(my_circularbuffer_test_allocatefree_1),
		cmocka_unit_test(my_circularbuffer_test_null),
		cmocka_unit_test(my_circularbuffer_test_initialized),
		cmocka_unit_test(my_circularbuffer_test_addremove),
		cmocka_unit_test(my_circularbuffer_test_full),
		cmocka_unit_test(my_circularbuffer_test_empty),
		cmocka_unit_test(my_circularbuffer_test_wrapadd),
		cmocka_unit_test(my_circularbuffer_test_wrapremove),
		cmocka_unit_test(my_circularbuffer_test_overfill),
		cmocka_unit_test(my_circularbuffer_test_overemove),
		
	};
	
	return cmocka_run_group_tests(tests,NULL,NULL);

}



	
