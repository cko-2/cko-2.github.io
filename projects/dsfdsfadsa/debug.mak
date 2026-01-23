all:
	g++ -ansi -pedantic-errors -Wall -DDEBUG -c llist.cpp -o llist.o
	g++ -ansi -pedantic-errors -Wall -DDEBUG -c user_interface.cpp -o user_interface.o
	g++ -o project_debug llist.o user_interface.o