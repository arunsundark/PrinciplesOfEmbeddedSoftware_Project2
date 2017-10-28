/**
*@file project2.c
*@brief project2 implementation is done from this file 
*@Author Aakash Kumar/ArunSundar
*@date Oct 28 2017

*/








#include"project2.h"



/***
#define alphabet_condition1 (((*removed_data)>=65) && ((*removed_data) <=90))
#define alphabet_condition2 (((*removed_data)>=97) && ((*removed_data) <=122))
#define number_condition1   (((*removed_data)>=48) && ((*removed_data) <=57))
#define punctuation_condition1   (((*removed_data)==34) | ((*removed_data)==33))
#define punctuation_condition2   (((*removed_data)>=39) && ((*removed_data)<=41))
#define punctuation_condition3   (((*removed_data)>=44) && ((*removed_data) <=46))
#define punctuation_condition4   (((*removed_data)==58) | ((*removed_data) ==59))
#define punctuation_condition5   (((*removed_data)==125) |((*removed_data) ==123))
#define punctuation_condition6   (((*removed_data)==63) | ((*removed_data) ==95))
#define misc_condition1   (((*removed_data)>=1) && ((*removed_data) <=32))

***/





uint8_t* dataprocesser(CB_t* source_ptr,uint8_t* count)
{
uint8_t * removed_data=(uint8_t*)malloc(sizeof(uint8_t));
uint8_t index=0;
	while(source_ptr->count >0)
	{		CB_status st=CB_buffer_remove_item(source_ptr,removed_data);
			
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


}
