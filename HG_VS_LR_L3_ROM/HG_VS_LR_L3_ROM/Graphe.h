#pragma once
#include <time.h> 
#include <math.h>
#include <vector>
#include "Sommet.h"
#include "Arete.h"
#include "Pile.h"

template <class S, class T>
class Graphe
{
public:
	
	vector<Sommet<T> *> lSommets; 
	vector<Arete<S, T> *> lAretes; 
	
	Graphe();
	Graphe(const Graphe<S, T> & graphe);
	
	~Graphe();

	const Graphe<S, T> & operator = (const Graphe<S, T> & graphe);
	operator string() const;

	int nombreSommets() const;
	int nombreAretes() const;

	Sommet<T>* getSommetByName(string);

	Sommet<T> * creeSommet(const string & nom, const T & bornInf, const T & bornSup);
	Sommet<T> * creeSommet2(const string & nom);
	
	Arete<S, T> *creeArete(Sommet<T> * debut, Sommet<T> * fin, const S & cout, const S & temps);
	
	vector< pair< Sommet<T> *, Arete<S, T>* > > adjacences(const Sommet<T> * sommet) const;
	vector< pair< Sommet<T> *, Arete<S, T>* > > adjacencesPlus(const Sommet<T> * sommet) const;

	Arete<S, T> * getAreteParSommets(const Sommet<T> * s1, const Sommet<T> * s2) const;

	bool hasCircuit();

	/* Parcours DFS du graphe */
	void Explore(Sommet<T> * i, int & k);
	void Explore(Sommet<T> * i, int & k, int & l);
	void DFS(Sommet<T> * som);
	void DFS();
};


template <class S, class T>
Graphe<S, T>::Graphe() :lAretes(NULL), lSommets(NULL){}


template <class S, class T>
Graphe<S, T>::Graphe(const Graphe<S, T> & graphe) : lAretes(NULL), lSommets(NULL)
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
		//S * v = new S((graphe.lAretes.at(i)->v));
		lAretes.push_back(new Arete<S, T>(tempSdeb, tempSfin, graphe.lAretes.at(i)->cout, graphe.lAretes.at(i)->temps));
	}
}


template <class S, class T>
Graphe<S, T>::~Graphe()
{
	for (int unsigned i = 0; i < lAretes.size(); i++)
		delete(lAretes.at(i));
	for (int unsigned i = 0; i < lSommets.size(); i++)
		delete(lSommets.at(i));
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
Graphe<S, T>::operator string() const
{
	ostringstream oss;
	int tailleLSommets = (int)this->lSommets.size();
	int tailleLAretes = (int)this->lAretes.size();
	oss << "Graphe( \n";
	oss << "nombre de sommets = " << tailleLSommets << "\n";
	oss << "liste des sommets = " << "\n";
	for (int i = 0; i < tailleLSommets; i++)
		oss << *lSommets.at(i) << "\n";
	oss << "nombre d'arêtes = " << tailleLAretes << "\n";
	oss << "liste des arêtes = " << "\n";
	for (int i = 0; i < tailleLAretes; i++)
		oss << *lAretes.at(i) << "\n";
	oss << ")";
	return oss.str();
}


template <class S, class T>
ostream & operator << (ostream & os, const Graphe<S, T> & gr)
{
	return os << (string)gr;
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
Sommet<T>* Graphe<S, T>::getSommetByName(string s){

	for (vector<Sommet<int>*>::iterator it = lSommets.begin(); it != lSommets.end(); ++it){
		if ((*it)->nom == s){
			return *it;
		}
	}
	return NULL;
}


template <class S, class T>
Sommet<T> * Graphe<S, T>::creeSommet(const string & nom, const T & bornInf, const T & bornSup)
{
	Sommet<T> * sommetCree = new Sommet<T>(nom, bornInf, bornSup);
	lSommets.push_back(sommetCree);
	return sommetCree;
}


template <class S, class T>
Sommet<T> * Graphe<S, T>::creeSommet2(const string & nom)
{
	Sommet<T> * sommetCree = new Sommet<T>(nom);
	lSommets.push_back(sommetCree);
	return sommetCree;
}


template <class S, class T>
Arete<S, T> * Graphe<S, T>::creeArete(Sommet<T> * debut, Sommet<T> * fin, const S & cout, const S & temps)
{
	Arete<S, T> * nouvelleArete;
	// ici tester que les 2 sommets sont bien existants dans le graphe
	//if(!PElement< Sommet<T> >::appartient(debut, lSommets)) throw Erreur("début d'arête non défini");
	//if(!PElement< Sommet<T> >::appartient(fin, lSommets)) throw Erreur("fin d'arête non définie");
	nouvelleArete = new Arete<S, T>(debut, fin, cout, temps);
	lAretes.push_back(nouvelleArete);
	//debut->degre++; fin->degre++;
	return nouvelleArete;
}


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


template <class S, class T>
Arete<S, T> * Graphe<S, T>::getAreteParSommets(const Sommet<T> * s1, const Sommet<T> * s2) const
{
	for (int unsigned i = 0; i < lAretes.size(); i++)
		if (lAretes.at(i)->estEgal(s1, s2))
			return lAretes.at(i);
	return NULL;
}


template <class S, class T>
bool Graphe<S, T>::hasCircuit(){

	Pile<Sommet<T> *> * a_traiter;
	int nbSommets = 0;

	for (int unsigned i = 0; i < lSommets.size(); i++){
		lSommets.at(i)->nbPredec = 0;
	}

	for (int unsigned i = 0; i < lSommets.size(); i++){
		vector< pair< Sommet<T> *, Arete<S, T>* > > adjP = adjacencesPlus(lSommets.at(i));
		for (int unsigned i = 0; i < adjP.size(); i++){
			lSommets.at(i)->nbPredec++;
		}
	}

	for (int unsigned i = 0; i < lSommets.size(); i++){
		if (lSommets.at(i)->nbPredec == 0){
			a_traiter = new Pile<T>(lSommets.at(i), a_traiter);
			nbSommets++;
		}
	}

	while (a_traiter != NULL){
		Sommet<T> * s = a_traiter->depiler();

		vector< pair< Sommet<T> *, Arete<S, T>* > > adjP = adjacencesPlus(lSommets.at(i));
		for (int unsigned i = 0; i < adjP.size(); i++){
			lSommets.at(i).first->nbPredec--;
			if (lSommets.at(i)->nbPredec == 0){
				a_traiter = new Pile<T>(lSommets.at(i), a_traiter);
				nbSommets++;
			}
		}
	}

	return !(nbSommets == lSommets.size());
}


template <class S, class T>
void Graphe<S, T>::Explore(Sommet<T> * i, int & k)
{
	vector<pair< Sommet<T> *, Arete<S, T>* >> successeurs = this->adjacencePlus(i);
	while (i->n > 0)
	{
		Sommet<T> * j = successeurs.at(i->n).second;
		i->n = i->n - 1;
		if (j->num == 0)
		{
			k = k + 1;
			j->num = k;
			this->Explore1(j);
		}
	}
}


template <class S, class T>
void Graphe<S, T>::Explore(Sommet<T> * i, int & k, int & l)
{
	vector<pair< Sommet<T> *, Arete<S, T>* >> successeurs = this->adjacencePlus(i);
	while (i->n > 0)
	{
		Sommet<T> * j = successeurs.at(i->n).second;
		i->n = i->n - 1;
		if (j->num == 0)
		{
			k = k + 1;
			j->num = k;
			this->Explore1(j);
		}
	}
}


template <class S, class T>
void Graphe<S, T>::DFS(Sommet<T> * som)
{
	int k = 1;
	for (int i = 0; i < (int)this->sommets.size(); i++)
	{
		this->sommets.at(i)->n = this->sommets.at(i)->dPlus;
		this->sommets.at(i)->num = 0;
	}
	som->num = k;
	this->Explore(som, k);
}


template <class S, class T>
void Graphe<S, T>::DFS()
{
	int k = 1;
	int l = 0;
	for (int i = 0; i < (int)this->sommets.size(); i++)
	{
		this->sommets.at(i)->n = this->sommets.at(i)->dPlus;
		this->sommets.at(i)->num = 0;
		this->sommets.at(i)->ncomp = 0;
	}
	for (int i = 0; i < (int)this->sommets.size(); i++)
		if (this->sommets.at(i)->ncomp == 0)
		{
			this->sommets.at(i)->num = k;
			l++;
			this->sommets.at(i)->ncomp = l;
			this->Explore(this->sommets.at(i), k, l);
		}		
}
