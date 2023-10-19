#ifndef MYBDD_H
#define MYBDD_H

#include "../Auteur/auteur.h"
#include "../Editeur/editeur.h"
#include "../Livre/livre.h"

class db {
public:
	void consultation(int valide, int navigato, char choixNav[20]);
	void actionChoix(int valide, char choixNav[20], int action, int nav, int newElement, int indice, int modifier);


	//Auteur* test = tabAuteurs;

private:
	
protected:
};

#endif // MYBDD_H

