#include "../Bdd/myBdd.h"
#include "../Auteur/auteur.h"
#include "../Editeur/Editeur.h"
#include <stdio.h> // Ajoutez l'inclusion nécessaire

		
void db::tableAuteur() {
	Auteur a1 = { 0,"Victor","Hugo","1802","1885" };
	Auteur a2 = { 1,"Charles","Baudelaire","1821","1867" };
	Auteur a3 = { 2,"Albert","Camus","1913","1960" };
	Auteur a4 = { 3,"Charles","Dikens","1812","1870" };
	Auteur a5 = { 4,"","Voltaire","1694","1778" };
	Auteur a6 = { 5,"","test","1999","2021" };

	tabAuteurs[0] = a1;
	tabAuteurs[1] = a2;
	tabAuteurs[2] = a3;
	tabAuteurs[3] = a4;
	tabAuteurs[4] = a5;
	tabAuteurs[5] = a6;

	Auteur headerTab; // Créer une instance de la classe Auteur
	headerTab.displayHeaderTabAuteur();


	for (int i = 0; i < lengthTabAuteurs; i++)
	{
		printf("|%d", tabAuteurs[i].id);
		printf("  |%s", tabAuteurs[i].nom);
		printf("      |%s", tabAuteurs[i].prenom);
		printf("                |%s", tabAuteurs[i].dateNaissance);
		printf("                |%s", tabAuteurs[i].dateDeces);
		printf("|\n");

	}

}

void db::tableEditeur() {
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

	Editeur headerTab; // Créer une instance de la classe Auteur
	headerTab.displayHeaderTabEditeur();


	for (int i = 0; i < lengthTabEditeurs; i++)
	{
		printf("|%d", tabEditeurs[i].id);
		printf("  |%s", tabEditeurs[i].nom);
		printf("|\n");

	}

}

