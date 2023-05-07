#============================================================================
# 	Makefile a Nagyházihoz (a féléves makefileokból lemásolva)
#
#		két opció:
#			$ make VAGY make main
#				->ez a sima make all -t hívja meg memtrace használatával
#			
#			$ make clean VAGY make del 
#				-> ez kitakarítja a .o és a nagyhazi.exe file-t a mappából
#					hogy csak a forráskódok maradjanak (WIN alatt del, UNIX
#					alatt clean működik jól.)
#																			
#=============================================================================

# fordito
CXX = g++

# MEMTRACE-hez:
CXXFLAGS = -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE

# fileok
OBJS = main.o memtrace.o csapat.o foci.o kosar.o kezi.o nyilvantartas.o menu.o

# program neve
PROGNAME = nagyhazi

# Ez a default cel
.PHONY: all
all: main

# memtracéval
main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o ${PROGNAME}

del:
	del ${OBJS}
	del ${PROGNAME}.exe

clean:
	rm -f ${OBJS}
	rm -f ${PROGNAME}
