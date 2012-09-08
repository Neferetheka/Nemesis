#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "fichier.h"
#include "world.h"
#include "jeu.h"

int main() //Fonction principal
{
	// Declaration des variables du main
	long int choix= 0; //Variable de choix du menu
	srand(time(NULL)); //On initialise le générateur de nombres aléatoires

	// Page d'acceuil
	system("clear"); //Appel systeme
	
	printf("\n Bienvenue sur Némésis !\n\n ");//Message de bienvenue
	
	printf(" \n 1)Nouvelle partie  \n 2)Continuer  \n 3)Vision  \n 4)Quitter  \n\n");
	scanf("%ld", &choix);
	switch (choix)
	{
		case 1 :
			// appel de fonction 1
			recherche_emplacement_vide();
		break;
		case 2 :
			// appel de fonction 2
			chargement();
		break;
		case 3 :
			// appel de fonction 3
			Visionneuse();
		break;
		default :
			//quitter
			printf(" \n Au revoir ! \n\n");
		break;
	}

return 0;
}

