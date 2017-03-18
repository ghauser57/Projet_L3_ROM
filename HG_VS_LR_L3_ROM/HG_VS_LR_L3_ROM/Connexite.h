#include "Graphe.h"

template <class S, class T>
void Graphe<S,T>::inversion(){

	for (int unsigned i = 0; i < lAretes.size(); i++)
	{

		Sommet<T> * A = new Sommet(*(lAretes.at(i)->debut));
		Sommet<T> * B = new Sommet(*(lAretes.at(i)->fin));

		lAretes.at(i)->debut = B;
		lAretes.at(i)->fin = A;
	}
}

template <class S, class T>
void Graphe<S, T>::connexite(){



}