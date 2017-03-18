#include "Graphe.h"

template <class S, class T>
void Graphe<S, T>::Ford_Bellman(){

	int nbIter = 0;
	source->pairPA.first = 0;
	bool fin = false;

	for (int unsigned i = 1; i = lSommets.size(); i++){
		lSommets.at(i)->pairPA.first = exp(99);
	}

	while (k < (lSommets.size() - 1) && !fin){

	}

	/*

	for (int unsigned k = 0; k < lSommets.size(); i++){

		vector< pair< Sommet<T> *, Arete<S, T>* > > adjP = adjacencesPlus(lSommets.at(k));
		for (int unsigned j = 0; j < adjP.size(); j++){

			if (adjP.at(j).first->pairPA.first >(adjP.at(j).first->pairPA.first + adjP.at(j).second->cout)){

				adjP.at(j).first->pairPA.first = adjP.at(j).first->pairPA.first + adjP.at(j).second->cout;
				adjP.at(j).first->pere = i;
			}
		}
	}
}