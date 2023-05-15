# Nagyházi feladat Prog2-ből:

Ez a féléves beadandó házim. A feladat pontos leírása [itt](https://infocpp.iit.bme.hu/hf_otlet) található Sportegyesület néven.

## Futtatás:
A fordítás után egy `nagyhazi` vagy `nagyhazi.exe` file fog keletkezni. Fordítani a következő féle képpen lehet: \
_(<u>megjegyzés</u>: a Linux, UNIX alapú operációs rendszereknél szügséges a [GNU Make](https://www.gnu.org/software/make/) telepítése. Ezt [Windows-ra is fel lehet imádkozni](https://stackoverflow.com/questions/11772602/how-to-compile-makefile-using-mingw), és akkor működnek a Makefile által nyújtott scriptek...)_

- Windows alatt:
```
Makefile_WIN.cmd
```

- Linux, UNIX alatt _(Makefile)_:
```
make
```

- Windows alatt test esetek futtatása:
```
Makefile_WIN_test.cmd
```

- Linux, UNIX alatt tesztek futtatása _(Makefile)_:
```
make cmd=-DG_TEST
```


## Dokumentáció:

A feladat PDF dokumentációja a [docs/Docs.pdf](https://github.com/zomborip/prog2_nagyhazi/blob/main/docs/Docs.pdf) helyen érhető el, a HTML dokumentáció a [html/](https://github.com/zomborip/prog2_nagyhazi/tree/main/docs/html) mappában az [index.html](https://github.com/zomborip/prog2_nagyhazi/blob/main/docs/html/index.html) futtatásával tekinthető meg.

## Specifikáció:

A feladathoz tartozó specifikáció, terv, pontosított specifikáció a [spec/Spec.pdf](https://github.com/zomborip/prog2_nagyhazi/blob/main/specs/Specs.pdf)-ben található.

## Állapot:

Kész. A feladat a Laborvezető elbírálására vár, utólagos javítások azután valószínűek.

## Changelog:

* Heterogén kollekció inplementálása (_2023.05.01_)
  * A Class-okban
  * A Nyilvántartás API-ban
  * A Menüben
  * Dokumentációban, Specifikációban
* G_TEST implementálása (_2023.05.11_)
  * make cmd=-DG_TEST
  * build option hozzáadása
  * futtatható tesztek
* KÉSZ (_2023.05.16_)
  * Jporta, Cporta, Gtest bemakrózása
  * Több teszt
  * Dokumentáció frissítése
  * Dokumentáció magyarosítása
  * Build options frissítése

## TODO!:
* ~~Dokumentáció frissitése:~~ _(2023.05.15)_
  * ~~G_TEST~~
  * ~~Updated build option (make cmd=-DG_TEST)~~
* ~~TÖBB TEST, hogy a Jporta ne szójon be a code coverage-ért~~ _(2023.05.16)_
  * ~~Nagyon idegesítő >:C~~
