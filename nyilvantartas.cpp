/// @file A Nyilvantartas class fuggvenyeinek az implementaciojat tartalmazo file... A teljes API implementacioja

#include <cstring>
#include <cmath>
#include <fstream>
#include "nyilvantartas.h"
#include "csapat.h"
#include "kezi.h"
#include "kosar.h"
#include "foci.h"
#include "memtrace.h"

using std::fstream;
using std::ios;
using std::getline;


Nyilvantartas::~Nyilvantartas(){
 delAll();
}

Lista *Nyilvantartas::uj(Tipus t) {
  // ha üres a lista
  if (csapatok == nullptr) {
    switch (t)
    {
    case NINCS:
      return nullptr;
      break;
    
    case FOCI:
      csapatok = new Lista;
      csapatok->adat = new Foci;
      break;

    case KOSAR:
      csapatok = new Lista;
      csapatok->adat = new Kosar;
      break;
    
    case KEZI:
      csapatok = new Lista;
      csapatok->adat = new Kezi;
      break;
    }
    csapatok->kovi = nullptr;
    return csapatok;
  } /*egyébként ha nem üres a lista*/ else {
    Lista *i; for (i=csapatok;i->kovi!=nullptr;i=i->kovi){}
    i->kovi = new Lista;

    switch (t)
    {
    case NINCS:
      return nullptr;
      break;
    
    case FOCI:
      i->kovi->adat = new Foci;
      break;

    case KOSAR:
      i->kovi->adat = new Kosar;
      break;
    
    case KEZI:
      i->kovi->adat = new Kezi;
      break;
    }

    i->kovi->kovi = nullptr;
    return i->kovi;
  }
}

void Nyilvantartas::addKezi(const char* csnev, const int letszam, const int tamogatas){
  Lista *editable = uj(KEZI);
  editable->adat->setNev(csnev);
  editable->adat->setLetszam(letszam);
  editable->adat->addTamogatas(tamogatas);
}

void Nyilvantartas::addKosar(const char* csnev, const int letszam, const int pompomn){
  Lista *editable = uj(KOSAR);
  editable->adat->setNev(csnev);
  editable->adat->setLetszam(letszam);
  editable->adat->addPompom(pompomn);
}

void Nyilvantartas::addFoci(const char* csnev, const int letszam, const int edzok){
  Lista *editable = uj(FOCI);
  editable->adat->setNev(csnev);
  editable->adat->setLetszam(letszam);
  editable->adat->addEdzo(edzok);
}

void Nyilvantartas::add(const Tipus T, const char* csnev, const int letszam, const int vari){
  if (T == KEZI) { addKezi(csnev, letszam, vari); }
  else if (T == KOSAR) { addKosar(csnev, letszam, vari); }
  else if (T == FOCI)  { addFoci(csnev, letszam, vari); }
}

Lista   *Nyilvantartas::find(const char *csapatnev) const {
  if (csapatok != nullptr) {
    Lista *i;
    for (i=csapatok; i != nullptr; i = i->kovi){
      if (*(i->adat) == csapatnev) {
        return i;
      }
    }
    return nullptr;
  } else {
    return nullptr;
  }
}

void Nyilvantartas::rm(Lista *& torlendo) {
  if (torlendo == nullptr) {return;}
  // ha az elejerol kell 
  if (torlendo == csapatok) {
    Lista *ujeleje = csapatok->kovi;
    if (torlendo->adat != nullptr)
      delete torlendo->adat;
    delete torlendo;
    csapatok = ujeleje;
  } else /* Ha a kozeperol v a vegerol torlunk */ {
    Lista *i; for (i = csapatok; i->kovi != torlendo; i = i->kovi) {}
    i->kovi = i->kovi->kovi;
    if (torlendo->adat != nullptr)
      delete torlendo->adat;
    delete torlendo;
  }
}

Lista   *Nyilvantartas::getLista() const {return csapatok;}

bool Nyilvantartas::loadKezi() {
  // File leírás:
  // Csapatnév [TABULÁTO] Csapatlétszám [TABULÁTOR] Támogatás

  fstream f;
  f.open("kezi.txt", ios::in);
  if (f.is_open()) {
    char c;
    char *csNevSTR = nullptr;
    char *letszamSTR = nullptr;
    char *variszamSTR = nullptr;
    int tabulatorCount = 0;
    int letszam = 0;
    int variszam = 0;

    // A filet végignyálazza betűnként.
    while (f.get(c) && c != EOF) {
      //Ha sor vége van, új lista láncolása logika és reset.
      if (c == '\n') {
        tabulatorCount = 0;
        sscanf(letszamSTR, "%d", &letszam);
        sscanf(variszamSTR, "%d", &variszam);
        add(KEZI, csNevSTR, letszam, variszam);
        strdel(csNevSTR); strdel(letszamSTR); strdel(variszamSTR);

      } else if (c == '\t') {tabulatorCount++;} // ha tab, más adadtba pakolunk bele betűket.
      else {
        // a megfelelő adatba a betűk belepakolása.
        if (tabulatorCount==0) {straddc(csNevSTR, c);}
        else if (tabulatorCount==1) {straddc(letszamSTR, c);}
        else if (tabulatorCount==2) {straddc(variszamSTR, c);}
      }
    }
    #ifdef ROSSZAVEGE
    //az eof után az utsó sor még nincs lerendezve
    sscanf(letszamSTR, "%d", &letszam);
    sscanf(variszamSTR, "%d", &variszam);
    add(KEZI, csNevSTR, letszam, variszam);
    strdel(csNevSTR); strdel(letszamSTR); strdel(variszamSTR);
    #endif
    f.close();
    return true;
  } else {
    return false;
  }
}

bool Nyilvantartas::loadKosar() {
  /// File leírás:
  // Csapatnév [TABULÁTO] Csapatlétszám [TABULÁTOR] Pompomlányokszáma

  fstream f;
  f.open("kosar.txt", ios::in);
  if (f.is_open()) {
    char c;
    char *csNevSTR = nullptr;
    char *letszamSTR = nullptr;
    char *variszamSTR = nullptr;
    int tabulatorCount = 0;
    int letszam = 0;
    int variszam = 0;

    // A filet végignyálazza betűnként.
    while (f.get(c) && c != EOF) {
      //Ha sor vége van, új lista láncolása logika és reset.
      if (c == '\n') {
        tabulatorCount = 0;
        sscanf(letszamSTR, "%d", &letszam);
        sscanf(variszamSTR, "%d", &variszam);
        add(KOSAR, csNevSTR, letszam, variszam);
        strdel(csNevSTR); strdel(letszamSTR); strdel(variszamSTR);

      } else if (c == '\t') {tabulatorCount++;} // ha tab, más adadtba pakolunk bele betűket.
      else {
        // a megfelelő adatba a betűk belepakolása.
        if (tabulatorCount==0) {straddc(csNevSTR, c);}
        else if (tabulatorCount==1) {straddc(letszamSTR, c);}
        else if (tabulatorCount==2) {straddc(variszamSTR, c);}
      }
    }
    #ifdef ROSSZAVEGE
    //az eof után az utsó sor még nincs lerendezve
    sscanf(letszamSTR, "%d", &letszam);
    sscanf(variszamSTR, "%d", &variszam);
    add(KOSAR, csNevSTR, letszam, variszam);
    strdel(csNevSTR); strdel(letszamSTR); strdel(variszamSTR);
    #endif
    f.close();
    return true;
  } else {
    return false;
  }
}

bool Nyilvantartas::loadFoci() {
  // File leírás:
  // Csapatnév [TABULÁTO] Csapatlétszám [TABULÁTOR] Edzokszama

  fstream f;
  f.open("foci.txt", ios::in);
  if (f.is_open()) {
    char c;
    char *csNevSTR = nullptr;
    char *letszamSTR = nullptr;
    char *variszamSTR = nullptr;
    int tabulatorCount = 0;
    int letszam = 0;
    int variszam = 0;

    // A filet végignyálazza betűnként.
    while (f.get(c) && c != EOF) {
      //Ha sor vége van, új lista láncolása logika és reset.
      if (c == '\n') {
        tabulatorCount = 0;
        sscanf(letszamSTR, "%d", &letszam);
        sscanf(variszamSTR, "%d", &variszam);
        add(FOCI, csNevSTR, letszam, variszam);
        strdel(csNevSTR); strdel(letszamSTR); strdel(variszamSTR);

      } else if (c == '\t') {tabulatorCount++;} // ha tab, más adadtba pakolunk bele betűket.
      else {
        // a megfelelő adatba a betűk belepakolása.
        if (tabulatorCount==0) {straddc(csNevSTR, c);}
        else if (tabulatorCount==1) {straddc(letszamSTR, c);}
        else if (tabulatorCount==2) {straddc(variszamSTR, c);}
      }
    }
    #ifdef ROSSZAVEGE
    //az eof után az utsó sor még nincs lerendezve
    sscanf(letszamSTR, "%d", &letszam);
    sscanf(variszamSTR, "%d", &variszam);
    add(FOCI, csNevSTR, letszam, variszam);
    strdel(csNevSTR); strdel(letszamSTR); strdel(variszamSTR);
    #endif
    f.close();
    return true;
  } else {
    return false;
  }
}

bool Nyilvantartas::load() {
  if (!loadKezi())  {return false;}
  if (!loadKosar()) {return false;}
  if (!loadFoci())  {return false;}
  return true;
}

int Nyilvantartas::intlen(const long long int szam) {
  for (int i = 0; i <= 64; i++) {
    if (szam % (long long int) pow(10, i) == szam) {
      return i==0 ? 1 : i;
    }
  }
  return 0;
}

void Nyilvantartas::straddc(char *&str, const char c){
  if (str == nullptr) {
    str = new char[2];
    str[0] = c;
    str[1] = '\0';
  } else {
    int l = strlen(str);
    char *temp = new char[l+1];
    strcpy(temp, str);
    delete[] str;
    str = new char[l+2];
    strcpy(str, temp);
    str[l] = c; str[l+1] = '\0';
    delete[] temp;
  }
}

void Nyilvantartas::strdel(char *&str){
  if (str == nullptr) {return;}
  delete[] str; str = nullptr;
}

void Nyilvantartas::saveKezi() const {
  fstream f;
  f.open("kezi.txt", ios::out);
  if (!f.is_open()) {return;}
  for (Lista *i = csapatok; i != nullptr; i = i->kovi) {
    if (i->adat->getTipus() == KEZI) {
      f << i->adat->getNev() << "\t" << i->adat->getLetszam() << 
      "\t" << i->adat->getTamogatas() << "\n";
    }
  }
  f.close();
}

void Nyilvantartas::saveKosar() const {
  fstream f;
  f.open("kosar.txt", ios::out);
  if (!f.is_open()) {return;}
  for (Lista *i = csapatok; i != nullptr; i = i->kovi) {
    if (i->adat->getTipus() == KOSAR) {  
      f << i->adat->getNev() << "\t" << i->adat->getLetszam() << 
      "\t" << i->adat->getPomPomDb() << "\n";
    }
  }
  f.close();
}

void Nyilvantartas::saveFoci() const {
  fstream f;
  f.open("foci.txt", ios::out);
  if (!f.is_open()) {return;}
  for (Lista *i = csapatok; i != nullptr; i = i->kovi) {
    if (i->adat->getTipus() == FOCI) {
      f << i->adat->getNev() << "\t" << i->adat->getLetszam() << 
      "\t" << i->adat->getEdzokszama() << "\n";
    }
  }
  f.close();
}

void Nyilvantartas::save() const {
  saveKezi();
  saveKosar();
  saveFoci();
}
