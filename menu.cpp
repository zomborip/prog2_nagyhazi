#include <iostream>
#include <cstring>
#include <cmath>
#include "csapat.h"
#include "kezi.h"
#include "kosar.h"
#include "foci.h"
#include "nyilvantartas.h"
#include "menu.h"
#include "memtrace.h"

using std::cout;
using std::cin;
using std::endl;

Menu::Menu(){
  DB.load();
  cout << "[+] Fileok Betoltese..." << endl;
}

Menu::~Menu(){
  DB.save();
  cout << "\n[+] Mentes...\n" << endl;
}

int Menu::maxStdRowLen() const {
  // A leghoszabb sorszám kiszámolása (teljessen folosleges es lassitja a programot, de szep lesz):
  int maxrow = 0;
  for (KeziListaElem* i = DB.getKeziLista(); i != nullptr; i = i->kovi ) {
    int currRow = strlen(i->adat.getNev()) + Nyilvantartas::intlen(i->adat.getLetszam())
      + Nyilvantartas::intlen(i->adat.getTamogatas()) + 4 + 4;
    if (currRow > maxrow) { maxrow = currRow;}
  }

  for (KosarListaElem* i = DB.getKosarLista(); i != nullptr; i = i->kovi ) {
    int currRow = strlen(i->adat.getNev()) + Nyilvantartas::intlen(i->adat.getLetszam())
      + Nyilvantartas::intlen(i->adat.getPomPomDb()) + 4 + 4;
    if (currRow > maxrow) { maxrow = currRow;}
  }

  for (FociListaElem* i = DB.getFociLista(); i != nullptr; i = i->kovi ) {
    int currRow = strlen(i->adat.getNev()) + Nyilvantartas::intlen(i->adat.getLetszam())
      + Nyilvantartas::intlen(i->adat.getEdzokszama()) + 4 + 4;
    if (currRow > maxrow) { maxrow = currRow;}
  }
  return maxrow;
}

int Menu::maxStdRowLen(Tipus t) const {
  // A leghoszabb sorszám kiszámolása (teljessen folosleges es lassitja a programot, de szep lesz):
  int maxrow = 0;
  if (t == KEZI) {
    for (KeziListaElem* i = DB.getKeziLista(); i != nullptr; i = i->kovi ) {
      int currRow = strlen(i->adat.getNev()) + Nyilvantartas::intlen(i->adat.getLetszam())
        + Nyilvantartas::intlen(i->adat.getTamogatas()) + 4 + 4;
      if (currRow > maxrow) { maxrow = currRow;}
    }
  }
  if (t == KOSAR){
    for (KosarListaElem* i = DB.getKosarLista(); i != nullptr; i = i->kovi ) {
      int currRow = strlen(i->adat.getNev()) + Nyilvantartas::intlen(i->adat.getLetszam())
        + Nyilvantartas::intlen(i->adat.getPomPomDb()) + 4 + 4;
      if (currRow > maxrow) { maxrow = currRow;}
    }
  }
  if (t == FOCI) {
    for (FociListaElem* i = DB.getFociLista(); i != nullptr; i = i->kovi ) {
      int currRow = strlen(i->adat.getNev()) + Nyilvantartas::intlen(i->adat.getLetszam())
        + Nyilvantartas::intlen(i->adat.getEdzokszama()) + 4 + 4;
      if (currRow > maxrow) { maxrow = currRow;}
    }
  }
  return maxrow;
}

int Menu::getStdRowLen(KeziListaElem *l) const {
  int n = 0;
  n += strlen(l->adat.getNev());
  n += Nyilvantartas::intlen(l->adat.getLetszam());
  n += Nyilvantartas::intlen(l->adat.getTamogatas());
  return n;
}

int Menu::getStdRowLen(KosarListaElem *l) const {
  int n = 0;
  n += strlen(l->adat.getNev());
  n += Nyilvantartas::intlen(l->adat.getLetszam());
  n += Nyilvantartas::intlen(l->adat.getPomPomDb());
  return n;
}

int Menu::getStdRowLen(FociListaElem *l) const {
  int n = 0;
  n += strlen(l->adat.getNev());
  n += Nyilvantartas::intlen(l->adat.getLetszam());
  n += Nyilvantartas::intlen(l->adat.getEdzokszama());
  return n;
}

void Menu::printAll() const {
  int maxrow = maxStdRowLen();
  if (DB.getKeziLista() == nullptr) {
    cout << "\n\n[+] Ures a kezilabda csapatok listaja\n" << endl;
  } else {
    cout << "\n\n\n[+] Kezilabda Csapatok:" << endl << endl;
    cout << "Nev-Letszam-Tamogatas"<< endl;
    for (int i=0;i<maxrow;i++) {cout << "=";} cout << endl;
    for (KeziListaElem* i = DB.getKeziLista(); i != nullptr; i = i->kovi) {
      int t = abs(maxrow-6 - getStdRowLen(i));
      //cout << "\t\t---" << t << "---" << maxrow << "---" << getStdRowLen(i) << endl;
      cout << i->adat.getNev();
      for (int j=0; j<t; j++) {cout << " " ;}
      cout << i->adat.getLetszam() << "\t" << i->adat.getTamogatas() << endl;
    }
    for (int i=0;i<maxrow;i++) {cout << "=";} cout << endl;
  }

  if (DB.getKosarLista() == nullptr) {
    cout << "\n\n[+] Ures a kosarlabda csapatok listaja\n" << endl;
  } else {
    cout << "\n\n\n[+] Kosarlabda Csapatok:" << endl << endl;
    cout << "Nev-Letszam-PomPomLanyok"<< endl;
    for (int i=0;i<maxrow;i++) {cout << "=";} cout << endl;
    for (KosarListaElem* i = DB.getKosarLista(); i != nullptr; i = i->kovi) {
      int t = abs(maxrow-6 - getStdRowLen(i));;
      //cout << "\t\t---" << t << "---" << maxrow << "---" << getStdRowLen(i) << endl;
      cout << i->adat.getNev();
      for (int j=0; j<t; j++) {cout << " " ;}
      cout << i->adat.getLetszam() << "\t" << i->adat.getPomPomDb() << endl;
    }
    for (int i=0;i<maxrow;i++) {cout << "=";} cout << endl;
  }

  if (DB.getFociLista() == nullptr) {
    cout << "\n\n[+] Ures a focilabda csapatok listaja\n" << endl;
  } else {
    cout << "\n\n\n[+] Focilabda Csapatok:" << endl << endl;
    cout << "Nev-Letszam-Edzok"<< endl;
    for (int i=0;i<maxrow;i++) {cout << "=";} cout << endl;
    for (FociListaElem* i = DB.getFociLista(); i != nullptr; i = i->kovi) {
      int t = abs(maxrow-6 - getStdRowLen(i));;
      //cout << "\t\t---" << t << "---" << maxrow << "---" << getStdRowLen(i) << endl;
      cout << i->adat.getNev();
      for (int j=0; j<t; j++) {cout << " " ;}
      cout << i->adat.getLetszam() << "\t" << i->adat.getEdzokszama() << endl;
    }

    for (int i=0;i<maxrow;i++) {cout << "=";} cout << endl;
  }
}

void Menu::printKezi() const {
  if (DB.getKeziLista() == nullptr) { cout << "\n\n[+]Ures a kezilabda csapatok listaja\n\n" << endl; return; }
  int maxrow = maxStdRowLen(KEZI);
  cout << "\n\n\n\t[+] Kezilabda Csapatok:" << endl << endl;
  cout << "\tNev-Letszam-Tamogatas"<< endl;
  cout<<"\t"; for (int i=0;i<maxrow;i++) {cout << "=";} cout << endl;
  for (KeziListaElem* i = DB.getKeziLista(); i != nullptr; i = i->kovi) {
    int t = abs(maxrow-6 - getStdRowLen(i));
    //cout << "\t\t---" << t << "---" << maxrow << "---" << getStdRowLen(i) << endl;
    cout << "\t" << i->adat.getNev();
    for (int j=0; j<t; j++) {cout << " " ;}
    cout << i->adat.getLetszam() << "\t" << i->adat.getTamogatas() << endl;
  }
  cout<<"\t"; for (int i=0;i<maxrow;i++) {cout << "=";} cout << endl;
}

void Menu::printKosar() const {
  if (DB.getKosarLista() == nullptr) { cout << "\n\n[+]Ures a kosarlabda csapatok listaja\n\n" << endl; return; }
  int maxrow = maxStdRowLen(KOSAR);
  cout << "\n\n\n\t[+] Kosarlabda Csapatok:" << endl << endl;
  cout << "\tNev-Letszam-PomPomLanyok"<< endl;
  cout<<"\t"; for (int i=0;i<maxrow;i++) {cout << "=";} cout << endl;
  for (KosarListaElem* i = DB.getKosarLista(); i != nullptr; i = i->kovi) {
    int t = abs(maxrow-6 - getStdRowLen(i));
    //cout << "\t\t---" << t << "---" << maxrow << "---" << getStdRowLen(i) << endl;
    cout << "\t" << i->adat.getNev();
    for (int j=0; j<t; j++) {cout << " " ;}
    cout << i->adat.getLetszam() << "\t" << i->adat.getPomPomDb() << endl;
  }
  cout<<"\t"; for (int i=0;i<maxrow;i++) {cout << "=";} cout << endl;
}

void Menu::printFoci() const {
  if (DB.getFociLista() == nullptr) { cout << "\n\n[+]Ures a focilabda csapatok listaja\n\n" << endl; return; }
  int maxrow = maxStdRowLen(FOCI);
  cout << "\n\n\n\t[+] Focilabda Csapatok:" << endl << endl;
  cout << "\tNev-Letszam-EdzokSzama"<< endl;
  cout<<"\t"; for (int i=0;i<maxrow;i++) {cout << "=";} cout << endl;
  for (FociListaElem* i = DB.getFociLista(); i != nullptr; i = i->kovi) {
    int t = abs(maxrow-6 - getStdRowLen(i));
    //cout << "\t\t---" << t << "---" << maxrow << "---" << getStdRowLen(i) << endl;
    cout << "\t" << i->adat.getNev();
    for (int j=0; j<t; j++) {cout << " " ;}
    cout << i->adat.getLetszam() << "\t" << i->adat.getEdzokszama() << endl;
  }
  cout<<"\t"; for (int i=0;i<maxrow;i++) {cout << "=";} cout << endl;
}

void Menu::printOne(KeziListaElem *p) const {
  if (p == nullptr) {return;}
  int sorlen = getStdRowLen(p);
  cout << endl << endl;
  cout << "\t\t[+] KERESETT KEZI CSAPAT" << endl;
  cout << "\t\tNev-Letszam-Tamogatas" << endl;
  cout << "\t\t"; for (int i=0; i<sorlen+10;i++){cout << "=";} cout << endl;
  cout << "\t\t" << p->adat.getNev() << "\t" << p->adat.getLetszam() << "\t" 
       << p->adat.getTamogatas() << endl;
  cout << "\t\t"; for (int i=0; i<sorlen+10;i++){cout << "=";} cout << endl << endl;
}

void Menu::printOne(KosarListaElem *p) const {
  if (p == nullptr) {return;}
  int sorlen = getStdRowLen(p);
  cout << endl << endl;
  cout << "\t\t[+] KERESETT KOSAR CSAPAT" << endl;
  cout << "\t\tNev-Letszam-PomPomLanyok" << endl;
  cout << "\t\t"; for (int i=0; i<sorlen+10;i++){cout << "=";} cout << endl;
  cout << "\t\t" << p->adat.getNev() << "\t" << p->adat.getLetszam() << "\t" 
       << p->adat.getPomPomDb() << endl;
  cout << "\t\t"; for (int i=0; i<sorlen+10;i++){cout << "=";} cout << endl << endl;
}

void Menu::printOne(FociListaElem *p) const {
  if (p == nullptr) {return;}
  int sorlen = getStdRowLen(p);
  cout << endl << endl;
  cout << "\t\t[+] KERESETT FOCICSAPAT" << endl;
  cout << "\t\tNev-Letszam-Edzok" << endl;
  cout << "\t\t"; for (int i=0; i<sorlen+10;i++){cout << "=";} cout << endl;
  cout << "\t\t" << p->adat.getNev() << "\t" << p->adat.getLetszam() << "\t" 
       << p->adat.getEdzokszama() << endl;
  cout << "\t\t"; for (int i=0; i<sorlen+10;i++){cout << "=";} cout << endl << endl;
}

void Menu::keziMenu() {
  int arg = -1;
  while (arg != 0) {
    cout << "\n\n\t[+]KEZILABDA CSAPAT MENU" << endl;
    cout << "\t=================================================================================================" << endl;
    cout << "\t| (1): Kezis csapatok listazasa | (2): Csapat Keresese | (3): Uj csapat felvetele | (0): Vissza |" << endl;
    cout << "\t=================================================================================================" << endl;
    cout << "\t[!] Valasszon a listabol. Adja meg a menu szamat!" << endl;
    cout << "\t[?] Menu szama: ";
    cin.sync();
    cin >> arg;
    switch (arg)
    {
    case 1:
      printKezi();
      break;

    case 2:
      keresKeziMenu();
      break;

    case 3:
      ujMenu(KEZI);
      break;

    case 0:
      arg = 0;
      break;
    
    default:
      cout << "\n\t[!] Nem letezo menu..." << endl;
      break;
    }
  }
}

void Menu::kosarMenu() {
  int arg = -1;
  while (arg != 0) {
    cout << "\n\n\t[+]KOSARLABDA CSAPAT MENU" << endl;
    cout << "\t===================================================================================================" << endl;
    cout << "\t| (1): Kosaras csapatok listazasa | (2): Csapat Keresese | (3): Uj csapat felvetele | (0): Vissza |" << endl;
    cout << "\t===================================================================================================" << endl;
    cout << "\t[!] Valasszon a listabol. Adja meg a menu szamat!" << endl;
    cout << "\t[?] Menu szama: ";
    cin.sync();
    cin >> arg;
    switch (arg)
    {
    case 1:
      printKosar();
      break;

    case 2:
      keresKosarMenu();
      break;

    case 3:
      ujMenu(KOSAR);
      break;

    case 0:
      arg = 0;
      break;
    
    default:
      cout << "\n\t[!] Nem letezo menu..." << endl;
      break;
    }
  }
}

void Menu::fociMenu() {
  int arg = -1;
  while (arg != 0) {
    cout << "\n\n\t[+]FOCILABDA CSAPAT MENU" << endl;
    cout << "\t===============================================================================================" << endl;
    cout << "\t| (1): Focicsapatok listazasa | (2): Csapat Keresese | (3): Uj csapat felvetele | (0): Vissza |" << endl;
    cout << "\t===============================================================================================" << endl;
    cout << "\t[!] Valasszon a listabol. Adja meg a menu szamat!" << endl;
    cout << "\t[?] Menu szama: ";
    cin.sync();
    cin >> arg;
    switch (arg)
    {
    case 1:
      printFoci();
      break;

    case 2:
      keresFociMenu();
      break;
    
    case 3:
      ujMenu(FOCI);
      break;

    case 0:
      arg = 0;
      break;
    
    default:
      cout << "\n\t[!] Nem letezo menu..." << endl;
      break;
    }
  }
}

void Menu::keresKeziMenu(){
  char buffer[256] = "";
  cout << "\t[?] Keresett csapat neve: ";
  cin.sync();
  #ifdef __linux__
    cin.ignore(1, '\n');
  #endif
  #ifdef __APPLE__
    cin.ignore(1, '\n');
  #endif
  cin.getline(buffer, 255);
  KeziListaElem *result = DB.findKezi(buffer);
  if (result == nullptr) {
    cout << "[!] Nincs ilyen nevu csapat!" << endl;
    return;
  } else {
    printOne(result);
    int arg = -1;
    int d = 0;
    while (arg != 0) {
      cout << "\t\t[+] CSAPAT KEZELO MENU" << endl;
      cout << "\t\t==============================================================" << endl;
      cout << "\t\t| (1): Csapat modositasa | (2): Csapat torlese | (0): Vissza |" << endl;
      cout << "\t\t==============================================================" << endl;
      cout << "\t\t[!] Valasszon a listabol. Adja meg a menu szamat!" << endl;
      cout << "\t\t[?] Menu szama: ";
      cin.sync();
      cin >> arg;
      switch (arg) {
        case 1:
          editKeziMenu(result);
          return;
          break;
        case 2:
          cout << "\n\t\t[?] Biztosan torli a csapatot? [(1): Igen | (0): Nem]: ";
          cin.sync();
          cin >> d;
          if (d == 1) { 
            DB.rm(result); 
            arg = 0; 
            cout << "\n[+] Mentes..." << endl;
            DB.save();
            return; 
          }
          break;
        case 0:
          arg = 0;
          break;
        default:
          cout << "\n\t[!] Nem letezo menu..." << endl;
          break;
      }
    }
  }
}

void Menu::keresKosarMenu(){
  char buffer[256] = "";
  cout << "\t[?] Keresett csapat neve: ";
  cin.sync();
  #ifdef __linux__
    cin.ignore(1, '\n');
  #endif
  #ifdef __APPLE__
    cin.ignore(1, '\n');
  #endif 
  cin.getline(buffer, 255);
  KosarListaElem *result = DB.findKosar(buffer);
  if (result == nullptr) {
    cout << "[!] Nincs ilyen nevu csapat!" << endl;
    return;
  } else {
    printOne(result);
    int arg = -1;
    int d = 0;
    while (arg != 0) {
      cout << "\t\t[+] CSAPAT KEZELO MENU" << endl;
      cout << "\t\t==============================================================" << endl;
      cout << "\t\t| (1): Csapat modositasa | (2): Csapat torlese | (0): Vissza |" << endl;
      cout << "\t\t==============================================================" << endl;
      cout << "\t\t[!] Valasszon a listabol. Adja meg a menu szamat!" << endl;
      cout << "\t\t[?] Menu szama: ";
      cin.sync();
      cin >> arg;
      switch (arg) {
        case 1:
          editKosarMenu(result);
          return;
          break;
        case 2:
          cout << "\n\t\t[?] Biztosan torli a csapatot? [(1): Igen | (0): Nem]: ";
          cin.sync();
          cin >> d;
          if (d == 1) { 
            DB.rm(result); 
            arg = 0; 
            cout << "\n[+] Mentes..." << endl;
            DB.save();
            return; 
          }
          break;
        case 0:
          arg = 0;
          break;
        default:
          cout << "\n\t[!] Nem letezo menu..." << endl;
          break;
      }
    }
  }
}

void Menu::keresFociMenu(){
  char buffer[256] = "";
  cout << "\t[?] Keresett csapat neve: ";
  cin.sync();
  #ifdef __linux__
    cin.ignore(1, '\n');
  #endif
  #ifdef __APPLE__
    cin.ignore(1, '\n');
  #endif
  cin.getline(buffer, 255);
  FociListaElem *result = DB.findFoci(buffer);
  if (result == nullptr) {
    cout << "[!] Nincs ilyen nevu csapat!" << endl;
    return;
  } else {
    printOne(result);
    int arg = -1;
    int d = 0;
    while (arg != 0) {
      cout << "\t\t[+] CSAPAT KEZELO MENU" << endl;
      cout << "\t\t==============================================================" << endl;
      cout << "\t\t| (1): Csapat modositasa | (2): Csapat torlese | (0): Vissza |" << endl;
      cout << "\t\t==============================================================" << endl;
      cout << "\t\t[!] Valasszon a listabol. Adja meg a menu szamat!" << endl;
      cout << "\t\t[?] Menu szama: ";
      cin.sync();
      cin >> arg;
      switch (arg) {
        case 1:
          editFociMenu(result);
          return;
          break;
        case 2:
          cout << "\n\t\t[?] Biztosan torli a csapatot? [(1): Igen | (0): Nem]: ";
          cin.sync();
          cin >> d;
          if (d == 1) { 
            DB.rm(result); 
            arg = 0; 
            cout << "\n[+] Mentes..." << endl;
            DB.save();
            return; 
          }
          break;
        case 0:
          arg = 0;
          break;
        default:
          cout << "\n\t[!] Nem letezo menu..." << endl;
          break;
      }
    }
  }
}

void Menu::editKeziMenu(KeziListaElem *p) {
  if (p == nullptr) {return;}
  cout << endl;
  cout << "\t\t\tMODOSITO MENU" << endl;
  cout << "\t\t\t============================================================================================" << endl;
  cout << "\t\t\t| (1): Csapatnev csere | (2): Letszam modositasa | (3): Tamogatas hozzaadasa | (0): Vissza |" << endl;
  cout << "\t\t\t============================================================================================" << endl;
  cout << "\t\t\t[!] Valasszon a listabol. Adja meg a menu szamat!" << endl;
  cout << "\t\t\t[?] Menu szama: ";
  int arg = -1;
  int l = 0;
  char buffer[256] = "";
  long long int t = 0;
  cin.sync();
  cin >> arg;
  while (arg != 0) {
    switch (arg) {
      case 1:
        cout << "\n\t\t\t[?] Uj csapatnev: ";
        cin.sync();
        #ifdef __linux__
          cin.ignore(1, '\n');
        #endif
        #ifdef __APPLE__
          cin.ignore(1, '\n');
        #endif
        cin.getline(buffer, 255);
        p->adat.setNev(buffer);
        DB.save();
        cout << "\n[+]Mentes..." << endl;
        return;
        break;

      case 2:
        cout << "\n\t\t\t[?] Uj Letszam: ";
        cin.sync();
        cin >> l;
        p->adat.setLetszam(l);
        DB.save();
        cout << "\n[+]Mentes..." << endl;
        return;
        break;
      
      case 3:
        cout << "\n\t\t\t[?] Tamogatas hozzaadasa: ";
        cin.sync();
        cin >> t;
        p->adat.addTamogatas(t);
        DB.save();
        cout << "\n[+]Mentes..." << endl;
        return;
        break;

      case 0:
        arg = 0;
        break;

      default:
        cout << "\t\t\t[!] Nem letezo menu..." << endl;
        break;
    }
  }
}

void Menu::editKosarMenu(KosarListaElem *p) {
  if (p == nullptr) {return;}
  cout << endl;
  cout << "\t\t\tMODOSITO MENU" << endl;
  cout << "\t\t\t================================================================================================" << endl;
  cout << "\t\t\t| (1): Csapatnev csere | (2): Letszam modositasa | (3): PomPomlanyok hozzaadaasa | (0): Vissza |" << endl;
  cout << "\t\t\t================================================================================================" << endl;
  cout << "\t\t\t[!] Valasszon a listabol. Adja meg a menu szamat!" << endl;
  cout << "\t\t\t[?] Menu szama: ";
  int arg = -1;
  int l = 0;
  char buffer[256] = "";
  int o = 0;
  cin.sync();
  cin >> arg;
  while (arg != 0) {
    switch (arg) {
      case 1:
        cout << "\n\t\t\t[?] Uj csapatnev: ";
        cin.sync();
        #ifdef __linux__
          cin.ignore(1, '\n');
        #endif
        #ifdef __APPLE__
          cin.ignore(1, '\n');
        #endif
        cin.getline(buffer, 255);
        p->adat.setNev(buffer);
        DB.save();
        cout << "\n[+]Mentes..." << endl;
        return;
        break;

      case 2:
        cout << "\n\t\t\t[?] Uj Letszam: ";
        cin.sync();
        cin >> l;
        p->adat.setLetszam(l);
        DB.save();
        cout << "\n[+]Mentes..." << endl;
        return;
        break;
      
      case 3:
        cout << "\n\t\t\t[?] PomPom lanyok hozzaadasa: ";
        cin.sync();
        cin >> o;
        p->adat.addPompom(o);
        DB.save();
        cout << "\n[+]Mentes..." << endl;
        return;
        break;

      case 0:
        arg = 0;
        break;

      default:
        cout << "\t\t\t[!] Nem letezo menu..." << endl;
        break;
    }
  }
}

void Menu::editFociMenu(FociListaElem *p) {
  if (p == nullptr) {return;}
  cout << endl;
  cout << "\t\t\tMODOSITO MENU" << endl;
  cout << "\t\t\t========================================================================================" << endl;
  cout << "\t\t\t| (1): Csapatnev csere | (2): Letszam modositasa | (3): Edzok hozzaadasa | (0): Vissza |" << endl;
  cout << "\t\t\t========================================================================================" << endl;
  cout << "\t\t\t[!] Valasszon a listabol. Adja meg a menu szamat!" << endl;
  cout << "\t\t\t[?] Menu szama: ";
  int arg = -1;
  int l = 0;
  char buffer[256] = "";
  int e = 0;
  cin.sync();
  cin >> arg;
  while (arg != 0) {
    switch (arg) {
      case 1:
        cout << "\n\t\t\t[?] Uj csapatnev: ";
        cin.sync();
        #ifdef __linux__
          cin.ignore(1, '\n');
        #endif
        #ifdef __APPLE__
          cin.ignore(1, '\n');
        #endif
        cin.getline(buffer, 255);
        p->adat.setNev(buffer);
        DB.save();
        cout << "\n[+]Mentes..." << endl;
        return;
        break;

      case 2:
        cout << "\n\t\t\t[?] Uj Letszam: ";
        cin.sync();
        cin >> l;
        p->adat.setLetszam(l);
        DB.save();
        cout << "\n[+]Mentes..." << endl;
        return;
        break;
      
      case 3:
        cout << "\n\t\t\t[?] Edzok hozzaadasa: ";
        cin.sync();
        cin >> e;
        p->adat.addEdzo(e);
        DB.save();
        cout << "\n[+]Mentes..." << endl;
        return;
        break;

      case 0:
        arg = 0;
        break;

      default:
        cout << "\t\t\t[!] Nem letezo menu..." << endl;
        break;
    }
  }
}

void Menu::ujMenu(Tipus T) {
  cout << endl;
  char nevbuffer[256];
  int letszam;
  long long int variszam;
  cout << "\n\t[?] Adja meg a csapat nevet: ";
  cin.sync();
  #ifdef __linux__
    cin.ignore(1, '\n');
  #endif
  #ifdef __APPLE__
    cin.ignore(1, '\n');
  #endif
  cin.getline(nevbuffer, 255);
  cout << "\t[?] Adja meg a csapat letszamat: ";
  cin.sync();
  cin >> letszam;
  switch (T){
    case KEZI:
      cout << "\t[?] Adja meg a csapat tamogatasat: "; cin >> variszam;
      cout << endl;
      DB.add(KEZI, nevbuffer, letszam, variszam);
      cout << "[+] Mentes...";
      DB.save();
      break;

    case KOSAR:
      cout << "\t[?] Adja meg a csapat pompomlanyai szamat: "; cin >> variszam;
      cout << endl;
      DB.add(KOSAR, nevbuffer, letszam, variszam);
      cout << "[+] Mentes...";
      DB.save();
      break;
    
    case FOCI:
      cout << "\t[?] Adja meg a csapat edzoinek szamat: "; cin >> variszam;
      cout << endl;
      DB.add(FOCI, nevbuffer, letszam, variszam);
      cout << "[+] Mentes...";
      DB.save();
      break;
    
    case NINCS:
      break;
  }
}

void Menu::foMenu() {
  cout << "\n\n\n\n[!] Sport Nyilvantarto Rendszer!\n\n\n" << endl;

  int arg = -1;
  while (arg != 0) {
    cout << "\n\n[+] FOMENU" << endl;
    cout << "=============================================================================================================" << endl;
    cout << "| (1): Csapatok listazasa | (2): Kezilabda menu | (3): Kosarlabda menu | (4): Focilabda menu | (0): Kilepes |" << endl;
    cout << "=============================================================================================================" << endl;
    cout << "[!] Valasszon a listabol. Adja meg a menu szamat!" << endl;
    cout << "[?] Menu szama: ";
    cin.sync();
    cin >> arg;
    switch (arg)
    {
    case 1:
      printAll();
      break;
    case 2:
      keziMenu();
      break;
    case 3:
      kosarMenu();
      break;
    case 4:
      fociMenu();
      break;
    case 0:
      break;
    default:
      cout << "\n[!] Nem letezo menu..." << endl;
      break;
    }
  }
  cout << "[+] Kilepes..." << endl;
}

