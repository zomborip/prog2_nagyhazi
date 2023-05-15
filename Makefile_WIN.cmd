echo "WINDOWS MAKEFILE"
echo "PROGRAM FORDITASA:"
g++ -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE   -c -o main.o main.cpp
g++ -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE   -c -o main_test.o main_test.cpp
g++ -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE   -c -o memtrace.o memtrace.cpp
g++ -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE   -c -o csapat.o csapat.cpp
g++ -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE   -c -o foci.o foci.cpp
g++ -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE   -c -o kosar.o kosar.cpp
g++ -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE   -c -o kezi.o kezi.cpp
g++ -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE   -c -o nyilvantartas.o nyilvantartas.cpp
g++ -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE   -c -o menu.o menu.cpp
g++ -std=c++11 -g -Wall -Werror -pedantic -DMEMTRACE main.o main_test.o memtrace.o csapat.o foci.o kosar.o kezi.o nyilvantartas.o menu.o -o nagyhazi
echo "HA NINCS HIBA: nagyhazi.exe"
pause
