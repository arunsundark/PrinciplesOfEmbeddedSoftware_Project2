#include "debug.h"
#include "memory.h"
#include "conversion.h"
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
	
	//uint8_t teststring[]="abcde\n4321";
	//uint8_t *ptr = teststring;
	char testdata[256],resultdata[256];
	int i;
	
		for(i=0;i<256;i++)
		{
			*(testdata+i)=i;
			*(resultdata+i)=255-i;
		}
	
	print_memory(my_reverse((uint8_t*)testdata,256),256);
	//print_memory(my_reverse(ptr,10),10);
	printf("\nNo ProjectN Compile Time Switch, if you need it run \nmake clean \nand run \nmake build PS=-DPROJECTn\n");
	//free(ptr);
#endif
return 0;
}
