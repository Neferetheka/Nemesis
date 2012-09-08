#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void new_game(long emplacement) //Fonction de creation du perso, avec la variable d'emplacement de sauvegarde
{
	// Declaration des variables
	char name[30];
	char race[30];
	long int sexe = 1 ;
	long int chrace = 1;	
	long int force =1;
	long int intel =1;
	long int endu =1;
	long int vital =1;
	long int chclasse =1;
	long int repeat =0;
	long int validation = 0;

	printf("\nBienvenue, jeune apprenti !\n\n");

	while (repeat == 0)
	{

	// Création du Personnage

		printf("\nQuel est votre nom?\n");
		scanf("%s", name);
		printf("\nQuel est votre sexe? \n1) Homme \n2) Femme \n");
		scanf("%ld", &sexe); //Valeur numerique

		// Sexe par défaut
		if ((sexe > 2) || (sexe < 1))	
			sexe = 2;

		
		if (sexe == 1)
		{
			printf("\nVous vous appelez donc %s et vous êtes un homme.\n\n", name);
		}
		else
		{
			printf("\nVous vous appelez donc %s et vous êtes une femme.\n\n",name); 		
		}
		
		
		// Choix de la race
		printf(" \nQuel est votre race? \n\n1) Humain (Force +1, Intelligence +1, Endurance +1, Vitalité +1)\n2) Elfe (Force -1, Intelligence +6, Endurance -1, Vitalité +0)\n3) Nain (Force +2, Intelligence -2, Endurance +4, Vitalité +2) \n4) Orque (Force +3, Intelligence -3, Endurance +2, Vitalité +2)\n");
		scanf("%ld",&chrace);
		
		// Application du choix de la race
		if (chrace == 1)
		{ 
			if(sexe == 1)
			{
				sprintf(race, "Humain");
			}
			else
			{
				sprintf(race, "Humaine");
			}
			force = 11;
			intel = 11;
			endu = 11;
			vital = 11;
		}
		else if (chrace == 2)
			{ 
				if(sexe == 1)
				{
                                	sprintf(race, "Elfe");
				}
				else
				{
					sprintf(race, "Elfette");
				}	
				force = 9;
				intel = 16;
				endu = 9;
				vital = 10;
			}
		else if (chrace == 3)
			{ 
                                if(sexe == 1)
				{
                                	sprintf(race, "Nain");
				}
				else
				{
					sprintf(race, "Naine");
				}
				force = 12;
				intel = 8;
				endu = 14;
				vital = 12;
			}
		else if (chrace == 4)
			{ 
                                if(sexe == 1)
				{
                                	sprintf(race, "Orque");
				}
				else
				{
					sprintf(race, "Orquette");
				}
				force = 13;
				intel = 7;
				endu = 12;
				vital = 12;
			}
		else
		{ 
			chrace =1;
			if(sexe == 1)
			{
				sprintf(race, "Humain");
			}
			else
			{
				sprintf(race, "Humaine");
			}
			force = 11;
			intel = 11;
			endu = 11;
			vital = 11;
		}
		
		if (sexe == 1)
		{
			printf("\nVous êtes donc un %s \n", race);
		}
		else
		{
			printf("\nVous êtes donc une %s \n", race);
		}
			
			
			
		printf("Vos caractéristiques de bases sont les suivantes:\n");
		printf("Force : %ld \nIntelligence: %ld \nEndurance: %ld \nVitalité: %ld \n", force, intel, endu, vital);
		
		// Choix de la classe

		printf("\n\nVous devez maintenant choisir votre classe.\n");
		printf("1) Guerrier (+2 force +2 endurance) \n2) Sorcier (+4 intelligence) \n");
		scanf("%ld", &chclasse);
	 	if (chclasse == 1)
		{
			if (sexe == 1)
			{
				printf("\nVous êtes donc un Guerrier ! \n\n");
			}
			else
			{
				printf("\nVous êtes donc une Guerrière ! \n\n");
			}
			force = force +2;
			endu = endu+2;
		}
		else
		{
			if (sexe == 1)
			{
				printf("\nVous êtes donc un Sorcier ! \n\n");
			}
			else
			{
				printf("\nVous êtes donc une Sorcière ! \n\n");
			}
			intel = intel+4;
		}
		
		
		
		// Recapitulation

		if (sexe == 1)
		{
			printf("Vous vous appelez %s et vous êtes  un homme.\n", name);
		}
		else
		{
			printf("Vous vous appelez %s et vous êtes  une femme.\n",name); 		
		}
		if (sexe == 1)
			{
				printf("Vous êtes un %s! \n", race);
			}
			else
			{
				printf("Vous êtes une %s! \n", race);
			}		 			
		if (chclasse == 1)
		{
			if (sexe == 1)
			{
				printf("Vous êtes un Guerrier ! \n");
			}
			else
			{
				printf("Vous êtes une Guerrière ! \n");
			}
			
		}
		else
		{
			if (sexe == 1)
			{
				printf("Vous êtes un Sorcier ! \n");
			}
			else
			{
				printf("Vous êtes une Sorcière ! \n");
			}
		}
		printf("Vos caractéristiques finales sont les suivantes:\n");
		printf("Force : %ld \nIntelligence: %ld \nEndurance: %ld \nVitalité: %ld \n", force, intel, endu, vital);


		printf("Etes-vous satisfait de vos choix (1) ou préferez vous tout recommencer (2) ?\n" );
		scanf("%ld",&validation);
		if (validation == 1)
		{
			repeat = 1;
		}
}


	sauvegarde(name, sexe ,chrace, chclasse, force, intel, endu, vital, 1, emplacement);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int game(long emplacement)
{
	system("clear");
	
	printf("Vous entrez dans une nouvelle salle du donjon et...\n");
	
 	long int min = 1;
	long int max = 3;
	long int nbaleatoire = 1;
 	nbaleatoire = (rand() %(max - min +1))+ min;
// 	nbaleatoire = 2;
	switch (nbaleatoire)
	{
		case 1:
			printf("Vous tombez sur un piège !\n");
			piege(emplacement);
		break;
		case 2:
			printf("Vous rencontrez un monstre !\n");
			combat(emplacement);
		break;
		case 3:
			printf("Vous entrez dans une salle contenant un bassin de guerison !\n");
			guerison(emplacement);
		break;
// 		case4:
// 			enigme(emplacement);
// 		break;
		default:
			rien(emplacement);
		break;
	}

}


void quitter()
{
	system("clear");
	printf("\n\nMerci d\'avoir joué à Némesis !\n\n");
}


void Visionneuse()
{
	FILE* fichier;
	
	long int choix, sexe, choix2;
	char path[50];
	char nom[35];
	char classe[30];
	char race[30];
	long int niv = 1;
	long int tab_carac[15] = {0};
	
	printf("Choisissez le personnage à regarder !\n");
	scanf("%ld", &choix);
	
	sprintf(path, "svg/joueur%ld.ars", choix);

	fichier = fopen(path, "r+");
	
	if(fichier == NULL)
	{
		printf("Le fichier de sauvegarde n\'existe pas !\n");
		main();
	}
	
	else
	{
		fscanf(fichier, "%s\n %ld, %ld,%ld,%ld,%ld,%ld,%ld,%ld, %ld", nom, &tab_carac[0], &tab_carac[1], &tab_carac[2], &tab_carac[3], &tab_carac[4], &tab_carac[5], &tab_carac[6], &tab_carac[7], &tab_carac[8]);
		
		sexe = tab_carac[0];
		
		if(tab_carac[1] == 1)
		{
			if(sexe == 1)
				sprintf(race, "Humain");
			else
				sprintf(race, "Humaine");
		}
		
		if(tab_carac[1] == 2)
		{
			if(sexe == 1)
				sprintf(race, "Elfe");
			else
				sprintf(race, "Elfette");
		}
		
		if(tab_carac[1] == 3)
		{
			if(sexe == 1)
				sprintf(race, "Nain");
			else
				sprintf(race, "Naine");
		}
		
		if(tab_carac[1] == 4)
		{
			if(sexe == 1)
				sprintf(race, "Orque");
			else
				sprintf(race, "Orquette");
		}
		
		
		
		
		if (tab_carac[2] == 1)
		{
			if (sexe == 1)
			{
				sprintf(classe, "Guerrier");

			}
			else
			{
				sprintf(classe, "Guerrière");
			}
		}
		
		else
		{
			if (sexe == 1)
			{
				sprintf(classe, "Sorcier");
			}
			else
			{
				sprintf(classe, "Sorcière");
			}
		}
		
		
		
		niv = conversion_xp(tab_carac[8]);

		printf("%s\n%s %s de niveau %ld\nForce : %ld\nIntelligence : %ld\nEndurance : %ld\nVitalité : %ld/%ld\nXP : %ld\n\n", nom, classe, race, niv, tab_carac[3], tab_carac[4], tab_carac[5], tab_carac[6], tab_carac[7], tab_carac[8]);
		
		printf("1)Jouer avec ce personnage\n2)Revenir au menu principal\n");
		scanf("%ld", &choix2);
		
		if(choix2 == 1)
			game(choix);
		else
			main();
	}
	
	

	
}
