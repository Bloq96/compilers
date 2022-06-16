.PHONY: config compile link run clean

all: compile link

config:
	mkdir obj bin

clean:   
	rm obj/* bin/*

compile:
	gcc -g -Wall -c -Iinclude lib/*
	mv *.o obj

link:
