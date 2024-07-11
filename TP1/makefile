CC = gcc
CFLAGS = -g -Wall -c -pedantic-errors -std=c2x

# Objetivos phony
.PHONY: clean run

prog: main.o conversion.o tabla.o
	$(CC) main.o conversion.o tabla.o -o prog

main.o: main.c tabla.h
	$(CC) $(CFLAGS) main.c -o main.o

tabla.o: tabla.c tabla.h conversion.h
	$(CC) $(CFLAGS) tabla.c -o tabla.o

conversion.o: conversion.c conversion.h
	$(CC) $(CFLAGS) conversion.c -o conversion.o

clean:
	rm -f main.o tabla.o conversion.o prog

run: prog
	./prog