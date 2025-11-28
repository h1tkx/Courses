#include <stdio.h>
#include <stdlib.h> // Pour malloc et free

// Définition de la structure Point (réutilisée)
typedef struct {
    int x;
    int y;
} Point;

int main(void) {
    int N; // Nombre de points
    Point *p_array; // Pointeur pour le début du tableau
    int i;

    printf("--- Exercice 3: Tableau dynamique de structures ---\n");
    printf("Combien de points souhaitez-vous stocker (N) ? ");
    
    // Lire le nombre de points
    if (scanf("%d", &N) != 1 || N <= 0) {
        fprintf(stderr, "Entrée invalide. Utilisation de N=3 par défaut.\n");
        N = 3;
    }

    // 1. Allocation dynamique du tableau de N structures Point
    // N * taille d'une seule structure
    p_array = (Point *)malloc(N * sizeof(Point)); 

    // 2. Vérification de l'allocation
    if (p_array == NULL) {
        fprintf(stderr, "Erreur: Allocation mémoire échouée.\n");
        return 1;
    }

    // 3. Remplissage du tableau
    printf("Remplissage du tableau...\n");
    for (i = 0; i < N; i++) {
        // Utilisation de la notation de tableau sur le pointeur
        p_array[i].x = i;
        p_array[i].y = i * 2;
    }
    
    // 4. Affichage du tableau
    printf("Affichage des %d points:\n", N);
    for (i = 0; i < N; i++) {
        printf("Point %d: (X=%d, Y=%d)\n", i, p_array[i].x, p_array[i].y);
    }

    // 5. Libération de la mémoire
    free(p_array);
    p_array = NULL;
    
    printf("Mémoire du tableau libérée.\n");

    return 0;
}