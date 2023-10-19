#define _CRT_SECURE_NO_WARNINGS
#include "../Editeur/editeur.h"
#include "../Bdd/myBdd.h"
#include <stdio.h> // Ajoutez l'inclusion nécessaire
#include <string.h>

Editeur::Editeur(){}
Editeur::Editeur(int _id, const char* _nom) {
	_id = lengthTabEditeurs;
	strcpy(nom, _nom);
}

Editeur::~Editeur() {
	delete[] tabEditeurs; // Libérez la mémoire à la fin de la vie de l'objet
}

void Editeur::tableEditeur() {
	Editeur e1 = { 0,"Gallimard" };
	Editeur e2 = { 1,"Flammarion" };
	Editeur e3 = { 2,"Hachette" };
	Editeur e4 = { 3,"Baudelaire" };
	Editeur e5 = { 4,"Minuit", };

	tabEditeurs[0] = e1;
	tabEditeurs[1] = e2;
	tabEditeurs[2] = e3;
	tabEditeurs[3] = e4;
	tabEditeurs[4] = e5;

	displayHeaderTabEditeur();


	for (int i = 0; i < lengthTabEditeurs; i++)
	{
		printf("|%d", tabEditeurs[i].id);
		printf("  |%s", tabEditeurs[i].nom);
		printf("|\n");

	}

}

void Editeur::ajouterEditeur() {

	char tempNom[50]; // Temporaire pour stocker le nom lu

	printf("Nom: ");
	fgets(tempNom, sizeof(tempNom), stdin);
	tempNom[strcspn(tempNom, "\n")] = '\0'; // Supprimer le caractère de nouvelle ligne

	db database;

	/*nouvelEditeur.id = nouvelEditeur.lengthTabEditeurs++;
	strncpy(nouvelEditeur.nom, nom, sizeof(nouvelEditeur.nom));*/

	if (lengthTabEditeurs < 50) {

		Editeur nouvelEditeur(lengthTabEditeurs, nom);

		tabEditeurs[lengthTabEditeurs] = nouvelEditeur;

		lengthTabEditeurs++;

		printf("\nEditeur ajoute avec succes.\n");
	}
	else {
		printf("\nLe tableau est plein. Impossible d'ajouter plus d'editeurs.\n");
	}

	tableEditeur();


}

void Editeur::modifierEditeur(int indice) {

}

void Editeur::supprimerEditeur(int indice) {


}


void Editeur::displayHeaderTabEditeur() {
	printf("|ID |Nom           | \n");
}

void Editeur::reEditeur(int nouvelEditeur, int validerConsulation, int navigation, char choixNavigation[20]) {
	db cons;
	int indice = 0;
	int modifier = 0;
	int action = 1;
	int valideActionChoix = -1;
	ajouterEditeur();
	printf("\nVoulez-vous ajouter un autre editeur ? (oui = 1 / non = 0)\n\n");
	scanf("%d", &nouvelEditeur);
	if (nouvelEditeur == 1) {
		while (nouvelEditeur == 1) {
			reEditeur(nouvelEditeur, validerConsulation, navigation, choixNavigation);
		}
	}
	else {
		validerConsulation = 0;
		cons.consultation(validerConsulation, navigation, choixNavigation);
		cons.actionChoix(valideActionChoix, choixNavigation, action, navigation, nouvelEditeur, indice, modifier);

	}
}
