#include "Graphe.h"

template <class S, class T>
void Graphe<S,T>::inversionArcs(){

	for (int unsigned i = 0; i < lAretes.size(); i++)
	{

		Sommet<T> * A = new Sommet(*(lAretes.at(i)->debut));
		Sommet<T> * B = new Sommet(*(lAretes.at(i)->fin));

		lAretes.at(i)->debut = B;
		lAretes.at(i)->fin = A;
	}
}

template <class S, class T>
bool Graphe<S, T>::connexite(const Sommet<T> * A, const Sommet<T> * B){

	DFS(A);
	if ((B->num) > 0)
		return true;
	else
		return false;

}