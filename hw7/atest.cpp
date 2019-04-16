#include <iostream>
#include "avlbst.h"
#include "print_bst.h"

using namespace std;

int main(int argc, char const *argv[])
{
	AVLTree<int, string>* tree = new AVLTree<int, string>();
	// tree->insert(make_pair(10, "top"));

	// tree->insert(make_pair(8, "middle"));
	// tree->insert(make_pair(6, "butt"));

	//right rotate on the tree from slides
	// tree->insert(make_pair(10, "z--root"));
	// tree->insert(make_pair(11, "d--root right"));
	// tree->insert(make_pair(5, "y--root left"));
	// tree->insert(make_pair(6, "c--y right"));
	// tree->insert(make_pair(2, "x--y left"));
	// tree->insert(make_pair(1, "a--x left"));
	// tree->insert(make_pair(3, "b--x right"));
	// tree->print();
	// tree->rightRotate(10);
	// tree->print();

	// tree->remove(5);
	// tree->print();
	// tree->clear();
	// tree->print();
	// tree->print();
	// tree->rightRotate(4);
	// tree->print();

	//right rotate on a small tree
	// tree->insert(make_pair(20, "test"));
	// tree->insert(make_pair(25, "test"));
	// tree->insert(make_pair(30, "test"));
	// tree->print();
	//tree->leftRotate(20);
	//tree->print();

	// tree->insert(make_pair(10, "root"));
	// tree->insert(make_pair(7, "a"));
	// tree->insert(make_pair(9, "b"));
	// tree->print();

	tree->insert(make_pair(5, "root"));
	tree->insert(make_pair(6, "a"));
	tree->insert(make_pair(7, "b"));
	tree->insert(make_pair(8, "c"));
	tree->insert(make_pair(9, "d"));
	tree->print();
	return 0;
}