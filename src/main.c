#include "debug.h"
#include "memory.h"
#include "conversion.h"
#include "platform.h"



int main()
{

#ifdef PROJECT1
	#include "project1.h"	
	project1();
	
#endif	

#ifdef PROJECT2
	#include "project2.h"	
	project2();
	
#endif	

#ifndef PROJECT1

printf("\nNo Project n Compile Time Switch, if you need it run \nmake clean \nand use \nPS=-DPROJECTn\n");

#endif
return 0;
}
