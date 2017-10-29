
/**
*@file project2.c
*@brief project2 implementation is done from this file 
*@Author Aakash Kumar/ArunSundar
*@date Oct 28 2017

*/

#include "project2.h"


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

uint8_t* dataprocesser(CB_t* source_ptr,uint32_t* count)
{
uint8_t * removed_data=(uint8_t*)malloc(sizeof(uint8_t));
uint8_t index=0;
	while(source_ptr->count >0)
	{
			CB_buffer_remove_item(source_ptr,removed_data);
			
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


CB_t * rx_cb; // Receive Circular Buffer

uint8_t test_data[17]="UART0 Initialized";
uint8_t num_alphabets[19]="No of Alphabets is:";
uint8_t num_integers[18]="No of Integers is:";
uint8_t num_punctuations[22]="No of Punctuations is:";
uint8_t num_specialchars[28]="No of Special Characters is:";

uint32_t char_count[4]={0,0,0,0},toTx;
uint8_t newline[1]="\n";
uint8_t tab[1]="\t";
int cur_position;
uint8_t  a[4];



void back_home(int n)
{
	int l;
	uint8_t bkspc_char=0x08;
	for(l=0;l<n;l++)
	{
		UART_send(&bkspc_char);
	}
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

    UART_configure(); // Initialize UART0

    // interrupt and NVIC functions from core_cm0plus.h
    NVIC_ClearPendingIRQ(UART0_IRQn); // Clear pending UART interrupts from NVIC ICPR register
    NVIC_EnableIRQ(UART0_IRQn); // Enable UART0 interrupt in NVIC ISER
    NVIC_SetPriority(UART0_IRQn,2); //Set priority of 2 for UART0 interrupt
    __enable_irq(); // Enable global interrupts

    rx_cb=malloc(sizeof(CB_t));
    CB_init(rx_cb,100);

    UART_send_n(test_data,17);
    UART_send(newline);
    back_home(17);
    for (;;) {


    	if(rx_cb->count == 100)
    	{
    		UART_send(newline);

    		dataprocesser(rx_cb,char_count);
    			for(int k=0;k<4;k++)
    			{
    				toTx=my_itoa(*(char_count+k),a,10);

    				if(k==0) cur_position=UART_send_n(num_alphabets,19);
    				if(k==1) cur_position=UART_send_n(num_integers,18);
    				if(k==2) cur_position=UART_send_n(num_punctuations,22);
    				if(k==3) cur_position=UART_send_n(num_specialchars,28);

    				cur_position+=UART_send_n(a,toTx);
    				back_home(cur_position);
    				UART_send(newline);

    			}


    	}

    }

}
