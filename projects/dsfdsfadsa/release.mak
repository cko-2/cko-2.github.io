all:
	g++ -ansi -pedantic-errors -Wall -c Ditto.cpp -o Ditto.o
	g++ -ansi -pedantic-errors -Wall -c Dwebble.cpp -o Dwebble.o
	g++ -ansi -pedantic-errors -Wall -c Wooper.cpp -o Wooper.o
	g++ -ansi -pedantic-errors -Wall -c Pokemon.cpp -o Pokemon.o
	g++ -ansi -pedantic-errors -Wall -c main.cpp -o main.o
	g++ -o homework9 Ditto.o Dwebble.o Wooper.o Pokemon.o main.o