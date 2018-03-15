# Simple makefile
LDFLAGS=
LDLIBS=-lgsl -lgslcblas -lfftw3

# Compiler flags
CC=g++ -g -pedantic -Wall

# Pick up modifications for compiling on mac (if present)
-include ../mac.mk

%.out : %.cpp
	$(CC)  $< $(LDFLAGS) $(LDLIBS) -o $@
