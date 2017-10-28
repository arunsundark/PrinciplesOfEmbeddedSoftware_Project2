#include "debug.h"
#include "memory.h"
#include "conversion.h"
#include "platform.h"
#include "circularbuffer.h"


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
	
	CB_t * my_cb=malloc(sizeof(CB_t));
	uint8_t *a=malloc(1*sizeof(uint8_t));
	
	printf("CB location %p",my_cb);
	printf("\n%d",CB_init(my_cb,10));
	printf("\ncreated\n");
	CB_buffer_add_item(my_cb,'e');
	printf("\nadded\n");
	//printf("\n%c\n",*a);
	//printf("\n%p\n",my_cb->head);
	//printf("\n%d\n",my_cb->tail);
	//printf("\n%d\n",my_cb->data);
	//printf("\n%x\n",my_cb);
	
	CB_buffer_remove_item(my_cb,a);
	printf("\n removed");
	printf("\n%c\n",*a);
	
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
