#include <iostream>
#include "puzzle_move.h"

using namespace std;

PuzzleMove::PuzzleMove(Board* board)
{
	b = board;
	g = 0;
	prev = nullptr;
}

PuzzleMove::PuzzleMove(int tile, Board* board, PuzzleMove *parent)
{
	b = board;
    prev = parent;
    tileMove = tile;
    g = (parent->g) + 1;
}


PuzzleMove::~PuzzleMove()
{
}