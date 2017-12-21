/**
 * @file formatInstance.cpp
 * @author Mahier Loïc && Phalavandishvili Demetre
 * @since december 21th, 2017
 * @brief fichier contenant les fonctions permettant de lire de trois manières différentes des instances
**/

#ifndef FORMAT_INSTANCE
#define FORMAT_INSTANCE

using namespace std;


/**
 * @name main
 * @brief  
**/
struct Instance
{
	unsigned int nbMachine = 0;
	unsigned int nbTache = 0;
	vector<int> duree;
};


/**
 * @name affchageInstance
 * @brief affiche le contenu d'une instance
 * @param Instance
 * @return
**/
void affichageInstance(Instance instance)
{
	cout << "Nombre de machine : " << instance.nbMachine << endl;
	cout << "Nombre de tâche : " << instance.nbTache << endl;

	for (unsigned int i = 0; i < instance.nbTache; ++i)
	{
		cout << "Duree de la tâche " << i << " : " << instance.duree[i] << endl;
	}
}


/**
 * @name fileReadInstance
 * @brief  
 * @param
 * @return Instance
**/
// Instance fileReadInstance()
// {

// }


/**
 * @name keyboardReadInstance
 * @brief l'instance est saisie au clavier
 * @param
 * @return Instance
**/
Instance keyboardReadInstance()
{
	Instance instance;
	string str;
	string tmp;
	int cpt = 0;

	cout << endl;
	cout << "Veuillez saisir une instance :" << endl;
	cout << "Attention, chaque valeur doit être séparée par le symbole \":\" sans espace, vous indiquerez d'abord le nombre de machine, puis le nombre de tâche et enfin la durée de chaque tâche. " << endl;
	cout << "_________________________________________________________" << endl;
	cout << endl;

	cin >> str;

	for (unsigned int i = 0; i <= str.length(); ++i)
	{
		if ( i != str.length() && (str[i] != ':')) tmp += str[i];
		else if (cpt == 0) 
		{
			instance.nbMachine = stoi(tmp);
			++cpt;
			tmp = "";
		}
		else if (cpt == 1)
		{
			instance.nbTache = stoi(tmp);
			++cpt;
			tmp = "";			
		}
		else 
		{
			instance.duree.push_back(stoi(tmp));
			tmp = "";				
		}
	}

	// on vérifie qu'on a bien autant de durée que de tâche
	assert(instance.nbTache == instance.duree.size());

	return instance;
}


/**
 * @name randomGeneratorInstance
 * @brief l'instance est générée aléatoirement, à partir de 5 entiers saisie par l'utilisateur
 * @param
 * @return Instance
**/
// Instance randomGeneratorInstance()
// {

// }

#endif