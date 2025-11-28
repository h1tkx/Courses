#include <stdio.h>
#include <stdlib.h> // Pour malloc et free

// Définition de la structure Point (réutilisée)
typedef struct {
    int x;
    int y;
} Point;

int main(void) {
    // 1. Déclaration d'un pointeur qui recevra l'adresse allouée
    Point *p_dynamic;

    // 2. Allocation dynamique de la mémoire
    // On alloue la taille nécessaire pour une seule structure Point
    p_dynamic = (Point *)malloc(sizeof(Point)); 
    
    printf("--- Exercice 2: Allocation dynamique d'une structure ---\n");

    // 3. Vérification de l'allocation
    if (p_dynamic == NULL) {
        fprintf(stderr, "Erreur: Allocation mémoire échouée (malloc).\n");
        return 1;
    }

    // 4. Initialisation des membres via le pointeur
    p_dynamic->x = 100;
    p_dynamic->y = 300;

    // 5. Affichage des membres
    printf("Structure Point allouée dynamiquement:\n");
    printf("X = %d\n", p_dynamic->x);
    printf("Y = %d\n", p_dynamic->y);
    
    // 6. Libération de la mémoire
    free(p_dynamic);
    p_dynamic = NULL; // Bonne pratique: éviter les pointeurs sauvages (dangling pointers)
    
    printf("Mémoire libérée avec free().\n");

    return 0;
}