#include <stdio.h>
#include <stdlib.h>
// add back of list

// Définition de la structure du Nœud de la liste
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Fonction pour ajouter un nouveau nœud à la fin de la liste
void add_back(Node **head_ref, int new_data) {
    // 1. Allouer le nouveau nœud
    Node *new_node = (Node *)malloc(sizeof(Node));
    Node *last = *head_ref; // Pointeur pour parcourir la liste

    if (new_node == NULL) {
        fprintf(stderr, "Erreur d'allocation pour le nouveau noeud.\n");
        return;
    }

    // 2. Remplir les données
    new_node->data = new_data;
    new_node->next = NULL; // Le nouveau nœud est toujours le dernier, donc son 'next' est NULL

    // 3. Cas spécial : si la liste est vide, le nouveau nœud est la tête
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // 4. Parcourir la liste jusqu'au dernier nœud
    while (last->next != NULL) {
        last = last->next;
    }

    // 5. Modifier le 'next' du dernier nœud pour qu'il pointe vers le nouveau nœud
    last->next = new_node;
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
        next = current->next;
        free(current);
        current = next;
    }
}

int main(void) {
    Node *head = NULL;

    printf("--- Exercice 5: Liste Chaînée - Ajout en Fin ---\n");

    // Ajout en tête (pour initialiser)
    add_back(&head, 10); // 10
    add_back(&head, 20); // 10 -> 20
    add_back(&head, 30); // 10 -> 20 -> 30

    printf("Liste après l'ajout en fin:\n");
    print_list(head);

    free_list(head);
    return 0;
}