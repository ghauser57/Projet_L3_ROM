#pragma once
#include "Graphe.h"
#include "LectureGPR.h"

void dijkstra(){

	Graphe<int, int> g = gprToGraphe("gpr_files/data_VRPTW_10.gpr");
	g.source->marquage = true;
	bool tousMarque = true;
	for (vector<Sommet<int>*>::iterator it = g.lSommets.begin(); it != g.lSommets.end(); ++it){
		if ((*it)->marquage){
			tousMarque = false;
		}
	}

	int nbsommets = g.nombreSommets();
	int k = 0, y = 0;
	bool fin = false;

	int nbsommets = 10;

	for (int i = 1; i < nbsommets; i++){
		y = 9999999;
	}

	while (tousMarque && !fin){
		for (vector<Sommet<int>*>::iterator it = g.lSommets.begin(); it != g.lSommets.end(); ++it){
			if (!(*it)->marquage){
				if (){

				}
			}
		}
	}

}