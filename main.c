/* REALISE PAR MESKALI REDA */



#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#define MAX	30




int fibonnaci(int n) /* FIBONNACI RENVOIE LE NOMBRE N DE LA SERIE DE FIBONNACI  O(n)*/
{
    int u1,u2,u0;
    u0 = 0;
    u1 = 1;
    int i =1;
    while(i<n)
    {
        u2 = u1+u0;
        u0 = u1;
        u1 = u2;
        i++;
    }
    return u2;
}
int fibonnaciRec(int n) /* FIBONNACI RECURSIF RENVOIE LE NOMBRE N DE LA SERIE DE FIBONNACI O(2^n)*/
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
        return fibonnaciRec(n-1)+fibonnaciRec(n-2);
    }
}
int factorielRec(int n) /* CALCUL DU FACTORIEL RECURSIF O(n) */
{
    if (n==0)
    {
        return 1;
    }
    else
    {
        return n*factorielRec(n-1);
    }
}
int factoriel(int n) /* CALCUL DU FACTORIEL O(n) */
{
    int i =1;
    int j;
    while(n>1)
    {

        i = i*n;
        n--;
    }
    return i;
}
void ObtenirChiffres(int n)  /* DONNE TOUS LES CHIFFRES QUI COMPOSE UN NOMBRE O(n) n le nbr de chiffres*/
{

     int reste ;
     while (n != 0)
     {
         reste = n % 10;
         n = n/10;
         printf(" %d ", reste);

     }
}
int rechercheDichoRec(int x, int t[], int debut, int fin)   /*Fonction de recherche dichotomique RECURSIF DANS UN TABLEAU TRIE  O(lg(n))*/
{
     int milieu = (debut+fin)/2;

     if(debut > fin) return (-1);
     if(x == t[milieu]) return milieu;
     if (x < t[milieu])
	 return rechercheDichoRec(x, t, debut, milieu-1);
     return rechercheDichoRec(x, t, milieu+1, fin);
}
int rechercheDicho(int tab[], int nbVal, int val)  /*  Fonction de recherche dichotomique DANS UN TABLEAU TRIE O(lg(n)) */
{

  /* déclaration des variables locales à la fonction */
  int trouve;  //vaut faux tant que la valeur "val" n'aura pas été trouvée
  int id;  //indice de début
  int ifin;  //indice de fin
  int im;  //indice de "milieu"

  /* initialisation de ces variables avant la boucle de recherche */
  trouve = 0;  //la valeur n'a pas encore été trouvée
  id = 0;  //intervalle de recherche compris entre 0...
  ifin = nbVal;  //...et nbVal

  /* boucle de recherche */
  while(!trouve && ((ifin - id) > 1)){

    im = (id + ifin)/2;  //on détermine l'indice de milieu

    trouve = (tab[im] == val);  //on regarde si la valeur recherchée est à cet indice

    if(tab[im] > val) ifin = im;  //si la valeur qui est à la case "im" est supérieure à la valeur recherchée, l'indice de fin "ifin" << devient >> l'indice de milieu, ainsi l'intervalle de recherche est restreint lors du prochain tour de boucle
    else id = im;  //sinon l'indice de début << devient >> l'indice de milieu et l'intervalle est de la même façon restreint
  }

  /* test conditionnant la valeur que la fonction va renvoyer */
  if(tab[id] == val) return(id);  //si on a trouvé la bonne valeur, on retourne l'indice
  else return(0);  //sinon on retourne -1

}
int RechLin(int tab[],int taille, int valeur)   /* RECHERCHE NAIF O(n) */
{
    int i =0;
    for(i=0;i<taille;i++)
    {
        if(tab[i]==valeur)
        {
            return 1;
        }
    }
    return 0;
}
int pgcdRec(int a,int b) /* PLUS GRAND DIVISEUR COMMUN RECURSIF O(lg(n)) */
{
    int r;
    if(b ==0)
    {
        return a;
    }
    else
    {
        r = a%b;
        a = b;
        b = r;
        return pgcdRec(a,b);
    }
}
int pgcd(int a, int b) /* PLUS GRAND DIVISEUR COMMUN ITERATIF O(lg(n)) */
{
  int r;
  while (b != 0)
    {
      r = a%b;
      a = b;
      b = r;
    }
  return a;
}
int PuissanceLogRec(int x,int n) /* CALCUL DE PUISSANCE RECURSIF LOGARITHMIQUE PERFORMANT  O(lg(n)) */
{
    if(n==0)
    {
        return 1;
    }
    if(n==1)
    {
        return x;
    }
    if(n%2==0)
    {
        return PuissanceLogRec(x*x,n/2);
    }
    else
    {
        return PuissanceLogRec(x,n-1)*x;
    }
}
int PuissanceLog(int x,int n) /* CALCUL DE PUISSANCE LOGARITHMIQUE PERFORMANT  O(lg(n)) */
{
    int r = 1;
    while(n!=0)
    {
        if(n%2==0)
        {
            x = x*x;
            n=n/2;
        }
        else
        {
            r = r*x;
            n=n-1;
        }
    }
    return r;
}
int puissanceRec(int x, int n) /* CALCUL RECURSIF NAIF DE PUISSANCE O(n) */
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return x*puissanceRec(x,n-1);
    }
}
int puissance(int x , int n) /* CALCUL ITERATIF NAIF DE PUISSANCE O(n)  */
{
    int r= 1;
    int i =0;
    for(i=0;i<n;i++)
    {
        r=r*x;
    }
    return r;
}
int partition(int tableau[], int deb, int fin) /* RECHERCHE DU PIVOT O(n)  */
{
    int compt=deb;
	    int pivot=tableau[deb];
    int i;

    for(i=deb+1;i<=fin;i++)
        {
        if(tableau[i]<pivot)
            {
            compt++;
            echanger(tableau,compt,i);
            }
        }
    echanger(tableau,compt,deb);
    return(compt);
}
void tri_rapide_bis(int tableau[],int debut,int fin) /* TRI RAPIDE RECURSIF O(lg(n)) */
{
    if(debut<fin)
        {
            int pivot=partition(tableau,debut,fin);
            tri_rapide_bis(tableau,debut,pivot-1);
            tri_rapide_bis(tableau,pivot+1,fin);
        }
}
void tri_rapide(int tableau[],int longueur) /* FONCTION D'APPEL !!! */
{
    tri_rapide_bis(tableau,0,longueur-1);
}
void tri_selection(int tab[], int taille) /* TRI PAR SELECTION SIMPLE  O(n²)*/
{
    int indice_max;

    // à chaque tour de boucle, on va déplacer le plus grand élément
    // vers la fin du tableau, on diminue donc à chaque fois sa taille
    // car le dernier élément est obligatoirement correctement
    // placé (et n'a donc plus besoin d'être parcouru/déplacé)

    for(; taille > 1 ; taille--) // tant qu'il reste des éléments non triés
    {
        indice_max = max(tab, taille);

        echanger(tab, taille-1, indice_max); // on échange le dernier élément avec le plus grand
    }
}
int max(int tab[], int taille)/* TROUVE LE MAX D'UN TABLEAU O(n) */
{
    // on considère que le plus grand élément est le premier
    int i=0, indice_max=0;

    while(i < taille)
    {
        if(tab[i] > tab[indice_max])
            indice_max = i;
        i++;
    }

    return indice_max;
}
void echanger(int tab[], int x, int y) /* PERUMUTE DANS TAB L'ELEMENT X AVEC Y */
{
    int tmp;

    tmp = tab[x];
    tab[x] = tab[y];
    tab[y] = tmp;
}
void fusion(int tableau[],int deb1,int fin1,int fin2) /* DIVISION DU TABLEAU O(n) */
{
    int *table1;
    int deb2=fin1+1;
    int compt1=deb1;
    int compt2=deb2;
    int i;

    table1=malloc((fin1-deb1+1)*sizeof(int));

    //on recopie les éléments du début du tableau
    for(i=deb1;i<=fin1;i++)
        {
        table1[i-deb1]=tableau[i];
        }

    for(i=deb1;i<=fin2;i++)
        {
        if (compt1==deb2) //c'est que tous les éléments du premier tableau ont été utilisés
            {
            break; //tous les éléments ont donc été classés
            }
        else if (compt2==(fin2+1)) //c'est que tous les éléments du second tableau ont été utilisés
            {
            tableau[i]=table1[compt1-deb1]; //on ajoute les éléments restants du premier tableau
            compt1++;
            }
        else if (table1[compt1-deb1]<tableau[compt2])
            {
            tableau[i]=table1[compt1-deb1]; //on ajoute un élément du premier tableau
            compt1++;
            }
        else
            {
            tableau[i]=tableau[compt2]; //on ajoute un élément du second tableau
            compt2++;
            }
        }
    free(table1);
}
void tri_fusion_bis(int tableau[],int deb,int fin)  /* CONQUETE  o(log(n)) */
{
    if (deb!=fin)
    {
        int milieu=(fin+deb)/2;
        tri_fusion_bis(tableau,deb,milieu);
        tri_fusion_bis(tableau,milieu+1,fin);
        fusion(tableau,deb,milieu,fin);
    }
}
void tri_fusion(int tableau[],int longueur) /* FONCTION D'APPEL */
 {
    if (longueur>0)
    {
        tri_fusion_bis(tableau,0,longueur-1);
    }
 }
void tri_bulles(int tab[],int taille) /* BULLES O(n²) */
{
    int ordre = 0;
    int i,tmp;

    while(ordre==0)
    {

        ordre = 1;
        for(i=0 ; i < taille-1 ; i++)
        {
            if(tab[i] > tab[i+1])
            {
                tmp = tab[i];
                tab[i]= tab[i+1];
                tab[i+1] = tmp;
               ordre = 0;
            }
        }
        taille--;
    }
}
void tri_insertion(int tab[], int taille) /* INSERTION  O(n²) */
{
   int i, j;
   for (i = 1; i < taille; ++i) {
       int elem = tab[i];
       for (j = i; j > 0 && tab[j-1] > elem; j--)
           tab[j] = tab[j-1];
       tab[j] = elem;
   }
}
typedef struct element{                /* STRUCTURE ELEMNTAIRE DE LA LISTE  */
    int val;
    struct element *next;
}element;
typedef struct file {                   /* STRUCTURE ELEMNTAIRE DE LA File  */
	int tab[MAX];
	int id;
	int NbElts;
} file;
typedef struct pile{                      /* STRUCTURE ELEMNTAIRE DE LA Pile  */
    int sommet;
    int tab[30];
}pile;
pile * creerPile()   /* CREE LA PILE O(1) */
{
    int i;
    pile *l=malloc(sizeof(pile));      /*creation d’une pile vide O(1) */
    l->sommet=-1;

    return l;
}
int pileVide(pile  *pp)  /* VERIFIE SI LA PILE EST VIDE O(1) */
{
    return (pp->sommet==-1); /* renvoie vrai si la pile pointee par pp est vide O(1) */
}
pile * empile(int e, pile * pp)     /*empile e sur la pile  O(1) */
{
    pp->sommet++;
    int i = pp->sommet;
    pp->tab[i]=e;
    return pp;
}
pile * depile(pile * pp)  /* RETIRE LE DERNIER ELEMENT DE LA PILE O(1) */
{
    if(pileVide(pp))
    {
        printf("Pile est vide");
        return NULL;
    }
    else
    {
        pp->sommet=pp->sommet-1;
        return pp;
    }

}
int taillePile(pile *pp)  /* RENVOIE LA TAILLE DE LA PILE O(1) */
{
    return(pp->sommet+1);
}
void afficherPile(pile *pp)  /* AFFICHE LA PILE O(n) */
{
    int i;
    if(pileVide(pp))
    {
        printf(" PILE EST Vide ");
    }
    else
    {
        for(i=0;i<pp->sommet+1;i++)
        {
            printf("%d %c ",pp->tab[i],178);
        }
    }

}
void initialiserFile(file *file)  /* CREE LA FILE O(1) */
{
	file->id = 0;
	file->NbElts = 0;
}
void enfiler(file *file, int obj) /* AJOUTE UN NOUVEAU ELEMENT AU DEBUT DE LA FILE O(1) */
{
	if (filepleine(*file)) {
		printf("Erreur, file pleine\n");
	}
	else {
		int indice;
		indice = (file->id + file->NbElts) % MAX;
		file->tab[indice] = obj;
		file->NbElts++;
	}
}
void defiler(file *file, int *obj)  /* SUPPRIME LE DERNIER ELEMENT DE LA FILE O(1) */
{
	if (filevide(*file)) {
		printf("Erreur, file vide\n");
        }
        else {
		*obj = file->tab[file->id];
		file->id++;
		if (file->id == MAX) file->id =0;
		file->NbElts--;
	}
}
int filevide(file file)   /* VERIFIE SI LA LISTE EST VIDE O(1) */
{
	return (file.NbElts == 0);
}
int filepleine(file file)  /* VERIFIE SI LA LISTE EST PLEINE O(1) */
{
	return file.NbElts == MAX;
}
void afficherFile(file file)  /* AFFICHAGE D'UNE FILE O(n) */
{
	int i, indice;
	if (filevide(file)) printf("La file est vide\n");
	else {
		if (filepleine(file)) printf("La file est pleine\n");
		printf("id = %d, NbElts = %d\n", file.id, file.NbElts);
		for (i=0; i<file.NbElts; i++) {
			indice = (file.id + i) % MAX;
			printf("file[%d]=%d ", i, file.tab[indice]);
		}
		printf("\n");
	}
}
void afficher(element *liste) /* AFFICHAGE D'UNE LISTE  O(n) */
{
    printf("\n\n");
    element * x=liste;
    if(x==NULL)
    {
        printf("\nListe vide \n");
    }
    else
    {
         while(x!=NULL)
            {
                printf("%d %c ",x->val,26);
                x=x->next;
            }
            printf("NULL");
    }
    printf("\n\n");
}
int longeur(element * liste) /*LONGEUR DE LA LISTE O(n) */
{
    int i=0;
    element * x = liste;
    while(x->next != NULL)
    {
        i++;
        x = x->next;
    }
    return i+1;
}
int estVide(element *liste) /* Savoir si la liste est vide O(1)*/
{
    return(liste == NULL);
}
element* inserer_entete(element *liste,int valeur) /* pour inserer un element en entete O(1)*/
{

    element *x = malloc(sizeof(element));
    x->val = valeur;
    x->next = liste;
    return x;
}
element* inserer_enqueue(element *liste,int valeur) /* pour inserer un element a la fin O(n) */
{
    element * x = malloc(sizeof(element));
    x->val = valeur;
    x->next = NULL;
    if(estVide(liste))
    {
        x->next = liste;
        return x;
    }
    else
    {
        element *y;
        y=liste;
        while(y->next!=NULL)
        {
            y=y->next;
        }
        y->next = x;
        return liste;
    }


}
element* InsererParIndice(element* liste,int valeur,int indice) /* chercher l'indice puis inserer O(indice) */
{
     if(indice<0)
     {
         printf("\n\n Indice negatif !! \n");
         return liste;
     }
     else if(estVide(liste))
     {
         element *y=malloc(sizeof(element));
         y->val = valeur;
         y->next = NULL;
         liste =  y;
         return liste;
     }
     else
     {
         element *y=malloc(sizeof(element));
         y->val = valeur;
         y->next = NULL;
         element *x;
         x =liste;
         indice --;
         while(indice--)
         {
             x=x->next;
             if(x == NULL)
             {
                 printf("L'indice depasse la taille");
                 return liste;
             }

         }
         y->next = x->next;
         x->next = y;
         return liste;

     }
}
int RechercherParValeur(element *liste,int valeur) /* renvoie l'indice de la valeur cherché O(n)*/
{
    int i=0;
    if(estVide(liste))
    {
        printf("\n Liste vides donc valeur non trouvé");
        return 0;
    }
    else
    {
        element *x;
       x=liste;
       while((x!=NULL)&&(x->val!=valeur))
       {
           x=x->next;
           i++;
       }
       if(x==NULL)
       {
           printf("L'element ne se trouve pas dans votre liste");
           return NULL;
       }

        printf("\n l'element %d se trouve a %d\n",valeur,i);
       return i;
    }

}
int RechercherParIndice(element *liste,int indice) /* Renvoie la valeur a l'indice recherché O(n) */
{
    if(indice<0)
    {
        printf("indice negatif erreur");
        return NULL;
    }
    else if(estVide(liste))
    {
        printf("Liste est vide");
        return NULL;
    }
    else
    {
        element *x;
        x = liste;
        while(indice--)
        {
            x=x->next;
            if(x==NULL)
            {
                printf("\n\n Indice depasse la taille de la liste \n\n");
                return NULL;
            }
        }
        printf("l'element avec l'indice %d contient la valeur %d",indice,x->val);
        return x->val;
    }
}
element* SupprimerEnTete(element *liste) /* supprime la tete O(1)*/
{
    if(estVide(liste))
    {
        return liste;
    }
    else
    {
        element * tmp = liste;
        liste=liste->next;
        free(tmp);
        return liste;
    }
}
element* SupprimerEnFin(element *liste) /* supprimer le dernier element O(n) */
{
    if(estVide(liste))
    {
        return liste;
    }
    else if(liste->next==NULL)
    {
        free(liste);
        return NULL;
    }
    else
    {
        element *tmp= liste;
        element *ptmp = liste;
        while(tmp->next!=NULL)
        {
            ptmp = tmp;
            tmp=tmp->next;

        }
        ptmp->next = NULL;
        free(tmp);
        return liste;
    }
}
element* SupprimerParValeur(element* liste,int valeur) /* cherche la premiere valeur et la supprime  O(n) */
{
    if(estVide(liste))
    {
        return liste;
    }
    else if(liste->val==valeur)
    {
        element *tmp=liste;
        liste=liste->next;
        free(tmp);
        return liste;
    }
    else
    {
        element * tmp = liste;
        element * ptmp = liste;
        while((tmp->val!=valeur))
        {
            ptmp=tmp;
            tmp=tmp->next;
            if(tmp==NULL)
            {
                return liste;
            }

        }
        ptmp->next=tmp->next;
        free(tmp);
        return liste;
    }

}
element* SupprimerParIndice(element * liste,int indice) /* cherche la valeur dont l'indice et la supprime O(indice) */
{
    if(estVide(liste))
    {
        printf("La liste est vide!! \n ");
        return liste;
    }
    else if(indice==0)
    {
        element * tmp=liste;
        liste = liste->next;
        free(tmp);
        return liste;
    }
    else
    {
        element* tmp=liste;
        element* ptmp=liste;
        while(indice--)
        {

            ptmp = tmp;
            tmp = tmp->next;
        }
        ptmp->next=tmp->next;
        free(tmp);
        return liste;

    }
}
element* SupprimerInstance(element * liste,int valeur)  /* SUPPRIMER INSTANCE D'UNE VALEUR O(n) */
{
    if(liste == NULL)
    {
        return NULL;
    }

    else
    {
        element *x = liste;
        int i = longeur(liste);
        while(i--)
        {
            x = SupprimerParValeur(x,valeur);
        }
        return x;
    }

}
int NombreOccurence(element * liste,int valeur)  /* retourne le nombres d'occurence d'une valeur O(n) */
{
    int i=0;
    if(estVide(liste))
    {
        printf("La liste est vide\n");
        return 0;
    }
    else
    {
        element *x;
       x=liste;
       while(x->next!=NULL)
       {
           if(x->val==valeur)
           {
               i++;
           }
           x=x->next;
       }
    return i;

    }
}
element* SupprimerRepetitionRecursive(element* liste) /* SUPPRIMER TOUTES LES REPETITIONS RECURSIVE O(n²)!! */
{
    if(estVide(liste))
    {
        return NULL;
    }
    else if (liste->next==NULL)
    {
        return liste;
    }
    else
    {
        int i = liste->val;
        element * tmp = liste->next;
        liste->next=SupprimerInstance(tmp,i);
        tmp=liste->next;
        tmp->next = SupprimerRepetitionRecursive(tmp->next);
        return liste;

    }
}
element* SupprimerRepetition(element * liste)    /*NON RECURSIVE O(n²) */
{
    if(estVide(liste))
    {
        return NULL;
    }
    else if (liste->next == NULL)
    {
        return liste;
    }
    else
    {
        element * x =  liste;
        while(x->next!=NULL)
        {
            int i = x->val;
            x->next = SupprimerInstance(x->next,i);
            x=x->next;
        }
        return liste;
    }
}
element* Concat(element * liste1,element* liste2) /*Liste 2 dans liste1 O(l) l: longeur de la plus petite liste */
{
    if(estVide(liste1))
    {
        return liste2;
    }
    else if(liste1->next==NULL)
    {
        liste1->next=liste2;
        return liste1;
    }
    else
    {
        element * x = liste1;
        while(x->next!=NULL)
        {
            x = x->next;
        }
        x->next = liste2;
        return liste1;
    }

}
int Compare(element* liste1,element* liste2) /*renvoie 1 si les listes sont identiques O(max(l1,l2) */
{
    if((liste1==NULL) && (liste2==NULL))
    {
        return 1;
    }
    else if ((liste1->next==NULL) && (liste2->next==NULL))
    {
        return(liste1->val==liste2->val);
    }
    else
    {
        element * x = liste1;
        element * y = liste2;
        while((x->next!=NULL) && (y->next!=NULL))
        {
            if(x->val!=y->val)
            {
                return 0;
            }
            x=x->next;
            y=y->next;
        }
        return 1;
    }


}
int CompareReccur(element* liste1,element* liste2)  /* Meme chose mais reccurence!O(max(l1,l2) */
{
    if(liste1==NULL && liste2 == NULL)
    {
        return 1;
    }
    else if(liste1->val!=liste2->val)
    {
        return 0;
    }
    else
    {
        return CompareReccur(liste1->next,liste2->next);
    }

}
int estTrieCroissant(element* liste) /* si la liste est trié O(n) */
{
    if(estVide(liste))
    {
        return 1;
    }
    else
    {
        element * x= liste;
        while(x->next!=NULL)
        {
            if(x->val>x->next->val)
            {
                return 0;
            }
            x=x->next;
        }
        return 1;
    }
}
int estTrieCroissantRec(element * liste )  /*Meme chose Recursive O(n) */
{
    if(liste==NULL)
    {
        return 1;
    }
    else if(liste->next==NULL)
    {
        return 1;
    }
    else if (liste->val>liste->next->val)
    {
        return 0;
    }

    else
    {
        return estTrieCroissantRec(liste->next);
    }
}
element * FusionnerListesTrie(element * liste1, element* liste2) /*FUSIONNE 2 LISTE TRIEES DANS LA PREMIERE O(l1+l2)?? (pas sur de la complexité) */
{

    if ((estVide(liste1)) && (estVide(liste2)))
    {
        return NULL;
    }
    else if ((liste1==NULL ) && (liste2!=NULL))
    {
        return liste2;
    }
    else if ((liste2==NULL ) && (liste1!=NULL))
    {
        return liste1;
    }
    else
    {

        element * x = liste1;
        element * y = liste2;
        element * l3=NULL;

        while( (x!=NULL) && (y!=NULL) )
        {

            if(x->val<y->val)
            {
                element *nou = malloc(sizeof(element));
                nou->val = x->val;
                nou->next = NULL;

                l3=Concat(l3,nou);
                x=x->next;
            }
            if(x->val>=y->val)
            {
                element *nou = malloc(sizeof(element));
                nou->val = y->val;
                nou->next = NULL;

                l3=Concat(l3,nou);
                y=y->next;

            }
            if(x==NULL)
            {
                l3 = Concat(l3,y);
                return l3;
            }
            if(y==NULL)
            {
                l3 = Concat(l3,x);
                return l3;
            }
        }

    }

}
element * InverserListe(element* liste)    /* Inverse O(n)*/
{
    if((estVide(liste)) || (liste->next == NULL))
    {
        return liste;
    }
    else
    {
        element * tmp;
        element * ptmp;
        tmp = liste->next;
        liste->next = NULL;
        while (tmp != NULL)
        {
            ptmp = tmp->next;
            tmp->next = liste;
            liste = tmp;
            tmp = ptmp;
        }
    }
    return liste;

}
int des1(element * liste)           /* SI LA LISTE EST COMPOSEE QUE DE 1 O(n) */
{
    if((liste==NULL) || (liste->val!=1))
    {
        return 0;
    }
    if((liste->next==NULL) && (liste->val==1))
    {
        return 1;
    }
    else
    {
        return des1(liste->next);
    }
}
element * TrierListe(element * liste) /* Simple tri par selection d'une liste chainée O(n²)*/
{
    // ici on va ranger les elements dans l'ordre croisssant avant de les afficher.
   element * temp;
   element * temp1;
   element * temp3;
   int min;
   for(temp=liste ; temp!=NULL ; temp=temp->next)
   {
     temp3=temp;
     min=temp->val;
     for(temp1=temp->next ; temp1!=NULL ; temp1=temp1->next)
     {
        if(min > temp1->val)
        {
           temp3=temp1; // le 3è temporaire est l'adresse de l'élement où se trouve le minimum
           min=temp3->val;
        }
     }
     temp3->val=temp->val; //echange des 2 elements...
     temp->val=min;
   }
   return liste;
}


int main()
{

    // TAPEZ VOS COMMANDES ICI







    /* DECOMMENTEZ POUR TESTER QUELQUES FONCTIONS  !





    element* liste = NULL;  // EXEMPLE D'UNE LISTE VIDE
    element* lista = NULL;


    lista = inserer_entete(lista,1); //DES INSERTION POUR REMPLIR LES LISTES*
    lista = inserer_entete(lista,1);
    lista = inserer_entete(lista,2);
    lista = inserer_entete(lista,2);
    lista = inserer_enqueue(lista , 1);

    liste = inserer_entete(liste,9);
    liste = inserer_entete(liste,8);
    liste = inserer_entete(liste,6);
    liste = inserer_entete(liste,5);
    liste = inserer_enqueue(liste , 10);


    afficher(liste);  //affichage

    liste = InverserListe(liste);
    afficher(liste);

    /*
     //OPERATIONS SUR LES PILES DECOMMENTER POUR ESSAYER
    pile *P = creerPile();
    printf(" %d ",pileVide(P));
    empile(10,P);
    empile(20,P);
    empile(30,P);
    empile(40,P);
    empile(50,P);
    depile(P);
    afficherPile(P);

    */

    /*
    // OPERATION SUR LES FILES DECCOMENTER POUR ESSAYER
    file file;
	int choix, obj;
	initialiserFile(&file);
	do {
		printf("1- initialiser\n");
		printf("2- ajouter\n");
		printf("3- retirer\n");
		printf("4- afficher\n");
		printf("0- quitter\n");
		printf("\tChoix : ");
		scanf("%d", &choix);
		switch (choix) {
			case 0: break;
			case 1: initialiserFile(&file); break;
			case 2:
				printf("\t\tvaleur ? ");
				scanf("%d", &obj);
				enfiler(&file, obj);
				afficherFile(file);
			   	break;
			case 3:
				defiler(&file, &obj);
				printf("\t\tvaleur retiree --> %d\n", obj);
				afficherFile(file);
				break;
			case 4: afficherFile(file); break;
			default: printf("erreur...\n"); break;
		}
	} while (choix !=0);

	*/



 return 0;
}
