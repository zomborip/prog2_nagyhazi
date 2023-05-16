/// @file Ez a test file. Csak a G_TEST definiálása után fut le. Teszt esetekért definiáljuk a makrót!


#ifndef TESZT_ESET
  // Hanyadig tesztet csinálja (összes = 99)
  //ITT KELL NÖVELNI
  #define TESZT_ESET 0
#endif


// Evvel meg lesz oldva az, hogy a JPortára feltöltött program alapból triggerelje a 
// teszt eseteket. Olyan Mintha make cmd=-G_TEST opcióval fordítanánk. Csak a Jporta
// 'tudni fogja', hogy ezt így kell.
#ifdef CPORTA
  #ifndef G_TEST
    #define G_TEST
  #endif
  #ifndef TESZT_ESET
    #define TESZT_ESET 99
  #else
    #undef TESZT_ESET
    #define TESZT_ESET 99
  #endif
#endif


// Ez az otthoni JPorta szimulációt oldja meg, mert valamiért nem fut le a gtest_lite 
// Windows alatt, a CPORTA makró definiálásaával ...
#ifdef JP
  #ifndef G_TEST
    #define G_TEST
  #endif
  #ifndef TESZT_ESET
    #define TESZT_ESET 99
  #else
    #undef TESZT_ESET
    #define TESZT_ESET 99
  #endif
#endif

// Evvel a preprocesszor setting-gel a main.cpp nem fut le, helyette ez. 
#ifdef G_TEST

  #include <iostream>
  #include <sstream>
  #include <clocale>
  #include "nyilvantartas.h"
  #include "csapat.h"
  #include "foci.h"
  #include "kezi.h"
  #include "kosar.h"
  #include "menu.h"
  #include "memtrace.h"
  #include "gtest_lite.h"

  int main() {
    std::cout << "CPORTA/GTEST script fut" << std::endl;
    GTINIT(std::cin);


    #if TESZT_ESET >= 1
    /// @brief [TEST ESET]
    /// @brief A csapatok homogenitását tezteli le
    TEST(CSAPAT, homogenitas){
      Csapat *vidi = new Kezi("Vidi", 69);
      Csapat *fradi = new Foci("FTC", 420);
      Csapat *honved = new Kosar("Honvéd", 123);

      vidi->addTamogatas(42069);
      fradi->addEdzo(2);
      honved->addPompom(10);

      EXPECT_EQ(69, vidi->getLetszam());
      EXPECT_EQ(42069, vidi->getTamogatas());
      EXPECT_EQ(-1, vidi->getPomPomDb());
      EXPECT_EQ(-1, vidi->getEdzokszama());

      EXPECT_EQ(420, fradi->getLetszam());
      EXPECT_EQ(2, fradi->getEdzokszama());
      EXPECT_EQ(-1, fradi->getTamogatas());
      EXPECT_EQ(-1, fradi->getPomPomDb());

      EXPECT_EQ(123, honved->getLetszam());
      EXPECT_EQ(10, honved->getPomPomDb());
      EXPECT_EQ(-1, honved->getEdzokszama());
      EXPECT_EQ(-1, honved->getTamogatas());

      vidi->addEdzo(111);
      vidi->addPompom(111);
      fradi->addTamogatas(111);
      fradi->addPompom(111);
      honved->addEdzo(111);
      honved->addTamogatas(111);

      if (vidi != nullptr) delete vidi;
      if (fradi != nullptr) delete fradi;
      if (honved != nullptr) delete honved;

    } ENDM
    #endif


    #if TESZT_ESET >= 2
    /// @brief [TEST ESET]
    /// @brief Kezi csapat módosító függvényeinek a tesztelése
    TEST(KEZI, modositasok_csapnev){
      Nyilvantartas db;
      EXPECT_TRUE(db.load());
      db.add(KEZI, "asdasdasdasd", 69, 69);
      db.save();

      EXPECT_TRUE(db.load());

      db.find("asdasdasdasd")->adat->setNev("rovidebb");
      EXPECT_EQ(true, (Lista *) nullptr != db.find("rovidebb"));

      db.save();
    } ENDM
    #endif


    #if TESZT_ESET >= 3
    /// @brief [TEST ESET]
    /// @brief Kezi csapat módosító függvényeinek a tesztelése
    TEST(KEZI, modositasok_csapnev_hosszabb){
      Nyilvantartas db;
      EXPECT_TRUE(db.load());

      const char *p = "sokkalsokkalsokkalsokkalsokkal_hosszabb_mint_az_eredeti";

      db.find("rovidebb")->adat->setNev(p);
      EXPECT_EQ(true, (Lista *) nullptr != db.find(p));

      db.find(p)->adat->setNev("Vidi");
      EXPECT_EQ(true, (Lista *) nullptr != db.find("Vidi"));

      db.save();
    } ENDM
    #endif

    
    #if TESZT_ESET >= 4
    /// @brief [TEST ESET]
    /// @brief Kezi csapat módosító függvényeinek a tesztelése
    TEST(KEZI, modositasok_tamogatas){
      Nyilvantartas db;
      EXPECT_TRUE(db.load());
      EXPECT_EQ(true, (Lista *) nullptr != db.find("Vidi"));

      db.find("Vidi")->adat->addTamogatas(42069);
      EXPECT_EQ((42069+69), db.find("Vidi")->adat->getTamogatas());

      db.save();
    } ENDM
    #endif


    #if TESZT_ESET >= 5
    /// @brief [TEST ESET]
    /// @brief Kezi csapat módosító függvényeinek a tesztelése
    TEST(KEZI, modositasok_letszam){
      Nyilvantartas db;
      EXPECT_TRUE(db.load());
      EXPECT_EQ(true, (Lista *) nullptr != db.find("Vidi"));

      db.find("Vidi")->adat->setLetszam(420);
      EXPECT_EQ(420, db.find("Vidi")->adat->getLetszam());

      db.save();

      Lista *tmp = nullptr;
      EXPECT_TRUE(db.load());
      tmp = db.getLista(); db.rm(tmp);  //ennek is működnie kell!
      tmp = db.getLista(); db.rm(tmp);  
      tmp = db.getLista(); db.rm(tmp);  
      tmp = db.getLista(); db.rm(tmp);  
      tmp = db.getLista(); db.rm(tmp);  
      db.save();
    } ENDM
    #endif


    #if TESZT_ESET >= 6
    /// @brief [TEST ESET]
    /// @brief A fileok beolvasasa
    TEST(NYILVANTARTAS, file_megnyitasok){
      Nyilvantartas db;
      EXPECT_TRUE(db.load());
    } ENDM
    #endif


    #if TESZT_ESET >= 7
    /// @brief [TEST ESET]
    /// @brief Uj kezilabdacsapat hozzaadasa
    TEST(NYILVANTARTAS, ujCsapatHozzaadasa){
      Nyilvantartas db;
      EXPECT_TRUE(db.load());
      const char *kezicsapat_nev = "Paks";      
      const int kezicsapat_letszam = 15;      
      const int kezicsapat_tamogatas = 450000;      
      db.addKezi(kezicsapat_nev, kezicsapat_letszam, kezicsapat_tamogatas);               // Kezi csapat hozzaadasa
    } ENDM
    #endif


    #if TESZT_ESET >= 8
    /// @brief [TEST ESET]
    /// @brief Uj kezilabdacsapat keresese
    TEST(NYILVANTARTAS, kereses){
      Nyilvantartas db;
      EXPECT_TRUE(db.load());
      const char *kezicsapat_nev = "Paks";      
      const int kezicsapat_letszam = 15;      
      const int kezicsapat_tamogatas = 450000;      
      db.addKezi(kezicsapat_nev, kezicsapat_letszam, kezicsapat_tamogatas);               // Kezi csapat hozzaadasa
      EXPECT_STREQ( kezicsapat_nev, db.find(kezicsapat_nev)->adat->getNev() );            // A csapnev lecsekkolasa
    } ENDM
    #endif


    #if TESZT_ESET >= 9
    /// @brief [TEST ESET]
    /// @brief Uj kezilabdacsapat fuggvenyek
    TEST(NYILVANTARTAS, tipusBiztosFuggvenyek){
      Nyilvantartas db;
      EXPECT_TRUE(db.load());
      const char *kezicsapat_nev = "Paks";      
      const int kezicsapat_letszam = 15;      
      const int kezicsapat_tamogatas = 450000;      
      db.addKezi(kezicsapat_nev, kezicsapat_letszam, kezicsapat_tamogatas);               // Kezi csapat hozzaadasa
      EXPECT_STREQ( kezicsapat_nev, db.find(kezicsapat_nev)->adat->getNev() );            // A csapnev lecsekkolasa
      EXPECT_EQ( kezicsapat_letszam, db.find(kezicsapat_nev)->adat->getLetszam() );       // letszam lecsekkolasa
      EXPECT_EQ( kezicsapat_tamogatas, db.find(kezicsapat_nev)->adat->getTamogatas() );   // tamogatas lecsekkolasa
      EXPECT_EQ( -1, db.find(kezicsapat_nev)->adat->getPomPomDb() );                      // mivel kezi csapat, nincsenek pompomlanyok. -1-et kell dobnia
    } ENDM
    #endif


    #if TESZT_ESET >= 10
    /// @brief [TEST ESET]
    /// @brief File mentés
    TEST(NYILVANTARTAS, mentes){
      Nyilvantartas db;
      EXPECT_TRUE(db.load());
      const char *kezicsapat_nev = "Paks";      
      const int kezicsapat_letszam = 15;      
      const int kezicsapat_tamogatas = 450000;      
      db.addKezi(kezicsapat_nev, kezicsapat_letszam, kezicsapat_tamogatas);               // Kezi csapat hozzaadasa
      db.save();
    } ENDM
    #endif


    #if TESZT_ESET >= 11
    /// @brief [TEST ESET]
    /// @brief Mentés ellenőrzés (minden cucc stimmel-e az előző előtti teszttel)
    TEST(NYILVANTARTAS, mentes_ellenorzes){
      Nyilvantartas db;
      EXPECT_TRUE(db.load());
      const char *kezicsapat_nev = "Paks";      
      const int kezicsapat_letszam = 15;      
      const int kezicsapat_tamogatas = 450000;      
      EXPECT_STREQ( kezicsapat_nev, db.find(kezicsapat_nev)->adat->getNev() );            // A csapnev lecsekkolasa
      EXPECT_EQ( kezicsapat_letszam, db.find(kezicsapat_nev)->adat->getLetszam() );       // letszam lecsekkolasa
      EXPECT_EQ( kezicsapat_tamogatas, db.find(kezicsapat_nev)->adat->getTamogatas() );   // tamogatas lecsekkolasa
      EXPECT_EQ( -1, db.find(kezicsapat_nev)->adat->getPomPomDb() );                      // mivel kezi csapat, nincsenek pompomlanyok. -1-et kell dobnia
      db.save();
    } ENDM
    #endif


    #if TESZT_ESET >= 12
    /// @brief [TEST ESET]
    /// @brief Törlés függvény
    TEST(NYILVANTARTAS, torles){
      Nyilvantartas db;
      EXPECT_TRUE(db.load());
      EXPECT_EQ(false, (Lista *) nullptr == db.find("Paks"));
      Lista * torlendo = db.find("Paks");
      db.rm( torlendo );
      EXPECT_EQ(true, (Lista *) nullptr == db.find("Paks"));
      db.save();
    } ENDM
    #endif


    #if TESZT_ESET >= 13
    /// @brief [TEST ESET]
    /// @brief Törlés ellenőrzés
    TEST(NYILVANTARTAS, torles_ellenorzes){
      Nyilvantartas db;
      EXPECT_TRUE(db.load());
      EXPECT_EQ(true, (Lista *) nullptr == db.find("Paks"));
      db.save();
    } ENDM
    #endif


    #if TESZT_ESET >= 14
    /// @brief [TEST ESET]
    /// @brief Törölt, üres filenak használhatónak kell lennie
    TEST(NYILVANTARTAS, torles_mentes){
      Nyilvantartas db;
      EXPECT_TRUE(db.load());
      db.addKezi("Videoton", 22, 560000);
      db.addKezi("Paks", 21, 450000);
      db.addKezi("Honvéd", 10, 100000);
      db.save();

      EXPECT_TRUE(db.load());
      Lista *vidi = db.find("Videoton");
      Lista *paks = db.find("Paks");
      Lista *ludovika = db.find("Honvéd");
      EXPECT_TRUE( (Lista*) nullptr != ( vidi ) );
      EXPECT_TRUE( (Lista*) nullptr != ( paks ) );
      EXPECT_TRUE( (Lista*) nullptr != ( ludovika ) );
      EXPECT_TRUE( (Lista*) nullptr == ( db.find("TUTI_NINCS_ILYEN_CSAPAT") ) );
      db.save();  
    } ENDM
    #endif


    #if TESZT_ESET >= 15
    /// @brief [TEST ESET]
    /// @brief Loopos törlés
    TEST(NYILVANTARTAS, torles_ellenorzes){
      Nyilvantartas db;
      EXPECT_TRUE(db.load());
      
      Lista *i = db.getLista();
      while (i != nullptr)
      {
        Lista *tmp = i->kovi;
        db.rm(i);
        i = tmp;
      }

      db.save();
    } ENDM
    #endif


    #if TESZT_ESET >= 16
    /// @brief [TEST ESET]
    /// @brief Törlés ellenőrzés, nem szabad hibát dobjon arra, ha az ureset akarom torolni
    TEST(NYILVANTARTAS, torles_ures){
      Nyilvantartas db;
      EXPECT_TRUE(db.load());
      EXPECT_EQ(true, (Lista *) nullptr == db.find("Paks"));
      Lista *elvilegUres = db.getLista();
      db.rm(elvilegUres);
      db.save();
    } ENDM
    #endif


    #if TESZT_ESET >= 17
    /// @brief [TEST ESET]
    /// @brief Törlés ellenőrzés, tényleges heterogén láncolt lista teszt
    TEST(NYILVANTARTAS, sok_fajta){
      Nyilvantartas db;
      EXPECT_TRUE(db.load());
      
      db.addKezi("Videoton", 22, 560000);
      db.addFoci("Fradi", 11, 3);
      db.addKezi("Paks", 21, 450000);
      db.addFoci("UTE", 12, 4);
      db.addKezi("Honvéd", 10, 100000);
      db.addKosar("Obudai Kaszasok", 40, 11);

      db.save();

      EXPECT_TRUE(db.load());

      Lista *vidi = db.find("Videoton");
      Lista *ftc = db.find("Fradi");
      Lista *ute = db.find("UTE");
      Lista *oek = db.find("Obudai Kaszasok");
      Lista *paks = db.find("Paks");
      Lista *ludovika = db.find("Honvéd");

      EXPECT_TRUE( (Lista*) nullptr != ( vidi ) );
      EXPECT_TRUE( (Lista*) nullptr != ( paks ) );
      EXPECT_TRUE( (Lista*) nullptr != ( ludovika ) );
      EXPECT_TRUE( (Lista*) nullptr != ( ftc ) );
      EXPECT_TRUE( (Lista*) nullptr != ( ute ) );
      EXPECT_TRUE( (Lista*) nullptr != ( oek ) );
      EXPECT_TRUE( (Lista*) nullptr == ( db.find("TUTI_NINCS_ILYEN_CSAPAT") ) );

      db.save();

      EXPECT_TRUE(db.load());
      
      Lista *i = db.getLista();
      while (i != nullptr)
      {
        Lista *tmp = i->kovi;
        db.rm(i);
        i = tmp;
      }

      db.save();

      EXPECT_TRUE(db.load());
      EXPECT_EQ(true, (Lista *) nullptr == db.find("Paks"));
      db.save();

    } ENDM
    #endif

    #ifdef CPORTA
      #if TESZT_ESET >= 18
      /// @brief [TEST ESET]
      /// @brief Jportás menü ellenörzés...
      TEST(MENU, JPorta_full){
        // Két féle képpen teszteli a főmenüjét a programnak.
        // Csak a kézi classt teszteli, de ez elég mert a többi 
        // úgy is CTRL+C CTRL+V. A menürendszer használatát mutatja be 
        // intuitívan...
        Menu m;
        
        m.foMenu();
        // JPporta bevitelre vár:
        /*
        1
        2
        1
        2
        nincsilyentutifix
        3
        Vidi
        11
        500000
        3
        Paks
        22
        222222
        3
        Tata
        33
        333333
        3
        Pecs
        44
        444444
        1
        2
        Vidi
        1
        1
        Videoton
        2
        Videoton
        1
        2
        44
        2
        Videoton
        1
        3
        10
        1
        2
        Videoton
        2
        1
        0
        1
        0
        */

        m.foMenu();
        //JPorta bevitelre vár:
        /*
        1
        2
        1
        2
        Pecs
        2
        1
        2
        Tata
        2
        1
        2
        Paks
        2
        1
        1
        0
        1
        0
        */

      } ENDM
      #endif
    #endif

    GTEND(std::cerr);
    return 0;

  }

#endif
