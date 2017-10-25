#Makefile for ECEN 5813-002 Project 2
#Author Aakash Kumar

# Variables for compiler
CC=gcc
CCBBB=arm-linux-gnueabihf-gcc

# Compiler flags
CSTD=c99
CFLAGS=-Wall\
	-std=$(CSTD)\
	-g\
#	-Werror\
	-O0

include sources.mk

# Flag for cmocka unit test framework
TESTINCLUDE=-lcmocka
	

#preprocessor flags and 	
CPPFLAGS=-E
LDFLAGS=

#Set platform to build for as host machine by default
PLATFORM=HOST

#size tools for different platforms
SIZETOOL=size
SIZETOOLBBB=arm-linux-gnueabihf-size
	
.PHONY:build clean compile-all upload unittests

#compile time switches for verbose output
#and adding in 
DS=VERBOSE
PS=

#List of files to be cleaned when running clean
TOREMOVE=$(OFILEPATH)/*.o\
	$(TESTOBJPATH)/*.o\
	$(TESTTARGET)\
	$(TARGET)\
	$(OFILEPATH)/*.map\
	*.asm\
	*.i\
	$(OFILEPATH)/*.d\
	$(TESTOBJPATH)/*.d\
	$(OFILEPATH)/*.dep\


#if platform is beaglebone black 	
#change compiler used
ifeq ($(PLATFORM),BBB)
CC = $(CCBBB)
SIZETOOL=$(SIZETOOLBBB)
else

#if platform is KL25Z, change compiler used and linker flags 
#and add additional startup code/Include files for KL25Z
ifeq ($(PLATFORM),KL25Z)
CC = arm-none-eabi-gcc
SIZETOOL=arm-none-eabi-size
DS=KL25Z
INCLUDES+=-I ../include/CMSIS\
	-I ../include/kl25z
LDFLAGS=-T ../platform/MKL25Z128xxx4_flash.ld\
	-march=armv6-m\
	-mthumb -mcpu=cortex-m0\
	-mfpu=fpv4-sp-d16\
	--specs=nosys.specs
SOURCES+=system_MKL25Z4.c\
	startup_MKL25Z4.s
OBJECTS+=$(addprefix $(OFILEPATH)/,$(SOURCES:.s=.o))
endif
endif

#Path where file is transferred to in the BBB when using the upload target
BBBPATH=/home/code/

#declaring targets with folders to put them in
CUR_TARGET=project2
TARGET=$(CUR_TARGET).elf
UPL_TARGET=project1_demo.elf
TESTTARGET=../unit_tests/unittests.out

#folder paths to create .o files in seperate folder 
#and not clutter the src folder
BINPATH=bin
OFILEPATH=obj
DEPFILES=dependencies
TESTSRCPATH=../unit_tests
TESTOBJPATH=../unit_tests/obj

#creating list of objects to be built based on source file
# these have been splitup to prevent errors from 2 main() s when 
# test code and build code are built together

#common objects to be built for test and final build
COMMONOBJECTS:=$(addprefix $(OFILEPATH)/,$(COMMONSOURCES:%.c=%.o))

#objects for build
OBJECTS:=$(addprefix $(OFILEPATH)/,$(MAINSOURCE:%.c=%.o)) $(COMMONOBJECTS)

#objects for test
TESTOBJECTS:=$(addprefix $(TESTOBJPATH)/,$(TESTSOURCES:%.c=%.o)) $(COMMONOBJECTS)

#list of dependencies
DEPS:=$(addprefix $(OFILEPATH),$(OBJECTS:.o=.d))

-include $(DEPS)

#************* build rules ********************

#script to run unit tests
unittests:$(TESTOBJECTS) 
	mkdir $(TESTOBJPATH) -p
	$(CC) $(TESTOBJECTS) -I$(INCLUDES) $(CFLAGS) -o $(TESTTARGET) $(PS) $(TESTINCLUDE)
	./$(TESTTARGET)

#script to build the executable from all source files	
build:$(OBJECTS)
	mkdir $(OFILEPATH) -p
	$(CC) $(OBJECTS) -I$(INCLUDES) $(CFLAGS) $(LDFLAGS) -o $(TARGET) -D$(DS) $(PS) -Xlinker -Map=$(OFILEPATH)/$(CUR_TARGET).map
#	@echo "\n******Built" $(TARGET)"******\n"
	$(SIZETOOL) $(OBJECTS) $(TARGET)
	./$(TARGET)

#building the executable for beaglebone black 
#and transfer it directly to the board using scp
upload:$(OBJECTS)
	$(CCBBB) $(OBJECTS) -I$(INCLUDES) $(CFLAGS) $(LDFLAGS) -o $(TARGET) -D$(DS) $(PS) -Xlinker -Map=$(OFILEPATH)/$(CUR_TARGET).map
#	@echo "\n******Built" $(TARGET)"******\n"
	$(SIZETOOLBBB) $(OBJECTS) $(TARGET)
	scp $(TARGET) root@192.168.7.2:$(BBBPATH)$(TARGET)

#script to just compile all	source files and not link
compile-all:$(OBJECTS)
	
$(OFILEPATH)/%.d : %.c
	mkdir $(OFILEPATH) -p
	$(CC) -MM $< -MF $@ -I$(INCLUDES) $(CFLAGS) $(CPPFLAGS) -D$(DS) $(LDFLAGS) $(PS)

%.i : %.c
	$(CC) $(CPPFLAGS) $< -o $@ -I$(INCLUDES) $(CFLAGS) $(LDFLAGS) -D$(DS) $(PS)
	
%.asm : %.c
	$(CC) -S $< -o $@ -I$(INCLUDES) $(CFLAGS) $(LDFLAGS) -D$(DS) $(PS)

$(OFILEPATH)/%.s : %.s
	mkdir $(OFILEPATH) -p
	cp $< $@
#	$(CC) -MMD -c $< -o $@ -I$(INCLUDES) $(CFLAGS) -D$(DS) $(LDFLAGS) $(PS)

#script to compile build C files
$(OFILEPATH)/%.o : %.c
	mkdir $(OFILEPATH) -p
#	$(CC) -MM $< -MF $(OFILEPATH)/$*.dep -I $(INCLUDES) $(CFLAGS) $(PS)
	$(CC) -MMD -c $< -o $@ -I$(INCLUDES) $(CFLAGS) -D$(DS) $(LDFLAGS) $(PS)
#	@echo "\n******Built" $@"******"	

#script to compile test C files	
$(TESTOBJPATH)/%.o	: $(TESTSRCPATH)/%.c
	mkdir $(TESTOBJPATH) -p
	$(CC) -MMD -c $< -o $@ -I$(INCLUDES) $(CFLAGS) $(PS) 
#	@echo "\n******Built" $@"******"

#script to delete objects created by build script
clean:
	rm -f $(TOREMOVE)
