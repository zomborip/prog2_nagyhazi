#============================================================================
# 	Makefile a Nagyházihoz (a féléves makefileokból lemásolva)
#
#		három opció:
#			$ make
#				->ez a sima make all -t hívja meg memtrace használatával
#					(a program normális lefordítása, használható program)
#
#			$ make cmd=-DG_TEST
#				->ez a gtest_lite használatával fordítja le a programot
#					(tesztesetek hívódnak meg, a program nem lesz használhatós) 
#			
#			$ make clean	(VAGY make del VAGY make clear)
#				-> ez kitakarítja a .o és a nagyhazi.exe file-t a mappából
#					hogy csak a forráskódok maradjanak (WIN alatt del, UNIX
#					alatt clean, clear működik jól.)
#																			
#=============================================================================

# fordito
CXX = g++

# MEMTRACE-hez:
CXXFLAGS = -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE
CXXFLAGS += $(cmd)

# fileok
OBJS = main.o main_test.o memtrace.o csapat.o foci.o kosar.o kezi.o nyilvantartas.o menu.o

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

clear:
	rm -f ${OBJS}
	rm -f ${PROGNAME}
