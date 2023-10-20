#ifndef EDITEUR_H
#define EDITEUR_H

class Editeur {
public:
	int id;
	char nom[50];
	int lengthTabEditeurs; // Initialisez lengthTabEditeurs avec la taille du tableau

	Editeur* tabEditeurs;

	Editeur();
	Editeur(int _id, const char* _nom); // Constructeur
	~Editeur(); // Destructeur

	void tableEditeur();
	void ajouterEditeur();
	void modifierEditeur(int indice);
	void supprimerEditeur(int indice);
	void displayHeaderTabEditeur();
	void reEditeur(int nouvelEditeur, int validerConsulation, int navigation, char choixNavigation[20]);
	void ajouterCondition(int nouvelEditeur, int validerConsulation, int navigation, char choixNavigation[20]);
	void modifierCondition(int indice, int modifier, int navigation);
private:

protected:
};



#endif EDITEUR_H

