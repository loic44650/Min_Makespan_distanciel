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
				affichageResultat(LSA(instance), LPT(instance));
				break;

			case 2 : // clavier
				instance = keyboardReadInstance();
				affichageResultat(LSA(instance), LPT(instance));
				break;

			case 3 : // générateur aléatoire
				instance = randomGeneratorInstance();
				break;

			case 4 :
				done = true;
				break;	
			
			default :
				cout << endl;
				cerr << "La saisie du choix est incorrecte ! Veuillez recommencer." << endl;
				cout << endl;
				break;
		}
	}




	// test
	// affichageInstance(instance);

	// test
	// affichageResultat(LSA(instance), LPT(instance));
	// vector<int> maxLSA = LSA(instance);
	// vector<int> maxLPT = LPT(instance);
	// cout << endl;
	// cout << "Temps max LSA : " << maxLSA[0] << endl;
	// cout << "Temps max LPT : " << maxLPT[0] << endl;

	// a priori on fait tjrs les 3 algos, donc pas besoin de menu

	// done = false;

	// Menu algo
	// while (!done)
	// {
	// 	cout << endl;
	// 	cout << "A l'aide de quel algorithme souhaitez-vous traiter cette instance ?" << endl;
	// 	cout << "____________________________________________________________________" << endl;
	// 	cout << endl;
	// 	cout << "Pour traiter une instance à l'aide du LSA, tapez 1." << endl;
	// 	cout << "Pour traiter une instance à l'aide du LPT, tapez 2." << endl;
	// 	cout << "Pour traiter une instance à l'aide de l'algo mystère, tapez 3." << endl;
	// 	cout << endl;

	// 	cin >> choix;

	// 	switch (choix)
	// 	{
	// 		case 1 : // LSA
	// 			// LSA();
	// 			done = true;
	// 			break;

	// 		case 2 : // LPT
	// 			// LPT();
	// 			done = true;
	// 			break;

	// 		case 3 : // MyAlgo
	// 			// MyAlgo();
	// 			done = true;
	// 			break;

	// 		default :
	// 			cout << endl;
	// 			cout << "La saisie du choix est incorrecte ! Veuillez recommencer." << endl;
	// 			cout << endl;
	// 			break;
	// 	}
	// }

	// incomplet --> afficher les résultats




	return 0;
}
