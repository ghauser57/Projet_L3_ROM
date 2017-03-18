#pragma once
/**
Sommet d'un graphe en général
v est l'information associée au sommet : elle dépend de l'application du graphe
*/
template <class T>
class Sommet
{
public:
	int dPlus, dMoins;
	string nom;
	T bornInf, bornSup;
	int n, num, ncomp;
	bool marquage;
	
	Sommet(const string & nom, const T & bornInf, const T & bornSup) :dPlus(0), dMoins(0), nom(nom), bornInf(bornInf), bornSup(bornSup), n(0), num(0), ncomp(0), marquage(false){}
	Sommet(const string & nom) :dPlus(0), dMoins(0), bornInf(0), bornSup(0), n(0), num(0), ncomp(0), marquage(false){}
	Sommet(const Sommet<T> & s) :dPlus(0), dMoins(0), nom(s.nom), bornInf(s.bornInf), bornSup(s.bornSup), n(s.n), num(s.num), ncomp(s.ncomp), marquage(s.marquage){}
	bool operator == (const Sommet<T> & s) const;
	bool operator != (const Sommet<T> & s) const;
	operator string () const;

};
template <class T>
Sommet<T>::operator string () const
{
	ostringstream oss;
	oss << "Sommet(" << "degre = " << (dPlus + dMoins) << " nom = " << nom << " bornInf " << bornInf << " bornSup " << bornSup << ")";
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
	return (this->nom == s.nom && this->bornInf == s.bornInf && this->bornSup == s.bornSup);
}

template <class T>
bool Sommet<T>::operator != (const Sommet<T> & s) const
{
	return !(*this == s);
}
