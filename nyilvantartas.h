#ifndef NYILVANTARTAS_H
#define NYILVANTARTAS_H

#include "csapat.h"
#include "kezi.h"
#include "kosar.h"
#include "foci.h"
#include "memtrace.h"

/// @brief A Kezi osztály láncolt listázásához szolgáló struktúra. Ez egy darab listaelem.
struct KeziListaElem {
  /// @brief A listaelem adata, ami egy Kezi osztály.
  Kezi adat;

  /// @brief A következő listaelemre mutató pointer.
  KeziListaElem *kovi;
};

/// @brief A Kosar osztály láncolt listázásához szolgáló struktúra. Ez egy darab listaelem.
struct KosarListaElem {
  /// @brief A listaelem adata, ami egy Kosar osztály.
  Kosar adat;

  /// @brief A következő listaelemre mutató pointer.
  KosarListaElem *kovi;
};

/// @brief A Foci osztály láncolt listázásához szolgáló struktúra. Ez egy darab listaelem.
struct FociListaElem {
  /// @brief A listaelem adata, ami egy Foci osztály.
  Foci adat;

  /// @brief A következő listaelemre mutató pointer.
  FociListaElem *kovi;
};

/// @brief A nyilvántartás osztály. Ez tárolja a csapatokat (Kosar, Foci, Kezi) láncolt listákban.
/// @brief Képes ezeket fileokból beolvasni, lementeni. Hozzáadni csapatokat, törölni csapatokat.
/// @brief A program futása során ebből több mint egyet létrehozni nem kell (nem értelmes).
class Nyilvantartas {
  private:
    /// @brief A kézilabda csapatokat tároló láncolt lista.
    KeziListaElem   *keziCS;
    
    /// @brief A kosárlabda csapatokat tároló láncolt lista.
    KosarListaElem  *kosarCS;

    /// @brief A focilabda csapatokat tároló láncolt lista. 
    FociListaElem   *fociCS;

    /// @brief A kézilabda csapatokat táloló láncolt listát felszabadító segédfüggvény.
    void delKezi(){
      if (keziCS != nullptr) {
        KeziListaElem* i = keziCS;
        while (i != nullptr) {
          KeziListaElem *kov = i->kovi;
          delete[] i;
          i = kov;
        }
      }
    }

    /// @brief A kosárlabda csapatokat táloló láncolt listát felszabadító segédfüggvény.
    void delKosar(){
      if (kosarCS != nullptr) {
        KosarListaElem* i = kosarCS;
        while (i != nullptr) {
          KosarListaElem *kov = i->kovi;
          delete[] i;
          i = kov;
        }
      }
    }

    /// @brief A focilabda csapatokat táloló láncolt listát felszabadító segédfüggvény.
    void delFoci(){
      if (fociCS != nullptr) {
        FociListaElem* i = fociCS;
        while (i != nullptr) {
          FociListaElem *kov = i->kovi;
          delete[] i;
          i = kov;
        }
      }
    }

  public:

    /// @brief Kiszamolja egy szám legnagyobb helyiértékét (tehát, milyen hosszú a szám). Statikus függvény.
    /// @brief Nem működik tökéletesen, de 63 számjegyig működik (egyébként sem reális 64 számjegyű támogatás,
    /// @brief vagy pompomlányok szóval most jó lesz...)
    /// @param szam a kiszámolandó szám.
    /// @return A szám legnagyobb helyiértéke.
    static int intlen(const long long int);

    /// @brief Statikus. Hozzáfűz egy karakterpointerhez egy betűt. (VIGYÁZAT UTÁNNA DELETE[]-ELNI KELL).
    /// @param str A karakterpointer.
    /// @param c A hozzáadandó betű.
    static void straddc(char *&, const char);

    /// @brief Felszabadít és nullptr-é tesz egy karakterpointert. Statikus.
    /// @param str A karakertpointer.
    static void strdel(char *&);

    /// @brief A default konstruktor, amely 'nem csinál semmit'. Magyarul inicializála a 
    /// @brief láncolt listákat. (mindegyiket nullptr-re rakja).
    Nyilvantartas() : keziCS(nullptr), kosarCS(nullptr), fociCS(nullptr) {}

    /// @brief A destruktor, felszabadítja a láncolt listákat a segédfüggvények segítségével.
    ~Nyilvantartas();

    /// @brief Létrehoz egy új kézilabda láncolt lista elemet, beláncolja a listába, majd 
    /// @brief visszaadja az erre mutató pointer (azért, hogy lehessen vele dolgozni.)
    /// @return Az újjonnan létrehozott láncolt listaelem pointere.
    KeziListaElem   *ujKezi();

    /// @brief Létrehoz egy új kosárlabda láncolt lista elemet, beláncolja a listába, majd 
    /// @brief visszaadja az erre mutató pointer (azért, hogy lehessen vele dolgozni.)
    /// @return Az újjonnan létrehozott láncolt listaelem pointere.
    KosarListaElem  *ujKosar();

    /// @brief Létrehoz egy új kosárlabda láncolt lista elemet, beláncolja a listába, majd 
    /// @brief visszaadja az erre mutató pointer (azért, hogy lehessen vele dolgozni.)
    /// @return Az újjonnan létrehozott láncolt listaelem pointere.
    FociListaElem   *ujFoci();

    /// @brief Beleláncol a listába a paramétereknek megfelelő Kézilabda csapatot.
    /// @param csapatnev a csapat neve.
    /// @param letszam a csapat létszáma.
    /// @param tamogatas a csapat támogatásai.
    void addKezi(const char*, const int, const int);

    /// @brief Beleláncol a listába a paramétereknek megfelelő Kosárlabda csapatot.
    /// @param csapatnev a csapat neve.
    /// @param letszam a csapat létszáma.
    /// @param pompom_lanyok a csapat pompom lányainak száma.
    void addKosar(const char*, const int, const int);

    /// @brief Beleláncol a listába a paramétereknek megfelelő Focilabda csapatot.
    /// @param csapatnev a csapat neve.
    /// @param letszam a csapat létszáma.
    /// @param edzok a csapat edzőinek száma.
    void addFoci(const char*, const int, const int);

    /// @brief Beleláncol a listába a paramétereknek megfelelő, Típustól függő csapatot csapatot.
    /// @param csapat_tipus Megadja a csapat típusát a Tipus enum segítségével.
    /// @param csapatnev a csapat neve.
    /// @param letszam a csapat létszáma.
    /// @param csapat_speicfikus_szam a csapatokra külön vonatkozó specifikus szám (támogatás, pompomlányok, edzők).
    void add(const Tipus, const char*, const int, const int);

    /// @brief A paraméternek megfelelő nevű csapatra mutató pointert ad vissza. Kikeresi a láncolt listából.
    /// @param csapat_nev a keresendő csapat neve.
    /// @return A keresendő csapatra mutató pointer, VAGY nullptr ha nem található ilyen csapat.
    KeziListaElem   *findKezi(const char*) const;

    /// @brief A paraméternek megfelelő nevű csapatra mutató pointert ad vissza. Kikeresi a láncolt listából.
    /// @param csapat_nev a keresendő csapat neve.
    /// @return A keresendő csapatra mutató pointer, VAGY nullptr ha nem található ilyen csapat.
    KosarListaElem  *findKosar(const char*) const;

    /// @brief A paraméternek megfelelő nevű csapatra mutató pointert ad vissza. Kikeresi a láncolt listából.
    /// @param csapat_nev a keresendő csapat neve.
    /// @return A keresendő csapatra mutató pointer, VAGY nullptr ha nem található ilyen csapat.
    FociListaElem   *findFoci(const char*) const;
    
    /// @brief Kitörli a láncolt listából a paraméterben megadott listaelemet.
    /// @param lista_elem a láncolt listában egy elem-re mutató pointer.
    void rm(KeziListaElem *&);

    /// @brief Kitörli a láncolt listából a paraméterben megadott listaelemet.
    /// @param lista_elem a láncolt listában egy elem-re mutató pointer.
    void rm(KosarListaElem *&);
    
    /// @brief Kitörli a láncolt listából a paraméterben megadott listaelemet.
    /// @param lista_elem a láncolt listában egy elem-re mutató pointer.
    void rm(FociListaElem *&);
    
    /// @brief Visszaadja a Kézilabda csapatok láncolt listáját.
    /// @return Az első listaelemre mutató pointer, vagy nullptr ha üres a lista.
    KeziListaElem   *getKeziLista() const;

    /// @brief Visszaadja a Kosárlabda csapatok láncolt listáját.
    /// @return Az első listaelemre mutató pointer, vagy nullptr ha üres a lista.
    KosarListaElem  *getKosarLista() const;

    /// @brief Visszaadja a Focilabda csapatok láncolt listáját.
    /// @return Az első listaelemre mutató pointer, vagy nullptr ha üres a lista.
    FociListaElem   *getFociLista() const;

    /// @brief Betölti a kezi.txt fileból a kézilabda csapat adatait a keziCS listába.
    /// @return Igaz, ha sikerült betölteni, hamis ha nem.
    bool loadKezi();

    /// @brief Betölti a kosar.txt fileból a kosárlabda csapat adatait a kosarCS listába.
    /// @return Igaz, ha sikerült betölteni, hamis ha nem.
    bool loadKosar();

    /// @brief Betölti a foci.txt fileból a kosárlabda csapat adatait a fociCS listába.
    /// @return Igaz, ha sikerült betölteni, hamis ha nem.
    bool loadFoci();

    /// @brief Elmenti a kezi.txt fileba a keziCS adatait.
    void saveKezi() const;

    /// @brief Elmenti a kosar.txt fileba a kosarCS adatait.
    void saveKosar() const;

    /// @brief Elmenti a foci.txt fileba a fociCS adatait.
    void saveFoci() const;

    /// @brief Betölti az összes fileból (kezi.txt, kosar.txt, foci.txt) az adatokat a 
    /// @brief listákba (keziCS, kosarCS, fociCS) a segédfüggvények segítségével.
    /// @return igaz ha sikeres, hamis ha nem sikeres.
    bool load();

    /// @brief Elmenti az összes listát (keziCS, kosarCS, fociCS) a megfelelő fileokba 
    /// @brief (kezi.txt, kosar.txt, foci.txt) a segédfüggvények segítségével.
    void save() const;
};

#endif