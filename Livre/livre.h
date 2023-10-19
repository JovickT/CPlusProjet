#ifndef LIVRE_H
#define LIVRE_H

class Livre {
public:
	int id;
	char titre[250];
	char datePublication[12];
	double prix;
	int lengthTabLivres; // Initialisez lengthTabLivres avec la taille du tableau

	Livre* tabLivres; // Déclaration d'un pointeur vers un tableau de Livre
	
	Livre();
	Livre(int _id, const char* _titre, const char* _datePublication, const double _prix); // Constructeur
	~Livre(); // Destructeur

	void tableLivre();
	void ajouterLivre();
	void modifierLivre(int indice);
	void supprimerLivre(int indice);
	void displayHeaderTabLivre();
	void reLivre(int nouveauLivre, int validerConsulation, int navigation, char choixNavigation[20]);
private:

protected:
};



#endif LIVRE_H

