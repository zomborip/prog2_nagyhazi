/// @file A Foci class fuggvenyeinek a deklaraciojat tartalmazo file.

#ifndef FOCI_H
#define FOCI_H

#include "csapat.h"
#include "memtrace.h"

/// @brief A focicsapat objektumja, amely örökli a Csapat objektum tulajdonságait.
class Foci : public Csapat {
  private:
    /// @brief A focicsapatra specifikus Edzőket számláló változó.
    int edzoDB;

  public:
    /// @brief A default konstruktor, amely a Csapat default konstruktorát használja
    /// @brief tehát létrehoz egy üres csapatot (csak a típusát FOCI-ra rakja).
    Foci();

    /// @brief A konstruktor, amely létrehoz az adatoknak megfelelő Csapat objektumot.
    /// @param csapat_nev a csapat beállítandó neve.
    /// @param letszam a csapat beállítandó létszáma.
    Foci(const char *, const int);

    /// @brief Sok darab új edzot ad hozzá a csapathoz. Növeli az edzoDB countert a megfelelő számmal.
    /// @param edzok_szama ennyivel növeli az edzoDB countert.
    void addEdzo(const int);

    /// @brief Visszaadja az edzők számát.
    /// @return Az edzők száma, int.
    const int getEdzokszama() const;

};

#endif