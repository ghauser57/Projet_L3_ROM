#include "Graphe.h"

template <class S, class T>
void Graphe<S, T>::Ford_Bellman(){

	int nbIter = 0;
	source->pairPA.first = 0;
	bool fin = false;

	for (int unsigned i = 1; i = lSommets.size(); i++){
		lSommets.at(i)->pairPA.first = exp(99);
	}


	for (int unsigned k = 0; k < lSommets.size(); i++){

		while (k < (lSommets.size() - 1) && !fin){

			k++;
			fin = true;
			lSommets.at(k)->pairPA.first = 0;
			lSommets.at(k)->pairPA.second = k;

			for (int unsigned j = 1; j = lSommets.size(); j++){
				
				vector< pair< Sommet<T> *, Arete<S, T>* > > adj = adjacences(lSommets.at(j));
				int min = exp(99);

				for (int unsigned j = 0; j = adj.size(); j++){
					if (min > (adj.at(j).first->pairPA.first + adj.at(j).second->cout))
						min = (adj.at(j).first->pairPA.first + adj.at(j).second->cout);
				}

				//if (lSommets.at(k)->pairPA.first = 0)
				// fin = false;
			}

		}

		if (!fin)
			//Il y a un circuit de valeur negatif

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

	*/
}