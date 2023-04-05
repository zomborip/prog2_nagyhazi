#include <cstring>
#include <cmath>
#include <fstream>
#include "csapat.h"
#include "kezi.h"
#include "kosar.h"
#include "foci.h"
#include "nyilvantartas.h"
#include "memtrace.h"

using std::fstream;
using std::ios;
using std::getline;


Nyilvantartas::~Nyilvantartas(){
  delKezi();
  delKosar();
  delFoci();
}

KeziListaElem *Nyilvantartas::ujKezi() {
  // ha üres a lista
  if (keziCS == nullptr) {
    keziCS = new KeziListaElem[1];
    keziCS->kovi = nullptr;
    return keziCS;
  } /*egyébként ha nem üres a lista*/ else {
    KeziListaElem *i; for (i=keziCS;i->kovi!=nullptr;i=i->kovi){}
    i->kovi = new KeziListaElem[1];
    i->kovi->kovi = nullptr;
    return i->kovi;
  }
}

void Nyilvantartas::addKezi(const char* csnev, const int letszam, const int tamogatas){
  KeziListaElem *editable = ujKezi();
  editable->adat.setNev(csnev);
  editable->adat.setLetszam(letszam);
  editable->adat.addTamogatas(tamogatas);
}

KosarListaElem *Nyilvantartas::ujKosar() {
  // ha üres a lista
  if (kosarCS == nullptr) {
    kosarCS = new KosarListaElem[1];
    kosarCS->kovi = nullptr;
    return kosarCS;
  } /*egyébként ha nem üres a lista*/ else {
    KosarListaElem *i; for (i=kosarCS;i->kovi!=nullptr;i=i->kovi){}
    i->kovi = new KosarListaElem[1];
    i->kovi->kovi = nullptr;
    return i->kovi;
  }
}

void Nyilvantartas::addKosar(const char* csnev, const int letszam, const int pompomn){
  KosarListaElem *editable = ujKosar();
  editable->adat.setNev(csnev);
  editable->adat.setLetszam(letszam);
  editable->adat.addPompom(pompomn);
}

FociListaElem *Nyilvantartas::ujFoci() {
  // ha üres a lista
  if (fociCS == nullptr) {
    fociCS = new FociListaElem[1];
    fociCS->kovi = nullptr;
    return fociCS;
  } /*egyébként ha nem üres a lista*/ else {
    FociListaElem *i; for (i=fociCS;i->kovi!=nullptr;i=i->kovi){}
    i->kovi = new FociListaElem[1];
    i->kovi->kovi = nullptr;
    return i->kovi;
  }
}

void Nyilvantartas::addFoci(const char* csnev, const int letszam, const int edzok){
  FociListaElem *editable = ujFoci();
  editable->adat.setNev(csnev);
  editable->adat.setLetszam(letszam);
  editable->adat.addEdzo(edzok);
}

void Nyilvantartas::add(const Tipus T, const char* csnev, const int letszam, const int vari){
  if (T == KEZI) { addKezi(csnev, letszam, vari); }
  else if (T == KOSAR) { addKosar(csnev, letszam, vari); }
  else if (T == FOCI)  { addFoci(csnev, letszam, vari); }
}

KeziListaElem   *Nyilvantartas::findKezi(const char *csapatnev) const {
  if (keziCS != nullptr) {
    KeziListaElem *i;
    for (i=keziCS; i != nullptr; i = i->kovi){
      if (i->adat == csapatnev) {
        return i;
      }
    }
    return nullptr;
  } else {
    return nullptr;
  }
}

KosarListaElem  *Nyilvantartas::findKosar(const char *csapatnev) const {
  if (kosarCS != nullptr) {
    KosarListaElem *i;
    for (i=kosarCS; i != nullptr; i = i->kovi){
      if (i->adat == csapatnev) {
        return i;
      }
    }
    return nullptr;
  } else {
    return nullptr;
  }
}

FociListaElem   *Nyilvantartas::findFoci(const char *csapatnev) const {
  if (fociCS != nullptr) {
    FociListaElem *i;
    for (i=fociCS; i != nullptr; i = i->kovi){
      if (i->adat == csapatnev) {
        return i;
      }
    }
    return nullptr;
  } else {
    return nullptr;
  }
}

void Nyilvantartas::rm(KeziListaElem *& torlendo) {
  if (torlendo == nullptr) {return;}
  // ha az elejerol kell 
  if (torlendo == keziCS) {
    KeziListaElem *ujeleje = keziCS->kovi;
    delete[] torlendo;
    keziCS = ujeleje;
  } else /* Ha a kozeperol v a vegerol torlunk */ {
    KeziListaElem *i; for (i = keziCS; i->kovi != torlendo; i = i->kovi) {}
    i->kovi = i->kovi->kovi;
    delete[] torlendo;
  }
}

void Nyilvantartas::rm(KosarListaElem *& torlendo) {
  if (torlendo == nullptr) {return;}
  // ha az elejerol kell 
  if (torlendo == kosarCS) {
    KosarListaElem *ujeleje = kosarCS->kovi;
    delete[] torlendo;
    kosarCS = ujeleje;
  } else /* Ha a kozeperol v a vegerol torlunk */ {
    KosarListaElem *i; for (i = kosarCS; i->kovi != torlendo; i = i->kovi) {}
    i->kovi = i->kovi->kovi;
    delete[] torlendo;
  }
}

void Nyilvantartas::rm(FociListaElem *& torlendo) {
  if (torlendo == nullptr) {return;}
  // ha az elejerol kell 
  if (torlendo == fociCS) {
    FociListaElem *ujeleje = fociCS->kovi;
    delete[] torlendo;
    fociCS = ujeleje;
  } else /* Ha a kozeperol v a vegerol torlunk */ {
    FociListaElem *i; for (i = fociCS; i->kovi != torlendo; i = i->kovi) {}
    i->kovi = i->kovi->kovi;
    delete[] torlendo;
  }
}

KeziListaElem   *Nyilvantartas::getKeziLista() const {return keziCS;}

KosarListaElem  *Nyilvantartas::getKosarLista() const {return kosarCS;}

FociListaElem   *Nyilvantartas::getFociLista() const {return fociCS;}

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
  for (KeziListaElem *i = keziCS; i != nullptr; i = i->kovi) {
    f << i->adat.getNev() << "\t" << i->adat.getLetszam() << 
    "\t" << i->adat.getTamogatas() << "\n";
  }
  f.close();
}

void Nyilvantartas::saveKosar() const {
  fstream f;
  f.open("kosar.txt", ios::out);
  if (!f.is_open()) {return;}
  for (KosarListaElem *i = kosarCS; i != nullptr; i = i->kovi) {
    f << i->adat.getNev() << "\t" << i->adat.getLetszam() << 
    "\t" << i->adat.getPomPomDb() << "\n";
  }
  f.close();
}

void Nyilvantartas::saveFoci() const {
  fstream f;
  f.open("foci.txt", ios::out);
  if (!f.is_open()) {return;}
  for (FociListaElem *i = fociCS; i != nullptr; i = i->kovi) {
    f << i->adat.getNev() << "\t" << i->adat.getLetszam() << 
    "\t" << i->adat.getEdzokszama() << "\n";
  }
  f.close();
}

void Nyilvantartas::save() const {
  saveKezi();
  saveKosar();
  saveFoci();
}
