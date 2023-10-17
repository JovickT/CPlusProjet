#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Bdd/myBdd.h"

enum navs {
	auteurs = 1,
	editeurs,
	livres
};

int main() {
    printf("ouverture de l'application \n");
    int valide = 0;
	int indice;
	int modifier = 0;
    int nav;
	int action;
	char choixNav[20];

    while (valide == 0) {

        printf("Consulter la liste des Auteurs, Editeurs ou Livres de la librairie ?\n");
        printf("Auteurs = 1\nEditeurs = 2 \nLivres = 3 \n\n");
        scanf("%d", &nav);
		if (nav == 1) {
			db database; // Créez une instance de la classe db
			database.tableAuteur(); // Appelez la méthode tableAuteur à travers l'instance de la classe db
			strcpy(choixNav, "auteur");
			valide = -1;

		}
		else if (nav == 2) {
			db database; // Créez une instance de la classe db
			database.tableEditeur(); // Appelez la méthode tableAuteur à travers l'instance de la classe db
			strcpy(choixNav, "editeur");;
			valide = -1;

		}
		else if (nav == 3) {
			db database; // Créez une instance de la classe db
			database.tableLivre(); // Appelez la méthode tableAuteur à travers l'instance de la classe db
			strcpy(choixNav, "livre");;
			valide = -1;
		}
		else {
			printf("Choix non repertorie ?\n");

			valide = 0;
		}

    }

	while (valide == -1) {
		printf("\nChoisissez une actions !!\n\n");
		printf("Ajouter (Ajouter = 1) un %s \n", choixNav);
		printf("Modifier (Modifier = 2) un %s \n", choixNav);
		printf("Supprimer (Supprimer = 3) un %s \n", choixNav);
		scanf("%d", &action);

		if (action == 1) {
			if (nav == 1) {
				Auteur ajouter;
				ajouter.ajouterAuteur();
			}
			else if (nav == 2) {
				Editeur ajouter;
				ajouter.ajouterEditeur();
			}
			else if (nav == 3) {
				Livre ajouter;
				ajouter.ajouterLivre();
			}
			valide = 0;

		}
		else if (action == 2) {
			printf("Tapez l'ID de l'entite que vous voulez modfier \n");
			scanf("%d", &indice);
			if (nav == 1) {
				Auteur update;
				update.modifierAuteur(indice);
				printf("\nVoulez-vous modifier de nouveau ? (oui = 1 / non = 0)");
				scanf("%d", &modifier);
				while (modifier == 1) {
					printf("Tapez l'ID de l'entite que vous voulez modfier \n");
					scanf("%d", &indice);
					Auteur update;
					update.modifierAuteur(indice);
					modifier = -1;
				}
			}
			else if (nav == 2) {
				//ajouterEditeur();
			}
			else if (nav == 3) {
				//ajouterLivre();
			}
			valide = 0;

		}
		else if (action == 3) {
			printf("Tapez l'ID de l'entite que vous voulez supprimer \n");
			scanf("%d", &indice);
			if (nav == 1) {
				//supprimerAuteur(indice);
			}
			else if (nav == 2) {
				//ajouterEditeur();
			}
			else if (nav == 3) {
				//ajouterLivre();
			}
			valide = 0;
		}
		else {
			printf("Choix non repertorie ?\n");
			valide = -1;
		}

	}

    return 0;
}