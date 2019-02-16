#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <sstream>
#include <string.h>
#include <cctype>
#include "stackstring.h"

using namespace std;

int evaluate(StackString& stack);
string subtract(string big, string small);
string add(string one, string two);
string check_carrots(string back, StackString& stack);

int main(int argc, char* argv[])
{
	if(argc < 3)
	{
		cout << "Not enough arguments" << endl;
	}
	ofstream ofile(argv[2]);
	if(ofile.fail())
	{
		cout << "Error" << endl;
	}
	ifstream infile(argv[1]);
	if(infile.fail())
	{
		cout << "Error" << endl;
		return 1;
	}
	string strline;
	bool valid_char = true;
	while(getline(infile, strline))
	{
		stringstream ss(strline);
		char c;
		string str = "";
		StackString stack;
		int operators = 0;
		int words = 0;
		int open_par = 0;
		int closed_par = 0;
		bool nextline = false;
		while(ss.get(c) && valid_char == true)
		{
			if(c >= 65 && c<=90)
			{
				valid_char == false;
				ofile << "Malformed" << endl;
				nextline = true;
				break;
			}
			
			//once we get a char
			if(islower(c))
			{
				//while reading in char build word
				while(islower(c))
				{
					str += c;
					ss.get(c);
					//implemented for case with only char's, no par
					if(ss.fail())
					{
						break;
					}
				}
			}

			
			//if I just built word, push to stack
			if(str != "") 
			{
				// cout << "word: " << str << endl;
				str = check_carrots(str, stack);
				// cout << "push modified word to stack: " << str << endl;
				stack.push(str);
				words++;
				//cout << "top in main: " << stack.top() << endl;
				//cout << "stack top: " << stack.top() << endl;
				//reset string
				str = "";
			}
			//skip over spaces
			if(isspace(c)) 
			{
				while(isspace(c))
				{
					ss.get(c);
					if(ss.fail())
					{
						break;
					}
				}
				if(islower(c))
				{
					str += c;
				}

			}
			while(c == '+' || c == '-' || c == '(' || c == '>' || c == '<')
			{
				//malform checking
				if(c == '+' || c == '-')
				{
					operators++;
				}
				if(c == '(')
				{
					open_par++;
				}
				string symbol(1, c);
				// cout << "push symbol in stack: " << symbol << endl;
				stack.push(symbol);
				ss.get(c);
				if(islower(c))
				{
					str += c;
				}
			}
			if(c == ')')
			{
				//malform check
				if(open_par > 0)
				{
					if(evaluate(stack) == 1)
					{
						//cout << "this malform" << endl;
						ofile << "Malformed" << endl;
						break;
					}
				}
				else
				{
					//cout << "which malform? " << endl;
					ofile << "Malformed" << endl;
					break;
				}
				closed_par++;
			}
		}
		//prevents double output of malform
		if(nextline == true)
		{
			continue;
		}
		// cout << "check" << endl;
		// cout << operators << endl;
		// cout << words << endl;
		// cout << stack.size() << endl;
		// if(stack.size() > 1 && operators != (words - 1))
		// {
		// 	ofile << "Malformed" << endl;
		// }
		if(open_par == closed_par && stack.size() == 1 && open_par > 0)
		{
			ofile << stack.top() << endl;
			stack.pop();
		}
		else if(open_par == 0 && closed_par == 0 && stack.size() == 1)
		{
			string no_par = check_carrots(stack.top(), stack);
			ofile << no_par << endl;
		}
		else if(stack.size() == 0)
		{
			ofile << endl;
		}
		else
		{
			// cout << "IN HERE MALFORM" << endl << endl;
			ofile << "Malformed" << endl;
		}
			
	}
}


int evaluate(StackString& stack)
{
	char test;
	string final;
	int plus = 0;
	int minus = 0;
	StackString holder;
	int words = 0;
	while(!stack.empty()) 
	{
		string back = stack.top();
		stack.pop();
		bool is_symbol = false;
		if(back == "+" || back == "-" || back == "<" || back == ">" || back == "(")
		{
			is_symbol = true;
		}
		if(is_symbol == false)
		{
			words++;
		}
		if(!stack.empty())
		{
			back = check_carrots(back, stack);
		}	
		stringstream ss(back);
		while(ss >> test)
		{
			final = back;
			if(test == '(')
			{
				if(plus > 0 && minus > 0)
				{
					//mixed operators
					if(!stack.empty() || !holder.empty())
					{
						while(!stack.empty())
						{
							stack.pop();
						}
						while(!holder.empty())
						{
							holder.pop();
						}
					}
					return 1;
				}
				if(minus > 1)
				{
					while(!stack.empty())
					{
						stack.pop();
					}
					while(!holder.empty())
					{
						holder.pop();
					}
				return 1;
				}
				string answer;
				answer = check_carrots(holder.top(), stack);
				// cout << "here" << endl;
				// cout << words << endl;
				// cout << (plus + minus) << endl; ///////////////////////////////
				// if((words - 1) != (plus + minus))
				// {
				// 	return 1;
				// }
				stack.push(answer);
				holder.pop();
				return 0;
			}
			// cout << "test: " << test << endl;
			if(test == '+')
			{
				// cout << "in plus" << endl;
				plus++;
				// if(stack.empty()) //////////////////////////////////////
				// {
				// 	return 1;
				// }
				string first = holder.top();
				// cout << "adding this(in holder): " << first << endl;
				// cout << "to this: " << stack.top() << endl;
				final = add(stack.top(), first);
				stack.pop();
				holder.pop();
				//holder.push(final); already have after if
				// cout << stack.size() << endl;
				// cout << stack.top() << endl;
			}
			if(test == '-')
			{
				minus++;
				string first = holder.top();
				//final = stack.top();
				// cout << "from this(in holder): " << stack.top() << endl;
				// cout << "subtracting this: " << first << endl;
				final = subtract(stack.top().c_str(), first);
				//cout << "final post sub: " << final << endl;
				stack.pop();
				holder.pop();
				//holder.push(final); already have below
			}
		}
		holder.push(final);
	}
}
string add(string one, string two)
{
	string final = (one + two);
	return final;
}
string subtract(string big, string small)
{
	bool found = false;
	string part1;
	string ans;
	for(unsigned int i = 0;i<big.size();i++)
	{
		string substr = big.substr(i, small.length());
		//cout << substr << endl;
		if(strcmp(substr.c_str(), small.c_str()) == 0)
		{
			found = true;
			part1 = big.substr(0, i);
			ans = part1 + big.substr(i + small.length(), big.length() - small.length() - part1.length());
			break;
		}
	}
	if(found == false)
	{
		return big;
	}
	else
	{
		return ans;
	}
}
string check_carrots(string back, StackString& stack)
{
	int f_remove = 0;
	int b_remove = 0;
	if(stack.empty())
	{
		return back;
	}
	if(back == "(" || back == "+" || back == "-" || back == "<" || back == ">")
	{
		return back;
	}
	if(stack.top() == "<" || stack.top() == ">")
	{
		while(!stack.empty() && (stack.top() == "<" || stack.top() == ">"))
		{
			if(stack.top() == "<")
			{
				b_remove++;
			}
			if(stack.top() == ">")
			{
				f_remove++;
			}
			//does this pop stack
			stack.pop();
		}
		// cout << "front remove: " << f_remove << endl;
		// cout << "back remove: " << b_remove << endl;
		// cout << "BEFORE: "<< back << endl;
		return back.substr(f_remove, back.length() - b_remove - f_remove);
	}
	else
	{
		// cout << "in else" << endl;
		return back;
	}
}