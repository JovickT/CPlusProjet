#ifndef EDITEUR_H
#define EDITEUR_H

class Editeur {
public:
	int id;
	char nom[50];

	void ajouterEditeur();
	void modifierEditeur(int indice);
	void supprimerEditeur(int indice);
	void displayHeaderTabEditeur();
private:

protected:
};



#endif EDITEUR_H

