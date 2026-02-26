#include <stdio.h>
#include <stdlib.h>

/****************************************************************************/
/* SI VOUS SOUHAITEZ COMMENTER LE CORPS D'UNE FONCTION QUE VOUS AVEZ ÉCRIT, */
/* NE COMMENTEZ QUE CE CORPS EN LAISSANT L'EN-TÊTE DE LA FONCTION, LES      */
/* ACCOLADES ET L'ÉVENTUEL RETURN TELS QU'ILS ÉTAIENT INITIALEMENT          */
/****************************************************************************/

// ============================== EXERCICE 1 ============================== //
/* Indice de la dernière lettre majuscule (sans accent) contenue dans une chaîne 
 * de caractères
 * Paramètre :
 *    - ch : adresse du premier caractère de la chaîne de caractères
 * Valeur de retour :
 *    - indice, dans la chaîne de caractères, du dernier (le plus à droite) caractère 
 * qui est une lettre majuscule ou -1 si la chaîne de caractères ne contient aucune
 * majuscule 
 */
int IndiceDerniereMajuscule(const char *ch){
    int i =0;
    int LastM = -1;
    while(ch[i] != '\0'){
        if(ch[i]>= 'A' && ch[i]<= 'Z'){
            LastM = i;
        }
        i++;
    }
    return LastM;
}


// ============================== EXERCICE 2 ============================== //
/* Calcul de statistiques sur un tableau de prix : 
 *     - moyenne des prix strictement inférieurs à un prix de référence
 *     - nombre de prix strictement inférieurs à un prix de référence
 * Paramètres :
 *    - Prix : tableau de prix de type float
 *    - NbPrix : nombre de prix stockés dans le tableau Prix (>= 1)
 *    - Ref : prix de référence
 *    - pMoy : adresse de la moyenne des prix strictement inférieurs à Ref
 * Valeur de retour :
 *    - nombre de prix strictement inférieurs à Ref
 */
int PasCher(float Prix[], int NbPrix, float Ref, float *pMoy){
    int i ;
    float somme;
    int nbinf = 0;
    for(i=0;i<NbPrix;i++){
        if(Prix[i] < Ref){
            nbinf ++ ;
            somme += Prix[i];
        }
    }
    *pMoy = somme/nbinf;
    return nbinf;
}

// ============================== EXERCICE 3 ============================== //
/* Taille maximale d'une matrice */
#define NB_LIG_MAX 100
#define NB_COL_MAX 100

/* Calcul des plus grands éléments de chaque colonne d'une matrice de valeurs de type int
 * et du plus grand élément de toute la matrice
 * Paramètres :
 *    - Mat : matrice (tableau à deux dimensions) de valeurs de type int
 *    - NbLig : nombre de lignes de la matrice (>= 1)
 *    - NbCol : nombre de colonnes de la matrice (>= 1)
 *    - Max : tableau des maximums de chaque colonne de la matrice
 * Valeur de retour :
 *    - maximum de tous les éléments de la matrice
 */
int MaxCol(int Mat[NB_LIG_MAX][NB_COL_MAX], int NbLig, int NbCol, int Max[NB_COL_MAX]){
    int i;
    int j;
    int eMax;
    for(j=0;i<NbCol;j++){
        Max[j] = Mat[0][j];
        for(i=0;j<NbLig;j=i++){
            if(Mat[i][j] > Max[j]){
                Max[j] = Mat[i][j];
            }
            
            
        }
    }
    eMax= Max[0];
    for(int k =0;k<NbCol;k++){
        if(Max[k] > eMax){
            eMax = Max[k];
        }
    }
    return eMax;
}

// ============================== EXERCICE 4 ============================== //
/* Recherche d'un caractère dans une une chaîne de caractères
 * Paramètres :
 *    - c : caractère recherché
 *    - ch : adresse du premier caractère de la chaîne de caractères
 * Valeur de retour :
 *    - 1 si le caractère appartient à la chaîne, 0 sinon
 */ 
int Appartient(char c, const char *ch)
{
    for (int i = 0; ch[i] != '\0'; i++) {
        if (ch[i] == c) {
            return 1;
        }
    }
    return 0; // LIGNE À MODIFIER
}

/* Recopie d'une chaîne de caractères avec suppression de certains caractères
 * Par exemple, si la source est "bonjour", si les caractères à supprimer sont ceux
 * de la chaîne "joe", la destination devra être "bnur".
 * Paramètres :
 *    - Source : adresse du premier caractère de la chaîne de caractères source
 *    - ASupprimer : adresse du premier caractère de la chaîne de caractères contenant 
 *                   les caractères à supprimer
 *    - Destination : adresse du premier caractère de la chaîne de caractères destination
 * Valeur de retour :
 *    - nombre de caractères supprimés (3 dans l'exemple ci-dessus)
 */
int SupprimerCaracteres(const char *Source, const char *ASupprimer, char *Destination)
{
   int count = 0;
    int supprime = 0; // Variable pour garder une trace du nombre de caractères supprimés
    for (int i = 0; Source[i] != '\0'; i++) {
        if (!Appartient(Source[i], ASupprimer)) {
            Destination[count++] = Source[i];
        } else {
            supprime++; // Incrémenter le compteur de caractères supprimés
        }
    }
    Destination[count] = '\0';
    return supprime;
}


// ============================== EXERCICE 5 ============================== //
/* Calcul de la multiplication élément par élément de deux tableaux
 * Le tableau résultat doit être alloué dynamiquement
 * Paramètres :
 *    - Tab1 : adresse du premier élément du premier tableau
 *    - Tab2 : adresse du premier élément du second tableau
 *    - NbElts : nombre d'éléments dans chacun des deux tableaux
 * Valeur de retour :
 *    - adresse du tableau résultat alloué dynamiquement par la fonction ou NULL en cas
 *      de problème d'allocation mémoire
 */
double *MultTab(const double *Tab1, const double *Tab2, int NbElts)
{
    double *tab = malloc(NbElts * sizeof(double));
    if(tab==NULL){
      return NULL;
    }
    for(int i=0; i<NbElts; i++){
      tab[i]=Tab1[i]*Tab2[i];
    }
    tab[NbElts]='\0';
    return tab; // LIGNE À MODIFIER
}


// ============================== EXERCICE 6 ============================== //
/* Extraction de la seconde moitié d'un tableau d'entiers
 * Cette fonction doit délivrer en sortie un tableau qu'elle aura alloué dynamiquement et
 *  y ranger les éléments qui se trouvent dans la seconde moitié du tableau placé en 
 * entrée. Il s'agit donc des éléments d'indices NbElts/2, NbElts/2+1, NbElts/2+2... 
 * où NbElts est le nombre d'éléments du tableau placé en entrée.
 * On suppose que le nombre d'éléments du tableau placé en entrée est pair.
 * Paramètres :
 *    - Tab : tableau de int
 *    - NbElts : nombre pair d'éléments dans le tableau Tab
 *    - pRes : adresse du pointeur vers le premier élément du tableau résultat qui doit
 *             être alloué dynamiquement par la fonction
 * Valeur de retour :
 *    - Nombre d'éléments rangés dans le tableau résultat
 */
int ExtractionSecondeMoitie(int Tab[], int NbElts, int **pRes)
{
  int n=NbElts/2;
  *pRes = malloc(n*sizeof(int));
  if(*pRes==NULL){
    return 0;
  }
  for(int i=0; i<n; i++){
    (*pRes)[i]=Tab[n+i];
  }
  return n; // LIGNE À MODIFIER
}


// ============================== EXERCICE 7 ============================== //
/* Type structuré pour décrire un point du plan */
struct sPoint
{
  int Identifiant; // Identifiant du point
  float x;         // Abscisse du point
  float y;         // Ordonnée du point
};

// ============================== EXERCICE 7.1 ============================== //
/* Création d'un point par allocation dynamique de la mémoire
 * La structure sera allouée dynamiquement
 * Paramètres :
 *    - Id : identifiant du point créé
 *    - x : abscisse du point créé
 *    - y : ordonnée du point créé
 * Valeur de retour :
 *    - adresse du point créé ou NULL en cas de problème d'allocation mémoire
 */
struct sPoint *CreerPoint(int Id, float x, float y)
{
    struct sPoint *point = malloc(sizeof(struct sPoint));
    if(point == NULL){
      return NULL;
    }
    point -> Identifiant = Id;
    point -> x = x;
    point -> y = y;    
    return point; // LIGNE À MODIFIER
}

// ============================== EXERCICE 7.2 ============================== //
/* Récupération des informations sur un point
 * Cette fonction délivre en sortie les information sur un point dont l'adresse est 
 * passée en paramètre
 * Paramètres :
 *    - pPoint : adresse de l'article
 *    - pRef : adresse de la référence
 *    - pPx : adresse du prix
 *    - pQt : adresse de la quantité
 */
void InformationsPoint(struct sPoint *pPoint, int *pId, float *px, float *py)
{
    
    *pId = pPoint -> Identifiant;
    *px = pPoint -> x;
    *py = pPoint -> y;
}


// ==================== FONCTION D'AFFICHAGE UTILISÉE DANS MAIN ==================== //
/* Affichage des éléments d'un tableau de int
 * Paramètres :
 *    - Tab : tableau de int
 *    - NbElts : nombre d'éléments du tableau Tab
 */
void AffTabInt(int Tab[], int n)
{
  printf("[%d",Tab[0]);
  for (int i=1; i<n; i++)
    printf(", %d",Tab[i]);
  printf("]");
  fflush(stdout);
}


/**************************************************************************/
/* POUR TESTER CHAQUE EXERCICE, "DÉ-COMMENTEZ" LES LIGNES CORRESPONDANTES */
/**************************************************************************/

int main(void)
{
  
  /*{
    printf("*** TEST DE L'EXERCICE 1 ***\n");
    char ch1[] = "Ven NOv";
    char ch2[] = " 17 NOVE";
    char ch3[] = "novembre";
    printf("\"%s\" : %d attendu, %d obtenu\n", ch1, 5, IndiceDerniereMajuscule(ch1));
    printf("\"%s\" : %d attendu, %d obtenu\n", ch2, 7, IndiceDerniereMajuscule(ch2));
    printf("\"%s\" : %d attendu, %d obtenu\n", ch3, -1, IndiceDerniereMajuscule(ch3));
  }
  
  
  {
    printf("\n*** TEST DE L'EXERCICE 2 ***\n");
    float Prix[5] = {9.0, 15.9, 14.5, 8.0, 10.0};
    float Moy;
    int NbInf;
    float r;
    r=10.0;
    printf("Prix de référence égal à %f :\n",r);
    NbInf=PasCher(Prix, 5, r, &Moy);
    printf("\tValeurs attendues : %f %d\n", 8.5, 2);
    printf("\tValeurs obtenues  : %f %d\n", Moy, NbInf);
    r=8.0;
    printf("Prix de référence égal à %f :\n",r);
    NbInf=PasCher(Prix, 5, r, &Moy);
    printf("\tValeurs attendue : %d\n", 0);
    printf("\tValeurs obtenue  : %d\n", NbInf);
  }
  
  
  {
    printf("\n*** TEST DE L'EXERCICE 3 ***\n");
    int Matrice[NB_LIG_MAX][NB_COL_MAX] = {{7, 8}, {3, 9}, {5, 2}};
    int Max, MaxColonnes[2] = {-2023, -2023};
    Max=MaxCol(Matrice, 3, 2, MaxColonnes);
    printf("Valeurs attendues : [%d, %d] %d\n", 7, 9, 9);
    printf("Valeurs obtenues  : [%d, %d] %d\n", MaxColonnes[0], MaxColonnes[1], Max);
  }  
  
  
  {
    printf("\n*** TEST DE L'EXERCICE 4 ***\n");
    char asup[] = "joe";
    char ch1[] = "bonjour";
    char ch2[] = "chat";
    char ch[80]="";
    int NbSup;
    NbSup=SupprimerCaracteres(ch1,asup,ch);
    printf("\"%s\" : \"%s\" et %d attendus, \"%s\" et %d obtenus\n", ch1, "bnur", 3, ch, NbSup);
    NbSup=SupprimerCaracteres(ch2,asup,ch);
    printf("\"%s\" : \"%s\" et %d attendus, \"%s\" et %d obtenus\n", ch2, "chat", 0, ch, NbSup);
  }  
  
  
  {
    printf("\n*** TEST DE L'EXERCICE 5 ***\n");
    double t1[3]={10.5,3.2,4.0};
    double t2[3]={2.0,0.5,1.5};
    double *Res=NULL;
    Res=MultTab(t1,t2,3);
    if (Res==NULL)
      fprintf(stderr,"Problème dans la fonction MultTab.\n");
    else
    {
      printf("[21.0, 1.6, 6.0] attendu, [%.1f, %.1f, %.1f] obtenu\n",Res[0],Res[1],Res[2]);
      free(Res);
    }
  }
  
  
  {
    printf("\n*** TEST DE L'EXERCICE 6 ***\n");
    int t[8]={1,2,3,4,5,6,7,8};
    int *Res=NULL,n;
    n=ExtractionSecondeMoitie(t,8,&Res);
    if (Res==NULL)
      fprintf(stderr,"Problème dans la fonction ExtractionSecondeMoitie.\n");
    else
    {
      printf("[5, 6, 7, 8] attendu, ");
      fflush(stdout);
      AffTabInt(Res,n);
      printf(" obtenu\n");   
      free(Res);
    }
  }
  
  
  {
    printf("\n*** TEST DE L'EXERCICE 7 ***\n");
    struct sPoint *pPt;
    pPt=CreerPoint(17,1.5,2.3);
    int Id=0;
    float x=0.0,y=0.0;
    InformationsPoint(pPt,&Id,&x,&y);
    printf("{%d, %.2f, %.2f} attendu, {%d, %.2f, %.2f} obtenu\n",17,1.5,2.3,Id,x,y);
    free(pPt);
  }*/
  
  return 0;
}
cc32.c
12 KB