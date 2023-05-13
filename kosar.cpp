/// @file A Kosar class fuggvenyeinek az implementaciojat tartalmazo file.

#include "csapat.h"
#include "kosar.h"
#include "memtrace.h"


Kosar::Kosar() : Csapat(0), pompomDB(0) {
  setTipus(KOSAR);
}

Kosar::Kosar(const char* p = "", const int n = 0) :
  Csapat(p, n), pompomDB(0) {
  setTipus(KOSAR);
}

void Kosar::addPompom(const int n) {pompomDB = n;}

const int Kosar::getPomPomDb() const {return pompomDB;}
