#============================================================================
# 	Makefile a Nagyházihoz (a féléves makefileokból lemásolva)
#
#		két opció:
#			$ make VAGY make main
#				->ez a sima make all -t hívja meg memtrace használatával
#			
#			$ make clean VAGY make cls
#				-> ez kitakarítja a .o és a nagyhazi.exe file-t a mappából
#					hogy csak a forráskódok maradjanak
#=============================================================================

# fordito
CXX = g++

# MEMTRACE-hez:
CXXFLAGS = -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE

# fileok
OBJS = main.o memtrace.o csapat.o foci.o kosar.o kezi.o nyilvantartas.o menu.o

# Ez a default cel
.PHONY: all
all: main

# memtracéval
main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o nagyhazi

cls: clean

clean:
	rm -f *.o nagyhazi
