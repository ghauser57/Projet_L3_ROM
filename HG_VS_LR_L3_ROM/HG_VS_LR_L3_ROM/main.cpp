#pragma once
#include "LectureGPR.h"



int main()
{
	// A modif DANS CONSTRUCTEUR RECOPIE GRAPHE
	//Graphe<int, int> * g = new Graphe<int, int>();
	//*g = 
	cout << endl;
	cout << endl;
	cout << endl;
	Graphe<int, int> g1 = gprToGraphe("gpr_files/data_VRPTW_10.gpr");
	
	cout << g1 << endl;

	system("PAUSE");

	return 0;
}