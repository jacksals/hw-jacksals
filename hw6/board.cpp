#include <iostream>
#include <sstream>
#include <iomanip>
#include <map>
#include <cmath>
#include <cstdlib>
#include <stdexcept>
#include "board.h"

using namespace std;

Board::Board(int dim, int numInitMoves, int seed )
{
  size_ = dim*dim;
  tiles_ = new int[size_];
  srand(seed);
  for(int i=0; i < size_; i++){
    tiles_[i] = i;
  }
  int blankLoc = 0;
  while(numInitMoves > 0){
    int r = rand()%4;
    int randNeighbor = -1;
    if(r == 0){
      int n = blankLoc - dim;
      if(n >= 0){
	randNeighbor = n;
      }
    }
    else if(r == 1){
      int w = blankLoc - 1;
      if(blankLoc % dim != 0){
	randNeighbor = w;
      }
    }
    else if(r == 2){
      int s = blankLoc + dim;
      if(s  < size_){
	randNeighbor = s;
      }
    }
    else {
      int e = blankLoc + 1;
      if(blankLoc % dim != dim-1){
	randNeighbor = e;
      }
    }
    if(randNeighbor > -1){
      tiles_[blankLoc] = tiles_[randNeighbor];
      tiles_[randNeighbor] = 0;
      blankLoc = randNeighbor;
      numInitMoves--;
    }
  }
}


void Board::move(int tile)
{
  int side_dim = dim();
  int tr, tc, br, bc;

  // find tile row and column
  int i=-1;
  while(tiles_[++i] != tile);

  tr = i / side_dim; 
  tc = i % side_dim;

  // find blank row and column
  int j=-1;
  while(tiles_[++j] != 0);

  br = j / side_dim;
  bc = j % side_dim;

  if( abs(static_cast<double>(tr-br)) + abs(static_cast<double>(tc-bc)) != 1){
    stringstream ss;
    ss << "Invalid move of tile " << tile << " at ";
    ss << tr << "," << tc << " and blank spot at ";
    ss << br << "," << bc << endl;
    throw BoardMoveError(ss.str());
  }
  // Swap tile and blank spot
  tiles_[j] = tile;
  tiles_[i] = 0;
}

// Generate new boards representing all the potential moves of tiles into 
// the current blank tile location. The returned map should have
// the key as the tile moved and the value as a new Board object with the
// configuration reflecting the move of that tile into the blank spot
map<int, Board*> Board::potentialMoves() const
{
  int j=-1;
  while(tiles_[++j] != 0);

  int side_dim = dim();
  int br = j / side_dim;
  int bc = j % side_dim;
  map<int, Board*> moves;

  int up = j - side_dim;
  int down = j + side_dim;
  int right = j + 1;
  int left = j - 1;

  if(up >= 0 && (up % side_dim == bc) )
  {
    Board* b = new Board(*this);
    b->move(tiles_[up]);
    moves.insert(make_pair(tiles_[up], b));
  }
  if(down < size() && (down % side_dim == bc) )
  {
    Board* b = new Board(*this);
    b->move(tiles_[down]);
    moves.insert(make_pair(tiles_[down], b));
  }
  if(right < size() && (right/side_dim == br) )
  {
    Board* b = new Board(*this);
    b->move(tiles_[right]);
    moves.insert(make_pair(tiles_[right], b));
  }
  if(left >= 0 && (left/side_dim == br) )
  {
    Board* b = new Board(*this);
    b->move(tiles_[left]);
    moves.insert(make_pair(tiles_[left], b));
  }

  return moves;

}

Board::Board(const Board& b)
{
  this->size_ = b.size_;
  this->tiles_ = new int[size_];
  for(int i = 0;i<size_;i++)
  {
    this->tiles_[i] = b.tiles_[i];
  }
}
Board::~Board()
{
  delete [] tiles_; 
}
bool Board::operator<(const Board& rhs) const
{
  for(int i = 0;i<rhs.size_;i++)
  {
    if(rhs.tiles_[i] > this->tiles_[i])
    {
      return false;
    }
  }
  return true;
}
ostream& operator<<(std::ostream &os, const Board &b)
{
  int dimen = b.dim();
  int count = 0;
  while(count < b.size_)
  {
    // for(int j = 0;j<dimen;j++)
    // {
    //   os << "+--";
    // }
    // os << "+";
    // os << endl;
    b.printRowBanner(os);
    for(int k = 0;k<dimen;k++)
    {
      if(b.tiles_[count] == 0)
      {
        cout << "|  ";
        count++;
      }
      else if(b.tiles_[count] < 10 && b.tiles_[count] != 0)
      {
        os << "| " << b.tiles_[count];
        count++;
      }
      else
      {
        os << "|" << b.tiles_[count];
        count++;
      }
    }
    os << "|" << endl;
  }
  return os;
}
// Complete this function
bool Board::solved() const
{
  for(int i = 0;i< (size_ - 1);i++)
  {
    if(tiles_[i] > tiles_[i + 1])
    {
      return false;
    }
  }
  return true;
}


const int& Board::operator[](int loc) const 
{ 
  return tiles_[loc]; 
}

int Board::size() const 
{ 
  return size_; 
}

int Board::dim() const
{
  return static_cast<int>(sqrt(size_));
}

void Board::printRowBanner(ostream& os) const
{
  int side_dim = dim();
  if(side_dim == 0) return;
  os << '+';
  for(int i=0; i < side_dim; i++){
    os << "--+";
  }
  os << endl;
}
