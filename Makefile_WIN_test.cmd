echo "WINDOWS MAKEFILE"
echo "TESZT PROGRAM FORDITASA:"
g++ -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE -DG_TEST   -c -o main.o main.cpp
g++ -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE -DG_TEST   -c -o main_test.o main_test.cpp
g++ -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE -DG_TEST   -c -o memtrace.o memtrace.cpp
g++ -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE -DG_TEST   -c -o csapat.o csapat.cpp
g++ -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE -DG_TEST   -c -o foci.o foci.cpp
g++ -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE -DG_TEST   -c -o kosar.o kosar.cpp
g++ -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE -DG_TEST   -c -o kezi.o kezi.cpp
g++ -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE -DG_TEST   -c -o nyilvantartas.o nyilvantartas.cpp
g++ -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE -DG_TEST   -c -o menu.o menu.cpp
g++ -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE -DG_TEST main.o main_test.o memtrace.o csapat.o foci.o kosar.o kezi.o nyilvantartas.o menu.o -o nagyhazi
echo "HA NINCS HIBA: nagyhazi.exe"
pause
