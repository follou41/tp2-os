# tp2-os
Question 1 :

Premièrement, le programme définit une size de 5 strictement. Il est composé de 2 fonctions : main et getint. La première main crée 3 variables n (entier) , array ( liste d'entier ), et int * un pointer vers un entier. Le programme s'arrete ( return 0) grâce a une boucle for qui regarde a chaque itération si n est plus grand que 5 et que l'element de la list ne soit pas un EOF ( fin du fichier ).

La deuxième finction getint prend en argument un pointeur d'entier pn. il crée 2 variables entière nommées c et sign. Le programme continue tant l'input est soit un espace ' ' ou un entier ou un '+' ou un '-' ( se termine a 5 input ou 5 +n à n espace donné). Sign égale +1 si c est égale a '-' sinon égale 1. si c est un '+' ou un '-' il redemande un input. puis le * pn représentant une valeur entière de l'arraylist est changée. Puis pour finir getint return l'input qu'on lui a donné en dernier.

Question 3 : strace est un outil permettant de tracer les appels système générer par un processus pendant son execution. au départ, il crée bien un shell enfant avec execve et s'exécute correctement.
