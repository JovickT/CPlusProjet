#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Bdd/myBdd.h"
#include <string.h>

enum navs {
	auteurs = 1,
	editeurs,
	livres
};


int main() {
    printf("ouverture de l'application \n\n");

	db begin;
	int valideConsultation = 0;
	char choixNav[20];
	int nav = 1;

	//printf("\nindice: %d et size of tabAuteurs: %d", indice, database.lengthTabAuteurs);
	/*Auteur as;
	as.displayHeaderTabAuteur();
	printf("|%d \n", begin.tabAuteurs[0].id);*/
	begin.consultation(valideConsultation, nav, choixNav);


    return 0;
}

