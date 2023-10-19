#define _CRT_SECURE_NO_WARNINGS
#include "../Bdd/myBdd.h"
#include "../Auteur/auteur.h"
#include "../Editeur/editeur.h"
#include "../Livre/livre.h"
#include <stdio.h> // Ajoutez l'inclusion nécessaire
#include <string.h>
#include <cmath>
//#include <mysql_driver.h>
//#include <mysql_connection.h>

		

void db::actionChoix(int valide, char choixNav[20], int action, int nav, int newElement, int indice, int modifier) {

	Auteur auteur;
	Editeur editeur;
	Livre livre;
	db database;

	printf("\nvaleur de nav: %d !!\n\n", nav);
	while (valide == -1) {
		printf("\nChoisissez une actions !!\n\n");
		printf("Ajouter (Ajouter = 1) un %s \n", choixNav);
		printf("Modifier (Modifier = 2) un %s \n", choixNav);
		printf("Supprimer (Supprimer = 3) un %s \n", choixNav);
		scanf("%d", &action);

		if (action == 1) {
			if (nav == 1) {
				while (newElement == 1) {
					if (newElement == 1) {
						auteur.reAuteur(newElement, valide, nav, choixNav);
					}
					else {
						newElement = -1;
					}
				}
			}
			else if (nav == 2) {
				while (newElement == 1) {
					if (newElement == 1) {
						editeur.reEditeur(newElement, valide, nav, choixNav);
					}
					else {
						newElement = -1;
					}
				}
			}
			else if (nav == 3) {
				while (newElement == 1) {
					if (newElement == 1) {
						livre.reLivre(newElement, valide, nav, choixNav);
					}
					else {
						newElement = -1;
					}
				}
			}
			valide = 0;

		}
		else if (action == 2) {
			printf("Tapez l'ID de l'entite que vous voulez modfier \n");
			scanf(" %d", &indice);
			if (nav == 1) {
				printf("|ID |\n");
				printf("|%d \n", auteur.tabAuteurs[indice].id);
				Auteur update;
				update.modifierAuteur(indice);
				update.reUpdAuteur(modifier, indice);
			}
			else if (nav == 2) {
				Editeur update;
				printf("|ID |\n");
				printf("|%d \n", update.tabEditeurs[indice].id);
				update.modifierEditeur(indice);
				//refaire.reUpdAuteur(modifier, indice);
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

}

void db::consultation(int valide, int navigato, char choixNav[20]) {
	int valideActionChoix = -1;
	int indice = 0;
	int modifier = 0;
	int action = 1;
	int newElement = 1;
	while (valide == 0) {

		printf("Consulter la liste des Auteurs, Editeurs ou Livres de la librairie ?\n");
		printf("Auteurs = 1\nEditeurs = 2 \nLivres = 3 \n\n");
		scanf("%d", &navigato);
		if (navigato == 1) {
			Auteur a; // Créez une instance de la classe db
			a.tableAuteur(); // Appelez la méthode tableAuteur à travers l'instance de la classe db
			strcpy(choixNav, "auteur");
			valide = -1;
		}
		else if (navigato == 2) {
			Editeur e; // Créez une instance de la classe db
			e.tableEditeur(); // Appelez la méthode tableAuteur à travers l'instance de la classe db
			strcpy(choixNav, "editeur");;
			valide = -1;
		}
		else if (navigato == 3) {
			Livre l; // Créez une instance de la classe db
			l.tableLivre(); // Appelez la méthode tableAuteur à travers l'instance de la classe db
			strcpy(choixNav, "livre");;
			valide = -1;
		}
		else {
			printf("Choix non repertorie ?\n");

			valide = 0;
		}

	}

	actionChoix(valideActionChoix, choixNav, action, navigato, newElement, indice, modifier);

}




