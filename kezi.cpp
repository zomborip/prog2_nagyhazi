/// @file A Kezi class fuggvenyeinek az implementaciojat tartalmazo file.

#include "csapat.h"
#include "kezi.h"
#include "memtrace.h"

Kezi::Kezi() : Csapat(0), tamogatas(0) {
  setTipus(KEZI);
}

Kezi::Kezi(const char* p, const int n) : 
  Csapat(p, n), tamogatas(0) {
  setTipus(KEZI);
}

void Kezi::addTamogatas(const int t) {
  tamogatas += t;
}

const int Kezi::getTamogatas() const {
  return tamogatas;
}
