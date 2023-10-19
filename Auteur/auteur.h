#ifndef AUTEUR_H
#define AUTEUR_H


class Auteur {
	public:
		int id;
		char nom[50];
		char prenom[50];
		char dateNaissance[6];
		char dateDeces[6];
		int lengthTabAuteurs = 6; // Initialisez lengthTabAuteurs avec la taille du tableau

		Auteur* tabAuteurs;
		Auteur();
		Auteur(int _id, const char* _nom, const char* _prenom, const char* _dateNaissance, const char* _dateDeces); // Constructeur
		//~Auteur(); // Destructeur

		void tableAuteur();
		void ajouterAuteur();
		void modifierAuteur(int indice);
		void supprimerAuteur(int indice);
		void displayHeaderTabAuteur();
		void reAuteur(int nouvelAuteur, int validerConsulation, int navigation, char choixNavigation[20]);
		void reUpdAuteur(int res, int indice);
	private:

	protected:
};



#endif AUTEUR_H

