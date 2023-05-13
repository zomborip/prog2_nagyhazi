/// @file Main file. Itt van meghívva a main, innen kezdodik a fomenu

// A JPORTA FELTOLTESHEZ KI KELL KOMMENTELNI A main_test.cpp-ben a #defile G_TEST -et
// (HOGY A MENURENDSZER NE ZAVARJON BE)
// AMUGY KI KELL KAPCSOLNI (ÉS A make cmd=-DG_TEST) BUILD OPTION-T HASZNALNI
// VAGY A Makefile_WIN_test.cmd COMPILE SCRIPTET HA TESTELNI AKARJUK A PROGRAMOT.
// ...
// Evvel a preprocesszor setting-gel a main.cpp nem fut le, helyette a main_test.cpp

#ifndef G_TEST

  #include <iostream>
  #include "memtrace.h"
  #include "menu.h"

  using std::cout;
  using std::endl;

  void scopeScript(){
    Menu m;
    m.foMenu();
  }

  int main() {
    scopeScript();
    cout << "[-]PROGRAMVEGE" << endl;
    return 0;
  }

#endif
