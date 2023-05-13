# Nagyházi feladat Prog2-ből:

Ez a féléves beadandó házim. A feladat pontos leírása [itt](https://infocpp.iit.bme.hu/hf_otlet) található Sportegyesület néven.

## Futtatás:
A fordítás után egy `nagyhazi` vagy `nagyhazi.exe` file fog keletkezni. Fordítani a következő féle képpen lehet:

- Windows alatt:
```
Makefile_WIN.cmd
```

- Linux, unix alatt:
```
make
```

## Dokumentáció:

A feladato PDF dokumentációja a [docs/Docs.pdf](https://github.com/zomborip/prog2_nagyhazi/blob/main/docs/Docs.pdf) helyen érhető el, a HTML dokumentáció a [html/](https://github.com/zomborip/prog2_nagyhazi/tree/main/docs/html) mappában az [index.html](https://github.com/zomborip/prog2_nagyhazi/blob/main/docs/html/index.html) futtatásával tekinthető meg.

## Specifikáció:

A feladathoz tartozó specifikáció a [spec/Spec.pdf](https://github.com/zomborip/prog2_nagyhazi/blob/main/specs/Specs.pdf)-ben található.

## Állapot:

(FÉL)Kész. A feladat a Laborvezető elbírálására vár, utólagos javítások azután valószínűek. (todo!)

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

## TODO!:
* Dokumentáció frissitése:
  * G_TEST
  * Updated build option (make cmd=-DG_TEST)
* TÖBB TEST, hogy a Jporta ne szójon be a code coverage-ért
  * Nagyon idegesítő >:C
