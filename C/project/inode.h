#ifndef INODE_H
#define INODE_H

#include <time.h>
#include <stdio.h>

// Nombre maximum de blocs directs dans un inode
#define NB_BLOCS_DIRECTS 10

// Type représentant la nature d'un fichier
typedef enum {
    ORDINAIRE,
    REPERTOIRE,
    AUTRE
} natureFichier;

// Type représentant un inode
typedef struct sInode* tInode;

// Fonctions du module
tInode CreerInode(unsigned int numInode, natureFichier type);
void DetruireInode(tInode* pInode);
unsigned int Numero(tInode inode);
time_t DateDerAcces(tInode inode);
time_t DateDerModif(tInode inode);
natureFichier Type(tInode inode);
long Taille(tInode inode);
time_t DateDerModifFichier(tInode inode);
void AfficherInode(tInode inode);
long EcrireDonneesInode(tInode inode, unsigned char *contenu, long taille, long decalage);
long LireDonneesInode(tInode inode, unsigned char *contenu, long taille, long decalage);
int SauvegarderInode(tInode inode, FILE *fichier);
int ChargerInode(tInode *pInode, FILE *fichier);
long TailleMaxFichier(void);

#endif