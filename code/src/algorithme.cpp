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
 * @name affchageResulata
 * @brief affiche le resulat des algorithmes LSA et LPT
 * @param vector<int>, vector<int>
 * @return
**/
void affichageResultat(vector<int> resLSA, vector<int> resLPT)
{
	assert(resLSA.size() == resLPT.size());

	for(unsigned int i = 0; i < resLSA.size(); ++i)
	{
		cout << endl;
		cout << "Pour l'instance n°" << i << " :" << endl;
		cout << "Résulat LSA : " << resLSA[i] << endl;
		cout << "Résulat LSA : " << resLPT[i] << endl;
		cout << endl;
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
	}

	return resultat;
}
	

/**
 * @name myAlgo
 * @brief  
 * @param vector<Instance>
 * @return
**/
// vector<int> myAlgo(vector<Instance> instance)
// {
// 	vector<int> resultat;


// 	return resultat;
// }

#endif
