#include<stdint.h>
#include"circularbuffer.h"
#include"uart.h"
#include<stdlib.h>

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

/*
@brief uint8_t* count counts the number of alphabets,numbers,punctuations, miscellaneous characters recieved 
@param CB_t* source_buffer the input buffer which is to be checked
@return  numbers of alphabets count

*/

uint8_t* dataprocesser(CB_t* source_ptr,uint32_t* count);






