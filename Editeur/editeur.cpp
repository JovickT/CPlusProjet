#define _CRT_SECURE_NO_WARNINGS
#include "../Editeur/editeur.h"
#include "../Bdd/myBdd.h"
#include <stdio.h> // Ajoutez l'inclusion nécessaire
#include <string.h>

void Editeur::ajouterEditeur() {

	printf("Nom: ");
	scanf("%s", &nom);

	db database;

	Editeur nouvelEditeur;
	nouvelEditeur.id = database.lengthTabEditeurs++;
	strncpy(nouvelEditeur.nom, nom, sizeof(nouvelEditeur.nom));

	if (nouvelEditeur.id < 250) {

		database.tabEditeurs[nouvelEditeur.id] = nouvelEditeur;

		printf("\nEditeur ajoute avec succes.\n");
	}
	else {
		printf("\nLe tableau est plein. Impossible d'ajouter plus d'editeurs.\n");
	}

	database.tableEditeur();


}

void Editeur::modifierEditeur(int indice) {

}

void Editeur::supprimerEditeur(int indice) {


}


void Editeur::displayHeaderTabEditeur() {
	printf("|ID |Nom           | \n");
}
