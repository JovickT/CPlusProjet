#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Bdd/myBdd.h"

int main() {
    printf("ouverture de l'application \n");
    int valide = 0;
    int nav;

    while (valide == 0) {

        printf("Consulter la liste des Auteurs, Editeurs ou Livres de la librairie ?\n");
        printf("Auteurs = 1\nEditeurs = 2 \nLivres = 3 \n\n");
        scanf("%d", &nav);
		if (nav == 1) {
			db database; // Créez une instance de la classe db
			database.tableAuteur(); // Appelez la méthode tableAuteur à travers l'instance de la classe db
		}
		else if (nav == 2) {
			db database; // Créez une instance de la classe db
			database.tableEditeur(); // Appelez la méthode tableAuteur à travers l'instance de la classe db
		}
		else if (nav == 3) {
			//db database; // Créez une instance de la classe db
			//database.tableLivre(); // Appelez la méthode tableAuteur à travers l'instance de la classe db
		}
		else {
			valide = 0;
		}

		valide = nav;
    }

   

    return 0;
}