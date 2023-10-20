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
	
	//printf("\nvaleur de valide: %d !!\n\n", valide);
	while (valide == -1) {
		printf("\nChoisissez une actions !!\n\n");
		printf("Ajouter (Ajouter = 1) un %s \n", choixNav);
		printf("Modifier (Modifier = 2) un %s \n", choixNav);
		printf("Supprimer (Supprimer = 3) un %s \n", choixNav);
		scanf("%d", &action);

		if (action == 1) {
			switch (nav)
			{
			case 1:
				auteur.ajouterCondition(newElement, valide, nav, choixNav);
				break;
			case 2:
				editeur.ajouterCondition(newElement, valide, nav, choixNav);
				break;
			case 3:
				livre.ajouterCondition(newElement, valide, nav, choixNav);
				break;
			default:
				newElement = -1;
				break;
			}
			valide = 0;

		}
		else if (action == 2) {
			switch (nav)
			{
			case 1:
				auteur.modifierCondition(indice, modifier, nav);
				break;
			case 2:
				editeur.modifierCondition(indice, modifier, nav);
				break;
			case 3:
				//livre.modifierCondition(indice, modifier, nav);
				break;
			default:
				break;
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
			printf("Choix non repertorie !! \n");
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

		Auteur a;
		Editeur e;
		Livre l;

		printf("Consulter la liste des Auteurs, Editeurs ou Livres de la librairie ?\n");
		printf("Auteurs = 1\nEditeurs = 2 \nLivres = 3 \n\n");
		scanf("%d", &navigato);
		printf("\nnav: %d\n", navigato);
		switch (navigato)
		{
			case 1:
				a.tableAuteur(); 
				strcpy(choixNav, "auteur");
				valide = -1;
				break;
			case 2:
				e.tableEditeur(); 
				strcpy(choixNav, "editeur");;
				valide = -1;
				break;
			case 3:
				l.tableLivre();
				strcpy(choixNav, "livre");;
				valide = -1;
				break;
			default:
				printf("Choix non repertorie ?\n");
				valide = 0;
				break;
		}

	}

	actionChoix(valideActionChoix, choixNav, action, navigato, newElement, indice, modifier);

}




