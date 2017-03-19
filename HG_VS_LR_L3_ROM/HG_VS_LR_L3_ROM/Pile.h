#pragma once
#include <sstream>
using namespace std;

template <class T>
class Pile
{
public:
	T* v;
	Pile<T> * s;

	Pile(T* v, Pile<T> * s) :v(v), s(s){}
	Pile(const Pile<T> & pe);

	Pile<T> * operator = (const Pile<T> & Pelem);

	static int taille(const Pile<T> * l);

	static const string toString(const Pile<T> *p,
		const char * debut = "( ",
		const char * separateur = ", ",
		const char * fin = " )");

	static void insertionOrdonnee(T * a,
		Pile<T> * & l,
		bool(*estPlusPetitOuEgal)(const T * a1, const T * a2));

	bool isIn(const T* elem);

	static void efface(Pile<T>* & l);

	T * depiler();
};

template <class T>
bool Pile<T>::isIn(const T* elem)
{
	Pile<T> * temp = this;
	while (temp != NULL)
	{
		printf("pas null\n");
		if (elem == temp->v)
			return true;
		temp = temp->s;
	}
	return false;
}

template <class T>
T * Pile<T>::depiler()
{
	if (this != NULL)
	{
		T * val = this->v;
		if (this->s != NULL)
		{
			this->v = this->s->v;
			this->s = this->s->s;
			//return val;
		}
		else
		{
			this->v = NULL;
		}
		return val;
	}
	return NULL;
}

template <class T>
Pile<T>::Pile(const Pile<T> & pe) :v(NULL), s(NULL)
{
	if (&pe != NULL)
	{
		Pile<T> * temp = new Pile<T>(pe.v, pe.s);
		Pile<T> * temp2 = NULL;

		v = new T(*temp->v);
		while (temp->s != NULL)
		{
			temp = temp->s;
			temp2 = new Pile<T>(new T(*temp->v), temp2);
		}
		s = temp2;
	}
}

template <class T>
int Pile<T>::taille(const Pile<T> * l)
{
	if (l == NULL)
		return 0;
	else
		return 1 + taille(l->s);
}

template <class T>
const string Pile<T>::toString(const Pile<T> *p,
	const char * debut = "( ",
	const char * separateur = ", ",
	const char * fin = " )")
{
	ostringstream flux;
	flux << debut;
	if (p != NULL)
	{
		while (p->s != NULL)
		{
			flux << *p->v << separateur;
			p = p->s;
		}
		flux << *p->v;
	}
	flux << fin;
	return flux.str();
}

template <class T>
void Pile<T>::insertionOrdonnee(T * a,
	Pile<T> * & l,
	bool(*estPlusPetitOuEgal)(const T * a1, const T * a2))
{
	if (l == NULL)
	{
		l = new Pile<T>(a, l);
	}
	else
	{
		if (estPlusPetitOuEgal(a, l->v))
			l = new Pile<T>(a, l);
		else
			insertionOrdonnee(a, l->s, estPlusPetitOuEgal);
	}
}

template <class T>
ostream & operator << (ostream & os, const Pile<T> * p)
{
	os << p->toString(p);
	return os;
}

bool comparaison(const double * a1, const double * a2)
{
	return *a1 <= *a2;
}

bool comparaison(const string * a1, const string * a2)
{
	return a1->compare(*a2) <= 0;
}

template <class T>
/* static */ void Pile<T>::efface(Pile<T>* & l)
{
	if (l)
	{
		Pile<T>::efface(l->s);
		delete l->v; delete l; l = NULL;
	}
}