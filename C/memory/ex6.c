#include <stdio.h>
#include <stdlib.h>

// Définition de la structure du Nœud de la liste
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Fonction pour ajouter un nouveau nœud APRES un nœud donné (prev_node)
void insert_after(Node *prev_node, int new_data) {
    // 1. Vérifier si le nœud précédent est NULL (impossible d'insérer)
    if (prev_node == NULL) {
        printf("Le nœud précédent ne peut pas être NULL.\n");
        return;
    }

    // 2. Allouer le nouveau nœud
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL) {
        fprintf(stderr, "Erreur d'allocation pour le nouveau noeud.\n");
        return;
    }

    // 3. Remplir les données
    new_node->data = new_data;

    // 4. Rendre le 'next' du nouveau nœud, le 'next' du nœud précédent
    new_node->next = prev_node->next;

    // 5. Rendre le nouveau nœud, le 'next' du nœud précédent
    prev_node->next = new_node;
}

// Fonction pour ajouter au début (réutilisée pour l'initialisation)
void add_front(Node **head_ref, int new_data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node) {
        new_node->data = new_data;
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
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

    printf("--- Exercice 6: Liste Chaînée - Insertion en Milieu ---\n");

    // Initialisation : Liste 10 -> 30 -> 40
    add_front(&head, 40);
    add_front(&head, 30);
    add_front(&head, 10);

    printf("Liste Initiale (avant insertion après 30):\n");
    print_list(head);

    // Trouver le nœud avec la donnée 30
    Node *node_30 = head->next; // (Dans cet exemple simple, c'est le deuxième nœud)

    // Insertion de 25 après le nœud '30'. La liste devient 10 -> 30 -> 25 -> 40
    insert_after(node_30, 25);

    printf("Liste Finale (après insertion de 25):\n");
    print_list(head);

    free_list(head);
    return 0;
}