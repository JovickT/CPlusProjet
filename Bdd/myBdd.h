#ifndef MYBDD_H
#define MYBDD_H

#include "../Auteur/auteur.h"
#include "../Editeur/editeur.h"

class db {
public:
	void tableAuteur();
	void tableEditeur();
private:
	int lengthTabAuteurs = 6; // Initialisez lengthTabAuteurs avec la taille du tableau
	int lengthTabEditeurs = 5; // Initialisez lengthTabEditeurs avec la taille du tableau
	Auteur tabAuteurs[50];
	Editeur tabEditeurs[50];
protected:
};

#endif // MYBDD_H

