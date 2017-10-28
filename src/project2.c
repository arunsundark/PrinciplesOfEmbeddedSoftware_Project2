#include "project2.h"
#include "uart.h"
#include "circularbuffer.h"



/***
#define alphabet_condition1 (((*(source_ptr->data+index))>=65) | ((*(source_ptr->data+index)) <=90))
#define alphabet_condition2 (((*(source_ptr->data+index))>=97) | ((*(source_ptr->data+index)) <=122))
#define number_condition1   (((*(source_ptr->data+index))>=48) | ((*(source_ptr->data+index)) <=57))
#define punctuation_condition1   (((*(source_ptr->data+index))==34) | ((*(source_ptr->data+index)) ==33))
#define punctuation_condition2   (((*(source_ptr->data+index))>=39) | ((*(source_ptr->data+index)) <=41))
#define punctuation_condition3   (((*(source_ptr->data+index))>=44) | ((*(source_ptr->data+index)) <=46))
#define punctuation_condition4   (((*(source_ptr->data+index))==58) | ((*(source_ptr->data+index)) ==59))
#define punctuation_condition5   (((*(source_ptr->data+index))==125) | ((*(source_ptr->data+index)) ==123))
#define punctuation_condition6   (((*(source_ptr->data+index))==63) | ((*(source_ptr->data+index)) ==95))
#define misc_condition1   (((*(source_ptr->data+index))>=1) | ((*(source_ptr->data+index)) <=32))
***/


/*
static uint16_t alphabet_count=0;
static uint16_t numeric_count=0;
static uint16_t punctuation_count=0;
static uint16_t misc_count=0;

*/


uint8_t* dataprocesser(CB_t* source_ptr,uint8_t* count)
{

uint8_t index=0;


	while(*(source_ptr->data+index)!='\0')
	{
		if(alphabet_condition1 | alphabet_condition2)
		{
			count[0]++;
		
		}
	
		if(number_condition1)
		{
			count[1]++;
		}

		if(punctuation_condition1 || punctuation_condition2 || punctuation_condition3 || punctuation_condition4 || punctuation_condition5 || punctuation_condition6)
		{
			count[2]++;
		}
		
		if(misc_condition1)
		{
			count[3]++;
		}


		index++;
	}
return count;
}





void project2(void)
{
/*
function call to recieve data from user;

function call to uart to configure and transmit to host ;
function call to recieve uart data;
function call to do data processing in uart;
functonal call to transmit statistics to host mcahine 
display in host machine

*/



}
