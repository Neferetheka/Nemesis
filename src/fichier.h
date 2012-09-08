#ifndef FICHIER

#define FICHIER


void sauvegarde(char nom[30], long sexe, long race, long classe, long force, long intelligence, long endurance, long pv, float niv, long place);
void sauvegarde_carac(long int emplacement, long int emplacement_carac, long int  carac);
float appel_carac_monstre(char nom[30], long emplacement);
float appel_carac_joueur(long int place, long emplacement);
void recherche_emplacement_vide();
void chargement();



#endif