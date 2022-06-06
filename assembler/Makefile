.PHONY: config compile link clean

all: compile link

config:
	mkdir obj bin

clean:   
	rm obj/* bin/*

compile:
	gcc -g -Wall -c -Iinclude src/*
	mv *.o obj

link:
	gcc obj/functions.o obj/emulator.o -o emulator
	gcc obj/functions.o obj/assembler.o -o assembler
	mv emulator assembler bin
