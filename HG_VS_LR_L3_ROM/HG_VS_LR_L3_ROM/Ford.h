#include "Graphe.h"

template <class S, class T>
void ford(){

	source->poids = 0;

	for (int unsigned i = 1; i < lSommets.size(); i++){
		lSommets.at(i)->poids = 9999999;
	}

	for (int unsigned k = 0; k < lSommets.size(); k++){

		vector< pair< Sommet<T> *, Arete<S, T>* > > adjP = adjacencesPlus(lSommets.at(k));

		for (int unsigned j = 0; j < adjP.size(); j++){

			if (poidsJ  >(poidsPere + poidsArc)){

				adjP.at(j).first->poids = lSommets.at(k)->poids + adjP.at(j).second->cout;
				adjP.at(j).first->pere = k;
			}
		}
	}
}