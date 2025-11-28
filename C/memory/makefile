# Nom du compilateur C
CC = gcc
# Options de compilation (standard C99, affichage des warnings)
CFLAGS = -std=c99 -Wall

# Liste des fichiers sources simplifiés (maintenant jusqu'à ex8.c)
PTR_SOURCES = ex1.c ex2.c ex3.c ex4.c ex5.c ex6.c ex7.c ex8.c

# Liste des exécutables (les noms explicites pour l'exécution)
PTR_EXECUTABLES = ptr_ex1 ptr_ex2 ptr_ex3 ptr_ex4 ptr_ex5 ptr_ex6 ptr_ex7 ptr_ex8

# ----------------------------------------------------------------------
# Règle par défaut : 'make'
# Compile tous les exécutables
# ----------------------------------------------------------------------
.PHONY: all
all: $(PTR_EXECUTABLES)

# Règles spécifiques pour compiler chaque exécutable à partir des sources simplifiées
# exN.c -> ptr_exN
ptr_ex1: ex1.c
	$(CC) $(CFLAGS) $< -o $@
ptr_ex2: ex2.c
	$(CC) $(CFLAGS) $< -o $@
ptr_ex3: ex3.c
	$(CC) $(CFLAGS) $< -o $@
ptr_ex4: ex4.c
	$(CC) $(CFLAGS) $< -o $@
ptr_ex5: ex5.c
	$(CC) $(CFLAGS) $< -o $@
ptr_ex6: ex6.c
	$(CC) $(CFLAGS) $< -o $@
ptr_ex7: ex7.c
	$(CC) $(CFLAGS) $< -o $@
ptr_ex8: ex8.c
	$(CC) $(CFLAGS) $< -o $@

# ----------------------------------------------------------------------
# Règles de Nettoyage : 'make clean'
# Supprime tous les exécutables générés
# ----------------------------------------------------------------------
.PHONY: clean
clean:
	@echo "Nettoyage des exécutables des exercices Pointeurs..."
	rm -f $(PTR_EXECUTABLES)

# ----------------------------------------------------------------------
# Règles d'Exécution : Ex: 'make run_ptr_exN'
# Lance l'exécutable correspondant
# ----------------------------------------------------------------------
.PHONY: run_ptr_ex1 run_ptr_ex2 run_ptr_ex3 run_ptr_ex4 run_ptr_ex5 run_ptr_ex6 run_ptr_ex7 run_ptr_ex8

run_ptr_ex1: ptr_ex1
	@echo "--- Exécution Exercice 1: Pointeur/Structure simple (ex1.c) ---"
	./ptr_ex1
run_ptr_ex2: ptr_ex2
	@echo "--- Exécution Exercice 2: Allocation dynamique d'une structure (ex2.c) ---"
	./ptr_ex2
run_ptr_ex3: ptr_ex3
	@echo "--- Exécution Exercice 3: Tableau dynamique de structures (ex3.c) ---"
	./ptr_ex3
run_ptr_ex4: ptr_ex4
	@echo "--- Exécution Exercice 4: Liste chaînée - Ajout en tête (ex4.c) ---"
	./ptr_ex4
run_ptr_ex5: ptr_ex5
	@echo "--- Exécution Exercice 5: Liste chaînée - Ajout en fin (ex5.c) ---"
	./ptr_ex5
run_ptr_ex6: ptr_ex6
	@echo "--- Exécution Exercice 6: Liste chaînée - Insertion en milieu (ex6.c) ---"
	./ptr_ex6
run_ptr_ex7: ptr_ex7
	@echo "--- Exécution Exercice 7: Structure de données File (Queue) (ex7.c) ---"
	./ptr_ex7
run_ptr_ex8: ptr_ex8
	@echo "--- Exécution Exercice 8: Structure de données Pile (Stack) (ex8.c) ---"
	./ptr_ex8
	
# ----------------------------------------------------------------------
# Règle pour lancer TOUS les exercices Pointeur/Struct/Malloc en séquence
# ----------------------------------------------------------------------
.PHONY: run_all
run_all: run_ptr_ex1 run_ptr_ex2 run_ptr_ex3 run_ptr_ex4 run_ptr_ex5 run_ptr_ex6 run_ptr_ex7 run_ptr_ex8
	@echo "Tous les 8 exercices Pointeur/Struct/Malloc ont été exécutés."