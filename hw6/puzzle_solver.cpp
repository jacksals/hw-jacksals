#include <iostream>
#include "puzzle_solver.h"
#include <map>

using namespace std;

PuzzleSolver::PuzzleSolver(const Board &b, PuzzleHeuristic* ph) : b_(b)

{
	ph_ = ph;
	expansions_ = 0;
}

// Destructor
PuzzleSolver::~PuzzleSolver()
{

}

// Run the A* search and builds the solution and tracks
// the number of expansions
void PuzzleSolver::run()
{
	PuzzleMoveScoreComp comp;
	Heap<PuzzleMove*, PuzzleMoveScoreComp> open_list = Heap<PuzzleMove*, PuzzleMoveScoreComp>(2, comp);
	PuzzleMoveSet closed_list;

	PuzzleMove* start = new PuzzleMove(&b_);
	set<PuzzleMove*> delete_these;
	delete_these.insert(start);
	start->h = ph_->compute(*(start->b));
	open_list.push(start);
	bool solved = false;
	PuzzleMove* top_list;
	while(!open_list.empty())
	{
		top_list = open_list.top();
		if(top_list->b->solved())
		{
			solved = true;
			break;
		}
		map<int, Board*> temp = (top_list->b)->potentialMoves();
		map<int, Board*>::iterator it;
		for(it = temp.begin(); it != temp.end(); ++it)
		{
			PuzzleMove* move = new PuzzleMove(it->first, it->second, top_list);
			delete_these.insert(move);
			if(closed_list.find(move) == closed_list.end()) {
				move->h = ph_->compute(*(move->b));
				open_list.push(move);
				expansions_++;
			}
		}
		closed_list.insert(top_list);
		open_list.pop();
	}
	if(solved == true)
	{
		solution_.push_back(top_list->tileMove);
		while(top_list->prev != nullptr)
		{
			solution_.push_back(top_list->prev->tileMove);
		}
	}
	set<PuzzleMove*>::iterator it2;
	for(it2 = delete_these.begin(); it2 != delete_these.end(); ++it2)
	{
		delete (*it2);
	}
}

// Return the solution deque
deque<int> PuzzleSolver::getSolution()
{

}

// Return how many expansions were performed in the search
int PuzzleSolver::getNumExpansions()
{

}