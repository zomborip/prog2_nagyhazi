#ifndef KEZI_H
#define KEZI_H

#include "csapat.h"
#include "memtrace.h"

/// @brief A kézilabda csapat objektumja, amely örökli a Csapat objektum tulajdonságait.
class Kezi : public Csapat {
  private:
    /// @brief Az éves támogatásokat tároló int.
    int tamogatas;
  
  public:
    /// @brief A default konstruktor, amely a Csapat default konstruktorát hívja, csak a 
    /// @brief típust KEZI-re rakja a Típus enum segítségével.
    Kezi();

    /// @brief A konstruktor, amely a megadott adatoknake megfelelően állítja be a csapatot.
    /// @param uj_csapat_nev a csapat uj neve.
    /// @param letszam a csapat létszáma.
    Kezi(const char*, const int);

    /// @brief A megadott számmal növeli a tamogatas változót.
    /// @param uj_tamogatas ennyivel növeli a támogatás változót.
    void addTamogatas(const int);

    /// @brief Visszaadja a támogatások számát.
    /// @return A támogatások száma.
    const int getTamogatas() const;
};

#endif