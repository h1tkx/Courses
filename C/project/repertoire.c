#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "repertoire.h"

// Defined in .c
struct sRepertoire {
    tEntreesRepertoire *table;
    int nbEntrees; // Helper to track count, though strictly table size is fixed by max inode size
};

// Calculate max entries based on PDF logic
// 640 / (24 + 4) = 22.8 -> 22 entries
#define MAX_ENTREES (640 / (TAILLE_NOM_FICHIER + 1 + sizeof(unsigned int)))

tRepertoire CreerRepertoire(void) {
    tRepertoire rep = (tRepertoire)malloc(sizeof(struct sRepertoire));
    if (rep == NULL) {
        fprintf(stderr, "CreerRepertoire: probleme creation\n");
        return NULL;
    }
    
    rep->table = (tEntreesRepertoire*)malloc(MAX_ENTREES * sizeof(tEntreesRepertoire));
    if (rep->table == NULL) {
        free(rep);
        fprintf(stderr, "CreerRepertoire: probleme creation table\n");
        return NULL;
    }
    
    for(int i=0; i<MAX_ENTREES; i++) rep->table[i] = NULL;
    rep->nbEntrees = 0;
    return rep;
}

void DetruireRepertoire(tRepertoire *pRep) {
    if (pRep && *pRep) {
        if ((*pRep)->table) {
            for(int i=0; i<MAX_ENTREES; i++) {
                if ((*pRep)->table[i]) free((*pRep)->table[i]);
            }
            free((*pRep)->table);
        }
        free(*pRep);
        *pRep = NULL;
    }
}

int EcrireEntreeRepertoire(tRepertoire rep, char nomEntree[], unsigned int numeroInode) {
    if (!rep) return -1;
    
    // Check if exists
    for (int i=0; i<MAX_ENTREES; i++) {
        if (rep->table[i] != NULL && strcmp(rep->table[i]->nomEntree, nomEntree) == 0) {
            rep->table[i]->numeroInode = numeroInode;
            return 0;
        }
    }
    
    // Add new
    for (int i=0; i<MAX_ENTREES; i++) {
        if (rep->table[i] == NULL) {
            rep->table[i] = (tEntreesRepertoire)malloc(sizeof(struct sEntreesRepertoire));
            strncpy(rep->table[i]->nomEntree, nomEntree, TAILLE_NOM_FICHIER);
            rep->table[i]->nomEntree[TAILLE_NOM_FICHIER] = '\0';
            rep->table[i]->numeroInode = numeroInode;
            rep->nbEntrees++;
            return 0;
        }
    }
    
    return -1; // Full
}

int EcrireRepertoireDansInode(tRepertoire rep, tInode inode) {
    if (!rep || !inode) return -1;
    
    // Serialization buffer
    // Since struct sEntreesRepertoire is simple, we can write it directly, but beware of padding/packing.
    // However, to be safe and consistent with specific sizes, we should serialize manually or ensure struct packing.
    // For this project level, we will assume writing the struct bytes is acceptable or serialize sequentially.
    // Let's allow direct byte dump of the structs for simplicity as per common C practices in school projects,
    // assuming same architecture for read/write.
    
    long offset = 0;
    for (int i=0; i<MAX_ENTREES; i++) {
        if (rep->table[i] != NULL) {
            // Write struct
            long w = EcrireDonneesInode(inode, (unsigned char*)rep->table[i], sizeof(struct sEntreesRepertoire), offset);
            if (w != sizeof(struct sEntreesRepertoire)) return -1;
            offset += sizeof(struct sEntreesRepertoire);
        }
    }
    
    // Truncate logic isn't explicitly available in Inode module provided, 
    // but the file size updates in EcrireDonneesInode. 
    // If directory shrinks, old data remains but isn't reached by our "valid entries" loop during read
    // unless we store the count.
    // Actually, simply relying on file size:
    // When reading, we read until EOF (taille inode).
    return 0;
}

int LireRepertoireDepuisInode(tRepertoire *pRep, tInode inode) {
    if (!inode) return -1;
    
    tRepertoire rep = CreerRepertoire();
    if (!rep) return -1;
    
    long tailleInode = Taille(inode);
    long offset = 0;
    struct sEntreesRepertoire buf;
    
    while (offset < tailleInode) {
        long r = LireDonneesInode(inode, (unsigned char*)&buf, sizeof(struct sEntreesRepertoire), offset);
        if (r != sizeof(struct sEntreesRepertoire)) break;
        
        EcrireEntreeRepertoire(rep, buf.nomEntree, buf.numeroInode);
        offset += r;
    }
    
    *pRep = rep;
    return 0;
}

int NbEntreesRepertoire(tRepertoire rep) {
    return rep ? rep->nbEntrees : 0;
}

int EntreesContenuesDansRepertoire(tRepertoire rep, struct sEntreesRepertoire tabNumInodes[]) {
    if (!rep) return 0;
    int count = 0;
    for (int i=0; i<MAX_ENTREES; i++) {
        if (rep->table[i] != NULL) {
            tabNumInodes[count] = *(rep->table[i]);
            count++;
        }
    }
    return count;
}

void AfficherRepertoire(tRepertoire rep) {
    if (!rep) return;
    for (int i=0; i<MAX_ENTREES; i++) {
        if (rep->table[i] != NULL) {
            printf("%s (Inode %u)\n", rep->table[i]->nomEntree, rep->table[i]->numeroInode);
        }
    }
}