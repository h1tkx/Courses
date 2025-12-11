#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bloc.h"

tBloc CreerBloc(void) {
    tBloc bloc = (tBloc)malloc(TAILLE_BLOC * sizeof(unsigned char));
    if (bloc == NULL) {
        fprintf(stderr, "CreerBloc: probleme creation\n");
        return NULL;
    }
    // Initialize with 0
    memset(bloc, 0, TAILLE_BLOC);
    return bloc;
}

void DetruireBloc(tBloc *pBloc) {
    if (pBloc != NULL && *pBloc != NULL) {
        free(*pBloc);
        *pBloc = NULL;
    }
}

long EcrireContenuBloc(tBloc bloc, unsigned char *contenu, long taille) {
    if (bloc == NULL || contenu == NULL) return 0;
    
    long tailleAEcrire = (taille > TAILLE_BLOC) ? TAILLE_BLOC : taille;
    memcpy(bloc, contenu, tailleAEcrire);
    return tailleAEcrire;
}

long LireContenuBloc(tBloc bloc, unsigned char *contenu, long taille) {
    if (bloc == NULL || contenu == NULL) return 0;

    long tailleALire = (taille > TAILLE_BLOC) ? TAILLE_BLOC : taille;
    memcpy(contenu, bloc, tailleALire);
    return tailleALire;
}

int SauvegarderBloc(tBloc bloc, long taille, FILE *fichier) {
    if (bloc == NULL || fichier == NULL) return -1;
    long tailleASauver = (taille > TAILLE_BLOC) ? TAILLE_BLOC : taille;
    
    if (fwrite(bloc, sizeof(unsigned char), tailleASauver, fichier) != tailleASauver) {
        return -1;
    }
    return 0;
}

int ChargerBloc(tBloc bloc, long taille, FILE *fichier) {
    if (bloc == NULL || fichier == NULL) return -1;
    long tailleALire = (taille > TAILLE_BLOC) ? TAILLE_BLOC : taille;
    
    if (fread(bloc, sizeof(unsigned char), tailleALire, fichier) != tailleALire) {
        return -1;
    }
    return 0;
}