#include <iostream>

#include "algo.cpp"

using namespace std;

// Déclaration des fonctions / procédures

//void fileReadInstance();
//void keyboardReadInstance();
//void randomGeneratorInstance();



// Programme principal

int main(int argc, char** argv)
{
	
	int choix;
	bool done = false;

	// Menu
	while (!done)
	{
		cout << endl;
		cout << "Bonjour, quelle type d'instance souhaitez-vous traiter ?" << endl;
		cout << "_________________________________________________________" << endl;
		cout << endl;
		cout << "Pour traiter une instance à partir d'un fichier, tapez 1." << endl;
		cout << "Pour traiter une instance saisie au clavier, tapez 2." << endl;
		cout << "Pour traiter une instance générée aléatoirement, tapez 3." << endl;
		
		cin >> choix;

		switch (choix)
		{
			case 1 : // fichier
				//fileReadInstance();
				done = true;
				break;

			case 2 : // clavier
				//keyboardReadInstance();
				done = true;
				break;

			case 3 : //générateur aléatoire
				//randomGeneratorInstance();
				done = true;
				break;

			default :
				cout << "La saisie du choix à est incorrecte ! Veuillez recommencer." << endl;
				cout << endl;
				break;
		}
	}

	// menu incomplet --> gérer les résultats




	return 0;
}

