#pragma once
#include <time.h> 
#include <math.h>
#include <vector>
#include "Sommet.h"
#include "Arete.h"

template <class S, class T>
class Graphe
{
public:
	vector<Sommet<T> *> lSommets; // liste de sommets
	vector<Arete<S, T> *> lAretes; // liste d'ar�tes
	/**
	* cr�e un graphe vide
	* */
	Graphe();
	/**
	* constructeur de copie obligatoire car la classe comporte une partie dynamique
	* */
	Graphe(const Graphe<S, T> & graphe);
	/**
	* op�rateur = obligatoire car la classe comporte une partie dynamique
	* */
	const Graphe<S, T> & operator = (const Graphe<S, T> & graphe);
	/**
	* destructeur obligatoire car la classe comporte une partie dynamique
	* */
	~Graphe();
	int nombreSommets() const;
	int nombreAretes() const;
	/**
	* cr�e un sommet isol�
	* */
	Sommet<T> * creeSommet(const string & nom, const T & info);
	/**
	* cr�e une ar�te joignant les 2 sommets debut et fin
	*
	* * met � jour les champs degr� de debut et de fin
	* */
	Arete<S, T> *
		creeArete(Sommet<T> * debut, Sommet<T> * fin, const S & info);
	/**
	recherche la liste des paires (voisin, ar�te) adjacentes de sommet dans le graphe
	*/
	PElement< pair< Sommet<T> *, Arete<S, T>* > >  *
		adjacences(const Sommet<T> * sommet) const;
	PElement< pair< Sommet<T> *, Arete<S, T>* > >  *
		adjacencesPlus(const Sommet<T> * sommet) const;
	operator string() const;
	/**
	* cherche l'ar�te s1 - s2 ou l'ar�te s2 - s1 si elle existe
	*
	* DONNEES : s1 et s2 deux sommets quelconques du graphe
	* RESULTATS : l'ar�te s'appuyant sur s1 et s2 si elle existe, NULL sinon
	*
	* */
	Arete<S, T> * getAreteParSommets(const Sommet<T> * s1, const Sommet<T> * s2) const;
	//const S cout() const;
	//void changementAleatoire();
	//---------------------- Graphe ----------------------------------
};
/**
* cr�e un graphe vide
*
* */
template <class S, class T>
Graphe<S, T>::Graphe() :lAretes(new vector<Arete<S, T>>()), lSommets(new vector<Sommet<T>>()){}
template <class S, class T>
Graphe<S, T>::Graphe(const Graphe<S, T> & graphe) :lAretes(*new vector<Arete<S, T>>()), lSommets(*new vector<Sommet<T>>(*graphe.lSommets))
{
	for (int unsigned i = 0; i<graphe.lAretes.size(); i++)
	{  

	}
	PElement<Arete<S, T>> * temp = graphe.lAretes;
	while (temp != NULL)
	{
		PElement<Sommet<T>> * tempSdeb = lSommets;
		PElement<Sommet<T>> * tempSfin = lSommets;

		while (*temp->v->debut != *tempSdeb->v && tempSdeb != NULL)
			tempSdeb = tempSdeb->s;
		while (*temp->v->fin != *tempSfin->v && tempSfin != NULL)
			tempSfin = tempSfin->s;
		S * v = new S((temp->v->v));
		//lAretes = new PElement<Arete<S, T>>(new Arete<S, T>(temp->v->clef, tempSdeb->v, tempSfin->v, *v), lAretes);
		temp = temp->s;
	}
}

template <class S, class T>
const Graphe<S, T> & Graphe<S, T>::operator = (const Graphe<S, T> & graphe)
{
	Graphe<S, T> * temp = new Graphe<S, T>(graphe);
	this->lAretes = temp->lAretes;
	this->lSommets = temp->lSommets;
	return *this;
}

template <class S, class T>
Graphe<S, T>::~Graphe()
{
	PElement< Arete<S, T>>::efface2(this->lAretes);
	PElement<Sommet<T> >::efface2(this->lSommets);
}

/**
* cr�e un sommet isol�
*
* */
template <class S, class T>
Sommet<T> * Graphe<S, T>::creeSommet(const string & nom, const T & bornInf, const T & bornSup)
{
	Sommet<T> * sommetCree = new Sommet<T>(nom, bornInf, bornSup);
	lSommets.push_back(sommetCree);
	return sommetCree;
}
/**
* cr�e une ar�te joignant les 2 sommets debut et fin
*
* met � jour les champs degre de debut et de fin
* */
template <class S, class T>
Arete<S, T> * Graphe<S, T>::creeArete(Sommet<T> * debut, Sommet<T> * fin, const S & cout, const S & temps)
{
	Arete<S, T> * nouvelleArete;
	// ici tester que les 2 sommets sont bien existants dans le graphe
	//if(!PElement< Sommet<T> >::appartient(debut, lSommets)) throw Erreur("d�but d'ar�te non d�fini");
	//if(!PElement< Sommet<T> >::appartient(fin, lSommets)) throw Erreur("fin d'ar�te non d�finie");
	nouvelleArete = new Arete<S, T>(debut, fin, cout, temps);
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
	oss << "Graphe( \n";
	oss << "prochaine clef = " << this->prochaineClef << endl;
	oss << "nombre de sommets = " << this->nombreSommets() << "\n";
	oss << PElement<Sommet<T> >::toString(lSommets, "", "\n", "");
	oss << "nombre d'ar�tes = " << this->nombreAretes() << "\n";
	oss << PElement<Arete<S, T> >::toString(lAretes, "", "\n", "");
	oss << ")";
	return oss.str();
}
template <class S, class T>
ostream & operator << (ostream & os, const Graphe<S, T> & gr)
{
	return os << (string)gr;
}
/**
* cherche l'ar�te s1 - s2 ou l'ar�te s2 - s1 si elle existe
*
* DONNEES : s1 et s2 deux sommets quelconques du graphe
* RESULTATS : l'ar�te s'appuyant sur s1 et s2 si elle existe, NULL sinon
*
* */
template <class S, class T>
Arete<S, T> * Graphe<S, T>::getAreteParSommets(const Sommet<T> * s1, const Sommet<T> * s2) const
{
	PElement<Arete<S, T> > * l;
	for (l = this->lAretes; l; l = l->s)
		if (l->v->estEgal(s1, s2))
			return l->v;
	return NULL;
}
/**
recherche la liste des paires (voisin, ar�te) adjacentes de sommet dans le graphe
*/
template <class S, class T>
PElement< pair< Sommet<T> *, Arete<S, T>* > >  *  Graphe<S, T>::adjacences(const Sommet<T> * sommet) const
{
	const PElement< Arete<S, T> > * l;
	PElement< pair< Sommet<T> *, Arete<S, T>* > > * r;    // pair< Sommet<T> *, Arete<S,T>* >
	for (l = lAretes, r = NULL; l; l = l->s)
		if (sommet == l->v->debut)
			r = new PElement< pair< Sommet<T> *, Arete<S, T>* > >
			(new pair< Sommet<T> *, Arete<S, T>* >(l->v->fin, l->v), r);
		else
			if (sommet == l->v->fin)
				r = new PElement< pair< Sommet<T> *, Arete<S, T>* > >
				(new pair< Sommet<T> *, Arete<S, T>* >
				(l->v->debut, l->v), r);
	return r;
}
template <class S, class T>
PElement< pair< Sommet<T> *, Arete<S, T>* > >  *  Graphe<S, T>::adjacencesPlus(const Sommet<T> * sommet) const
{
	const PElement< Arete<S, T> > * l;
	PElement< pair< Sommet<T> *, Arete<S, T>* > > * r;    // pair< Sommet<T> *, Arete<S,T>* >
	for (l = lAretes, r = NULL; l; l = l->s)
	{
		if (sommet == l->v->debut)
			r = new PElement< pair< Sommet<T> *, Arete<S, T>* > >
			(new pair< Sommet<T> *, Arete<S, T>* >(l->v->fin, l->v), r);
	}
	return r;
}
