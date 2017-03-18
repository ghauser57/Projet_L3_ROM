#include "Graphe.h"

template <class S, class T>
void Graphe<S,T>::Bellman()
{
	lSommets.at(0)->poids = 0;
	for (int j = 1; j < lSommets.size(); j++)
		lSommets.at(j)->poids = exp(99);
	for (int j = 1; j < lSommets.size(); j++)
	{
		vector< pair< Sommet<T> *, Arete<S, T>* > > predecesseurs = this->adjacencesMoins(lSommets.at(j));
		for (int i = 0; i < predecesseurs.size(); i++)
			if (predecesseurs.at(i).first->poids + predecesseurs.at(i).second->cout < lSommets.at(j)->poids)
			{
				lSommets.at(j)->poids = predecesseurs.at(i).first->poids + predecesseurs.at(i).second->cout;
				lSommets.at(j)->pere = predecesseurs.at(i).first->pere;
			}
	}
}