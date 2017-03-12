#pragma once
//#include "LectureGPR.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 
#include "Vecteur2D.h"
#include "Graphe.h"

using namespace std;

int main()
{
	Vecteur2D v1(1, 2);
	Vecteur2D v2(3, 1);
	Vecteur2D v3(5, 2);
	Vecteur2D v4(5, 3);
	Vecteur2D v5(3, 4);
	Vecteur2D v6(1, 3);


	Graphe<double, Vecteur2D> g2;
	Sommet<Vecteur2D> *som1 = g2.creeSommet("s1", v1);
	Sommet<Vecteur2D> *som2 = g2.creeSommet("s2", v2);
	Sommet<Vecteur2D> *som3 = g2.creeSommet("s3", v3);
	Sommet<Vecteur2D> *som4 = g2.creeSommet("s4", v4);
	Sommet<Vecteur2D> *som5 = g2.creeSommet("s5", v5);
	Sommet<Vecteur2D> *som6 = g2.creeSommet("s6", v6);

	Arete<double, Vecteur2D> * arr1 = g2.creeArete(som1, som3, som1->v.distance(som3->v));
	g2.creeArete(som3, som5, som3->v.distance(som5->v));
	g2.creeArete(som5, som6, som5->v.distance(som6->v));
	g2.creeArete(som6, som4, som6->v.distance(som4->v));
	g2.creeArete(som4, som2, som4->v.distance(som2->v));
	g2.creeArete(som2, som1, som2->v.distance(som1->v));


	cout << "g2 = " << g2 << endl;

	Graphe<double, Vecteur2D> g = g2;

	cout << "g = " << g << endl;
	/*
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

	*/

	system("PAUSE");

	return 0;
}