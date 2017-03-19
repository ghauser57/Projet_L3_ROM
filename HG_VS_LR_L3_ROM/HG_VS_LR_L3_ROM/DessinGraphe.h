#include "Graphe.h"

using namespace std;

template <class S, class T>
void dessinGraphe(ofstream & of, Graphe<S,T> & graphe)
{
	of << "digraph G {" << endl;
	for (int i = 0; i < graphe.lAretes.size(); i++)
	{
		of << graphe.lAretes.at(i)->debut->nom << " -> " << graphe.lAretes.at(i)->fin->nom;
		of << " [label=\"" << graphe.lAretes.at(i)->cout << " | " << graphe.lAretes.at(i)->temps << "\"]" << endl;
	}
	of << "}";
}