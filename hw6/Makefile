CXX=g++
CXXFLAGS=-g -Wall -std=c++11

OBJS=puzzle.o board.o puzzle_heur.o puzzle_move.o puzzle_solver.o

all: puzzle

puzzle: $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)
puzzle.o: puzzle.cpp board.h puzzle_heur.h puzzle_move.h puzzle_solver.h heap.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c puzzle.cpp
board.o: board.cpp board.h heap.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c board.cpp 
puzzle_heur.o: puzzle_heur.cpp puzzle_heur.h heap.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c puzzle_heur.cpp
puzzle_move.o: puzzle_move.cpp puzzle_move.h heap.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c puzzle_move.cpp
puzzle_solver.o: puzzle_solver.cpp puzzle_solver.h heap.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c puzzle_solver.cpp

clean:
	rm -f *.o puzzle