########################################################################
# CPT220 - Programming in C
# Study Period 4 2015 Assignment #3
# Full Name        : Rohan Moon Richards 
# Student Number   : s330153
# Start up code provided by Paul Miller
########################################################################
CC=gcc
CFLAGS=-ansi -Wall -pedantic -g
SOURCES=checker.c list.c options.c menu.c utility.c
HEADERS=checker.h list.h options.h menu.h utility.h shared.h
OBJECTS=checker.o list.o options.o menu.o utility.o
README=readme.txt
MAKEFILE=Makefile

all:check

check:$(OBJECTS)
	$(CC) $(OBJECTS) -o check

%.0:%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

archive:$(USER)-a3.zip
$(USER).zip:
	zip $@ $(SOURCES) $(HEADERS) $(README) $(MAKEFILE)

