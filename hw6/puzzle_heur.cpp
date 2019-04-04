#include <iostream>
#include <stdlib.h>
#include "puzzle_heur.h"

using namespace std;

int PuzzleManhattanHeuristic::compute(const Board& b)
{
	int distance = 0;
	for(int i = 0;i<b.size();i++)
	{
		if(b[i] == 0)
		{
			continue;
		}
		if(b[i] !=  0 && b[i] != i)
		{

			distance += abs((b[i] % b.dim()) - (i % b.dim()));
			distance += abs((b[i] / b.dim()) - (i / b.dim()));
		}
	}
	return distance;
}
int PuzzleOutOfPlaceHeuristic::compute(const Board& b)
{
	int out_of_place = 0;
	for(int i = 0;i<b.size();i++)
	{
		if(b[i] == 0)
		{
			continue;
		}
		if(b[i] != i)
		{
			out_of_place++;
		}
	}
	return out_of_place;
}
int PuzzleBFSHeuristic::compute(const Board& b)
{
	return 0;
}