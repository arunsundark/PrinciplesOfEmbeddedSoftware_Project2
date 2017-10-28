#include<stdint.h>
#include"circularbuffer.h"
#include"uart.h"
typedef struct
{
	static uint16_t alphabet_count=0;
	static uint16_t numeric_count=0;
	static uint16_t punctuation_count=0;
	static uint16_t misc_count=0;
}stats;	

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


/*
@brief counts the number of alphabets recieved 
@param CB_t* source_buffer the input buffer which is to be checked
@return  numbers of alphabets count

*/

uint16_t count_alphabets(CB_t* source_ptr);




/*
@brief counts the number of "numbers" recieved 
@param CB_t* source_buffer the input buffer which is to be checked
@return  numbers of "numbers" count

*/

uint16_t count_numbers(CB_t* source_ptr);







/*
@brief counts the number of punctuation marks recieved 
@param CB_t* source_buffer the input buffer which is to be checked
@return  numbers of punctuation mark counts

*/
uint16_t count_punctuations(CB_t* source_ptr);








/*
@brief counts the number of miscellaneous characters recieved 
@param CB_t* source_buffer the input buffer which is to be checked
@return  numbers of miscellaneous characters counts

*/
uint16_t count_misc(CB_t* source_ptr);









