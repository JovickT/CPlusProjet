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

Auteur::~Auteur() {
	//delete[] tabAuteurs; // Libérez la mémoire à la fin de la vie de l'objet
}

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

	printf("Nom: ");
	scanf("%s",&nom); 

	printf("\nPrenom: ");
	scanf("%s", &prenom); 


	printf("\nDate de naissance: ");
	scanf("%s", &dateNaissance);


	printf("\nDate de deces: ");
	scanf("%s", &dateDeces);


	//lengthTabAuteurs++;
	printf("\njuste pour voir id indice 3 = : %d", tabAuteurs[3].id);

	Auteur nouvelAuteur;

	nouvelAuteur.id = lengthTabAuteurs;
	//printf("\nTaille du tableau d'auteur: %d\n", nouvelAuteur.id);
	strncpy(nouvelAuteur.nom, nom, sizeof(nouvelAuteur.nom));
	strncpy(nouvelAuteur.prenom, prenom, sizeof(nouvelAuteur.prenom));
	strncpy(nouvelAuteur.dateNaissance, dateNaissance, sizeof(nouvelAuteur.dateNaissance));
	strncpy(nouvelAuteur.dateDeces, dateDeces, sizeof(nouvelAuteur.dateDeces));

	if (lengthTabAuteurs < 50) {

		tabAuteurs[lengthTabAuteurs] = nouvelAuteur;
		
		lengthTabAuteurs++;
		//printf("\nlenghTabAuteurs 3: %d", lengthTabAuteurs);

		printf("\nAuteur ajoute avec succes.\n");
	}
	else {
		printf("\nLe tableau est plein. Impossible d'ajouter plus d'auteurs.\n");
	}

	//printf("\nsize of board auteurs: %d \n",lengthTabAuteurs);
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

void Auteur::ajouterCondition(int nouvelAuteur, int validerConsulation, int navigation, char choixNavigation[20]) {

	while (nouvelAuteur == 1) {
		if (nouvelAuteur == 1) {
			reAuteur(nouvelAuteur, validerConsulation, navigation, choixNavigation);
		}
		else {
			nouvelAuteur = -1;
		}
	}
}

void Auteur::modifierCondition(int indice,int modifier, int navigation) {
	printf("Tapez l'ID de l'entite que vous voulez modfier \n");
	scanf(" %d", &indice);
	if (navigation == 1) {
		printf("|ID |\n");
		printf("|%d \n", tabAuteurs[indice].id);
		Auteur update;
		update.modifierAuteur(indice);
		update.reUpdAuteur(modifier, indice);
	}
}

