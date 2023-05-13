/// @file A Csapat class fuggvenyeinek az implementaciojat tartalmazo file.

#include <cstring>
#include "csapat.h"
#include "memtrace.h"

Csapat::Csapat(const char* p, int n) : letszam(n), tipus(NINCS) {
  nev = new char[strlen(p)+1];
  strcpy(nev, p);
}

Csapat::Csapat(const char* p) : letszam(0), tipus(NINCS) {
  nev = new char[strlen(p)+1];
  strcpy(nev, p);
}

Csapat::Csapat(int n) : nev(nullptr), letszam(n), tipus(NINCS) {}

void Csapat::setLetszam(int n) {
  letszam = n;
}

void Csapat::setNev(const char* p) {
  delNev();
  nev = new char[strlen(p)+1];
  strcpy(nev, p);
}

void Csapat::setTipus(const Tipus t) {
  tipus = t;
}

Tipus Csapat::getTipus() const {
  return tipus;
}

int Csapat::getLetszam() const {
  return letszam;
}

const char *Csapat::getNev() const {
  return nev;
}

bool Csapat::operator==(const char *str){
  return (strcmp(nev, str) == 0) ? true : false;
}

Csapat::~Csapat(){
  delNev();
}
