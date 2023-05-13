/// @file Ez a test file. Csak a G_TEST definiálása után fut le

//#define G_TEST // A JPORTA FELTOLTESHEZ KI KELL KOMMENTELNI (HOGY A MENURENDSZER NE ZAVARJON BE)
                 // AMUGY KI KELL KAPCSOLNI (ÉS A make cmd=-DG_TEST) BUILD OPTION-T HASZNALNI
                 // VAGY A Makefile_WIN_test.cmd COMPILE SCRIPTET HA TESTELNI AKARJUK A PROGRAMOT.
                 // ...
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
  #include "memtrace.h"
  #include "gtest_lite.h"

  int main() {
    GTINIT(std::cin);

    /// @brief [TEST ESET]
    /// @brief A fileok beolvasasa
    TEST(NYILVANTARTAS, file_megnyitasok){
      Nyilvantartas db;
      EXPECT_TRUE(db.load());
    } ENDM

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

    /// @brief [TEST ESET]
    /// @brief Uj kezilabdacsapat fuggvenyek
    TEST(NYILVANTARTAS, mentes){
      Nyilvantartas db;
      EXPECT_TRUE(db.load());
      const char *kezicsapat_nev = "Paks";      
      const int kezicsapat_letszam = 15;      
      const int kezicsapat_tamogatas = 450000;      
      db.addKezi(kezicsapat_nev, kezicsapat_letszam, kezicsapat_tamogatas);               // Kezi csapat hozzaadasa
      db.save();
    } ENDM

    /// @brief [TEST ESET]
    /// @brief Uj kezilabdacsapat fuggvenyek
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
    
    /// @brief [TEST ESET]
    /// @brief Uj kezilabdacsapat fuggvenyek
    TEST(NYILVANTARTAS, torles){
      Nyilvantartas db;
      EXPECT_TRUE(db.load());
      EXPECT_EQ(false, (Lista *) nullptr == db.find("Paks"));
      Lista * torlendo = db.find("Paks");
      db.rm( torlendo );
      EXPECT_EQ(true, (Lista *) nullptr == db.find("Paks"));
      db.save();
    } ENDM


    GTEND(std::cerr);
    return 0;

  }

#endif
