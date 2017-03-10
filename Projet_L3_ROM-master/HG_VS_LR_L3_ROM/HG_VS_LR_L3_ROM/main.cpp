#pragma once
//#include "LectureGPR.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 

using namespace std;

int main()
{
	ifstream fichier("gpr_files/data_VRPTW_10_3_2_4.gpr");

	if (fichier)
	{
		string ligne; //Une variable pour stocker les lignes lues
		int n;
		int position;
		//int m;

		while (getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
		{
		cout << ligne << endl;

		//fichier.seekg(0, ios::end);
		//fichier >> n;
		//fichier.seekg(8, ios::cur);
		//fichier >> m;
		//position = fichier.tellg();
		//cout << n << endl;

		//cout << position << endl;


		//getline(fichier, ligne);
		//getline(fichier, ligne);
		//cout << ligne << endl;
		//position = fichier.tellg();
		//cout << position << endl;
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}



	system("PAUSE");

	return 0;
}