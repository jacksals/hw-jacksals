#include <iostream>
#include "split.h"
using namespace std;

void funcB (Node* in1, Node* in2);

Node* funcA (Node* in)
{
   if (in == NULL) return NULL;
   Node* out = NULL;
   if (in->next != NULL)
   {
       out = funcA (in->next);
       funcB (in, out);
       in->next = NULL;
       return out;
   }
   return in;
}

void funcB (Node* in1, Node* in2)
{
   if (in2->next != NULL) 
   {
       funcB (in1, in2->next);
       return;
   }
   in2->next = in1;
}

int main(int argc, char* argv[])
{
	
	
	
	
	Node* five = new Node(5, NULL);
	Node* four = new Node(4, five);
	Node* three = new Node(3,four);
	Node* two = new Node(2, three);
	Node* in = new Node(1, two);

	cout << "here" << endl;
	funcA(in);
	//Node* curr = in;
	cout << five->next->value << endl;
	cout << four->next->value << endl;
	cout << three->next->value << endl;
	cout << two->next->value << endl;
	
	//Node* odds = NULL;
	//Node* evens = NULL;

	// while (in != nullptr){
	// 	cout << in->value << endl;
	// 	in = in->next;
	// }
	
	//one->value = 1;
	// two->value = 2;
	// three->value = 3;
	// four->value = 4;
	// five->value = 5;
	// in->next = one;
	// one->next = two;
	// two->next = three;
	// three->next = four;
	// four->next = five;
	// five->next = NULL;
	// odds->next = NULL;
	// evens->next = NULL;
	// split(in, odds, evens);
	// while (odds != NULL) {
	// 	cout << "odds: " << odds->value << endl;
	// 	odds = odds->next;
	// }
	// while (evens != NULL) {
	// 	cout << "evens: " << evens->value << endl;
	// 	evens = evens->next;
	// }
	return 0;
}
