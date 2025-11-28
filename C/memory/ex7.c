#include <stdio.h>
#include <stdlib.h>

// Définition de la structure du Nœud
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Définition de la structure de la File (pour maintenir la tête ET la queue)
typedef struct Queue {
    Node *front; // Tête de la file (sortie)
    Node *rear;  // Queue de la file (entrée)
} Queue;

// 1. Création et initialisation d'une nouvelle File
Queue *create_queue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL) {
        fprintf(stderr, "Erreur d'allocation pour la File.\n");
        return NULL;
    }
    q->front = q->rear = NULL;
    return q;
}

// 2. Ajouter un élément à la File (enqueue - ajouté à la queue/rear)
void enqueue(Queue *q, int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        fprintf(stderr, "Erreur d'allocation pour le Nœud.\n");
        return;
    }
    temp->data = data;
    temp->next = NULL;

    // Si la file est vide, le nouveau nœud est à la fois la tête et la queue
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    // Le nouveau nœud devient le 'next' de l'ancienne queue
    q->rear->next = temp;
    // Mise à jour de la queue
    q->rear = temp;
}

// 3. Retirer un élément de la File (dequeue - retiré de la tête/front)
int dequeue(Queue *q) {
    if (q->front == NULL) {
        printf("Erreur: File vide.\n");
        return -1;
    }
    
    // Sauvegarder l'ancienne tête
    Node *temp = q->front;
    int data = temp->data;

    // Déplacer la tête au nœud suivant
    q->front = q->front->next;

    // Si la tête devient NULL, la file est vide, la queue doit aussi être NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    return data;
}

// 4. Afficher la File
void print_queue(Queue *q) {
    Node *temp = q->front;
    printf("Queue (FIFO): Front ");
    while (temp != NULL) {
        printf("<- [%d] ", temp->data);
        temp = temp->next;
    }
    printf("<- Rear\n");
}

int main(void) {
    printf("--- Exercice 7: Implémentation de la File (Queue) ---\n");
    Queue *my_queue = create_queue();

    enqueue(my_queue, 100);
    enqueue(my_queue, 200);
    enqueue(my_queue, 300);

    print_queue(my_queue); // 100 <- 200 <- 300

    printf("Dequeue: %d\n", dequeue(my_queue)); // Retrait de 100
    printf("Dequeue: %d\n", dequeue(my_queue)); // Retrait de 200
    
    enqueue(my_queue, 400); // Ajout de 400

    print_queue(my_queue); // 300 <- 400

    // Libérer les nœuds restants et la structure Queue elle-même
    free_list(my_queue->front);
    free(my_queue);

    return 0;
}