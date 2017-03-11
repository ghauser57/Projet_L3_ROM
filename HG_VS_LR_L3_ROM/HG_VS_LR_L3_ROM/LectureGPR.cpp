#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 

using namespace std;

//template <S,T>
void GrpToGraphe(const string & fileName)
{
	ifstream fichier(fileName, ios::in);  // on ouvre le fichier en lecture

	if (fichier)  // si l'ouverture a réussi
	{
		// string qui va contenir les ligne du fichiers
		string line;

		while (getline(fichier, line)){
			cout << line << endl;
		}


		fichier.close();  // on ferme le fichier
	}
	else  // sinon
		cerr << "Impossible d'ouvrir le fichier !" << endl;
}