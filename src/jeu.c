#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void mort(long int emplacement)
{
	long int xp, pv;
	
	printf("Vous êtes mort !\n\n");
	
	xp = appel_carac_joueur(emplacement, 10);
	xp *= 0.9;
	
	sauvegarde_carac(emplacement, 10, xp);
	
	pv = appel_carac_joueur(emplacement, 9);
	sauvegarde_carac(emplacement, 8, pv);
	
}

void piege(emplacement)
{
	FILE* fichier = NULL;
	long int nbaleatoire = 0;
	long int nbaleatoire2 = 0;

	long int i,j, choix = 0;
	long int evite, degat = 0;
	char nom[50];
	char path[50];
	long int taille_max = 50;
	long int pv = 1;
	long int nombre = 0;
	
	fichier = fopen("pieges/liste.ars", "r+");
	
	fscanf(fichier, "%ld", &nombre);
	
	fclose(fichier);
	
	nbaleatoire = (rand() % (nombre - 1 + 1)) +1 ;
	
	sprintf(path, "pieges/piege%ld.ars", nbaleatoire);

	fichier = fopen(path, "r+");
	
	fscanf(fichier, "%s\n%ld, %ld", nom, &evite, &degat);
	
	printf("Il s\'agit d\'un piège mortel nommé %s\n", nom);
	
	fclose(fichier);
	
	
	nbaleatoire2 = (rand() % (100 - 1 +1)) +1;
	
	if (nbaleatoire2 <= evite)
	{
		printf("\nVous avez évité le piège\n");	
	}
	else
	{
		printf("\nVous n'avez pas réussi à éviter le piège et vous subissez %ld dégats.\n", degat);
		pv = appel_carac_joueur(emplacement,8);
		pv = pv - degat;
		if (pv <= 0)
		{
			mort(emplacement);
			pv = 0;
		}
		sauvegarde_carac(emplacement,8,pv);
	}
	
	
	printf("\nVoulez-vous continuer à jouer (1), ou arrêter (2) ?\n");
	scanf("%ld", &choix);
	
	if(choix == 1)
		game(emplacement);
	else
	{
		quitter();
	}
}




long int conversion_xp (long int joueur_xp)
{

	long int tab_niv[100] = {0};
	long int i = 2;
	tab_niv[0] = 1;
	tab_niv[1] = 100;
	long int joueur_niv = 1;
	
	while (i <= 100)
	{
		
		tab_niv[i] = floor(tab_niv[i-1] * 1.1);
		i++;
	}
	
	i = 0;
	
	while (i < 105)
	{
		if(joueur_xp > tab_niv[i])
		{
			joueur_niv = i;
			
		}
		
		else
		{
			i = 120;
// 			joueur_niv -= 1;
		}
		
		i++;
	}
// 		printf("test\n");

	if(joueur_niv < 1)
		joueur_niv = 1;
	
	return joueur_niv;
// 	return 1;
}


void combat (emplacement)
{
	//variables
	FILE* fichier = NULL;
	char path[50];
	long int nombre = 0;
	long int choix = 1;
	char nom[35];
	long int alea = 1;
	long min = 1;
	long max = 0;
	float degat = 0;
	float nbaleatoire = 0;
	long int i = 0;

	//caracs monstre & joueurs
	long int monstre_attaque, monstre_endu, monstre_pv, monstre_exp;
	long int joueur_force, joueur_intelligence, joueur_endurance, joueur_pv, joueur_pv_total;
	long int joueur_classe = 0;
	long int joueur_attaque = 0;
	long int joueur_niv;
	long int new_niveau = 1; 
	long int niv_actuel = 1;
	
	
	fichier = fopen("monstres/liste.ars", "r+");
	
	fscanf(fichier, "%ld", &nombre);

	max = nombre;
	
	alea = (rand() % (max - min + 1)) + min; //Alea indique le numero du monstre !
// 	printf("Nombre : %ld\n", alea);

	sprintf(path, "monstres/monstre%ld.ars", alea);
	
	fichier = fopen(path, "r+");
	
	fgets(nom, 35, fichier);

	
	printf("Il s\'agit d\'un %s", nom);
	
	//Maintenant qu'on a le nom du monstre, on prend ses caracs
	monstre_attaque = appel_carac_monstre (alea, 2); //INVOCATIOOOOOOOOOOOOOOOOOOOOOOOONNNNNNNN !!!!!!
	monstre_endu = appel_carac_monstre(alea, 3); //INVOCATION 2222222222222222222222222222222222 !!!!!!!!!!!!!!
	monstre_pv = appel_carac_monstre(alea, 4); //KAMAHAMEHAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA!!!!!!
	monstre_exp = appel_carac_monstre(alea, 5);
	
// 	printf("Attaque : %ld\nEndu: %ld\npv:%ld\nexp : %ld\n", monstre_attaque, monstre_endu, monstre_pv, monstre_exp);
	
// 	printf("Attaque : %ld\n", monstre_attaque);
	
	
	//On prend les caracs du persos
	joueur_force = appel_carac_joueur(emplacement, 5);
	joueur_intelligence = appel_carac_joueur(emplacement, 6);
	joueur_endurance = appel_carac_joueur(emplacement, 7);
	joueur_pv = appel_carac_joueur(emplacement, 8);
	joueur_pv_total = appel_carac_joueur(emplacement, 9);
	joueur_niv = appel_carac_joueur(emplacement, 10);
	joueur_classe = appel_carac_joueur(emplacement, 4);
	
// 	printf("Attaque : %ld\n", joueur_niv);



        fclose(fichier);
	
	if (joueur_classe == 1)
	{
		joueur_attaque = joueur_force ;
	}
	
	else
	{
		joueur_attaque = joueur_intelligence ;
	}
	
	printf("\n%s vous attaque !\n",nom);
	while ((monstre_pv > 0) && (joueur_pv > 0))
		{
			
			nbaleatoire = floor(((rand() % ((joueur_attaque*5) - 1 + 1)) + 1)/50);
			degat = (joueur_attaque + nbaleatoire) - monstre_endu;
			if(degat < 0)
				degat = 0;
			printf("Vous attaquez %s et lui infligez %0.0f points de dégats\n", nom, degat);
			monstre_pv = monstre_pv - degat;

			
			nbaleatoire = floor(((rand() % ((monstre_attaque*5) - 1 + 1)) + 1) / 50);
			degat = (monstre_attaque + nbaleatoire) - joueur_endurance;
			if(degat < 0)
				degat = 0;
			printf("%s vous attaque et vous inflige %0.0f points de dégats\n", nom, degat);
			joueur_pv = joueur_pv - degat;	
				
		}

	if ((monstre_pv <= 0) && (joueur_pv > 0))
	{
		printf("\nVous avez vaincu %s !!! \n", nom);
		monstre_exp *= 4;
		printf("\nVous gagnez %ld points d'experience !\n\n", monstre_exp);
		
		niv_actuel = joueur_niv; //sauvegarde des xp du joueur
// 		printf("niv_actuel : %ld", niv_actuel);
		niv_actuel = conversion_xp(niv_actuel); //conversion des xp en niveau avant nouveaux xp


		joueur_niv = joueur_niv + monstre_exp; //gain de xp du monstre

		sauvegarde_carac(emplacement, 10, joueur_niv); //On sauvegarde le nombre de xp
		sauvegarde_carac(emplacement, 8, joueur_pv);
// 		
		new_niveau = conversion_xp(joueur_niv); //On genere le lvl du perso avec ses nouveaux xp
			
		if(niv_actuel < new_niveau)
			lvl_up(emplacement, new_niveau);
		
		
		
		
		
	}
	
	else if((joueur_pv <= 0) && (monstre_pv > 0))
	{
		printf("\nVous avez été vaincu par %s ...\n\n",nom);
		
		mort(emplacement);
	}
	else
	{
		printf("\n Dans une lutte sanglante, vous et %s vous êtes entretués, . \n\n", nom);
		
		mort(emplacement);
		
	}
	
	
	
	printf("\nVoulez-vous continuer à jouer (1), ou arrêter (2) ?\n");
	scanf("%ld", &choix);
	
	if(choix == 1)
		game(emplacement);
	else
	{
		quitter();
	}
	
	
	
}	




int lvl_up(long int emplacement, long int niv)
{
	long int choix;
	
	printf("Felicitations, vous avez acquis un niveau !\n\nVous allez à présent devoir déterminer quelle amélioration vous désirez !\n\n");
	
	printf("1)Force\n2)Intelligence\n3)Endurance\n4)Vitalité\n\n");
	
	scanf("%ld", &choix);
	
	if(choix != 4)
		augmenter_carac(emplacement, choix);
	else 
		augmenter_carac_vitalite(emplacement);
}


int augmenter_carac(long int emplacement, long int choix)
{
	long int e_carac = 5;
	long int carac = 1;
	
	if(choix == 1)
		e_carac = 5;
	else if (choix == 2)
		e_carac = 6;
	else
		e_carac = 7;
	
	carac = appel_carac_joueur(emplacement, e_carac);
	carac ++;
	
	sauvegarde_carac(emplacement, e_carac, carac);
}

int augmenter_carac_vitalite(long int emplacement)
{
	long int pv = appel_carac_joueur(emplacement, 9);
	pv +=5;
	
	sauvegarde_carac(emplacement, 9, pv);
	
}


int rien(long emplacement)
{
	printf("Il n\'y a rien ici !\n");
	game(emplacement);
}

void guerison(long int emplacement)
{
	long int max = 100;
	long int min = 1;
	long int pv, pv_total, alea, choix;
	
	alea = (rand() % (max - min + 1)) + min;
	
	pv = appel_carac_joueur(emplacement, 8);
	pv_total = appel_carac_joueur(emplacement, 9);
	
	pv += alea;
	if(pv > pv_total)
		pv = pv_total;
	
	printf("Vous avez regagné %ld points de vie !\n", alea);
	
	sauvegarde_carac(emplacement, 8, pv);
	
	printf("\nVoulez-vous continuer à jouer (1), ou arrêter (2) ?\n");
	scanf("%ld", &choix);
	
	if(choix == 1)
		game(emplacement);
	else
	{
		quitter();
	}
}



	