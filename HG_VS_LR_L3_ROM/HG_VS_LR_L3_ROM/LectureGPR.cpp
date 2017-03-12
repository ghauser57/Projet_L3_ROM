#ifdef _MSC_VER

#define _CRT_SECURE_NO_WARNINGS

#endif



#pragma once

#include "Erreur.h"

#include <fstream>

#include <stdlib.h> 





//template <S,T>

void GrpToGraphe(const string & fileName)

{

	ifstream fichier(fileName);



	if (fichier)

	{

		string line;

		string str;

		int nbRessources;



		getline(fichier, line);



		int N = 0, M = 0;



		sscanf(line.c_str(), "# Graphe N = %d ; M = %d", &N, &M);



		if (N != 0 && M != 0){

			// Valeur récupérée avec succès !



			cout << "N = " << N << " et M = " << M << endl;



			fichier >> str;

			fichier >> nbRessources;

			fichier >> str;



			for (int i = 0; i < N; i++){



			}

		}

		else{

			// Erreur (La chaîne ne corresponds pas au format)



			cout << "Erreur de valeur du M " << endl;

		}



	}

	else

	{

		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;

	}



}