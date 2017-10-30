#include "debug.h"
#include "memory.h"
#include "platform.h"


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
	
	printf("\nNo ProjectN Compile Time Switch, if you need it run \nmake clean \nand run \nmake build PS=-DPROJECTn\n");
	uint8_t * memmove_src= malloc(sizeof(uint8_t)*10);
	uint8_t * memmove_dst= memmove_src + 5;
	int index=0;
	
	for(index=0;index<10;index++)
		{
			*(memmove_src+index)=index;
		}
		printf("\nbefore\n");
	print_memory(memmove_src,10);
	print_memory(memmove_dst,10);
	my_memmove(memmove_src,memmove_dst,10);
	printf("\nafter\n");
	print_memory(memmove_src,10);
	print_memory(memmove_dst,10);
	
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
	
	//free(ptr); */
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
	
	
	CB_t * my_cb=malloc(sizeof(CB_t));
    CB_init(my_cb,10);
	
	uint8_t *a=malloc(1*sizeof(uint8_t));
	
	//printf("CB location %p",my_cb);
	//printf("\n%d",CB_init(my_cb,10));
	//printf("\ncreated\n");
	printf("\n1. %d",CB_buffer_add_item(my_cb,'e'));
	printf("\n2. %d",CB_buffer_add_item(my_cb,'e'));
	printf("\n3. %d",CB_buffer_add_item(my_cb,'e'));
	printf("\n4. %d",CB_buffer_add_item(my_cb,'e'));
	printf("\n5. %d",CB_buffer_add_item(my_cb,'e'));
	printf("\n6. %d",CB_buffer_add_item(my_cb,'e'));
	printf("\n7. %d",CB_buffer_add_item(my_cb,'e'));
	printf("\n8. %d",CB_buffer_add_item(my_cb,'e'));
	printf("\n9. %d",CB_buffer_add_item(my_cb,'e'));
	printf("\n10. %d",CB_buffer_add_item(my_cb,'e'));
	printf("\n11. %d",CB_buffer_add_item(my_cb,'e'));
	//printf("\nadded\n");
	//printf("\n%c\n",*a);
	//printf("\n%p\n",my_cb->head);
	//printf("\n%d\n",my_cb->tail);
	//printf("\n%d\n",my_cb->data);
	//printf("\n%x\n",my_cb);
	
	//CB_buffer_remove_item(my_cb,a);
	//printf("\n removed");
	//printf("\n%c\n",*a);
	int i=1;
	while(CB_is_empty(my_cb)!=0)
    		{	
    			CB_buffer_remove_item(my_cb,a);
    			printf("\n%d ,%c",i,*a);
				++i;
    		}
	
	
	CB_destroy(my_cb);
	*/
