

void initialisation (Liste * liste) {   
	liste->debut = NULL;   
	liste->fin = NULL;   
	liste->taille = 0; 
} 

/* insertion dans une liste vide */ 

int ins_dans_liste_vide (Liste * liste, char *definition ){   
	
	Element *nouveau_element;   

	if ((nouveau_element = (Element *) malloc (sizeof (Element))) == NULL)     
		return -1;   
	if ((nouveau_element->definition = (char *) malloc (50 * sizeof (char)))  == NULL)
       		return -1;   
	strcpy (nouveau_element->definition ,definition ); 
	nouveau_element->suivant = NULL;   
	liste->debut = nouveau_element;   
	liste->fin = nouveau_element;   
	liste->taille++;   
	return 0; 
	} 

/* insertion au début de la liste */ 

int ins_debut_liste (Liste * liste, char *definition ){
	
	Element *nouveau_element;   
	
	if ((nouveau_element = (Element *) malloc (sizeof (Element))) == NULL)
 		return -1;   
	if ((nouveau_element->definition  = (char *) malloc (50 * sizeof (char))) == NULL)     
		return -1;   

	strcpy (nouveau_element->definition , definition );   
	nouveau_element->suivant = liste->debut;   
	liste->debut = nouveau_element;   
	liste->taille++;   return 0; } 

/*insertion à la fin de la liste */ 

int ins_fin_liste (Liste * liste, Element * courant, char *definition ){   

	Element *nouveau_element;   

	if ((nouveau_element = (Element *) malloc (sizeof (Element))) == NULL)     
		return -1;   
	if ((nouveau_element->definition  = (char *) malloc (50 * sizeof (char))) == NULL)     
		return -1;   
	strcpy (nouveau_element->definition , definition );   
	courant->suivant = nouveau_element;   
	nouveau_element->suivant = NULL;   
	liste->fin = nouveau_element;   
	liste->taille++;   
	return 0; } 

/* insertion à la position demandée */ 

int ins_liste (Liste * liste, char *definition , int pos){   

	if (liste->taille < 2)     
		return -1;   
	if (pos < 1 || pos >= liste->taille)     
		return -1;   

	Element *courant;   
	Element *nouveau_element;   
	int i;  

	if ((nouveau_element = (Element *) malloc (sizeof (Element))) == NULL)     
		return -1;   
	if ((nouveau_element->definition  = (char *) malloc (50 * sizeof (char)))  == NULL)     
		return -1;   
	courant = liste->debut;   
	for (i = 1; i < pos; ++i)     courant = courant->suivant;   if (courant->suivant == NULL)     
		return -1;   
	strcpy (nouveau_element->definition , definition );   
	nouveau_element->suivant = courant->suivant;   
	courant->suivant = nouveau_element;   
	liste->taille++;   
	return 0; }


/* suppression au début de la liste */ 

int supp_debut (Liste * liste){   
	if (liste->taille == 0)     
		return -1;   
	Element *supp_element;   
	supp_element = liste->debut;   
	liste->debut = liste->debut->suivant;   
	if (liste->taille == 1)     
		liste->fin = NULL;   
	free (supp_element->definition );   
	free (supp_element);   
	liste->taille--;   
	return 0; }


/* supprimer un element après la position demandée */ 

int supp_dans_liste (Liste * liste, int pos){   

	if (liste->taille <= 1 || pos < 1 || pos >= liste->taille)     
		return -1;   
	int i;   
	Element *courant;   
	Element *supp_element;   
	courant = liste->debut;   

	for (i = 1; i < pos; ++i)     
		courant = courant->suivant;   
	supp_element = courant->suivant;   
	courant->suivant = courant->suivant->suivant;   

	if(courant->suivant == NULL)           
	liste->fin = courant;   

	free (supp_element->definition );   
	free (supp_element);   
	liste->taille--;   
	return 0; } 

/* affichage de la liste */ 

void affiche (Liste * liste){   

	Element *courant;   
	courant = liste->debut;  

	 while (courant != NULL){       

	printf ("%p - %s\n", courant, courant->definition );       
	courant = courant->suivant;   
		}
	
 } 


/* detruire la liste */ 

void detruire (Liste * liste){   

	while (liste->taille > 0)     
	supp_debut (liste); 	
		} 

int menu (Liste *liste,int *k){   

	int choix;   
	printf("********** MENU **********\n");   
	if (liste->taille == 0){     

		printf ("1. Ajout du 1er element\n");     
		printf ("2. Quitter\n"); 
  
	}else if(liste->taille == 1 || *k == 1){     
		printf ("1. Ajout au debut de la liste\n");    
		printf ("2. Ajout a la fin de la liste\n");     
		printf ("4. Suppression au debut de la liste\n");     
		printf ("6. Detruire la liste\n");     
		printf ("7. Quitter\n");   

	}else {     
		printf ("1. Ajout au debut de la liste\n");     
		printf ("2. Ajout a la fin de la liste\n");     
		printf ("3. Ajout apres la position specifie\n");     
		printf ("4. Suppression au debut de la liste\n");     
		printf ("5. Suppression apres la position specifie\n");     
		printf ("6. Detruire la liste\n");     
		printf ("7. Quitter\n");   
	}   

	printf ("\n\nFaites votre choix : ");   
	scanf ("%d", &choix);   
	getchar();   
	if(liste->taille == 0 && choix == 2)    
	choix = 7;	
	return choix; 
	} 

