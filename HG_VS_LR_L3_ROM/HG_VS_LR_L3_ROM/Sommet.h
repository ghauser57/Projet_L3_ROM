#pragma once
#include "GElement.h"
/**
Sommet d'un graphe en g�n�ral
v est l'information associ�e au sommet : elle d�pend de l'application du graphe
*/
template <class T>
class Sommet : public GElement
{
public:
	int degre;
	string nom;
	T bornInf, bornSup;
	Sommet(const int clef, const string & nom, const T & bornInf, const T & bornSup) :GElement(clef), degre(0), nom(nom), bornInf(bornInf), bornSup(bornSup){}
	Sommet(const Sommet<T> & s) :GElement(s.clef), degre(s.degre), nom(s.nom), bornInf(s.bornInf), bornSup(s.bornSup){}
	bool operator == (const Sommet<T> & s) const;
	bool operator != (const Sommet<T> & s) const;
	operator string () const;
};
template <class T>
Sommet<T>::operator string () const
{
	ostringstream oss;
	oss << "Sommet(" << endl;
	oss << GElement::operator string() << endl;
	oss << "degr� = " << degre << endl;
	oss << "nom = " << nom << endl;
	oss << "v = " << v << endl;
	oss << ")";
	return oss.str();
}
template <class T>
ostream & operator << (ostream & os, const Sommet<T> & sommet)
{
	return os << (string)sommet;
}
template <class T>
bool Sommet<T>::operator == (const Sommet<T> & s) const
{
	return (this->clef == s.clef && this->degre == s.degre && this->nom == s.nom && this->bornInf == s.bornInf && this->bornSup == s.bornSup);
}
template <class T>
bool Sommet<T>::operator != (const Sommet<T> & s) const
{
	return !(*this == s);
}