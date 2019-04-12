#include <iostream>
#include "bst.h"
#include "print_bst.h"

using namespace std;

int main(int argc, char const *argv[])
{
	BinarySearchTree<int, string>* tree = new BinarySearchTree<int, string>();
	// tree->insert(make_pair(25, "root"));
	// tree->insert(make_pair(30, "bill"));
	// tree->insert(make_pair(29, "jeff"));
	// tree->insert(make_pair(31, "jay"));
	// tree->insert(make_pair(21, "egg"));
	// tree->insert(make_pair(23, "gas"));
	// tree->insert(make_pair(19, "oil"));
	// tree->print();
	// if(tree->isBalanced() == true)
	// {
	// 	cout << "balanced" << endl;
	// }
	// else
	// {
	// 	cout << "unbalanced" << endl;
	// }
	//  tree->remove(29);
	// cout << "removing 21" << endl;
	// tree->remove(21); //delete normal with 2 children. WORKS
	// tree->print();
	// if(tree->isBalanced() == true)
	// {
	// 	cout << "balanced" << endl;
	// }
	// else
	// {
	// 	cout << "unbalanced" << endl;
	// }
	// tree->remove(31);
	// tree->print();
	// if(tree->isBalanced() == true)
	// {
	// 	cout << "balanced" << endl;
	// }
	// else
	// {
	// 	cout << "unbalanced" << endl;
	// }
	// tree->remove(30);
	// tree->print();
	// if(tree->isBalanced() == true)
	// {
	// 	cout << "balanced" << endl;
	// }
	// else
	// {
	// 	cout << "unbalanced" << endl;
	// }
	// tree->insert(make_pair(25, "root"));
	// tree->insert(make_pair(30, "bill"));
	// tree->insert(make_pair(29, "jeff"));
	// tree->insert(make_pair(31, "jay"));
	// tree->insert(make_pair(21, "poop"));
	// tree->insert(make_pair(23, "gas"));
	// tree->insert(make_pair(19, "oil"));
	// tree->insert(make_pair(18, "arg"));
	// tree->insert(make_pair(20, "log"));
	// tree->print();
	// if(tree->isBalanced() == true)
	// {
	// 	cout << "balanced" << endl;
	// }
	// else
	// {
	// 	cout << "unbalanced" << endl;
	// }
	// cout << "removing 21" << endl;
	// tree->remove(21); //delete normal with 2 children. WORKS
	// tree->print();
	// if(tree->isBalanced() == true)
	// {
	// 	cout << "balanced" << endl;
	// }
	// else
	// {
	// 	cout << "unbalanced" << endl;
	// }
	tree->insert(make_pair(25, "root"));
	tree->insert(make_pair(30, "bill"));
	tree->insert(make_pair(29, "jeff"));
	tree->insert(make_pair(31, "jay"));
	tree->insert(make_pair(21, "poop"));
	tree->insert(make_pair(23, "gas"));
	tree->insert(make_pair(19, "oil"));
	tree->print();
	cout << "removing 25" << endl;
	tree->remove(25); //deletes root on tree with both sides. WORKS
	tree->print();
	tree->insert(make_pair(30, "bobby"));
	tree->print();

	// tree->insert(make_pair(5, "jess"));
	// tree->insert(make_pair(7, "diane"));
	// tree->insert(make_pair(9, "joey"));
	// tree->insert(make_pair(6, "joey"));
	// tree->insert(make_pair(8, "panda"));
	// if(tree->isBalanced() == true)
	// {
	// 	cout << "balanced" << endl;
	// }
	// else
	// {
	// 	cout << "unbalanced" << endl;
	// }
	// tree->print();
	// //tree->remove(5); //deletes root  on a right only tree. WORKS
	// //tree->print();
	// if(tree->isBalanced() == true)
	// {
	// 	cout << "balanced" << endl;
	// }
	// else
	// {
	// 	cout << "unbalanced" << endl;
	// }
	//tree->clear();
	//cout << "before print" << endl;
	// cout << (tree->begin())->first << endl;
	// cout << (++tree->begin())->first << endl;
	// cout << (++++tree->begin())->first << endl;
	// cout << (++++++tree->begin())->first << endl;
	// tree->print();
	// tree->clear();
	//BinarySearchTree<int, string>* btree = new BinarySearchTree<int, string>();
	//tree->print();
	// tree->insert(make_pair(15, "root"));
	// tree->insert(make_pair(7, "diane"));
	// tree->insert(make_pair(9, "diane"));
	// tree->insert(make_pair(6, "joey"));
	// tree->insert(make_pair(5, "panda"));
	// tree->insert(make_pair(16, "ugo"));
	// tree->insert(make_pair(100, "ugo"));
	// tree->print();
	// //tree->remove(8); //deletes root on left only tree. WORKS
	// //tree->print();
	// if(tree->isBalanced() == true)
	// {
	// 	cout << "balanced" << endl;
	// }
	// else
	// {
	// 	cout << "unbalanced" << endl;
	// }
	// tree->remove(9);
	// tree->print();
	// if(tree->isBalanced() == true)
	// {
	// 	cout << "balanced" << endl;
	// }
	// else
	// {
	// 	cout << "unbalanced" << endl;
	// }
	return 0;
}