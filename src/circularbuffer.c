/**
*@file circularbuffer.c
*@brief circularbuffer usage functions 
*@Author Aakash Kumar/ArunSundar
*@date Oct 16 2017

*/




#include<circularbuffer.h>

/**
@brief  Initializes the data memebers of the CB_t structure
        and allocates memory for the circularbuffer 

@param  CB_t* source_ptr pointer to the CB_t structure

@param  length gives the length of the circular buffer

@return returns the status of the operation on the buffer
*/


CB_status CB_init(CB_t* source_ptr, int length)
{	
	/*checks for null pointer */


	if(source_ptr==NULL && length==0)
	{
		return nullerror;
	}
	else 
	{       /* initializes the pointers to the circular buffer*/

		source_ptr->data=(int*)malloc(length*sizeof(int));

		source_ptr->head=source_ptr->data;

		source_ptr->tail=source_ptr->head;

		source_ptr->length=length;
		//printf("%d \n",source_ptr->length);

		source_ptr->limit=source_ptr->data+(length-1);

		source_ptr->count=0;

		return success;	
	}
}


/**
@brief  Adds data to the circular buffer 

@param  CB_t* source_ptr pointer to the CB_t structure

@param  value gives the value to be added to the circular buffer

@return returns the status of the operation on the buffer
*/

CB_status CB_buffer_add_item(CB_t* source_ptr,uint8_t value)
{

	/*checks for null pointer */

	if(source_ptr==NULL)
	{
		return nullerror;
	}

	else
	{	/*Checks if the buffer is full */ 

		if(source_ptr->count = source_ptr->length)

		{
			source_ptr->tail=value;

			/* sets the head pointer to the currently added location */

			source_ptr->head=source_ptr->tail;

			int last_data;

			/* call remove function to set the tail pointer to the new "oldest element" in the buffer */

			CB_status st=CB_buffer_remove_item(source_ptr,last_data);
		}
		else
		{	/* For adding when the buffer is not full */
			source_ptr->head+=1;

			source_ptr->head=value;

		}
	source_ptr->count++;

	return success;
	}
}


/**
@brief  Removes data to the circular buffer 

@param  CB_t* source_ptr pointer to the CB_t structure

@param  value gets the value to be removed from the circular buffer

@return returns the status of the operation on the buffer
*/


CB_status CB_buffer_remove_item(CB_t* source_ptr,int* value)
{
	/*checks for null pointer */
	 
	if(source_ptr==NULL)
	{
		return nullerror;
	}

	else
	{
		/* gets the value that is removed */

		*value=*(source_ptr->tail);
			
		/* checks corner case and assigns tails to the base address */

		if(source_ptr->tail==source_ptr->limit)
		{
			printf("your code works \n");

			printf("%p \n",source_ptr->tail);

			printf("your code works \n");

			source_ptr->tail=source_ptr->data;
		}
		else 
		{ 

			/* for regular cases other than the corner cases */	

			printf("your code doesnt work \n");

			printf("%p \n",source_ptr->tail);

			source_ptr->tail+=1;

			printf("your code doesnt work \n");

			printf("%p \n",source_ptr->tail);

			printf("%d \n",*(source_ptr->tail));
		}
		source_ptr->count--;
		return success;
	}
}


/**
@brief  Peeks into the circular buffer 

@param  CB_t* source_ptr pointer to the CB_t structure

@param  peeked_ptr gives the peeked value from the circular buffer

@param  position gives the position to peek from the circular buffer

@return returns the status of the operation on the buffer
*/


CB_status CB_peek(CB_t* source_ptr,int position, int* peeked_ptr)
{


	/*checks for null pointer */

	if(source_ptr == NULL)
	{
		return nullerror;
	}

	else
	{

		/* checks for non-corner cases */

		if(((source_ptr->head) + position) <= source_ptr->limit)
		{
			*peeked_ptr = *((source_ptr->head) + position);

			return success;
		}
 

		else if(((source_ptr->head) + position) > source_ptr->limit)
		{ 

			/*checks for corner cases */

			int difference = ((source_ptr->head) + position) - source_ptr->limit;

			*peeked_ptr=*((source_ptr->data) + difference);

			return success;
 

		}
	}
}


/**
@brief  Checks if the circular buffer is full 

@param  CB_t* source_ptr pointer to the CB_t structure

@return returns the status of the operation on the buffer
*/



CB_status CB_is_full(CB_t* source_ptr)
{	

	/*checks for null pointer */


	if(source_ptr==NULL)
	{
		return nullerror;
	}

	else
	{

		/* check buffer full condition */

		if(source_ptr->count==source_ptr->length)
		{
			printf("buffer is full");
			return buffer_full;
		}
	}
}


/**
@brief  Checks if the circular buffer is empty

@param  CB_t* source_ptr pointer to the CB_t structure

@return returns the status of the operation on the buffer
*/




CB_status CB_is_empty(CB_t* source_ptr)
{

	/*checks for null pointer */


	if(source_ptr==NULL)
	{
		return nullerror;
	}
	else 
	{

		/* check buffer full condition */			

		if(source_ptr->count==0)
		{
			printf("buffer is empty");

			return buffer_empty;
		}
	}
}


/**
@brief  frees the memory allocated to the circular buffer

@param  CB_t* source_ptr pointer to the CB_t structure

@return returns the status of the operation on the buffer
*/




CB_status CB_destroy(CB_t* source_ptr)
{

	/* check for null pointer condition */

	if(source_ptr==NULL)
	{
		return nullerror;
	}
	else
	{

		/* frees the allocated memory */ 

		free(source_ptr->data);

		return success;
	}
}


