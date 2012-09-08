#Constantes
O=Nemesis
CP=gcc 

all: main.c jeu.c world.c fichier.c
	$(CP) -lm main.c jeu.c world.c fichier.c -o $(O)
	
lancement: main.c jeu.c world.c fichier.c
	$(CP) -lm main.c jeu.c world.c fichier.c -o $(O)
	./Nemesis

clean:
	rm -vf *.o
	rm -vf *~
	rm -fv Nemesis

