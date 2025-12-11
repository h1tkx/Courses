#ifndef BLOC_H
#define BLOC_H

#include <stdio.h>

// Taille d'un bloc en octets
#define TAILLE_BLOC 64

// Type public représentant un bloc de données
typedef unsigned char *tBloc;

// Fonctions du module
tBloc CreerBloc(void);
void DetruireBloc(tBloc *pBloc);
long EcrireContenuBloc(tBloc bloc, unsigned char *contenu, long taille);
long LireContenuBloc(tBloc bloc, unsigned char *contenu, long taille);
int SauvegarderBloc(tBloc bloc, long taille, FILE *fichier);
int ChargerBloc(tBloc bloc, long taille, FILE *fichier);

#endif