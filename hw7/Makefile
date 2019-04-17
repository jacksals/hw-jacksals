CXX=g++
CXXFLAGS=-g -Wall -std=c++11

OBJS=floorplan.o

all: floorplan

floorplan: $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)

floorplan.o: floorplan.cpp avlbst.h bst.h print_bst.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c floorplan.cpp
	