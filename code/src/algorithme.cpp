/**
 * @file algorithme.cpp
 * @author Mahier Loïc && Phalavandishvili Demetre
 * @since december 21th, 2017
 * @brief fichier contenant différents algorithmes d'ordonnancement
**/

#ifndef ALGORITHME
#define ALGORITHME

#include "formatInstance.cpp"

using namespace std;


/**
 * @name affchageResulat
 * @brief affiche le resulat des algorithmes LSA et LPT
 * @param vector<Instance>, vector<int>, vector<int>
 * @return
**/
void affichageResultat(vector<Instance> instance, vector<int> resLSA, vector<int> resLPT) // faudra rajouter le 3 eme algo
{
	assert(resLSA.size() == resLPT.size());

	int max = 0;
	int moy = 0;

	for(unsigned int i = 0; i < instance[0].nbTache; ++i)
	{
		moy += instance[0].duree[i];

		if(max < instance[0].duree[i]) max = instance[0].duree[i];  
	}

	for(unsigned int i = 0; i < resLSA.size(); ++i)
	{
		cout << endl;
		cout << "Pour l'instance n°" << i + 1 << " :" << endl;
		cout << "Borne inférieur maximum : " << max << endl;
		cout << "Borne inférieur moyenne : " << moy / instance[0].nbTache << endl;
		cout << "Résulat LSA : " << resLSA[i] << endl;
		cout << "Résulat LPT : " << resLPT[i] << endl;
		cout << "Résulat myAlgo : " << endl;
		cout << endl;
	}
}


/**
 * @name ecritureResulat
 * @brief écrit le resulat des algorithmes LSA et LPT dans un fichier
 * @param vector<Instance>, vector<int>, vector<int>
 * @return
**/
void ecritureResultat(vector<Instance> inst, vector<int> resLSA, vector<int> resLPT) // faudra rajouter le 3 eme algo
{
	string nomFichier;
	int max;
	int moy;
	int cpt = 0;

	assert(resLSA.size() == resLPT.size());

	cout << endl;
	cout << "Veuillez saisir le nom du fichier contenant l'instance :" << endl;
	cout << "_________________________________________________________" << endl;
	cout << endl;

	cin >> nomFichier;	

	ofstream fichier(nomFichier);

	if(!fichier.is_open()) cerr << "Impossible d'ouvrir le fichier " << nomFichier << " !" << endl;
	else
	{
		fichier << "================================================" << endl;
		fichier << " Résulats des instances générées aléatoirements " << endl;
		fichier << "================================================" << endl;
		fichier << endl;		

		for(auto n : inst)
		{
			max = 0;
			moy = 0;

			for(unsigned int i = 0; i < n.nbTache; ++i)
			{
				moy += n.duree[i];

				if(max < n.duree[i]) max = n.duree[i];  
			}

			moy /= n.nbTache;

			fichier << endl;
			fichier << "Pour l'instance n°" << cpt + 1 << " :" << endl;
			fichier << "Borne inférieur maximum : " << max << endl;
			fichier << "Borne inférieur moyenne : " << moy << endl;
			fichier << "Résulat LSA : " << resLSA[cpt] << endl;
			fichier << "Résulat LPT : " << resLPT[cpt] << endl;
			fichier << "Résulat myAlgo : " << endl;
			fichier << "================================================" << endl;
			fichier << endl;

			++cpt;
		}

		// ratio à calculer !!

		fichier << endl;
		fichier << "Ratio d'approximation moyen LSA : " << endl;
		fichier << "Ratio d'approximation moyen LPT : " << endl;
		fichier << "Ratio d'approximation moyen myAlgo : " << endl;
		fichier << "================================================" << endl;
		fichier << endl;

		fichier.close();
	}
}


/**
 * @name LSA
 * @brief List Scheduling Algorithm 
 * @param vector<Instance>
 * @return
**/
vector<int> LSA(vector<Instance> instance)
{
	vector<int> machines;
	vector<int> resultat;
	int tmp;

	for(auto inst : instance)
	{
		// on crée nos machines, et on les mets à 0
		for(unsigned int i = 0; i < inst.nbMachine; ++i)
		{
			machines.push_back(0);
		}

		// on va parcourir toutes les tâches et les atribuées à la première machine disponible
		for(auto dureeTache : inst.duree)
		{
			tmp = 0;

			for(unsigned int j = 1; j < inst.nbMachine; ++j)
			{
				if(machines[j] < machines[tmp]) tmp = j;
			}

			machines[tmp] += dureeTache; 
		}

		tmp = 0;

		// on recup le max
		for(unsigned int k = 1; k < inst.nbMachine; ++k)
		{
			if(machines[k] > machines[tmp]) tmp = k;
		}

		resultat.push_back(machines[tmp]);
		machines.clear();
	}

	return resultat;
}


/**
 * @name sup
 * @brief  
 * @param
 * @return
**/
bool sup(int i, int j) { return(i > j); }


/**
 * @name LPT
 * @brief Largest Processing Time 
 * @param vector<Instance>
 * @return
**/
vector<int> LPT(vector<Instance> instance)
{
	vector<int> machines;
	vector<int> resultat;
	int tmp;

	for(auto inst : instance)
	{
		// on ordonne de manière décroissante nos durées
		sort(inst.duree.begin(), inst.duree.end(), sup);
		
		// on crée nos machines, et on les mets à 0
		for(unsigned int i = 0; i < inst.nbMachine; ++i)
		{
			machines.push_back(0);
		}

		// on va parcourir toutes les tâches et les atribuées à la première machine disponible
		for(auto dureeTache : inst.duree)
		{
			tmp = 0;

			for(unsigned int j = 1; j < inst.nbMachine; ++j)
			{
				if(machines[j] < machines[tmp]) tmp = j;
			}

			machines[tmp] += dureeTache; 
		}

		tmp = 0;

		// on recup le max
		for(unsigned int k = 1; k < inst.nbMachine; ++k)
		{
			if(machines[k] > machines[tmp]) tmp = k;
		}

		resultat.push_back(machines[tmp]);
		machines.clear();
	}

	return resultat;
}
	

/**
 * @name myAlgo
 * @brief  
 * @param vector<Instance>
 * @return
**/
vector<int> myAlgo(vector<Instance> instance)
{
	vector<int> resultat;



	return resultat;
}


#endif
