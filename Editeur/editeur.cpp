#define _CRT_SECURE_NO_WARNINGS
#include "../Editeur/editeur.h"
#include "../Bdd/myBdd.h"
#include <stdio.h> // Ajoutez l'inclusion n�cessaire
#include <string.h>

Editeur::Editeur(){}
Editeur::Editeur(int _id, const char* _nom) {
	id = _id;
	strcpy(nom, _nom);
}

Editeur::~Editeur() {
	//delete[] tabEditeurs; // Lib�rez la m�moire � la fin de la vie de l'objet
}

void Editeur::tableEditeur() {
	/*Editeur e1 = { 0,"Gallimard" };
	Editeur e2 = { 1,"Flammarion" };
	Editeur e3 = { 2,"Hachette" };
	Editeur e4 = { 3,"Baudelaire" };
	Editeur e5 = { 4,"Minuit" };*/
	tabEditeurs = new Editeur[lengthTabEditeurs];

	tabEditeurs[0] = { 0,"Gallimard" };
	tabEditeurs[1] = { 1,"Flammarion" };
	tabEditeurs[2] = { 2,"Hachette" };
	tabEditeurs[3] = { 3,"Baudelaire" };
	tabEditeurs[4] = { 4,"Minuit" };

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
	tempNom[strcspn(tempNom, "\n")] = '\0'; // Supprimer le caract�re de nouvelle ligne

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

void Editeur::ajouterCondition(int nouvelEditeur, int validerConsulation, int navigation, char choixNavigation[20]) {

	while (nouvelEditeur == 1) {
		if (nouvelEditeur == 1) {
			reEditeur(nouvelEditeur, validerConsulation, navigation, choixNavigation);
		}
		else {
			nouvelEditeur = -1;
		}
	}
}

void Editeur::modifierCondition(int indice, int modifier, int navigation) {
	printf("Tapez l'ID de l'entite que vous voulez modfier \n");
	scanf(" %d", &indice);
	if (navigation == 1) {
		printf("|ID |\n");
		printf("|%d \n", tabEditeurs[indice].id);
		Editeur update;
		update.modifierEditeur(indice);
		//update.reUpdEditeur(modifier, indice);
	}
}
