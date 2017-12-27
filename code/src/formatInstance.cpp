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
 * @name Instance
 * @brief struture de notre instance : un nombre de machine et un nombre e tâche ainsi qu'un vecteur contenant leurs durées
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
void affichageInstance(vector<Instance> instance)
{
	for(auto n : instance)
	{
		cout << "Nombre de machine : " << n.nbMachine << endl;
		cout << "Nombre de tâche : " << n.nbTache << endl;

		for(unsigned int i = 0; i < n.nbTache; ++i)
		{
			cout << "Duree de la tâche " << i << " : " << n.duree[i] << endl;
		}
	}
	
	cout << endl;
}


/**
 * @name fileReadInstance
 * @brief l'instance est lu à partir dun fichier
 * @param
 * @return Instance
**/
vector<Instance> fileReadInstance()
{
	vector<Instance> vector;
	Instance instance;
	string nomFichier;
	string str;
	string tmp;
	int cpt = 0;

	cout << endl;
	cout << "Veuillez saisir le nom du fichier contenant l'instance :" << endl;
	cout << "_________________________________________________________" << endl;
	cout << endl;

	cin >> nomFichier;	

	ifstream fichier(nomFichier);

	if(!fichier.is_open()) cerr << "Impossible d'ouvrir le fichier " << nomFichier << " !" << endl;
	else
	{
		while(!fichier.eof())
		{
			getline(fichier, str);

			for(unsigned int i = 0; i <= str.length(); ++i)
			{
				if(i != str.length() && (str[i] != ':')) tmp += str[i];
				else if(cpt == 0) 
				{
					instance.nbMachine = stoi(tmp);
					++cpt;
					tmp = "";
				}
				else if(cpt == 1)
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
		}		

		fichier.close();
	}

	// on vérifie qu'on a bien autant de durée que de tâche
	assert(instance.nbTache == instance.duree.size());

	vector.push_back(instance);

	return vector;
}


/**
 * @name keyboardReadInstance
 * @brief l'instance est saisie au clavier
 * @param
 * @return Instance
**/
vector<Instance> keyboardReadInstance()
{
	vector<Instance> vector;
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

	for(unsigned int i = 0; i <= str.length(); ++i)
	{
		if(i != str.length() && (str[i] != ':')) tmp += str[i];
		else if(cpt == 0) 
		{
			instance.nbMachine = stoi(tmp);
			++cpt;
			tmp = "";
		}
		else if(cpt == 1)
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

	vector.push_back(instance);

	return vector;
}


/**
 * @name randomGeneratorInstance
 * @brief plusieurs instances sont générées aléatoirements, à partir de 5 entiers saisie par l'utilisateur
 * @param
 * @return Instance
**/
vector<Instance> randomGeneratorInstance()
{
	vector<Instance> vector;
	Instance instance;
	int nbMachine;
	int nbTache;
	int nbInstance;
	int min;
	int max;

	cout << endl;
	cout << "Veuillez saisir ces informations pour générer des instances aléatoires :" << endl;
	cout << "_________________________________________________________________________" << endl;
	cout << endl;
	cout << "Nombre de machine : " ; cin >> nbMachine; cout << endl;
	cout << "Nombre de tâche : " ; cin >> nbTache; cout << endl;
	cout << "Nombre d'instance : " ; cin >> nbInstance; cout << endl;
	cout << "Duree min : " ; cin >> min; cout << endl;
	cout << "Duree max : " ; cin >> max; cout << endl;

	instance.nbMachine = nbMachine;
	instance.nbTache = nbTache;

	for(int i = 0; i < nbInstance; ++i)
	{
		instance.duree.clear();

		for(int j = 0; j < nbTache; ++j)
		{
			int temp = (rand() % ((max-min)+1)) + min;
			instance.duree.push_back(temp); // probleme au niveau du random je crois
			// l'interval n'ai pas bon !!
		}

		vector.push_back(instance);
	}

	return vector;
}

#endif
