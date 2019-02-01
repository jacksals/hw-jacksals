/*
CSCI 104: Homework 2 Problem 6

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <iostream>

using namespace std;

/* Add a prototype for a helper function here if you need */
void split_helper(Node*& in, Node*& odds, Node*& evens);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
	split_helper(in, odds, evens);
	in = nullptr;
}

/* If you needed a helper function, write it here */
void split_helper(Node*& in, Node*& odds, Node*& evens)
{
	if(in == nullptr)
	{
		return;
	}
	split_helper(in->next, odds, evens);
	if((in->value)%2 == 0)
	{
		in->next = evens;
		evens = in;
	}
	else if((in->value)%2 == 1)
	{
		in->next = odds;
		odds = in;
	}
}
