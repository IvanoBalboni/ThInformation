#ifndef TP_HEAD
#define TP_HEAD
#include <stdio.h>

typedef int* VECTEUR;
typedef int** MATRICE;

/* part 1*/
int pow2(unsigned int);
VECTEUR vecteur_vide(unsigned int);
void affiche_vecteur(VECTEUR, unsigned int);
void affiche_vecteur_mirroir(VECTEUR , unsigned int );
VECTEUR vecteur(unsigned int, unsigned int);
int valeur(VECTEUR, unsigned int);
/*part 2*/
VECTEUR* mots(unsigned int);
unsigned int poids(VECTEUR, int );
VECTEUR diff(VECTEUR, VECTEUR, int );
unsigned int hamming(VECTEUR, VECTEUR, int);
/*part 3*/

#endif
