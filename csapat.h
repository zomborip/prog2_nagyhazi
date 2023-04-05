#ifndef CSAPAT_H
#define CSAPAT_H

#include "memtrace.h"

/// @brief A csapatok típusait tartalmazó enum.
enum Tipus {
  /// @brief Nincs típus.
  NINCS, 
  
  /// @brief A kézilabda csapat típusa.
  KEZI, 
  
  /// @brief A focicsapat típusa.
  FOCI, 
  
  /// @brief A kosárcsapat típusa.
  KOSAR
};

/// @brief A csapatok szülőobjektuma. Ez írja je a csapatok közös viselkedését, tulajdonságait.
/// 
class Csapat {
  protected:
    /// @brief A csapat neve.
    char *nev;

    /// @brief A csapat létszáma.
    int letszam;

    /// @brief A csapat típusa a Típus enum segítségével.
    Tipus tipus;

    /// @brief Segédfunkció, amely kitörli, felszabadítja a nevet, ha az nem üres.
    void delNev() { if (nev != nullptr) { delete[] nev; } };

  public:
    /// @brief Default konstruktor, amely létrehoz egy NINCS típusú, 0 létszámú, semmilyen nevű csapatot.
    Csapat() : nev(nullptr), letszam(0), tipus(NINCS) {};

    /// @brief Név és létszámos konstruktor, amely létrehozza az adadtoknak megfelelő csapatot.
    /// @param csapat_nev ez a const char* paraméter a csapat neve lesz.
    /// @param letszam ez az int paraméter a csapat létszáma lesz.
    Csapat(const char *, int);

    /// @brief A csapat nevét létrehozó konstruktor, amely az a adoktnak megfelelő csapatot hoz létre, és a létszámot nullázza.
    /// @param csapat_nev ez a const char* paraméter a csapat neve lesz.
    Csapat(const char *);

    /// @brief A csapat létszámot is létrehozó konstruktor, amely nem hoz létre csapatnevet.
    /// @param letszam ez az int paraméter a csapatlétszám lesz.
    Csapat(int);

    /// @brief A csapat létszámát átállító, beállító függvény.
    /// @param uj_letszam Ez az int parameter lesz az új létszáma a csapatnak.
    void setLetszam(int);

    /// @brief A csapat nevét átállító, beállító függvény.
    /// @param uj_nev Ez a const char* paraméter lesz a csapat új neve.
    void setNev(const char *);

    /// @brief A csapat típusát beállító függvény (többször átállítani nincs értelme, mert úgyis öröklődik és az örökös tulajdonságai mások).
    /// @param uj_tipus Ez a Tipus parameter a csapat típusát adja meg a Tipus enum segítségével.
    void setTipus(const Tipus);

    /// @brief Viszaadja a csapat típusát a Tipus enum segítségével.
    /// @return A csapat típusa a Tipus enum-ban.
    Tipus getTipus() const;

    /// @brief Visszaadja a csapat létszámát.
    /// @return A csapat létszáma, int.
    int getLetszam() const;

    /// @brief Visszaadja a csapat nevét.
    /// @return A csapat neve, const char*.
    const char *getNev() const;

    /// @brief Lehetővé teszi a csapatok közti gyors keresést a == operátor túlterhelésével.
    /// @brief Megvizsgálja, hogy az adott névvel egyezik-e a csapat neve és ennek megfelelő
    /// @brief bool (igaz/hamis) értéket dob vissza.
    /// @param keresett_csapat_nev A keresett csapatnév const char* paraméter.
    /// @return Egy igaz hamis érték, hogy egyezik-e a csapatnév.
    bool operator==(const char*);

    /// @brief Virtuális destruktor (mert öröklődik majd a class).
    virtual ~Csapat();

};

#endif