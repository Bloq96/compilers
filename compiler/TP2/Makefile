.PHONY: all clean config

all: bin/a.out

clean:
	rm obj/* bin/*

config:
	mkdir obj bin

src/lex.yy.c: lex/cool.flex
	lex lex/cool.flex
	mv lex.yy.c src

obj/extra.o: src/extra.c
	gcc -g -Wall -c src/extra.c
	mv extra.o obj

obj/lex.yy.o: include/cool-parse.h include/stringtab.h include/utilities.h src/lex.yy.c
	gcc -g -Wall -c -Iinclude src/lex.yy.c
	mv lex.yy.o obj

obj/main.o: src/main.c
	gcc -g -Wall -c src/main.c
	mv main.o obj

bin/a.out: obj/extra.o obj/lex.yy.o obj/main.o
	gcc obj/extra.o obj/lex.yy.o obj/main.o -o a.out
	mv a.out bin
