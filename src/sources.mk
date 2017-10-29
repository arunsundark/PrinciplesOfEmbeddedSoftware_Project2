
MAINSOURCE= main.c

COMMONSOURCES= debug.c\
	memory.c\
	conversion.c\
	circularbuffer.c
	
KL25ZSOURCES=uart.c\
	project2.c\
	system_MKL25Z4.c
	
ASSOURCE=startup_MKL25Z4.s
	
INCLUDES=../include/common

TESTSOURCES=test_memory.c
