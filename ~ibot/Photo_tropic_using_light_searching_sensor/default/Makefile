###############################################################################
# Makefile for the project Photo_tropic_using_light_searching_sensor
###############################################################################

## General Flags
PROJECT = Photo_tropic_using_light_searching_sensor
MCU = atmega8
TARGET = Photo_tropic_using_light_searching_sensor.elf
CC = avr-gcc.exe

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -Os -std=gnu99 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=Photo_tropic_using_light_searching_sensor.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Objects that must be built in order to link
OBJECTS = Photo_tropic_using_light_searching_sensor.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) Photo_tropic_using_light_searching_sensor.hex Photo_tropic_using_light_searching_sensor.eep Photo_tropic_using_light_searching_sensor.lss size

## Compile
Photo_tropic_using_light_searching_sensor.o: ../Photo_tropic_using_light_searching_sensor.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) Photo_tropic_using_light_searching_sensor.elf dep/* Photo_tropic_using_light_searching_sensor.hex Photo_tropic_using_light_searching_sensor.eep Photo_tropic_using_light_searching_sensor.lss Photo_tropic_using_light_searching_sensor.map


## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)

