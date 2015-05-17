# Makefile for Hello


hello: bin main.o hello.o
	gcc -o bin/hello bin/main.o bin/hello.o

bin: 
	mkdir bin

main.o: main.c
	gcc -c main.c -o bin/main.o

hello.o: hello.c
	gcc -c hello.c	-o bin/hello.o

clear: 
	rm -f bin/*.o bin/hello
