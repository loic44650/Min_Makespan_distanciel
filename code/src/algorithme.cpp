/**
 * @file algorithme.cpp
 * @author Mahier Loïc && Phalavandishvili Demetre
 * @since december 21th, 2017
 * @brief fichier contenant différents algorithmes d'ordonnancement
**/

#ifndef ALGORITHME
#define ALGORITHME

#include "formatInstance.cpp"
#include <numeric>
#include <algorithm>

using namespace std;


/**
 * @name affchageResulat
 * @brief affiche le résultat des algorithmes LSA, LPT et myAlgo
 * @param vector<Instance>, vector<int>, vector<int>, vector<int>
 * @return
**/
void affichageResultat(vector<Instance> instance, vector<int> resLSA, vector<int> resLPT,vector<int> resMyAlgo) // faudra rajouter le 3 eme algo
{
	assert(resLSA.size() == resLPT.size());
	assert(resLSA.size() == resMyAlgo.size());

	int max = 0;
	int moy = 0;

	// on calcul la moyenne et le maximum en même temps
	for(unsigned int i = 0; i < instance[0].nbTache; ++i)
	{
		moy += instance[0].duree[i];

		if(max < instance[0].duree[i]) max = instance[0].duree[i];  
	}

	// les résultats
	for(unsigned int i = 0; i < resLSA.size(); ++i)
	{
		cout << endl;
		cout << "Pour l'instance n°" << i + 1 << " :" << endl;
		cout << "Borne inférieur maximum : " << max << endl;
		cout << "Borne inférieur moyenne : " << moy / instance[0].nbTache << endl;
		cout << "Résulat LSA : " << resLSA[i] << endl;
		cout << "Résulat LPT : " << resLPT[i] << endl;
		cout << "Résulat myAlgo : " << resMyAlgo[i] << endl;
		cout << endl;
	}
}


/**
 * @name ecritureResulat
 * @brief écrit le résultat des algorithmes LSA, LPT et myAlgo dans un fichier
 * @param vector<Instance>, vector<int>, vector<int>, vector<int>
 * @return
**/
void ecritureResultat(vector<Instance> inst, vector<int> resLSA, vector<int> resLPT,vector<int> resMyAlgo) // faudra rajouter le 3 eme algo
{
	assert(resLSA.size() == resLPT.size());
	assert(resLSA.size() == resMyAlgo.size());

	string nomFichier;
	int maxi;
	int moy;
	int cpt = 0;
	int mI;
	double sumLSA = 0, sumLPT = 0,sumMyAlgo = 0;

	cout << endl;
	cout << "Veuillez saisir le nom du fichier dans lequel écrire le résultat :" << endl;
	cout << "______________________________________________________________" << endl;
	cout << endl;

	cin >> nomFichier;	

	ofstream fichier(nomFichier);

	if(!fichier.is_open()) cerr << "Impossible d'ouvrir le fichier " << nomFichier << " !" << endl;
	else
	{
		// on écrit dans le fichier
		fichier << "================================================" << endl;
		fichier << " Résulats des instances générées aléatoirements " << endl;
		fichier << "================================================" << endl;
		fichier << endl;		

		for(auto n : inst)
		{
			maxi = 0;
			moy = 0;

			// on calcul la moyenne et le maximum en même temps
			for(unsigned int i = 0; i < n.nbTache; ++i)
			{
				moy += n.duree[i];

				if(maxi < n.duree[i]) maxi = n.duree[i];  
			}

			// les résultats
			fichier << "Pour l'instance n°" << cpt + 1 << " :" << endl;
			fichier << "Borne inférieur maximum : " << maxi << endl;
			fichier << "Borne inférieur moyenne : " << moy / n.nbTache << endl;
			fichier << "Résulat LSA : " << resLSA[cpt] << endl;
			fichier << "Résulat LPT : " << resLPT[cpt] << endl;
			fichier << "Résulat myAlgo : " << resMyAlgo[cpt]<< endl;
			fichier << endl;
			fichier << "================================================" << endl;
			fichier << endl;

			mI = max(maxi,(moy /(int) n.nbTache) );
			sumLSA += resLSA[cpt] / mI;
			sumLPT += resLPT[cpt] / mI;
			sumMyAlgo += resMyAlgo[cpt] / mI;

			++cpt;
		}

		// les ratios d'approximation
		fichier << "Ratio d'approximation moyen LSA : " << sumLSA / inst.size() << endl;
		fichier << "Ratio d'approximation moyen LPT : " << sumLPT / inst.size() << endl;
		fichier << "Ratio d'approximation moyen myAlgo : " << sumMyAlgo / inst.size() << endl;
		fichier << "================================================" << endl;
		fichier << endl;

		fichier.close();
	}
}


/**
 * @name LSA
 * @brief List Scheduling Algorithm 
 * @param vector<Instance>
 * @return vector<int>
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

		// on recupère le maximum
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
 * @brief retourne vrai si i est supérieur strict à j 
 * @param int, int
 * @return bool
**/
bool sup(int i, int j) { return(i > j); }


/**
 * @name LPT
 * @brief Largest Processing Time 
 * @param vector<Instance>
 * @return vector<int>
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

		// on va parcourir toutes les tâches et les atribuer à la première machine disponible
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

		// on recupère le maximum
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
 * @brief ordonne les tâches en fonction de la moyenne de la durée totale par machine 
 * @param vector<Instance>
 * @return vector<int>
**/
vector<int> myAlgo(vector<Instance> instance)
{
	vector<int> resultat;
	vector<int> machines;
	int moyenne, indiceMachine, somme, tmp;
	unsigned int i, j;
	bool stopLoop = false;

	for(auto inst : instance)
	{
		// calcul de la moyenne en utilisant la fonction de STL de c++
		moyenne = accumulate(inst.duree.begin(), inst.duree.end(), 0) / inst.nbMachine;

		// on crée nos machines, et on les mets à 0
		for(unsigned int m = 0; m < inst.nbMachine; ++m)
		{
			machines.push_back(0);
		}

		i = 0;
		indiceMachine = 0;

		// Début du parcours des tâches sans ordre specifique
		while(i < inst.nbTache)
		{	
			somme = 0;
			j = i;
			stopLoop = false;
			
			// Parcours des tâches pour affecter à la machine d'indice 'indiceMachine'
			while((j < inst.nbTache) && (!stopLoop))
			{
				somme += inst.duree[j];
				
				// On verifie si la somme des tâches parcourues dépasse la moyenne
				if(somme >= moyenne) 
				{
					stopLoop = true;
					machines[indiceMachine] = somme;
					++indiceMachine;
				}
				
				++j;
			}

			i = j;		
		}

		tmp = 0;

		// on recupère le maximum
		for(unsigned int k = 1; k < inst.nbMachine; ++k)
		{
			if(machines[k] > machines[tmp]) tmp = k;
		}

		resultat.push_back(machines[tmp]);
		machines.clear();
	}

	return resultat;
}


#endif
