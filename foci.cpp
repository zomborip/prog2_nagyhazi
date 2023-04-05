#include "csapat.h"
#include "foci.h"
#include "memtrace.h"

Foci::Foci() : Csapat(0), edzoDB(0) {
  setTipus(FOCI);
}

Foci::Foci(const char *p = "", const int n = 0) : 
  Csapat(p, n), edzoDB(0) {
  setTipus(FOCI);
}

void Foci::addEdzo() {edzoDB++;}

void Foci::addEdzo(const int n) {edzoDB = n;}

const int Foci::getEdzokszama() const {return edzoDB;}

