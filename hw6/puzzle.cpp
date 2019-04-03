#include <iostream>
#include <cstdlib>
#include <deque>
#include "board.h"
#include "puzzle_heur.h"
#include "puzzle_solver.h"
#include <string>
/////////////////////////////////correct include?
#include <stdexcept>

int main(int argc, char *argv[])
{
  if(argc < 5){
    cerr << "Usage: ./puzzle size initMoves seed heur" << endl;
    return 1;
  }

  int n = stoi(argv[1]);
  int initMoves = stoi(argv[2]);
  int seed = stoi(argv[3]);
  int heur = stoi(argv[4]);
  PuzzleHeuristic* h;
  //BFS
  if(heur == 0)
  {
  	h = new PuzzleBFSHeuristic();
  }
  //Tiles Out of Place
  else if(heur == 1)
  {
  	h = new PuzzleOutOfPlaceHeuristic();
  }
  //Manhattan distance
  else if(heur == 2)
  {
  	h = new PuzzleManhattanHeuristic();
  }
  //Invalid heur
  else
  {
  	cout << "Invalid Hueristic" << endl;
  }
  Board* b = new Board(n, initMoves, seed);
  int mytile;
  while(mytile != 0 || !b->solved())
  {
	//display board
	cout << *b;
	cout << "Enter tile number to move or -1 for a cheat: ";
	cin >> mytile;
	if(mytile == -1)
	{
		//run A* and output sequence
		PuzzleSolver ps = PuzzleSolver(*b, h);
		ps.run();
		deque<int> cheats = ps.getSolution();
		for(unsigned int i = 0;i<cheats.size();i++)
		{
			cout << "Try this sequence: " << cheats[i] << " ";
		}
		cout << endl;
		cout << "(Expansions = " << ps.getNumExpansions() << ")" << endl;
	}
	else
	{
		try {
			b->move(mytile);
		}
		catch(BoardMoveError& e) {
			cout << e.what() << endl;
		}
		
	}

  }
  /*
  // might not need this if
  if(mytile == 0)
  {
  	//cleanup and quit program
  }
*/

  return 0;
}
