#ifndef MYBDD_H
#define MYBDD_H

#include "../Auteur/auteur.h"
#include "../Editeur/editeur.h"
#include "../Livre/livre.h"

class db {
public:
	void tableAuteur();
	void tableEditeur();
	void tableLivre();

	int lengthTabAuteurs = 6; // Initialisez lengthTabAuteurs avec la taille du tableau
	int lengthTabEditeurs = 5; // Initialisez lengthTabEditeurs avec la taille du tableau
	int lengthTabLivres = 5; // Initialisez lengthTabLivres avec la taille du tableau
	Auteur tabAuteurs[50];
	Editeur tabEditeurs[50];
	Livre tabLivres[50];
private:
	
protected:
};

#endif // MYBDD_H

