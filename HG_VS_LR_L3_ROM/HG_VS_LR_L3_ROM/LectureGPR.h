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


//template <S,T>
void GprToGraphe(const string & fileName)
{
	ifstream fichier(fileName);

	if (fichier)
	{
		string line;
		string str;
		string nbRessources;
		char msg[500];
		Graphe<int, int> * g = new Graphe<int, int>();
		vector<Sommet<int>*> * vSommets = new vector<Sommet<int>*>();

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
					Sommet<int> * s = new Sommet<int>(sommets[0]);
					vSommets->push_back(s);
					cout << *s << endl;
				}
				else if (sizeSom == 3) {
					Sommet<int> * s = new Sommet<int>(sommets[0], atoi(sommets[1]), atoi(sommets[2]));
					vSommets->push_back(s);
					cout << *s << endl;
				}
					
			}

			getline(fichier, line);

		}

		/*
		PK CA MARCHE PAS WESH HELP
		g->lSommets = new vector<Sommet<int>*>(vSommets);

		for (vector<Sommet<int>*>::iterator it = (g->getSommets())->begin(); it != (g->getSommets())->end(); ++it){
			cout << **it << endl;
		}
		*/

		cout << "==================" << endl;
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

			for (vector<char *>::iterator iter = puits.begin(); iter != puits.end(); iter++)
				cout << *iter << " ";
			cout << endl;
			getline(fichier, line);

		}

		cout << "==================" << endl;
		cout << " ARCS" << endl;
		cout << "==================" << endl;
		getline(fichier, line);



		cout << vSommets->size() << endl;

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

			
			for (vector<char *>::iterator iter = arcs.begin(); iter != arcs.end(); iter++)
				cout << *iter << " ";
			cout << endl;
			

			int sizeArc = arcs.size();

			
			Sommet<int> * s1;
			Sommet<int> * s2;

			if (sizeArc != 0){
				for (vector<Sommet<int>*>::iterator it = vSommets->begin(); it != vSommets->end(); ++it){
					
					//cout << **it << endl;
					/*
					s1 = g.getSommetByName(string(arcs[1]));					
					s2 = g.getSommetByName(string(arcs[2]));
					cout << "S1 = " << *s1 << endl;
					cout << "S2 = " << *s2 << endl;
					*/
				}
			}
			
			/*
			if (sizeArc == 5){
				Arete<int, int> * a = new Arete<int, int>(s, s2, atoi(arcs[3]), atoi(arcs[4]));
				cout << *a << endl;
			}
			*/
			

			getline(fichier, line);

		}

		cout << "==================" << endl;
		cout << " GRAPHE" << endl;
		cout << "==================" << endl;

		// parcours des secgions sommets et stockage des valeurs de chaque puits
		while (getline(fichier, line)){

			strcpy(msg, line.c_str());
			vector<char *> arcs;
			char * pch = strtok(msg, " ");

			while (pch != NULL)
			{
				arcs.push_back(trimChar(pch));
				pch = strtok(NULL, " ");
			}

			for (vector<char *>::iterator iter = arcs.begin(); iter != arcs.end(); iter++)
				cout << *iter << " ";
			cout << endl;
		}

	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}

}