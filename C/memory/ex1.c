#include <stdio.h>

// Définition de la structure Point
typedef struct {
    int x;
    int y;
} Point;

int main(void) {
    // 1. Déclaration et initialisation d'une variable Point
    Point p1 = {10, 20};
    
    // 2. Déclaration d'un pointeur vers la structure
    Point *ptr_p1;

    // 3. Le pointeur pointe vers la structure p1
    ptr_p1 = &p1;

    printf("--- Exercice 1: Pointeur et structure simple ---\n");
    
    // Affichage des membres via le pointeur (opérateur flèche ->)
    printf("Coordonnées de p1 (via pointeur):\n");
    printf("X = %d\n", ptr_p1->x);
    printf("Y = %d\n", ptr_p1->y);
    
    // Modification de la valeur via le pointeur
    ptr_p1->x = 50;
    printf("Nouvelle valeur de X = %d\n", p1.x); // Vérification que p1 est bien modifiée

    return 0;
}