#ifndef REPERTOIRE_H
#define REPERTOIRE_H

#include "inode.h"

// Taille maximale d'un nom de fichier
#define TAILLE_NOM_FICHIER 24

// Structure représentant une entrée de répertoire
struct sEntreesRepertoire {
    char nomEntree[TAILLE_NOM_FICHIER + 1];
    unsigned int numeroInode;
};

// Type représentant une entrée de répertoire
typedef struct sEntreesRepertoire *tEntreesRepertoire;

// Type représentant un répertoire
typedef struct sRepertoire *tRepertoire;

// Fonctions
tRepertoire CreerRepertoire(void);
void DetruireRepertoire(tRepertoire *pRep);
int EcrireEntreeRepertoire(tRepertoire rep, char nomEntree[], unsigned int numeroInode);
int LireRepertoireDepuisInode(tRepertoire *pRep, tInode inode);
int EcrireRepertoireDansInode(tRepertoire rep, tInode inode);
int NbEntreesRepertoire(tRepertoire rep);
int EntreesContenuesDansRepertoire(tRepertoire rep, struct sEntreesRepertoire tabNumInodes[]);
void AfficherRepertoire(tRepertoire rep);

#endif