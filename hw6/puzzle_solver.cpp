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
	PuzzleMoveBoardComp bc;
	PuzzleMoveSet closed_list(bc);

	PuzzleMove* start = new PuzzleMove(&b_);
	set<PuzzleMove*> delete_these;
	delete_these.insert(start);
	start->h = ph_->compute(*(start->b));
	open_list.push(start);
	bool solved = false;
	PuzzleMove* top_list;
	while(!open_list.empty() && solved == false)
	{
		top_list = open_list.top();
		closed_list.insert(top_list);
		open_list.pop();
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
			if(closed_list.find(move) == closed_list.end()) 
			{
				move->h = ph_->compute(*(move->b));
				move->g = (top_list->g) + 1;
				open_list.push(move);
				expansions_++;
			}
		}
	}
	if(solved == true)
	{
		while(top_list->prev != nullptr)
		{
			solution_.push_front(top_list->tileMove);
			top_list = top_list->prev;
		}
	}
	// set<PuzzleMove*>::iterator it2;
	// for(it2 = delete_these.begin(); it2 != delete_these.end(); ++it2)
	// {
	// 	delete (*it2);
	// }
	// for(int i = 0;i<open_list.size();i++)
	// {
	// 	delete open_list[i];
	// }
	PuzzleMoveSet::iterator it2;
	for(it2 = closed_list.begin(); it2 != closed_list.end();++it2)
	{
		delete (*it2);
	}

}

// Return the solution deque
deque<int> PuzzleSolver::getSolution()
{
	return solution_;
}

// Return how many expansions were performed in the search
int PuzzleSolver::getNumExpansions()
{
	return expansions_;
}