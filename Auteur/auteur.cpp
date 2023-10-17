#define _CRT_SECURE_NO_WARNINGS
#include "../Auteur/auteur.h"
#include "../Bdd/myBdd.h"
#include <stdio.h> // Ajoutez l'inclusion nécessaire
#include <string.h>

void Auteur::ajouterAuteur() {

	printf("Nom: ");
	scanf("%s", &nom);

	printf("\nPrenom: ");
	scanf("%s", &prenom);

	printf("\nDate de naissance: ");
	scanf("%s", &dateNaissance);

	printf("\nDate de deces: ");
	scanf("%s", &dateDeces);

	db database;

	Auteur nouvelAuteur;
	nouvelAuteur.id = database.lengthTabAuteurs++;
	strncpy(nouvelAuteur.nom, nom, sizeof(nouvelAuteur.nom));
	strncpy(nouvelAuteur.prenom, prenom, sizeof(nouvelAuteur.prenom));
	strncpy(nouvelAuteur.dateNaissance, dateNaissance, sizeof(nouvelAuteur.dateNaissance));
	strncpy(nouvelAuteur.dateDeces, dateDeces, sizeof(nouvelAuteur.dateDeces));

	if (nouvelAuteur.id < 250) {
		
		database.tabAuteurs[nouvelAuteur.id] = nouvelAuteur;

		printf("\nAuteur ajoute avec succes.\n");
	}
	else {
		printf("\nLe tableau est plein. Impossible d'ajouter plus d'auteurs.\n");
	}

	database.tableAuteur();
}

void Auteur::modifierAuteur(int indice) {

	char updNom;
	char updPrenom;
	char updDn;
	char updDd;

	db database;

	printf("\nindice: %d", indice);

	displayHeaderTabAuteur();
	printf("|%d", database.tabAuteurs[indice].id);
	/*printf("  |%s", database.tabAuteurs[indice].nom);
	printf("      |%s", database.tabAuteurs[indice].prenom);
	printf("                |%s", database.tabAuteurs[indice].dateNaissance);
	printf("                |%s", database.tabAuteurs[indice].dateDeces);
	printf("|\n");*/

	printf("Voulez-vous modifier le nom ? (Y/N): ");
	scanf(" %c", &updNom);

	if (updNom == 'Y' || updNom == 'y') {
		//printf("\nNom: %s \nindice: %d", tab[indice].nom, indice);
		scanf("%s", database.tabAuteurs[indice].nom);

		//printf("\nNouveau nom: %s", database.tabAuteurs[indice].nom);
	}

	database.tableAuteur();

}

void Auteur::supprimerAuteur(int indice) {

			
}


void Auteur::displayHeaderTabAuteur() {
	printf("\n|ID |Nom      | Prenom      |Date de Naissance      |Date deces | \n");
}
