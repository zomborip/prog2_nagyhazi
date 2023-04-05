#ifndef MENU_H
#define MENU_H

#include "nyilvantartas.h"
#include "memtrace.h"

/// @brief A futó programot irányító menürendszer objektuma.
class Menu {
  private:
    /// @brief A nyilvántartás adatbázis.
    Nyilvantartas DB;
  public:

    /// @brief Default konstruktor, betölti a nyilvántartás adatait fileból.
    Menu();
    
    /// @brief Destruktor, lementi a nyilvántartás adatait fileokba.
    ~Menu();

    /// @brief Getter. Visszaadja az egész nyilvántartás osztályt (Debug célokra főképp, mivel nincs értelme a classal kommunikálni kívülről.)
    /// @return Nyilvántartás adatbázis.
    Nyilvantartas getNyilvantartas() const { return DB;}

    /// @brief Kilistázza megformázva az összes adatot.
    void printAll() const;

    /// @brief Kilistázza megformázva a Kézilabda (Kezi) csapatokat.
    void printKezi() const;

    /// @brief Kilistázza megformázva a Kárlabda (Kosar) csapatokat.
    void printKosar() const;

    /// @brief Kilistázza megformázva a Focilabda (Foci) csapatokat.
    void printFoci() const;

    /// @brief Egy listaelemet ír ki megformázva.
    /// @param listaelem A lista láncszemére mutató pointer.
    void printOne(KeziListaElem *) const;

    /// @brief Egy listaelemet ír ki megformázva.
    /// @param listaelem A lista láncszemére mutató pointer.
    void printOne(KosarListaElem *) const;
    
    /// @brief Egy listaelemet ír ki megformázva.
    /// @param listaelem A lista láncszemére mutató pointer.
    void printOne(FociListaElem *) const;

    /// @brief Kiszámolja a leghoszabb sor hosszát a nyilvántartásban. Erre a TAB-ok és a kinézet miatt van szügség.
    /// @return A leghoszabb sor hossza az adatbáisban.
    int maxStdRowLen() const;

    /// @brief Kiszámolja, hogy a nyílvántartás típus szerinti láncolt listájában mennyi a leghoszabb sor. Erre a TAB-ok és a kinézet miatt van szüggség.
    /// @param tipus A láncolt lista típusa, hogy melyikben keresse a leghoszabb sort.
    /// @return A maximális sor hossz.
    int maxStdRowLen(Tipus) const;

    /// @brief Egy adott listaelem sorának hosszát adja vissza. Design felhasználási céllal.
    /// @param listaelem Ennek a sorhosszára vagyunk kíváncsiak.
    /// @return A listaelem sorának hossza.
    int getStdRowLen(KeziListaElem *) const;

    /// @brief Egy adott listaelem sorának hosszát adja vissza. Design felhasználási céllal.
    /// @param listaelem Ennek a sorhosszára vagyunk kíváncsiak.
    /// @return A listaelem sorának hossza.
    int getStdRowLen(KosarListaElem *) const;

    /// @brief Egy adott listaelem sorának hosszát adja vissza. Design felhasználási céllal.
    /// @param listaelem Ennek a sorhosszára vagyunk kíváncsiak.
    /// @return A listaelem sorának hossza.
    int getStdRowLen(FociListaElem *) const;

    /// @brief Főmenü. Innen indul minden. Ez tujajdonképpen az entrypoint, ahonnan a class
    /// @brief átveszi az irányítást, és automata menürendszerként üzemel.
    void foMenu();

    /// @brief A kézilabda csapatokkal foglalkozó almenü. Innen lehet kézi sprecifikus dolgokat csinálni.
    void keziMenu();

    /// @brief A kosárlabda csapatokkal foglalkozó almenü. Innen lehet kosár sprecifikus dolgokat csinálni.
    void kosarMenu();

    /// @brief A focicsapatokkal foglalkozó almenü. Innen lehet foci sprecifikus dolgokat csinálni.
    void fociMenu();

    /// @brief Egy kézilabda csapat keresési menüje.
    void keresKeziMenu();

    /// @brief Egy kosárlabda csapat keresési menüje.
    void keresKosarMenu();

    /// @brief Egy focilabda csapat keresési menüje.
    void keresFociMenu();

    /// @brief A láncolt lista egy elemét módosító almenü.
    /// @param listaelem Ennek módosításában segít a menü.
    void editKeziMenu(KeziListaElem *);

    /// @brief A láncolt lista egy elemét módosító almenü.
    /// @param listaelem Ennek módosításában segít a menü.
    void editKosarMenu(KosarListaElem*);

    /// @brief A láncolt lista egy elemét módosító almenü.
    /// @param listaelem Ennek módosításában segít a menü.
    void editFociMenu(FociListaElem *);

    /// @brief Egy új tipus típusú csapat lérehozására létező almenü.
    /// @param tipus Az új csapat típusa.
    void ujMenu(Tipus);
};

#endif