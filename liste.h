
typedef struct ElementListe 
{ 
  char *definition; 
  struct ElementListe *suivant; 
} Element; 

typedef struct ListeRepere 
{ 
  Element *debut; 
  Element *fin; 
  int taille; 
} Liste; 

/* initialisation de la liste */ 
void initialisation (Liste * liste); 


/* INSERTION */ 

/* insertion dans une liste vide */ 
int ins_dans_liste_vide (Liste * liste, char *definition); 

/* insertion au début de la liste */ 
int ins_debut_liste (Liste * liste, char *definition); 

/* insertion Ã a fin de la liste */ 
int ins_fin_liste (Liste * liste, Element * courant, char *definition); 

/* insertition ailleurs */ 
int ins_liste (Liste * liste, char *definition, int pos); 


/* SUPPRESSION */ 

int supp_debut (Liste * liste); 
int supp_dans_liste (Liste * liste, int pos); 


int menu (Liste *liste,int *k); 
void affiche (Liste * liste); 
void detruire (Liste * liste); 

