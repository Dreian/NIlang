# NIlang: programski jezik Nedelje informatike

Ovaj jezik je osmišljen za potrebe predavanja "Kratak kurs konstrukcije
kompajlera" na šestoj Nedelji informatike.
Reč je o jednostavnom jeziku koji služi za potrebe priče o jednostavnim
kompajlerima.
Sintaksa je inspirisana Pascal-om, ali jezik ne podržava nikakve potprograme.

## Kratka uputstva

Ovaj kod je testiran pod Linux-om i možda takođe radi pod Mac OS.
Za potrebe kompajliranja ovog kompajlera su vam neophodni `clang`, `cmake` i
`llvm` (poželjno bar verzija 11).
U nekim okruženjima su neophodni i paketi `pkg-config` i `libossp-uuid16`,
instalirajte ih ako vam kompajliranje ne radi i CMake se žali što neki paketi
nedostaju.
Kompajlerov *front end* koristi ANTLR4 (C++ interfejs), ali ne treba ništa
dodatno da se preuzme.

Najjednostavniji način da se kompajler kompajlira je pokretanjem skripte
`generate.sh`.
Postoji mogućnost da skripta nema setovan *executable* bit i da ne može da se
pokrene: ako je tako, samo prvo pokrenite `izvršine +x generate.sh`.
Ukoliko skripta ne radi, rešenje koje verovatno radi je da se ukucaju sledeće
instrukcije:
```
mkdir build
cd build
cmake -DLLVM_CONFIG=/put/do/llvm-config ../
make
```
Put do `llvm-config` programa (ili `llvm-config-XX`) može da se odredi
pokretanjem `whereis llvm-config`.
Prvo kompajliranje može da traje dugo (preuzimanje relevantnih ANTLR4
biblioteka).
Rezultat je program `nilang`.

Objekti fajl može da se kreira tako što se u komandnoj liniji izvrši (iz root
foldera ovog izvornog koda):
```
build/nilang <izvorni_kod> -t <objektni_fajl>
```
Ovo nije izvršni fajl, objektni fajl mora da se linkuje.
Ukoliko NIlang program koristi standardni izlaz, onda treba da se iskoristi
`clang`:
```
clang <objektni_fajl> -o <izvršni_fajl>
```
Na primer:
```
build/nilang examples/arith_sum.ni -t arith_sum.o && \
    clang arith_sum.o -o arith_sum
```
i onda `arith_sum` može da se izvrši.
Fajl `arith_sum` je *executable* program, ali postoji mogućnost da mu taj bit
nije podešen (što može da se ispravi jednim `chmod +x arith_sum` pozivom).

## Zahvalnost

Hvala Marku Stanojeviću na testiranju kompajlera i korisnim sugestijama!
