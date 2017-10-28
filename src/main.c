#include "debug.h"
#include "memory.h"
#include "conversion.h"
#include "platform.h"
#include "circularbuffer.h"
//#include "uart.h"

int main()
{

#ifdef PROJECT1
	#define NOPRINTDEFAULT
	#include "project1.h"	
	project1();
	
#endif	

#ifdef PROJECT2
	#define NOPRINTDEFAULT
	#include "project2.h"	
	project2();
	
#endif	


#ifndef NOPRINTDEFAULT
	/*
	uint8_t test_data[16]="UART_Initialized";

	uint8_t newline[1]="\n";
	UART_configure(); // Initialize UART0

    // interrupt and NVIC functions from core_cm0plus.h
    NVIC_ClearPendingIRQ(UART0_IRQn); // Clear pending UART interrupts from NVIC ICPR register
    NVIC_EnableIRQ(UART0_IRQn); // Enable UART0 interrupt in NVIC ISER
    NVIC_SetPriority(UART0_IRQn,2); //Set priority of 2 for UART0 interrupt
    __enable_irq(); // Enable global interrupts

    UART_send_n(test_data,16);
    UART_send(newline);
	*/
	
	
	uint8_t *a=malloc(1*sizeof(uint8_t));
	
	//printf("CB location %p",my_cb);
	//printf("\n%d",CB_init(my_cb,10));
	//printf("\ncreated\n");
	CB_buffer_add_item(my_cb,'e');
	//printf("\nadded\n");
	//printf("\n%c\n",*a);
	//printf("\n%p\n",my_cb->head);
	//printf("\n%d\n",my_cb->tail);
	//printf("\n%d\n",my_cb->data);
	//printf("\n%x\n",my_cb);
	
	CB_buffer_remove_item(my_cb,a);
	//printf("\n removed");
	//printf("\n%c\n",*a);
	
	CB_destroy(my_cb);
	
#endif
return 0;

}



	//uint8_t teststring[]="abcde\n4321";
	//uint8_t *ptr = teststring;
	/*char testdata[256],resultdata[256];
	int i;
	
		for(i=0;i<256;i++)
		{
			*(testdata+i)=i;
			*(resultdata+i)=255-i;
		}
	
	print_memory(my_reverse((uint8_t*)testdata,256),256);
	//print_memory(my_reverse(ptr,10),10);
	printf("\nNo ProjectN Compile Time Switch, if you need it run \nmake clean \nand run \nmake build PS=-DPROJECTn\n");
	//free(ptr); */
