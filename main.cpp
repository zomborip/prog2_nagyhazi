/// @file Main file. Itt van meghívva a main(), innen kezdodik a fomenu

// GitHub-on              : https://github.com/zomborip/prog2_nagyhazi
// Leírás                 : README.md
// Specifikáció           : spec/Spec.pdf
// Dokumentáció (Doxygen) : docs/Docs.pds


// Evvel meg lesz oldva az, hogy a JPortára feltöltött program alapból triggerelje a 
// teszt eseteket. Olyan Mintha make cmd=-G_TEST opcióval fordítanánk. Csak a Jporta
// 'tudni fogja', hogy ezt így kell.
#ifdef CPORTA
  #define G_TEST
#endif

// Ez az otthoni JPorta szimulációt oldja meg, mert valamiért nem fut le a gtest_lite 
// Windows alatt, a CPORTA makró definiálásaával ...
#ifdef JP
  #ifndef G_TEST
    #define G_TEST
  #endif
#endif

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
