#include <iostream>
#include "heap.h"
using namespace std;

int main()
{
	Heap<int> h(2);
	h.push(25.0, 10);
	h.push(22.0, 17);
	h.push(20.0, 12);
	h.decreaseKey(2, 10);
	h.pop();
	h.decreaseKey(1, 10);
	return 0;
}