#ifndef KOSAR_H
#define KOSAR_H

#include "csapat.h"
#include "memtrace.h"

/// @brief A kosárlabda csapat objektumja, amely örökli a Csapat objektum tulajdonságait.
class Kosar : public Csapat {
  private:
    /// @brief A pompomlányok száma.
    int pompomDB;
  
  public:
    /// @brief A default konstruktor, amely a Csapat default konstruktorát hívja, csak a 
    /// @brief típust átállítja KOSAR-ra a Tipus enum segítségével.
    Kosar();

    /// @brief Az adatoknak megfelelő csapatot hoz létre.
    /// @param csapatnev az uj csapatnév.
    /// @param letszam az új létszám.
    Kosar(const char*, const int);

    /// @brief Az adatoknak megfelelő mennyiségű pompomlányt ad a csapathoz.
    /// @param darabSzam ennyi pompomlány lesz a csapatban a csapathoz.
    void addPompom(const int);

    /// @brief Visszaadja a pompomlányok számát.
    /// @return A pompomlányok száma.
    const int getPomPomDb() const;

};

#endif