#include <stdio.h>
#include <stdlib.h> // Pour malloc et free

// 1. Définition de la structure du Nœud de la liste
typedef struct Node {
    int data;            // La donnée du nœud
    struct Node *next;   // Pointeur vers le nœud suivant
} Node;

// 2. Fonction pour ajouter un nouveau nœud au début de la liste
// Elle prend un POINTEUR VERS le pointeur de tête (Node **head_ref)
void add_front(Node **head_ref, int new_data) {
    // Allouer de l'espace pour le nouveau nœud
    Node *new_node = (Node *)malloc(sizeof(Node));

    // Vérification de l'allocation
    if (new_node == NULL) {
        fprintf(stderr, "Erreur d'allocation pour le nouveau noeud.\n");
        return;
    }

    // Remplir les données du nouveau nœud
    new_node->data = new_data;
    
    // Le 'next' du nouveau nœud pointe vers l'ancienne tête
    // *head_ref donne accès à la valeur du pointeur 'head' (l'ancienne tête)
    new_node->next = *head_ref;

    // Le pointeur de tête de la liste (*head_ref) devient le nouveau nœud
    *head_ref = new_node;
}

// Fonction pour afficher la liste
void print_list(Node *node) {
    while (node != NULL) {
        printf("-> [%d] ", node->data);
        node = node->next;
    }
    printf("-> [NULL]\n");
}

// Fonction pour libérer la mémoire de toute la liste
void free_list(Node *head) {
    Node *current = head;
    Node *next;
    
    while (current != NULL) {
        next = current->next; // Sauvegarder l'adresse du suivant
        free(current);        // Libérer le nœud courant
        current = next;       // Passer au suivant
    }
}

int main(void) {
    // Déclaration du pointeur de tête de la liste (initialement NULL)
    Node *head = NULL; 

    printf("--- Exercice 4: Liste Chaînée Simple (Pointeur vers Pointeur) ---\n");

    // Ajouter des éléments (les ajoute au début: 30 -> 20 -> 10)
    add_front(&head, 10); 
    add_front(&head, 20); 
    add_front(&head, 30); 
    
    printf("Liste après l'ajout de 3 nœuds:\n");
    print_list(head);

    // Libérer toute la mémoire
    free_list(head);
    head = NULL;
    printf("Liste vidée et mémoire libérée.\n");

    return 0;
}