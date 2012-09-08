//fichier.h => fichier de fonctions de manipulation des fichiers (ouverture/fermeture/sauvegarde/chargement etc.)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


void sauvegarde(char nom[30], long sexe, long race, long classe, long force, long intelligence, long endurance, long pv, long niv, long place)
{
	
	printf("\nSauvegarde en cours sur emplacement %ld...\n", place);
	
	FILE* fichier = NULL;
	char mode[3] = "w+";
	char path[15];
	long int choix = 1;
// 	char svg[300];
	
	sprintf(path, "svg/joueur%ld.ars", place);
	
	fichier = fopen(path, mode);
	
// 	sprintf(svg, "%s, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %f", nom,  sexe,  race,  classe,  force,  intelligence,  endurance, pv, niv);
	
	//on enregistre la chaine dans le fichier !
	fprintf(fichier, "%s\n %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld", nom,  sexe,  race,  classe,  force,  intelligence,  endurance, pv, pv, niv);

	
	fclose(fichier);
	
	printf("Voulez-vous continuer à jouer, ou arrêter?\n");
	scanf("%ld", &choix);
	
	if(choix == 1)
		game(place);
	else
	{;}
}


void sauvegarde_carac(long int emplacement, long int emplacement_carac, long int carac)
{
	FILE* fichier = NULL;
	char path[15];
	long int tab_carac[15] = {0};
	char nom[30];
	long int niv = 1;
	
	emplacement_carac -= 2;
	
	sprintf(path, "svg/joueur%ld.ars", emplacement);
	
	fichier = fopen(path, "r+");
	
	fscanf(fichier, "%s\n %ld, %ld,%ld,%ld,%ld,%ld,%ld,%ld, %ld", nom, &tab_carac[0], &tab_carac[1], &tab_carac[2], &tab_carac[3], &tab_carac[4], &tab_carac[5], &tab_carac[6], &tab_carac[7], &tab_carac[8]);
	
	tab_carac[emplacement_carac] = carac;
	
	fclose(fichier);
	
	fichier = fopen(path, "w+");
	
	fprintf(fichier, "%s\n %ld, %ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld", nom, tab_carac[0], tab_carac[1], tab_carac[2], tab_carac[3], tab_carac[4], tab_carac[5], tab_carac[6], tab_carac[7], tab_carac[8]);
	
	
	fclose(fichier);


}


long appel_carac_monstre(long int numero, long emplacement)
{
	FILE* fichier = NULL;
	char path[30];
	char nom[30];
	long carac = 0;
	long tab_carac[7] = {0};
	
	sprintf(path, "monstres/monstre%ld.ars", numero);
// 	printf("%s", path);
	fichier = fopen(path, "r+");
	
	fscanf(fichier, "%s\n %ld, %ld, %ld, %ld", nom, &tab_carac[2], &tab_carac[3], &tab_carac[4], &tab_carac[5]);
	
	carac = tab_carac[emplacement];
	
// 	, &tab_carac[9], &tab_carsac[10], &tab_carac[11], &tab_carac[12], &tab_carac[13], &tab_carac[14]
	
// 	fclose(fichier);
// 	FILE* fichier = NULL;

	return carac;
	
}

// char appel_nom_monstre(long numero, char *nom_monstre[35])
// {
// 	FILE* fichier = NULL;
// 	char nom[35];
// 	char path[50];
// 	
// // 	printf("%p", nom_monstre);
// 	
// 	sprintf(path, "monstres/monstre%ld.ars", numero);
// 	
// 	fichier = fopen(path, "r+");
// 	
// 	fgets(nom, 35, fichier);
// 	
// 	
// 	return nom_monstre;
// }


long int appel_carac_joueur(long int place, long emplacement)
{
	FILE* fichier = NULL;
	char mode[3] = "r+";
	char path[15];
	float carac = 0;
	emplacement -=2;
	long int  tab_carac[15] = {0};
	char nom[30];
	
	sprintf(path, "svg/joueur%ld.ars", place);
	
	fichier = fopen(path, mode);
	
	fscanf(fichier, "%s\n %ld, %ld,%ld,%ld,%ld,%ld,%ld,%ld, %ld", nom, &tab_carac[0], &tab_carac[1], &tab_carac[2], &tab_carac[3], &tab_carac[4], &tab_carac[5], &tab_carac[6], &tab_carac[7], &tab_carac[8], &tab_carac[9]);
	//PV =>PV TOTAL
	
	carac = tab_carac[emplacement];
	
	
	fclose(fichier);

	return carac;
	
}

float appel_carac_piege(char nom[30], long emplacement)
{
	FILE* fichier = NULL;
	char mode[3] = "r+";
	char path[15];
	float carac = 0;
	emplacement -=1;
	long tab_carac[2] = {0};
	
	sprintf(path, "pieges/%s.ars", nom);
	
	fichier = fopen(path, mode);
	
	fscanf(fichier, "%s\n %ld, %ld", nom, &tab_carac[0], &tab_carac[1]);
	
	carac = tab_carac[emplacement];
	
// 	, &tab_carac[9], &tab_carsac[10], &tab_carac[11], &tab_carac[12], &tab_carac[13], &tab_carac[14]
	
	fclose(fichier);

	return carac;
	
}


//Fonction de recherche d'emplacement vide
int recherche_emplacement_vide()
{
	//declaration des pointeurs de fichiers
	FILE* fichier = NULL;

	printf("Veuillez choisir un emplacement de sauvegarde s\'il vous plait !\n\n");
	
	//variables
	long int i, j = 0;
	char path[15];
	long int libre[4] = {0}; //Tableau d'emplacement libre
	long choix = 1;
	long choix2 = 2;
	long int relance = 0;
	char chaine[30];
	
	for(i = 1; i<=5; i++)
	{
		sprintf(path, "svg/joueur%ld.ars", i);
		
		fichier = fopen(path, "r+");
		
		if(fichier == NULL)
		{
			printf("Partie %ld : Emplacement vide\n", i);
			j = i-1;
			libre[j] = 1;

		}
		
		else
		{
			fgets(chaine, 30, fichier);
			printf("Partie %ld : %s", i, chaine);
		}

// 		
	}
	
	scanf("%ld", &choix);
	
	choix -= 1;
	
	if(libre[choix] == 0) //Si emplacement pris !
	{
		printf("Attention, emplacement pris ! Voulez-vous vraiment écraser la partie ?\n1)Oui\n2)Non");
		scanf("%ld", &choix2); //demande du choix
		
		if(choix2==1) //S'il veut supprimer
		{
			choix +=1;
			sprintf(path, "svg/joueur%ld.ars", choix); //On continue en supprimant le fichier existant
			remove(path);
		} 
		
		else //Sinon, on relance la fonction !
		{
			relance = 1;
		}
	}
	
	else
	{
		relance = 0;
		choix += 1;

		new_game(choix);
	}
	
	if(relance == 0)
		return 0;
	else
		recherche_emplacement_vide();
	
}


int chargement()
{
	//declaration des pointeurs de fichiers
	FILE* fichier = NULL;

	printf("Veuillez choisir un emplacement de sauvegarde à charger s\'il vous plait !\n\n");
	
	//variables
	long int i, j = 0;
	char path[15];
	long int libre[4] = {0};
	long choix = 1;
	long choix2 = 2;
	long int relance = 0;
	char chaine[30];
	
	for(i = 1; i<=5; i++)
	{
		sprintf(path, "svg/joueur%ld.ars", i);
		
		fichier = fopen(path, "r+");
		
		if(fichier != NULL)
		{
			fgets(chaine, 25, fichier);
			printf("Partie %ld : %s", i, chaine);
		}

// 		
	}
	
	scanf("%ld", &choix);

	game(choix);
	
}
		


