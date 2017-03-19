#include "Graphe.h"

template <class S, class T>
void Graphe<S, T>::Ford(){

	source->poids = 0;

	for(int unsigned i = 0; i = lSommets.size(); i++){
		lSommets.at(i)->poids = exp(99);
	}


	for (int unsigned k = 0; k < lSommets.size(); k++){

		vector< pair< Sommet<T> *, Arete<S, T>* > > adjP = adjacencesPlus(lSommets.at(k));
		for (int unsigned j = 0; j < adjP.size(); j++){

			if (adjP.at(j).first->poids  >(adjP.at(j).first->poids + adjP.at(j).second->cout)){

				adjP.at(j).first->poids = adjP.at(j).first->poids + adjP.at(j).second->cout;
				adjP.at(j).first->pere = i;
			}
		}
	}
}