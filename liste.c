#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "liste.h" 
#include "liste_function.h" 
int main (void) 
{
char choix;
char *nom;
Liste *liste;
Element *courant;
if ((liste = (Liste *)malloc(sizeof (Liste))) == NULL)
return -1;
if ((nom = (char *) malloc(50))== NULL)     
return -1;
courant = NULL;
choix = 'o';
initialisation (liste);
int pos, k;
while (choix != 7)
{       choix = menu (liste, &k);
switch (choix) 
{
case 1:           printf ("Entrez un element : ");
scanf ("%s", nom);
getchar ();
if (liste->taille == 0)  
ins_dans_liste_vide (liste, nom);
else ins_debut_liste (liste, nom);
printf ("%d elements:deb=%s,fin=%s\n", liste->taille, liste->debut->definition, liste->fin->definition);
affiche (liste);
break;
case 2: printf ("Entrez un element : ");
scanf ("%s", nom);
getchar ();
ins_fin_liste (liste, liste->fin, nom);
printf ("%d elements:deb=%s,fin=%s\n", liste->taille,                   liste>debut->definition, liste->fin->definition);
affiche (liste);
break;
case 3:
printf ("Entrez un element : ");
scanf ("%s", nom);
getchar ();
do
{
printf ("Entrez la position : ");
scanf ("%d", &pos);
}
while (pos < 1 || pos > liste->taille);
getchar ();
if (liste->taille == 1 || pos == liste->taille)
{
k = 1;
printf("-----------------------------------------------\n");
printf(" \Insertion echouée.Utilisez le menu {1|2}  \\n");
printf("-----------------------------------------------\n");
break;
}
ins_liste (liste, nom, pos);
printf ("%d elements:deb=%s,fin=%s\n", liste->taille,                   liste->debut->definition, liste->fin->definition);
affiche (liste);
break;
case 4:supp_debut (liste);

if (liste->taille != 0)printf ("%d elements:deb=%s,fin=%s\n", liste->taille,                     liste->debut->definition, liste->fin->definition);
else printf ("liste vide\n");
affiche (liste);
break;
case 5:
do
{
printf ("Entrez la position : ");
scanf ("%d", &pos);
}while (pos < 1 || pos > liste->taille);
getchar ();
supp_dans_liste (liste, pos);
 if (liste->taille != 0)
printf ("%d elements:deb=%s,fin=%s\n", liste->taille,                     liste->debut->definition, liste->fin->definition);
else printf ("liste vide\n");
affiche (liste);
break;
case 6:
detruire (liste);
printf ("la liste a ete detruite : %d elements\n", liste->taille);           break;
}   
}   
return 0; } 
