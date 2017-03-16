#pragma once
/**
Sommet d'un graphe en général
v est l'information associée au sommet : elle dépend de l'application du graphe
*/
template <class T>
class Sommet
{
public:
	int degre;
	string nom;
	T bornInf, bornSup;
	int nbPredec;
	Sommet(const string & nom, const T & bornInf, const T & bornSup) :degre(0), nom(nom), bornInf(bornInf), bornSup(bornSup), nbPredec(0){}
	Sommet(const string & nom) :degre(0), nom(nom), bornInf(0), bornSup(0), nbPredec(0){}
	Sommet(const Sommet<T> & s) :degre(s.degre), nom(s.nom), bornInf(s.bornInf), bornSup(s.bornSup), nbPredec(s.nbPredec){}
	bool operator == (const Sommet<T> & s) const;
	bool operator != (const Sommet<T> & s) const;
	operator string () const;

	Sommet<T> * getSommetByName(string s){
		if (this->nom == s) return this;
	}
};
template <class T>
Sommet<T>::operator string () const
{
	ostringstream oss;
	oss << "Sommet(" << "degre = " << degre << " nom = " << nom << " bornInf " << bornInf << " bornSup " << bornSup << ")";
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
	return (this->degre == s.degre && this->nom == s.nom && this->bornInf == s.bornInf && this->bornSup == s.bornSup && this->nbPredec == s.nbPredec);
}
template <class T>
bool Sommet<T>::operator != (const Sommet<T> & s) const
{
	return !(*this == s);
}
