#pragma once
#include "LectureGPR.h"



int main()
{

	Graphe<int, int> * g = new Graphe<int, int>();
	*g = gprToGraphe("gpr_files/data_VRPTW_10.gpr");

	system("PAUSE");

	return 0;
}