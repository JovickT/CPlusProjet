#ifndef LIVRE_H
#define LIVRE_H

class Livre {
public:
	int id;
	char titre[250];
	char datePublication[12];
	double prix;

	void ajouterLivre();
	void modifierLivre(int indice);
	void supprimerLivre(int indice);
	void displayHeaderTabLivre();
private:

protected:
};



#endif LIVRE_H

