FILENAME = Stepper
PORT = /dev/cu.usbmodem1101
DEVICE = atmega328p
PROGRAMMER = arduino
BAUD = 115200
AVRDUDE_CONF = /Users/andrewcaravaggio/Library/Arduino15/packages/arduino/tools/avrdude/6.3.0-arduino17/etc/avrdude.conf
COMPILE = avr-gcc -Wall -Os -DF_CPU=16000000UL -mmcu=$(DEVICE)


default: compile upload clean serial

compile:
	$(COMPILE) -c $(FILENAME).c -o $(FILENAME).o
	$(COMPILE) -o $(FILENAME).elf $(FILENAME).o
	avr-objcopy -j .text -j .data -O ihex $(FILENAME).elf $(FILENAME).hex 
	avr-size --format=avr --mcu=$(DEVICE) $(FILENAME).elf

upload:
	avrdude -v -p $(DEVICE) -c $(PROGRAMMER) -P $(PORT)  -C $(AVRDUDE_CONF) -b $(BAUD) -U flash:w:$(FILENAME).hex:i

clean:
	rm $(FILENAME).o
	rm $(FILENAME).elf
	rm $(FILENAME).hex



