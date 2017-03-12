#pragma once
#include <time.h> 
#include <math.h>
#include <vector>
#include "Sommet.h"
#include "Arete.h"

template <class S, class T>
class Graphe
{
protected:
	int prochaineClef;
public:
	vector<Sommet<T> *> lSommets; // liste de sommets
	vector<Arete<S, T> *> lAretes; // liste d'arêtes
	/**
	* crée un graphe vide
	* */
	Graphe();
	/**
	* constructeur de copie obligatoire car la classe comporte une partie dynamique
	* */
	Graphe(const Graphe<S, T> & graphe);
	/**
	* opérateur = obligatoire car la classe comporte une partie dynamique
	* */
	const Graphe<S, T> & operator = (const Graphe<S, T> & graphe);
	/**
	* destructeur obligatoire car la classe comporte une partie dynamique
	* */
	~Graphe();
	int nombreSommets() const;
	int nombreAretes() const;
	/**
	* crée un sommet isolé
	* */
	Sommet<T> * creeSommet(const string & nom, const T & info);
	/**
	* crée une arête joignant les 2 sommets debut et fin
	*
	* * met à jour les champs degré de debut et de fin
	* */
	Arete<S, T> *
		creeArete(Sommet<T> * debut, Sommet<T> * fin, const S & info);
	/**
	recherche la liste des paires (voisin, arête) adjacentes de sommet dans le graphe
	*/
	vector< pair< Sommet<T> *, Arete<S, T>* > >
		adjacences(const Sommet<T> * sommet) const;
	vector< pair< Sommet<T> *, Arete<S, T>* > >
		adjacencesPlus(const Sommet<T> * sommet) const;

	operator string() const;
	/**
	* cherche l'arête s1 - s2 ou l'arête s2 - s1 si elle existe
	*
	* DONNEES : s1 et s2 deux sommets quelconques du graphe
	* RESULTATS : l'arête s'appuyant sur s1 et s2 si elle existe, NULL sinon
	*
	* */
	Arete<S, T> * getAreteParSommets(const Sommet<T> * s1, const Sommet<T> * s2) const;
	//const S cout() const;
	//void changementAleatoire();
	//---------------------- Graphe ----------------------------------
};
/**
* crée un graphe vide
*
* */
template <class S, class T>
Graphe<S, T>::Graphe() :prochaineClef(0), lAretes(NULL), lSommets(NULL){}
template <class S, class T>
Graphe<S, T>::Graphe(const Graphe<S, T> & graphe) : prochaineClef(graphe.prochaineClef), lAretes(NULL), lSommets(NULL)
{
	for (int unsigned i = 0; i < graphe.lSommets.size(); i++)
	{
		lSommets.push_back(new Sommet<T>(*graphe.lSommets.at(i)));
	}
	for (int unsigned i = 0; i<graphe.lAretes.size(); i++)
	{
		Sommet<T> * tempSdeb = NULL;
		Sommet<T> * tempSfin = NULL;
		int unsigned j = 0;
		while ((tempSdeb == NULL || tempSfin == NULL) && j < lSommets.size())
		{
			if (*graphe.lAretes.at(i)->debut == *lSommets.at(j))
				tempSdeb = lSommets.at(j);
			if (*graphe.lAretes.at(i)->fin == *lSommets.at(j))
				tempSfin = lSommets.at(j);
			j++;
		}
		S * v = new S((graphe.lAretes.at(i)->v));
		lAretes.push_back(new Arete<S, T>(graphe.lAretes.at(i)->clef, tempSdeb, tempSfin, *v));
	}
}

template <class S, class T>
const Graphe<S, T> & Graphe<S, T>::operator = (const Graphe<S, T> & graphe)
{
	Graphe<S, T> * temp = new Graphe<S, T>(graphe);
	this->prochaineClef = temp->prochaineClef;
	this->lAretes = temp->lAretes;
	this->lSommets = temp->lSommets;
	return *this;
}

template <class S, class T>
Graphe<S, T>::~Graphe()
{
	for (int unsigned i = 0; i < lAretes.size(); i++)
		delete(lAretes.at(i));
	for (int unsigned i = 0; i < lSommets.size(); i++)
		delete(lSommets.at(i));
}

/**
* crée un sommet isolé
*
* */
template <class S, class T>
Sommet<T> * Graphe<S, T>::creeSommet(const string & nom, const T & info)
{
	Sommet<T> * sommetCree = new Sommet<T>(prochaineClef++, nom, info);
	lSommets.push_back(sommetCree);
	return sommetCree;
}
/**
* crée une arête joignant les 2 sommets debut et fin
*
* met à jour les champs degre de debut et de fin
* */
template <class S, class T>
Arete<S, T> * Graphe<S, T>::creeArete(Sommet<T> * debut, Sommet<T> * fin, const S & info)
{
	Arete<S, T> * nouvelleArete;
	// ici tester que les 2 sommets sont bien existants dans le graphe
	//if(!PElement< Sommet<T> >::appartient(debut, lSommets)) throw Erreur("début d'arête non défini");
	//if(!PElement< Sommet<T> >::appartient(fin, lSommets)) throw Erreur("fin d'arête non définie");
	nouvelleArete = new Arete<S, T>(prochaineClef++, debut, fin, info);
	lAretes.push_back(nouvelleArete);
	debut->degre++; fin->degre++;
	return nouvelleArete;
}
template <class S, class T>
int Graphe<S, T>::nombreSommets() const
{
	return lSommets.size();
}
template <class S, class T>
int Graphe<S, T>::nombreAretes() const
{
	return lAretes.size();
}
template <class S, class T>
Graphe<S, T>::operator string() const
{
	ostringstream oss;
	int tailleLSommets = (int)this->lSommets.size();
	int tailleLAretes = (int)this->lAretes.size();
	oss << "Graphe( \n";
	oss << "prochaine clef = " << this->prochaineClef << endl;
	oss << "nombre de sommets = " << tailleLSommets << "\n";
	oss << "liste des sommets = " << "\n";
	for (int  i = 0; i < tailleLSommets; i++)
		oss << *lSommets.at(i) << "\n";
	oss << "nombre d'arêtes = " << (int)this->lAretes.size() << "\n";
	oss << "liste des arêtes = " << "\n";
	for (int  i = 0; i < tailleLAretes; i++)
		oss << *lAretes.at(i) << "\n";
	oss << ")";
	return oss.str();
}
template <class S, class T>
ostream & operator << (ostream & os, const Graphe<S, T> & gr)
{
	return os << (string)gr;
}
/**
* cherche l'arête s1 - s2 ou l'arête s2 - s1 si elle existe
*
* DONNEES : s1 et s2 deux sommets quelconques du graphe
* RESULTATS : l'arête s'appuyant sur s1 et s2 si elle existe, NULL sinon
*
* */
template <class S, class T>
Arete<S, T> * Graphe<S, T>::getAreteParSommets(const Sommet<T> * s1, const Sommet<T> * s2) const
{
	for (int unsigned i = 0; i < lAretes.size(); i++)
		if (lAretes.at(i)->estEgal(s1, s2))
			return lAretes.at(i);
	return NULL;
}
/**
recherche la liste des paires (voisin, arête) adjacentes de sommet dans le graphe
*/
template <class S, class T>
vector< pair< Sommet<T> *, Arete<S, T>* > >  Graphe<S, T>::adjacences(const Sommet<T> * sommet) const
{
	vector< pair< Sommet<T> *, Arete<S, T>* > > r();    // pair< Sommet<T> *, Arete<S,T>* >
	for (int unsigned i = 0; i < lAretes.size(); i++)
		if (sommet == lAretes.at(i)->debut)
			r.push_back(new pair< Sommet<T> *, Arete<S, T>* >(lAretes.at(i)->fin, lAretes.at(i)));
		else
			if (sommet == lAretes.at(i)->fin)
				r.push_back(new pair< Sommet<T> *, Arete<S, T>* >(lAretes.at(i)->debut, lAretes.at(i)));
	return r;
}

template <class S, class T>
vector< pair< Sommet<T> *, Arete<S, T>* > >  Graphe<S, T>::adjacencesPlus(const Sommet<T> * sommet) const
{
	vector< pair< Sommet<T> *, Arete<S, T>* > > r();    // pair< Sommet<T> *, Arete<S,T>* >
	for (int unsigned i = 0; i < lAretes.size(); i++)
		if (sommet == lAretes.at(i)->debut)
			r.push_back(new pair< Sommet<T> *, Arete<S, T>* >(lAretes.at(i)->fin, lAretes.at(i)));
	return r;
}
