# Simple makefile for Part II Computational Physics
CAV_ROOT=/ux/PHYSICS/PART_2
CPPFLAGS=-I$(CAV_ROOT)
LDFLAGS=
LDLIBS=$(CAV_ROOT)/cavlib/cavlib.a -lgsl -lgslcblas -lfftw3

# Compiler flags
CC=g++ -g -pedantic -Wall

# Pick up modifications for compiling on mac (if present)
-include ../mac.mk

%.out : %.cpp
	$(CC) $(CPPFLAGS)  $< $(LDFLAGS) $(LDLIBS) -o $@
