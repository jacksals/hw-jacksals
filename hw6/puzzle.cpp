#include <iostream>
#include <cstdlib>
#include <deque>
#include "board.h"
#include "puzzle_heur.h"
#include "puzzle_solver.h"
#include <string>
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
  int mytile = -1;
  bool solved = false;
  while(solved == false)
  {
  	if(mytile == 0)
  	{
  		break;
  	}
	//display board
	cout << *b;
	if(b->solved() == true)
	{
		solved = true;
		break;
	}
	cout << "Enter tile number to move or -1 for a cheat: ";
	cin >> mytile;
	if(mytile == -1)
	{
		//run A* and output sequence
		PuzzleSolver ps = PuzzleSolver(*b, h);
		ps.run();
		deque<int> cheats = ps.getSolution();
		cout << "Try this sequence: ";
		for(unsigned int i = 0;i<cheats.size();i++)
		{
			cout << cheats[i] << " ";
		}
		cout << endl;
		cout << "(Expansions = " << ps.getNumExpansions() << ")" << endl;
	}
	else if(mytile < -1 || mytile > (b->size()) ) 
	{
		continue;
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
  
  delete h;
  delete b;

  return 0;
}
