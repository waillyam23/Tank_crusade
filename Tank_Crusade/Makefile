# Makefile du projet Tank Crusade

# Definitions de macros

CC = g++
CFLAGS = -Wall -Wextra -o
CFILES = main.cpp entities.cpp utility.cpp
OFILES = main.o entities.o utility.o
SDL = -lSDL2 -I SDL2/

# Definition de la premiere regle

main: $(OFILES)
	$(CC) $(CFILES) $(CFLAGS) Tank_Crusade $(SDL)

# Definitions de cibles particulieres

clean:
	rm -rf *.o

re:
	clear
	make delete
	make main

delete:
	make clean
	rm Tank_Crusade

# Regles d'inter-dependance generees automatiquement

main.o: main.cpp entities.h utility.h

entities.o: entities.cpp entities.h

utility.o: utility.cpp utility.h



