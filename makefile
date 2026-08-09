COMPILER = avr-gcc
MMCU = atmega328p
PLATFORM = arduino
NOLINK = -c

START_LOCATION = main.c
END_LOCATION = devbin
FILENAME = sample

SRC = lcd1602

PORT = COM4
BAUD = 115200

ALL: BUILD LINKER INTELHEX FLASH

BUILD:
	$(COMPILER) -g -Os -mmcu=$(MMCU) $(NOLINK) testing/$(START_LOCATION) -o $(END_LOCATION)/$(FILENAME).o
	$(COMPILER) -g -Os -mmcu=$(MMCU) $(NOLINK) LCD1602/$(SRC).c -o  $(END_LOCATION)/$(SRC).o

LINKER: 
	$(COMPILER) -g -mmcu=$(MMCU) -mrelax \
	 $(END_LOCATION)/$(FILENAME).o $(END_LOCATION)/$(SRC).o \
	-o $(END_LOCATION)/$(FILENAME).elf 

INTELHEX:
	avr-objcopy -j .text -j .data -O ihex $(END_LOCATION)/$(FILENAME).elf $(END_LOCATION)/$(FILENAME).hex

FLASH:
	avrdude -p $(MMCU) -c $(PLATFORM) -P $(PORT) -b $(BAUD) -U flash:w:$(END_LOCATION)/$(FILENAME).hex:i
