**Exercice 1 : Pointeur et Structure Simple**

Objectif : Définir une structure Point (contenant x et y entiers).

Déclarer une variable de type Point et un pointeur vers cette structure.

Initialiser la structure, puis utiliser le pointeur pour afficher ses membres via l'opérateur flèche (->).



**Exercice 2 : Allocation Dynamique pour une Structure**

Objectif : Allouer dynamiquement (avec malloc) l'espace mémoire nécessaire pour une seule variable de type Point (définie dans l'Ex. 1). Initialiser ses membres, l'afficher, et surtout, libérer la mémoire allouée (avec free) pour éviter les fuites de mémoire.



Contrainte : Gérer l'échec possible de malloc.



**Exercice 3 : Tableau Dynamique de Structures**

Objectif : Demander à l'utilisateur le nombre de points N qu'il souhaite stocker. Allouer dynamiquement un tableau de N structures Point. Remplir ce tableau avec des coordonnées basées sur leur indice (e.g., Point 0 = (0, 0), Point 1 = (1, 1), etc.). Afficher ensuite tous les points.



Contrainte : Utiliser la notation de tableau p\_array\[i] sur le pointeur alloué.



**Exercice 4 : Construction d'une Liste Chaînée**

Objectif : Définir une structure Node pour une liste chaînée simple (contenant un entier data et un pointeur next vers le prochain Node). Écrire une fonction add\_front qui alloue dynamiquement un nouveau nœud et l'insère au début de la liste.



Contrainte : La fonction add\_front doit prendre un pointeur vers le pointeur de tête de la liste (Node \*\*head\_ref) pour pouvoir modifier la tête.



Exercices Avancés : Listes Chaînées, Piles et Files



Ces exercices continuent l'exploration des pointeurs, de l'allocation dynamique (malloc/free) et des structures de données dérivées à partir d'une liste chaînée.



**Exercice 5: Liste Chaînée - Ajout en Fin (add\_back)**



Fichier Source: ex5.c

Objectif: Implémenter la fonction add\_back(Node \*\*head\_ref, int new\_data).

Cette fonction doit:



Allouer dynamiquement un nouveau nœud.



Si la liste est vide, faire du nouveau nœud la tête.



Sinon, parcourir la liste (while (last->next != NULL)) jusqu'au dernier élément.



Attacher le nouveau nœud à la fin de la liste.

Complexité: O(N) dans le pire des cas (parcours complet).



**Exercice 6: Liste Chaînée - Insertion en Milieu (insert\_after)**



Fichier Source: ex6.c

Objectif: Implémenter la fonction insert\_after(Node \*prev\_node, int new\_data).

Cette fonction doit:



Vérifier si le nœud précédent (prev\_node) est valide (non NULL).



Allouer dynamiquement le nouveau nœud.



Effectuer les deux étapes cruciales de l'insertion médiane:

a) Le champ next du nouveau nœud doit pointer vers l'élément qui était après prev\_node.

b) Le champ next de prev\_node doit pointer vers le nouveau nœud.

Complexité: O(1) (si le nœud précédent est déjà connu).



**Exercice 7: Structure de Données File (Queue)**



Fichier Source: ex7.c

Objectif: Implémenter la structure de données File (Queue), qui suit le principe FIFO (First In, First Out). La File doit être implémentée en utilisant une liste chaînée avec des pointeurs vers le front (tête) et le rear (queue) pour garantir des opérations O(1).

Fonctions à implémenter:



create\_queue(): Allocation de la structure Queue.



enqueue(): Ajout en fin de liste (au rear).



dequeue(): Suppression en tête de liste (au front).



print\_queue(): Affichage des éléments.



**Exercice 8: Structure de Données Pile (Stack)**



Fichier Source: ex8.c

Objectif: Implémenter la structure de données Pile (Stack), qui suit le principe LIFO (Last In, First Out). La Pile doit être implémentée en utilisant une liste chaînée où toutes les opérations se font uniquement au niveau du top (sommet) de la liste.

Fonctions à implémenter:



create\_stack(): Allocation de la structure Stack.



push(): Ajout au sommet de la pile (en tête de liste).



pop(): Suppression du sommet de la pile (en tête de liste).



print\_stack(): Affichage des éléments.

Complexité: Les opérations push et pop doivent être O(1).



