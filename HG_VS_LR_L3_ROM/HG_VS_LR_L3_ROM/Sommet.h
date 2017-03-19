#pragma once


using namespace std;
/**
Sommet d'un graphe en général
*/
template <class T>
class Sommet
{
public:
	int dPlus, dMoins;
	string nom;
	T bornInf, bornSup;
	int pere;
	vector<int> poids;
	int n, num, ncomp;
	int prefixe, suffixe;
	bool marquage;
	
	Sommet(const string & nom, const T & bornInf, const T & bornSup) :dPlus(0), dMoins(0), nom(nom), bornInf(bornInf), bornSup(bornSup), pere(-1), n(0), num(0), ncomp(0), marquage(false), prefixe(0), suffixe(0), pairPA(0,0){}
	Sommet(const string & nom) :dPlus(0), dMoins(0), bornInf(0), bornSup(0), pere(-1), n(0), num(0), ncomp(0), marquage(false), prefixe(0), suffixe(0), pairPA(0, 0){}
	Sommet(const Sommet<T> & s) :dPlus(0), dMoins(0), nom(s.nom), bornInf(s.bornInf), bornSup(s.bornSup), pere(s.pere), n(s.n), num(s.num), ncomp(s.ncomp), marquage(s.marquage), prefixe(s.prefixe), suffixe(s.suffixe), pairPA(s.pairPA){}
	bool operator == (const Sommet<T> & s) const;
	bool operator != (const Sommet<T> & s) const;
	operator string () const;

};
template <class T>
Sommet<T>::operator string () const
{
	ostringstream oss;
	oss << "Sommet(" << "degre = " << (dPlus + dMoins) << " nom = " << nom << " bornInf " << bornInf << " bornSup " << bornSup << " num " << num << " ncom " << ncomp << ")" ;
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
