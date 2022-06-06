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
	mv emulator bin
