#ifndef SF_H
#define SF_H

#include <stdbool.h>
#include "inode.h"

#define TAILLE_NOM_DISQUE 24

struct sSuperBloc {
    char nomDisque[TAILLE_NOM_DISQUE + 1];
    time_t dateDerModif;
};

typedef struct sSuperBloc *tSuperBloc;

struct sListeInodesElement {
    tInode inode;
    struct sListeInodesElement *suivant;
};

struct sListeInodes {
    struct sListeInodesElement *premier, *dernier;
    int nbInodes;
};

struct SSF {
    tSuperBloc superBloc;
    struct sListeInodes listeInodes;
};

typedef struct SSF *tSF;

// Fonctions
tSF CreerSF(char nomDisque[]);
void AfficherSF(tSF sf);
void DetruireSF(tSF *pSF);
long EcrireFichierSF(tSF sf, char nomFichier[], natureFichier type);
int SauvegarderSF(tSF sf, char nomFichier[]);
int ChargerSF(tSF *pSF, char nomFichier[]);
int Ls(tSF sf, bool detail);

#endif