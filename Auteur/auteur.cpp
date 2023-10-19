#define _CRT_SECURE_NO_WARNINGS
#include "../Auteur/auteur.h"
#include "../Bdd/myBdd.h"
#include <stdio.h> // Ajoutez l'inclusion nécessaire
#include <string.h>
//#include <iostream>

Auteur::Auteur(){}
Auteur::Auteur(int _id, const char* _nom, const char* _prenom, const char* _dateNaissance, const char* _dateDeces) {
	id = _id;
	strcpy(nom, _nom);
	strcpy(prenom, _prenom);
	strcpy(dateNaissance, _dateNaissance);
	strcpy(dateDeces, _dateDeces);
}

//Auteur::~Auteur() {
//	delete[] tabAuteurs; // Libérez la mémoire à la fin de la vie de l'objet
//}

void Auteur::tableAuteur() {
	tabAuteurs = new Auteur[lengthTabAuteurs]; // allouez dynamiquement la mémoire

	// Initialisation des données
	tabAuteurs[0] = { 0, "Victor", "Hugo", "1802", "1885" };
	tabAuteurs[1] = { 1, "Charles", "Baudelaire", "1821", "1867" };
	tabAuteurs[2] = { 2, "Albert", "Camus", "1913", "1960" };
	tabAuteurs[3] = { 3, "Charles", "Dikens", "1812", "1870" };
	tabAuteurs[4] = { 4, "", "Voltaire", "1694", "1778" };
	tabAuteurs[5] = { 5, "", "test", "1999", "2021" };

	displayHeaderTabAuteur();


	for (int i = 0; i < lengthTabAuteurs; i++)
	{
		printf("|%d \0", tabAuteurs[i].id);
		printf("  |%s \0", tabAuteurs[i].nom);
		printf("      |%s \0", tabAuteurs[i].prenom);
		printf("                |%s \0", tabAuteurs[i].dateNaissance);
		printf("                |%s \0", tabAuteurs[i].dateDeces);
		printf("|\n");

	}


}

void Auteur::ajouterAuteur() {

	//char tempNom[50]; // Temporaire pour stocker le nom lu

	printf("Nom: ");
	scanf("%s",&nom); // Supprimer le caractère de nouvelle ligne

	printf("\nPrenom: ");
	scanf("%s", &prenom); // Supprimer le caractère de nouvelle ligne


	printf("\nDate de naissance: ");
	scanf("%s", &dateNaissance); // Supprimer le caractère de nouvelle ligne


	printf("\nDate de deces: ");
	scanf("%s", &dateDeces); // Supprimer le caractère de nouvelle ligne


	//lengthTabAuteurs++;
	printf("\nlenghTabAuteurs 1: %d", lengthTabAuteurs);

	Auteur nouvelAuteur;

	/*nouvelAuteur.id = lengthTabAuteurs;
	printf("\nTaille du tableau d'auteur: %d\n", nouvelAuteur.id);
	strncpy(nouvelAuteur.nom, nom, sizeof(nouvelAuteur.nom));
	strncpy(nouvelAuteur.prenom, prenom, sizeof(nouvelAuteur.prenom));
	strncpy(nouvelAuteur.dateNaissance, dateNaissance, sizeof(nouvelAuteur.dateNaissance));
	strncpy(nouvelAuteur.dateDeces, dateDeces, sizeof(nouvelAuteur.dateDeces));*/

	if (lengthTabAuteurs < 50) {

		nouvelAuteur.tabAuteurs = new Auteur[lengthTabAuteurs + 1];
		printf("\tabAuteurs id 0 : %d", tabAuteurs[0].id);

		// Copiez les données de l'ancien tableau vers le nouveau
		for (int i = 0; i < lengthTabAuteurs; ++i) {
			//nouvelAuteur.tabAuteurs[i] = tabAuteurs[i];
			nouvelAuteur.tabAuteurs[i].id = tabAuteurs[i].id;
			strcpy(nouvelAuteur.tabAuteurs[i].nom, tabAuteurs[i].nom);
			strcpy(nouvelAuteur.tabAuteurs[i].prenom, tabAuteurs[i].prenom);
			strcpy(nouvelAuteur.tabAuteurs[i].dateNaissance, tabAuteurs[i].dateNaissance);
			strcpy(nouvelAuteur.tabAuteurs[i].dateDeces, tabAuteurs[i].dateDeces);
		}

		// Ajoutez le nouvel auteur à la fin du tableau
		nouvelAuteur.tabAuteurs[lengthTabAuteurs] = { lengthTabAuteurs ,nom, prenom, dateNaissance, dateDeces};

		// Incrémentez la taille du tableau
		lengthTabAuteurs++;
		printf("\nlenghTabAuteurs 3: %d", lengthTabAuteurs);

		printf("\nAuteur ajoute avec succes.\n");
	}
	else {
		printf("\nLe tableau est plein. Impossible d'ajouter plus d'auteurs.\n");
	}

	printf("\nsize of board auteurs: %d \n",lengthTabAuteurs);
	tableAuteur();
}

void Auteur::modifierAuteur(int indice) {

	char updNom;
	char updPrenom;
	char updDn;
	char updDd;

	db database;


	printf("\nindice: %d et size of tabAuteurs: %d", indice, lengthTabAuteurs);

	displayHeaderTabAuteur();
	printf("|%d", tabAuteurs[indice].id);
	/*printf("  |%s", database.tabAuteurs[indice].nom);
	printf("      |%s", database.tabAuteurs[indice].prenom);
	printf("                |%s", database.tabAuteurs[indice].dateNaissance);
	printf("                |%s", database.tabAuteurs[indice].dateDeces);*/
	printf("|\n");

	printf("Voulez-vous modifier le nom ? (Y/N): ");
	scanf(" %c", &updNom);

	if (updNom == 'Y' || updNom == 'y') {
		//printf("\nNom: %s \nindice: %d", tab[indice].nom, indice);
		scanf(" %s", tabAuteurs[4].nom);

		//printf("\nNouveau nom: %s", database.tabAuteurs[indice].nom);
	}else {
		printf("Voulez-vous modifier le prenom ? (Y/N): ");
		scanf(" %c", &updPrenom);
		if (updPrenom == 'Y' || updPrenom == 'y') {
			//printf("\nNom: %s \nindice: %d", tab[indice].nom, indice);
			scanf(" %s", tabAuteurs[4].prenom);

			//printf("\nNouveau nom: %s", database.tabAuteurs[indice].nom);
		}
	}

	tableAuteur();

}

void Auteur::supprimerAuteur(int indice) {

			
}


void Auteur::displayHeaderTabAuteur() {
	printf("\n|ID |Nom      | Prenom      |Date de Naissance      |Date deces | \n");
}

void Auteur::reAuteur(int nouvelAuteur, int validerConsulation, int navigation, char choixNavigation[20]) {
	db cons;
	int indice = 0;
	int modifier = 0;
	int action = 1;
	int valideActionChoix = -1;
	ajouterAuteur();
	printf("\nVoulez-vous ajouter un autre auteur ? (oui = 1 / non = 0)\n\n");
	scanf("%d", &nouvelAuteur);
	if (nouvelAuteur == 1) {
		while (nouvelAuteur == 1) {
			reAuteur(nouvelAuteur, validerConsulation, navigation, choixNavigation);
		}
	}
	else {
		cons.consultation(validerConsulation = 0, navigation, choixNavigation);
		cons.actionChoix(valideActionChoix, choixNavigation, action, navigation, nouvelAuteur, indice, modifier);
	}

}

void Auteur::reUpdAuteur(int res, int indice) {
	printf("\nVoulez-vous modifier de nouveau ? (oui = 1 / non = 0)");
	scanf("%d", &res);
	while (res == 1) {
		printf("Tapez l'ID de l'entite que vous voulez modfier \n");
		scanf("%d", &indice);
		modifierAuteur(indice);
		res = -1;
	}
}

