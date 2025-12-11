#include <stdio.h>
#include <stdlib.h>
#include "sf.h"

int main(void) {
    printf("=== CREATION SF ===\n");
    tSF sf = CreerSF("MonDisque");
    
    printf("\n=== AJOUT FICHIERS ===\n");
    EcrireFichierSF(sf, "grenouille.txt", ORDINAIRE);
    EcrireFichierSF(sf, "chat.txt", ORDINAIRE);
    EcrireFichierSF(sf, "lion.txt", ORDINAIRE); // Should be big
    
    printf("\n=== LS (SIMPLE) ===\n");
    Ls(sf, false);
    
    printf("\n=== LS (DETAIL) ===\n");
    Ls(sf, true);
    
    printf("\n=== AFFICHAGE COMPLET SF ===\n");
    AfficherSF(sf);
    
    printf("\n=== SAUVEGARDE ===\n");
    SauvegarderSF(sf, "backup.dat");
    
    printf("\n=== DESTRUCTION SF MEMOIRE ===\n");
    DetruireSF(&sf);
    
    printf("\n=== CHARGEMENT SF ===\n");
    if (ChargerSF(&sf, "backup.dat") == 0) {
        printf("Chargement reussi.\n");
        printf("\n=== LS APRES CHARGEMENT ===\n");
        Ls(sf, true);
        DetruireSF(&sf);
    } else {
        fprintf(stderr, "Erreur chargement\n");
    }
    
    return 0;
}