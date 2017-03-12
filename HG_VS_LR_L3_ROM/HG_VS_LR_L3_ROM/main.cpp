#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#pragma once
#include "Erreur.h"
#include <fstream>
#include <stdlib.h> 
#include <vector>
//#include "LectureGPR.cpp"

//trim d'un char *
char *trimChar(char *str)
{
	char *end;

	// Trim leading space
	while (isspace((unsigned char)*str)) str++;

	if (*str == 0)  // All spaces?
		return str;

	// Trim trailing space
	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end)) end--;

	// Write new null terminator
	*(end + 1) = 0;

	return str;
}


int main()
{
	ifstream fichier("gpr_files/data_VRPTW_10.gpr");

	if (fichier)
	{
		string line;
		string str;
		int nbRessources;
		char msg[500];

		getline(fichier, line);

		int N = 0, M = 0;

		sscanf(line.c_str(), "# Graphe N = %d ; M = %d", &N, &M);

		if (N != 0 && M != 0){
			// Valeur récupérée avec succès !

			cout << "N = " << N << " et M = " << M << endl;

			//stocker le n° nb ressources
			fichier >> str;
			fichier >> nbRessources;
			fichier >> str;

			//mettre le curseur sur le premier des sections sommets
			getline(fichier, line);
			getline(fichier, line);

			// parcours des secgions sommets et stockage des valeurs de chaque sommets
			while (line !="sources"){

				strcpy(msg, line.c_str());
				vector<char *> message;
				char * pch = strtok(msg, " ");

				while (pch != NULL)
				{
					message.push_back(trimChar(pch));
					pch = strtok(NULL, " ");
				}

				for (vector<char *>::iterator iter = message.begin(); iter != message.end(); iter++)
					cout << *iter << endl;

				getline(fichier, line);
		
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

	system("PAUSE");

	return 0;
}