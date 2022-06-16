.PHONY: config all clean

DIRSTRUCT := obj bin

all: bin/assembler bin/emulator 

bin/emulator: obj/functions.o obj/emulator.o 
	gcc obj/functions.o obj/emulator.o -o emulator
	@mv emulator bin

bin/assembler: obj/functions.o obj/assembler.o 
	gcc obj/functions.o obj/assembler.o -o assembler
	@mv assembler bin

obj/functions.o: include/functions.h src/functions.c | $(DIRSTRUCT)
	gcc -g -Wall -c -I include src/functions.c
	@mv *.o obj

obj/emulator.o: src/emulator.c include/functions.h | $(DIRSTRUCT)
	gcc -g -Wall -c -I include src/emulator.c
	@mv *.o obj

obj/assembler.o: src/assembler.c include/functions.h | $(DIRSTRUCT)
	gcc -g -Wall -c -I include src/assembler.c
	@mv *.o obj

$(DIRSTRUCT):
	mkdir $(DIRSTRUCT)

clean:   
	rm obj/* bin/*