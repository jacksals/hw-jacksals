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

	// tree->insert(make_pair(50, "x"));
	// tree->insert(make_pair(60, "y"));
	// tree->print();
	// tree->insert(make_pair(70, "z"));
	// tree->print();
	// tree->insert(make_pair(30, "e"));
	// tree->print();
	// tree->insert(make_pair(20, "d"));
	// tree->print();
	// tree->insert(make_pair(10, "f"));
	// tree->print();


	//test cases i fail
	// tree->insert(make_pair(2, "root"));
	// tree->insert(make_pair(1, "l"));
	// tree->insert(make_pair(3, "r"));
	// tree->print();
	// tree->remove(2);
	// tree->print();

	// tree->insert(make_pair(5, "1"));
	// tree->insert(make_pair(2, "1"));
	// tree->insert(make_pair(6, "1"));
	// tree->insert(make_pair(4, "1"));
	// tree->print();
	// tree->remove(5);
	// tree->print();

	// tree->insert(make_pair(1, "one"));
	// tree->print();
	// tree->remove(1);
	// tree->print();



	// tree->insert(make_pair(5, "root"));
	// tree->insert(make_pair(6, "a"));
	// tree->insert(make_pair(7, "b"));
	// tree->insert(make_pair(8, "c"));
	// tree->insert(make_pair(9, "d"));
	// tree->print();
	// tree->remove(5);
	// tree->print();

	AVLTree<int, int> bst;
	//remove right child
	for(int i = 0; i<30;i++)
	{
		bst.insert(make_pair(i, i + 1));
		bst.print();
	}
	for(int j = 5; j<15;j++)
	{
		bst.remove(j);
		bst.print();
	}
	// bst.print();
	// bst.insert(make_pair(11, 12));
	// bst.print();
	// bst.insert(std::make_pair(1, "root"));
	// bst.insert(std::make_pair(2, "second"));
	// bst.insert(std::make_pair(3, "third"));
	// bst.print();
	// bst.remove(1);
	//bst.print();
	//remove left child
	// bst.insert(std::make_pair(3, "root"));
	// bst.insert(std::make_pair(2, "second"));
	// bst.insert(std::make_pair(1, "third"));
	// bst.print();
	// bst.remove(3);
	// bst.print();

	//TwoChildrenRemove_3Node
	// AVLTree<int, double> bst;
	// // bst.insert(std::make_pair(2, 1.0));
	// // bst.insert(std::make_pair(1, 1.0));
	// // bst.insert(std::make_pair(3, 1.0));
	// // bst.print();
	// // bst.remove(2);
	// // bst.print();

	// bst.insert(std::make_pair(5, 1.0));
	// bst.insert(std::make_pair(2, 1.0));
	// bst.insert(std::make_pair(6, 1.0));
	// bst.insert(std::make_pair(4, 1.0));
	// bst.print();
	// bst.remove(5);
	// bst.print();

	return 0;
}