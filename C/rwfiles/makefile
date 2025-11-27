# Nom du compilateur C
CC = gcc
# Options de compilation (standard C99, affichage des warnings)
CFLAGS = -std=c99 -Wall

# Liste des fichiers sources (les 4 exercices .c)
SOURCES = ex1_write_text.c ex2_read_text.c ex3_binary_io.c ex4_random_access.c

# Liste des exécutables (remplacement de .c par un nom sans extension)
EXECUTABLES = ex1 ex2 ex3 ex4

# ----------------------------------------------------------------------
# Règle par défaut : 'make'
# Compile tous les exécutables
# ----------------------------------------------------------------------
.PHONY: all
all: $(EXECUTABLES)

# Règle générique pour la compilation de tous les exécutables
# $^ est la liste des dépendances (ex: ex1_write_text.c)
# $@ est la cible (ex: ex1)
$(EXECUTABLES): %: %.c
	$(CC) $(CFLAGS) $< -o $@

# ----------------------------------------------------------------------
# Règles de Nettoyage : 'make clean'
# Supprime tous les exécutables et les fichiers de données générés
# ----------------------------------------------------------------------
.PHONY: clean
clean:
	@echo "Cleaning up generated files..."
	# Supprime les exécutables
	rm -f $(EXECUTABLES)
	# Supprime les fichiers de données temporaires créés par les exercices
	rm -f info.txt numbers.dat

# ----------------------------------------------------------------------
# Règles d'Exécution : Ex: 'make run_ex1'
# Lance l'exécutable correspondant
# ----------------------------------------------------------------------
.PHONY: run_ex1 run_ex2 run_ex3 run_ex4

run_ex1: ex1
	@echo "--- Running Exercise 1 (ex1_write_text.c) ---"
	./ex1

run_ex2: ex2
	@echo "--- Running Exercise 2 (ex2_read_text.c) ---"
	./ex2

run_ex3: ex3
	@echo "--- Running Exercise 3 (ex3_binary_io.c) ---"
	./ex3

run_ex4: ex4
	@echo "--- Running Exercise 4 (ex4_random_access.c) ---"
	./ex4

# ----------------------------------------------------------------------
# Règle pour lancer TOUS les exercices en séquence
# ----------------------------------------------------------------------
.PHONY: run_all
run_all: run_ex1 run_ex2 run_ex3 run_ex4
	@echo "All exercises executed successfully."