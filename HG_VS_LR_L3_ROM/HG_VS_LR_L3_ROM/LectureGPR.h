#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#pragma once
#include "Erreur.h"
#include "Graphe.h"
#include <fstream>
#include <stdlib.h> 
#include <vector>

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


Graphe<int,int> gprToGraphe(const string & fileName)
{
	ifstream fichier(fileName);
	Graphe<int, int> * g = new Graphe<int, int>();

	if (fichier)
	{
		string line;
		string str;
		string nbRessources;
		char msg[500];

		getline(fichier, line);

		//stocker le n° nb ressources
		fichier >> str;
		fichier >> nbRessources;
		fichier >> str;

		//mettre le curseur sur le premier des sections sommets
		getline(fichier, line);
		getline(fichier, line);

		cout << "==================" << endl;
		cout << "SECTIONS SOMMETS" << endl;
		cout << "==================" << endl;

		// parcours des sections sommets et stockage des valeurs de chaque sommets
		while (line != "sources"){

			strcpy(msg, line.c_str());
			vector<char *> sommets;
			char * pch = strtok(msg, " ");

			while (pch != NULL)
			{
				sommets.push_back(trimChar(pch));
				pch = strtok(NULL, " ");
			}

			int sizeSom = sommets.size();
			
			if (sizeSom != 0){

				if (sizeSom == 1){	
					g->creeSommet2(sommets[0]);
					
				}
				else if (sizeSom == 3) {
					g->creeSommet(sommets[0], atoi(sommets[1]), atoi(sommets[2]));
				}				
			}

			getline(fichier, line);

		}

		// AFFICHAGE SOMMETS==========
		for (vector<Sommet<int>*>::iterator it = g->lSommets.begin(); it != g->lSommets.end(); ++it){
			cout << **it << endl;
		}
		
		cout << endl << "==================" << endl;
		cout << " SOURCES" << endl;
		cout << "==================" << endl;
		getline(fichier, line);

		// parcours des sections sommets et stockage des valeurs de chaque sources
		while (line != "puits"){

			strcpy(msg, line.c_str());
			vector<char *> sources;
			char * pch = strtok(msg, " ");

			while (pch != NULL)
			{
				sources.push_back(trimChar(pch));
				pch = strtok(NULL, " ");
			}
		
			// AFFICHAGE SOURCES==========
			for (vector<char *>::iterator iter = sources.begin(); iter != sources.end(); iter++)
				cout << *iter << " ";
			cout << endl;
			
			getline(fichier, line);
		}

		cout << "==================" << endl;
		cout << " PUITS" << endl;
		cout << "==================" << endl;
		getline(fichier, line);

		// parcours des secgions sommets et stockage des valeurs de chaque puits
		while (line != "sectionArcs"){

			strcpy(msg, line.c_str());
			vector<char *> puits;
			char * pch = strtok(msg, " ");

			while (pch != NULL)
			{
				puits.push_back(trimChar(pch));
				pch = strtok(NULL, " ");
			}

			// AFFICHAGE PUITS==========
			for (vector<char *>::iterator iter = puits.begin(); iter != puits.end(); iter++)
				cout << *iter << " ";
			cout << endl;
			
			getline(fichier, line);

		}

		cout << "==================" << endl;
		cout << " ARCS" << endl;
		cout << "==================" << endl;
		getline(fichier, line);

		// parcours des secgions sommets et stockage des valeurs de chaque puits
		while (line != "sectionGraphes"){

			strcpy(msg, line.c_str());
			vector<char *> arcs;
			char * pch = strtok(msg, " ");

			while (pch != NULL)
			{
				arcs.push_back(trimChar(pch));
				pch = strtok(NULL, " ");
			}
			
			int sizeArc = arcs.size();

			Sommet<int> * s1;
			Sommet<int> * s2;

			if (sizeArc != 0){
				for (vector<Sommet<int>*>::iterator it = g->lSommets.begin(); it != g->lSommets.end(); ++it){
					s1 = g->getSommetByName(string(arcs[1]));
					s2 = g->getSommetByName(string(arcs[2]));
				}
				g->creeArete(s1, s2, atoi(arcs[3]), atoi(arcs[4]));
			}

			getline(fichier, line);

		}

		// AFFICHAGE ARCS==========
		for (vector<Arete<int,int>*>::iterator it = g->lAretes.begin(); it != g->lAretes.end(); ++it){
			cout << **it << endl;
		}

		cout << endl << "==================" << endl;
		cout << " GRAPHE" << endl;
		cout << "==================" << endl;

		// parcours des sections sommets et stockage des valeurs de chaque puits
		while (getline(fichier, line)){

			strcpy(msg, line.c_str());
			vector<char *> arcs;
			char * pch = strtok(msg, " ");

			while (pch != NULL)
			{
				arcs.push_back(trimChar(pch));
				pch = strtok(NULL, " ");
			}
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
	
	// AFFICHAGE GRAPHE==========
	cout << *g << endl;
	
	return *g;
}