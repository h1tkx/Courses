#include <stdio.h>
#include <stdlib.h>

// Définition de la structure du Nœud
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Définition de la structure de la Pile (seulement besoin de la tête)
typedef struct Stack {
    Node *top; // Sommet de la pile
} Stack;

// 1. Création et initialisation d'une nouvelle Pile
Stack *create_stack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s == NULL) {
        fprintf(stderr, "Erreur d'allocation pour la Pile.\n");
        return NULL;
    }
    s->top = NULL;
    return s;
}

// 2. Ajouter un élément à la Pile (push - ajouté au sommet)
// Equivalent à add_front
void push(Stack *s, int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        fprintf(stderr, "Erreur d'allocation pour le Nœud.\n");
        return;
    }
    temp->data = data;
    temp->next = s->top; // Le nouveau nœud pointe vers l'ancien sommet
    s->top = temp;       // Le nouveau nœud devient le sommet
}

// 3. Retirer un élément de la Pile (pop - retiré du sommet)
// Equivalent à suppression en tête
int pop(Stack *s) {
    if (s->top == NULL) {
        printf("Erreur: Pile vide.\n");
        return -1;
    }

    Node *temp = s->top;
    int data = temp->data;

    // Le sommet est déplacé vers le nœud suivant
    s->top = s->top->next;

    free(temp);
    return data;
}

// 4. Afficher la Pile
void print_stack(Stack *s) {
    Node *temp = s->top;
    printf("Stack (LIFO): Top ");
    while (temp != NULL) {
        printf("-> [%d] ", temp->data);
        temp = temp->next;
    }
    printf("-> [Bottom]\n");
}

int main(void) {
    printf("--- Exercice 8: Implémentation de la Pile (Stack) ---\n");
    Stack *my_stack = create_stack();

    push(my_stack, 10);
    push(my_stack, 20);
    push(my_stack, 30); // 30 est au sommet

    print_stack(my_stack); // Top -> 30 -> 20 -> 10 -> Bottom

    printf("Pop: %d\n", pop(my_stack)); // Retrait de 30
    printf("Pop: %d\n", pop(my_stack)); // Retrait de 20
    
    push(my_stack, 40); // 40 devient le nouveau sommet

    print_stack(my_stack); // Top -> 40 -> 10 -> Bottom

    // Libérer les nœuds restants et la structure Stack elle-même
    // Note: La fonction free_list doit être adaptée ou réécrite pour libérer la mémoire.
    // Utilisons un loop simple pour le nettoyage ici :
    while(my_stack->top != NULL) {
        pop(my_stack);
    }
    free(my_stack);

    return 0;
}