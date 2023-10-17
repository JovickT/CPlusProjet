#define _CRT_SECURE_NO_WARNINGS
#include "../Livre/livre.h"
#include "../Bdd/myBdd.h"
#include <stdio.h> // Ajoutez l'inclusion nécessaire
#include <string.h>

void Livre::ajouterLivre() {

	printf("Titre: ");
	scanf("%s", &titre);

	printf("\nDate de publication: ");
	scanf("%s", &datePublication);

	printf("\nPrix: ");
	scanf("%lf", &prix);

	db database;

	Livre nouvelLivre;
	nouvelLivre.id = database.lengthTabLivres++;
	strncpy(nouvelLivre.titre, titre, sizeof(nouvelLivre.titre));
	strncpy(nouvelLivre.datePublication, datePublication, sizeof(nouvelLivre.titre));
	nouvelLivre.prix = prix;

	if (nouvelLivre.id < 250) {

		database.tabLivres[nouvelLivre.id] = nouvelLivre;

		printf("\nLivre ajoute avec succes.\n");
	}
	else {
		printf("\nLe tableau est plein. Impossible d'ajouter plus d'livres.\n");
	}

	database.tableLivre();
}



void Livre::modifierLivre(int indice) {

}

void Livre::supprimerLivre(int indice) {


}


void Livre::displayHeaderTabLivre() {
	printf("|ID |Titre              |Date de Publication |Prix| \n");
}
