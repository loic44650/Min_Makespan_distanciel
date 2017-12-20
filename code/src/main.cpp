#include <iostream>

#include "algo.cpp"

using namespace std;

int main()
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

				done = true;
				break;

			case 2 : // clavier

				done = true;
				break;

			case 3 : //générateur aléatoire
			
				done = true;
				break;

			default :
				cout << "La saisie du choix à est incorrecte ! Veuillez recommencer." << endl;
				cout << endl;
				break;
		}
	}



	return 0;
}