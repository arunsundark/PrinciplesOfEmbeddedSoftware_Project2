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

	printf("\nNo Project n Compile Time Switch, if you need it run \nmake clean \nand use \nPS=-DPROJECTn\n");

#endif
return 0;
}
