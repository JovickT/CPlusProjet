#ifndef AUTEUR_H
#define AUTEUR_H

class Auteur {
	public:
		int id;
		char nom[50];
		char prenom[50];
		char dateNaissance[6];
		char dateDeces[6];

		void ajouterAuteur();
		void modifierAuteur(int indice);
		void supprimerAuteur(int indice);
		void displayHeaderTabAuteur();
	private:

	protected:
};



#endif AUTEUR_H

