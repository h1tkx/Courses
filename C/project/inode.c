#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "inode.h"
#include "bloc.h"

// Definition of the struct hidden in .c
struct sInode {
    unsigned int numero;
    natureFichier type;
    long taille;
    tBloc blocDonnees[NB_BLOCS_DIRECTS];
    time_t dateDerAcces, dateDerModif, dateDerModifInode;
};

// Helper to update times
static void update_times_modif(tInode inode) {
    time_t now = time(NULL);
    inode->dateDerModif = now;
    inode->dateDerModifInode = now;
}

static void update_time_access(tInode inode) {
    inode->dateDerAcces = time(NULL);
}

tInode CreerInode(unsigned int numInode, natureFichier type) {
    tInode inode = (tInode)malloc(sizeof(struct sInode));
    if (inode == NULL) {
        fprintf(stderr, "CreerInode: probleme creation\n");
        return NULL;
    }
    inode->numero = numInode;
    inode->type = type;
    inode->taille = 0;
    
    // Initialize block pointers to NULL
    for(int i = 0; i < NB_BLOCS_DIRECTS; i++) {
        inode->blocDonnees[i] = NULL;
    }
    
    time_t now = time(NULL);
    inode->dateDerAcces = now;
    inode->dateDerModif = now;
    inode->dateDerModifInode = now;
    
    return inode;
}

void DetruireInode(tInode* pInode) {
    if (pInode != NULL && *pInode != NULL) {
        for(int i = 0; i < NB_BLOCS_DIRECTS; i++) {
            if ((*pInode)->blocDonnees[i] != NULL) {
                DetruireBloc(&((*pInode)->blocDonnees[i]));
            }
        }
        free(*pInode);
        *pInode = NULL;
    }
}

unsigned int Numero(tInode inode) { return inode->numero; }
time_t DateDerAcces(tInode inode) { return inode->dateDerAcces; }
time_t DateDerModif(tInode inode) { return inode->dateDerModif; }
natureFichier Type(tInode inode) { return inode->type; }
long Taille(tInode inode) { return inode->taille; }
time_t DateDerModifFichier(tInode inode) { return inode->dateDerModif; }

void AfficherInode(tInode inode) {
    if (inode == NULL) {
        printf("vide\n");
        return;
    }
    
    char *typeStr;
    switch(inode->type) {
        case ORDINAIRE: typeStr = "ORDINAIRE"; break;
        case REPERTOIRE: typeStr = "REPERTOIRE"; break;
        default: typeStr = "AUTRE";
    }

    char *timeStr = ctime(&inode->dateDerAcces);
    if(timeStr[strlen(timeStr)-1] == '\n') timeStr[strlen(timeStr)-1] = '\0';
    
    printf("type : %s\n", typeStr);
    printf("    taille : %ld octets\n", inode->taille);
    printf("    date dernier accès : %s\n", timeStr);
    
    // Note: ctime returns pointer to static buffer, calling it again overwrites previous result
    // So we print immediately or copy it.
    timeStr = ctime(&inode->dateDerModif);
    if(timeStr[strlen(timeStr)-1] == '\n') timeStr[strlen(timeStr)-1] = '\0';
    printf("    date dernière modification : %s\n", timeStr);

    timeStr = ctime(&inode->dateDerModifInode);
    if(timeStr[strlen(timeStr)-1] == '\n') timeStr[strlen(timeStr)-1] = '\0';
    printf("    date dernière modification inode : %s\n", timeStr);
    
    printf("Donnees :\n");
    // Print content of blocks
    unsigned char buffer[TAILLE_BLOC + 1];
    long remaining = inode->taille;
    for(int i=0; i<NB_BLOCS_DIRECTS && remaining > 0; i++) {
        if(inode->blocDonnees[i] != NULL) {
            long toRead = (remaining > TAILLE_BLOC) ? TAILLE_BLOC : remaining;
            LireContenuBloc(inode->blocDonnees[i], buffer, toRead);
            buffer[toRead] = '\0'; // Safe for printing text, though binary might look weird
            printf("%s", buffer);
            remaining -= toRead;
        }
    }
    printf("\n");
}

long EcrireDonneesInode(tInode inode, unsigned char *contenu, long taille, long decalage) {
    if (inode == NULL || contenu == NULL) return -1;
    
    // Limit total file size
    long maxTaille = NB_BLOCS_DIRECTS * TAILLE_BLOC;
    if (decalage >= maxTaille) return 0;
    
    long octetsEcrits = 0;
    long remainingToWrite = taille;
    
    // Adjust if writing beyond max capacity
    if (decalage + remainingToWrite > maxTaille) {
        remainingToWrite = maxTaille - decalage;
    }

    int blocIdx = decalage / TAILLE_BLOC;
    int offsetInBloc = decalage % TAILLE_BLOC;
    
    unsigned char buffer[TAILLE_BLOC];
    
    while (remainingToWrite > 0 && blocIdx < NB_BLOCS_DIRECTS) {
        // Allocate block if it doesn't exist
        if (inode->blocDonnees[blocIdx] == NULL) {
            inode->blocDonnees[blocIdx] = CreerBloc();
            if (inode->blocDonnees[blocIdx] == NULL) break; // Allocation error
        }

        // Calculate how much to write in this block
        int spaceInBloc = TAILLE_BLOC - offsetInBloc;
        int chunk = (remainingToWrite > spaceInBloc) ? spaceInBloc : remainingToWrite;
        
        // Read current content if we are doing partial write to preserve surrounding data
        // (Only strictly necessary if we aren't overwriting the whole block or if the block was just created)
        // But since CreerBloc initializes to 0, strict read-modify-write is good practice
        LireContenuBloc(inode->blocDonnees[blocIdx], buffer, TAILLE_BLOC);
        
        // Update buffer
        memcpy(buffer + offsetInBloc, contenu + octetsEcrits, chunk);
        
        // Write back
        EcrireContenuBloc(inode->blocDonnees[blocIdx], buffer, TAILLE_BLOC); // We write full block logic usually
        
        octetsEcrits += chunk;
        remainingToWrite -= chunk;
        
        // Next iteration setup
        blocIdx++;
        offsetInBloc = 0; // Next blocks start at 0
    }
    
    // Update file size if we extended it
    if (decalage + octetsEcrits > inode->taille) {
        inode->taille = decalage + octetsEcrits;
    }
    
    update_times_modif(inode);
    return octetsEcrits;
}

long LireDonneesInode(tInode inode, unsigned char *contenu, long taille, long decalage) {
    if (inode == NULL || contenu == NULL) return -1;
    
    if (decalage >= inode->taille) return 0;
    
    long octetsLus = 0;
    long remainingToRead = taille;
    
    // Cannot read past EOF
    if (decalage + remainingToRead > inode->taille) {
        remainingToRead = inode->taille - decalage;
    }
    
    int blocIdx = decalage / TAILLE_BLOC;
    int offsetInBloc = decalage % TAILLE_BLOC;
    
    unsigned char buffer[TAILLE_BLOC];
    
    while (remainingToRead > 0 && blocIdx < NB_BLOCS_DIRECTS) {
        if (inode->blocDonnees[blocIdx] == NULL) {
            // Should not happen if logic matches size, but safe guard: act as zeros
            memset(buffer, 0, TAILLE_BLOC);
        } else {
            LireContenuBloc(inode->blocDonnees[blocIdx], buffer, TAILLE_BLOC);
        }
        
        int spaceInBloc = TAILLE_BLOC - offsetInBloc;
        int chunk = (remainingToRead > spaceInBloc) ? spaceInBloc : remainingToRead;
        
        memcpy(contenu + octetsLus, buffer + offsetInBloc, chunk);
        
        octetsLus += chunk;
        remainingToRead -= chunk;
        
        blocIdx++;
        offsetInBloc = 0;
    }
    
    update_time_access(inode);
    return octetsLus;
}

// Level 3 Saving
int SauvegarderInode(tInode inode, FILE *fichier) {
    if (inode == NULL || fichier == NULL) return -1;
    
    // Write metadata
    if (fwrite(&inode->numero, sizeof(unsigned int), 1, fichier) != 1) return -1;
    if (fwrite(&inode->type, sizeof(natureFichier), 1, fichier) != 1) return -1;
    if (fwrite(&inode->taille, sizeof(long), 1, fichier) != 1) return -1;
    if (fwrite(&inode->dateDerAcces, sizeof(time_t), 1, fichier) != 1) return -1;
    if (fwrite(&inode->dateDerModif, sizeof(time_t), 1, fichier) != 1) return -1;
    if (fwrite(&inode->dateDerModifInode, sizeof(time_t), 1, fichier) != 1) return -1;
    
    // Write Block existence mask (bitmap) or just loop
    // To simplify: Write a bool for each block slot indicating if it exists
    for (int i = 0; i < NB_BLOCS_DIRECTS; i++) {
        int exists = (inode->blocDonnees[i] != NULL);
        if (fwrite(&exists, sizeof(int), 1, fichier) != 1) return -1;
        if (exists) {
            if (SauvegarderBloc(inode->blocDonnees[i], TAILLE_BLOC, fichier) != 0) return -1;
        }
    }
    return 0;
}

int ChargerInode(tInode *pInode, FILE *fichier) {
    if (pInode == NULL || fichier == NULL) return -1;
    
    tInode inode = (tInode)malloc(sizeof(struct sInode));
    if (!inode) return -1;
    
    if (fread(&inode->numero, sizeof(unsigned int), 1, fichier) != 1) { free(inode); return -1; }
    if (fread(&inode->type, sizeof(natureFichier), 1, fichier) != 1) { free(inode); return -1; }
    if (fread(&inode->taille, sizeof(long), 1, fichier) != 1) { free(inode); return -1; }
    if (fread(&inode->dateDerAcces, sizeof(time_t), 1, fichier) != 1) { free(inode); return -1; }
    if (fread(&inode->dateDerModif, sizeof(time_t), 1, fichier) != 1) { free(inode); return -1; }
    if (fread(&inode->dateDerModifInode, sizeof(time_t), 1, fichier) != 1) { free(inode); return -1; }
    
    for (int i = 0; i < NB_BLOCS_DIRECTS; i++) {
        int exists;
        if (fread(&exists, sizeof(int), 1, fichier) != 1) { 
             // Cleanup partial
             *pInode = inode; DetruireInode(pInode); return -1; 
        }
        
        if (exists) {
            inode->blocDonnees[i] = CreerBloc();
            if (ChargerBloc(inode->blocDonnees[i], TAILLE_BLOC, fichier) != 0) {
                 *pInode = inode; DetruireInode(pInode); return -1;
            }
        } else {
            inode->blocDonnees[i] = NULL;
        }
    }
    
    *pInode = inode;
    return 0;
}

long TailleMaxFichier(void) {
    return NB_BLOCS_DIRECTS * TAILLE_BLOC;
}