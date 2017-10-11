CC=gcc
CSTD=c99
CFLAGS=-Wall\
	-std=$(CSTD)\
	-g\
#	-Werror\
	-O0

include sources.mk
	
CPPFLAGS=-E
LDFLAGS=
PLATFORM=HOST

SIZETOOL=size
	
.PHONY:build clean compile-all upload

DS=VERBOSE
PS=

TOREMOVE=$(OFILEPATH)/*.o\
	bin/*.out\
	$(OFILEPATH)/*.map\
	*.asm\
	*.i\
	$(OFILEPATH)/*.d\
	$(OFILEPATH)/*.dep\
	bin/*.elf

ifeq ($(PLATFORM),BBB)
CC = arm-linux-gnueabihf-gcc
SIZETOOL=arm-linux-gnueabihf-size
else

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

TARGET=$(BINPATH)/project1.elf
UPL_TARGET=project1_demo.elf

BINPATH=bin
OFILEPATH=obj
DEPFILES=dependencies
OBJECTS:=$(addprefix $(OFILEPATH)/,$(SOURCES:%.c=%.o))

DEPS:=$(addprefix $(OFILEPATH),$(SOURCES:.c=.d))

-include $(DEPS)

upload:$(OBJECTS)
	$(CC) $(OBJECTS) -I$(INCLUDES) $(CFLAGS) $(LDFLAGS) -o $(UPL_TARGET) -D$(DS) $(PS) -Xlinker -Map=$(OFILEPATH)/project1.map
#	@echo "\n******Built" $(TARGET)"******\n"
	$(SIZETOOL) $(OBJECTS) $(UPL_TARGET)
	scp $(UPL_TARGET) root@192.168.7.2:/home/code/$(UPL_TARGET)

build:$(OBJECTS)
	mkdir $(BINPATH) -p
	$(CC) $(OBJECTS) -I$(INCLUDES) $(CFLAGS) $(LDFLAGS) -o $(TARGET) -D$(DS) $(PS) -Xlinker -Map=$(OFILEPATH)/project1.map
#	@echo "\n******Built" $(TARGET)"******\n"
#	$(SIZETOOL) $(OBJECTS) $(TARGET)
#	./$(TARGET)

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
	
$(OFILEPATH)/%.o : %.c
	mkdir $(OFILEPATH) -p
#	$(CC) -MM $< -MF $(OFILEPATH)/$*.dep -I $(INCLUDES) $(CFLAGS) $(PS)
	$(CC) -MMD -c $< -o $@ -I$(INCLUDES) $(CFLAGS) -D$(DS) $(LDFLAGS) $(PS)
#	@echo "\n******Built" $@"******"

clean:
	rm -f $(TOREMOVE)
