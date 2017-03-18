#include "Graphe.h"

void Bellman()
{
	lSommets.at(0)->poids = 0;
	for (int j = 1; j < lSommets.size(); j++)
		lSommets.at(j)->poids = exp(99);
	for (int j = 1; j < lSommets.size(); j++)
	{
		this->adjacencesPlus(lSommets.at(j));
	}
}