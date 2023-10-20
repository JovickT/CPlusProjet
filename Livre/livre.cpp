#define _CRT_SECURE_NO_WARNINGS
#include "../Livre/livre.h"
#include "../Bdd/myBdd.h"
#include <stdio.h> // Ajoutez l'inclusion nécessaire
#include <string.h>

Livre::Livre(){}
Livre::Livre(int _id, const char* _titre, const char* _datePublication, const double _prix) {
	id = _id;
	strcpy(titre, _titre);
	strcpy(datePublication, _datePublication);
	prix = _prix;
	//tabAuteurs = new Auteur[lengthTabAuteurs]; // Allouez dynamiquement de la mémoire pour le tableau
}

Livre::~Livre() {
	//delete[] tabLivres; // Libérez la mémoire à la fin de la vie de l'objet
}

void Livre::tableLivre() {
	Livre l1 = { 0,"Candide","2017",3.50 };
	Livre l2 = { 1,"L'Etranger","2002",2.50 };
	Livre l3 = { 2,"La Peste","2002",6.76 };
	Livre l4 = { 3,"Les Miserables","21/11/2019",4.80 };
	Livre l5 = { 4,"David Copperfield","13/08/2020",7.90 };

	tabLivres = new Livre[lengthTabLivres];

	tabLivres[0] = l1;
	tabLivres[1] = l2;
	tabLivres[2] = l3;
	tabLivres[3] = l4;
	tabLivres[4] = l5;

	displayHeaderTabLivre();

	for (int i = 0; i < lengthTabLivres; i++)
	{
		printf("|%d", tabLivres[i].id);
		printf("  |%s", tabLivres[i].titre);
		printf("           |%s", tabLivres[i].datePublication);
		printf("                |%lf", tabLivres[i].prix);
		printf(" |\n");
	}
}

void Livre::ajouterLivre() {

	char tempTitre[50]; // Temporaire pour stocker le nom lu

	printf("Titre: ");
	fgets(tempTitre, sizeof(tempTitre), stdin);
	tempTitre[strcspn(tempTitre, "\n")] = '\0'; // Supprimer le caractère de nouvelle ligne

	printf("\nDate de publication: ");
	fgets(datePublication, sizeof(datePublication), stdin);
	datePublication[strcspn(datePublication, "\n")] = '\0';

	printf("\nPrix: ");
	scanf("%lf", &prix);

	db database;


	/*nouvelLivre.id = nouvelLivre.lengthTabLivres++;
	strncpy(nouvelLivre.titre, titre, sizeof(nouvelLivre.titre));
	strncpy(nouvelLivre.datePublication, datePublication, sizeof(nouvelLivre.titre));
	nouvelLivre.prix = prix;*/

	if (lengthTabLivres < 50) {

		Livre nouveauLivre(lengthTabLivres, titre, datePublication, prix);

		tabLivres[lengthTabLivres] = nouveauLivre;

		lengthTabLivres++;

		printf("\nLivre ajoute avec succes.\n");
	}
	else {
		printf("\nLe tableau est plein. Impossible d'ajouter plus d'livres.\n");
	}

	tableLivre();
}



void Livre::modifierLivre(int indice) {

}

void Livre::supprimerLivre(int indice) {


}


void Livre::displayHeaderTabLivre() {
	printf("|ID |Titre              |Date de Publication |Prix| \n");
}

void Livre::reLivre(int nouveauLivre, int validerConsulation, int navigation, char choixNavigation[20]) {
	ajouterLivre();
	printf("\nVoulez-vous ajouter un autre livre ? (oui = 1 / non = 0)\n\n");
	scanf("%d", &nouveauLivre);
}

void Livre::ajouterCondition(int nouveauLivre, int validerConsulation, int navigation, char choixNavigation[20]) {

	while (nouveauLivre == 1) {
		if (nouveauLivre == 1) {
			reLivre(nouveauLivre, validerConsulation, navigation, choixNavigation);
		}
		else {
			nouveauLivre = -1;
		}
	}
}


