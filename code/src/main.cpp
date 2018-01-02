/**
 * @file main.cpp
 * @author Mahier Loïc && Phalavandishvili Demetre
 * @since december 20th, 2017
 * @brief programme principal
**/


#include <iostream>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "algorithme.cpp"
#include "formatInstance.cpp"

using namespace std;


/**
 * @name main
 * @brief fonction main du programme principal
 * @param
 * @return
**/
int main(int argc, char** argv)
{
	vector<Instance> instance; 
	int choix;
	bool done = false;

	// Menu instance
	while (!done)
	{
		cout << endl;
		cout << "Bonjour, quel type d'instance souhaitez-vous traiter ?" << endl;
		cout << "_______________________________________________________" << endl;
		cout << endl;
		cout << "Pour traiter une instance à partir d'un fichier, tapez 1." << endl;
		cout << "Pour traiter une instance saisie au clavier, tapez 2." << endl;
		cout << "Pour traiter une instance générée aléatoirement, tapez 3." << endl;
		cout << "Pour quitter l'application, tapez 4." << endl;		
		cout << endl;

		cin >> choix;

		switch (choix)
		{
			case 1 : // fichier
				instance = fileReadInstance();
				affichageInstance(instance);
				affichageResultat(instance, LSA(instance), LPT(instance),myAlgo(instance));
				break;

			case 2 : // clavier
				instance = keyboardReadInstance();
				// affichageInstance(instance);
				affichageResultat(instance, LSA(instance), LPT(instance),myAlgo(instance));
				break;

			case 3 : // générateur aléatoire
				instance = randomGeneratorInstance();
				affichageInstance(instance);
				ecritureResultat(instance, LSA(instance), LPT(instance),myAlgo(instance));
				break;

			case 4 : // fermeture de l'appli.
				done = true;
				break;	
			
			default : // mauvais choix
				cout << endl;
				cerr << "La saisie du choix est incorrecte ! Veuillez recommencer." << endl;
				cout << endl;
				break;
		}
	}

	return 0;
}
