#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <cctype>
#include "stackstring.h"

using namespace std;

int main(int argc, char* argv[])
{
	ifstream infile(argv[2]);
	if(infile.fail())
	{
		cout << "Error" << endl;
		return 1;
	}
	string strline;
	getline(infile, strline);
	stringstream ss(strline);
	char c;
	string str = "";
	StackString stack;
	int front= 0;
	int back = 0;
	while(ss.get(c))
	{
		while(isspace(c))
		{
			ss.get(c);
		}
		while(c == '+' || c == '-' || c == '<' || c == '>')
		{
			stack.push_back(c);
			ss.get(c);
		}
		if(c == ')')
		{
			evaluate(stack);
		}
		else {
			str += c;
			stack.push_back(str);
		}
	}
}


void evaluate(StackString stack)
{
	char test;
	while(!stack.empty()) 
	{
		string back = stack.back();
		stringstream ss(back);
		while(test != '(')
		{
			ss >> test;
			if(test == '+')
			{
				stack.pop_back();
				string first = stack.back();
				add(first, back);
			}
			if(test == '-')
			{
				stack.pop_back();
				string first = stack.back();
				subtract(first, back);
			}
			if(test == '<')
			{
				//problem: this could erase other carrots
				back.erase(back.length());
			}
			if(test == '>')
			{
				//problem: this could erase other carrots
				back.erase(0);
			}
		}
		stack.pop_back();
	}
}
string add(string one, string two)
{
	string final = (one + two);
	return final;
}
string subtract(string big, string small)
{
	for(int i = 0;i<big.size();i++)
	{
		string substr = big.substr(i, i + small.length());
		if(strcmp(substr, small))
		{
			return substr;
		}
	}
}