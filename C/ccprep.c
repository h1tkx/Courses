#include <stdio.h>
#include <stdlib.h>

#define NB_LIG_MAX 100
#define NB_COL_MAX 100

// ============================== EXERCICE 1 ============================== //
// Retourne l'indice de la dernière majuscule, ou -1 si aucune.
int IndiceDerniereMajuscule(const char *ch){
    int indice_derniere_majuscule = -1;
    int i = 0;

    while (ch[i] != '\0') {
        if (ch[i] >= 'A' && ch[i] <= 'Z') {
            indice_derniere_majuscule = i;
        }
        i++;
    }
    return indice_derniere_majuscule;
}

// ============================== EXERCICE 2 ============================== //
// Renvoie le nombre de prix < Ref et écrit la moyenne dans *pMoy
int PasCher(float Prix[], int NbPrix, float Ref, float *pMoy){
    float somme = 0.0;
    int count = 0;

    for (int i = 0; i < NbPrix; i++){
        if (Prix[i] < Ref){
            somme += Prix[i];
            count++; 
        }
    }

    if (count > 0)
        *pMoy = somme / count;
    else
        *pMoy = 0;   // selon les consignes, on peut mettre 0

    return count;
}

// ============================== EXERCICE 3 ============================== //
// Max de chaque colonne + max global
int MaxCol(int Mat[NB_LIG_MAX][NB_COL_MAX], int NbLig, int NbCol, int Max[]){
    int max_global = Mat[0][0];

    for (int col = 0; col < NbCol; col++){
        Max[col] = Mat[0][col];  // init

        for (int lig = 1; lig < NbLig; lig++){
            if (Mat[lig][col] > Max[col])
                Max[col] = Mat[lig][col];

            if (Mat[lig][col] > max_global)
                max_global = Mat[lig][col];
        }
    }

    return max_global;
}

int main(void){
    // Test EX1
    char t1[] = "SalMa";
    char t2[] = "doRrA";

    printf("Dernière majuscule dans %s = %d\n", t1, IndiceDerniereMajuscule(t1));
    printf("Dernière majuscule dans %s = %d\n", t2, IndiceDerniereMajuscule(t2));

    // Test EX2
    float Prix[5] = {8.4, 9.6, 4.2, 3.3, 7.0};
    float Ref = 5.0;
    float moy;

    int nb = PasCher(Prix, 5, Ref, &moy);

    printf("Nb prix < %.1f : %d, moyenne = %.2f\n", Ref, nb, moy);

    // Test EX3
    int Mat[NB_LIG_MAX][NB_COL_MAX] = {
        {1, 5, 8},
        {7, 2, 3},
        {4, 9, 6}
    };

    int Max[NB_COL_MAX];
    int max_global = MaxCol(Mat, 3, 3, Max);

    printf("Max colonnes : ");
    for(int i = 0; i < 3; i++) printf("%d ", Max[i]);
    printf("\nMax global = %d\n", max_global);

    return 0;
}
