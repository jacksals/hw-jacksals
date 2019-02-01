/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;
#include <string>

int main(int argc, char* argv[])
{
	//test push_front starting with empty
	ULListStr u = ULListStr();
	cout << "Creating blank ULList 1" << endl;
	cout << "Current size is of ULList 1: " << u.size() << endl;
	cout << "push_front all letters of the alphabet (26 values)" << endl;
	int L = 26;
    for(int i = 0;i<L;i++) {
    	std::string s(1, 'z' - i);

  		u.push_front(s);
  	}
  	cout << "Listing values:" << endl;
  	for(int j = 0;j<26;j++) {
  		cout << u.get(j) << " ";
  	}
  	cout << endl << endl;
  	cout << "Front value is: " << u.front() << endl;
  	cout << "Back value is: " << u.back() << endl;
  	cout << endl;
  	cout << "Current size of ULList 1 is: " << u.size() << endl;
  	cout << "Popping 6 values from back" << endl;
  	for(int i = 0;i<6;i++) {
  		u.pop_back();
  	}
  	cout << "New back value is: " << u.back() << endl;

  	cout << "Popping 10 more values from back" << endl;
  	for(int i = 0;i<10;i++) {
  		u.pop_back();
  	}

  	cout << "New back value is: " << u.back() << endl;

  	cout << "Popping 5 values from front" << endl;
  	for(int i = 0;i<5;i++) {
  		u.pop_front();
  	}
  	cout << "New front value is: " << u.front() << endl;
  	cout << "Current size of ULList 1 is: " << u.size() << endl;
  	cout << "Popping 5 more values from back" << endl;
  	for(int i = 0;i<5;i++) {
  		u.pop_back();
  	}
  	cout << "Current size of ULList 1 is: " << u.size() << endl;
  	cout << endl;
  	cout << "pushing back 'back' 3 times" << endl;
  	for(int i = 0;i<3;i++) {
  		u.push_back("back");
  	}
  	cout << "Listing values:" << endl;
  	for(int j = 0;j<3;j++) {
  		cout << u.get(j) << " ";
  	}
  	cout << endl;
  	cout << "pushing front 'front' 4 times" << endl;
  	for(int i = 0;i<4;i++) {
  		u.push_front("front");
  	}
  	cout << "Listing values:" << endl;
  	for(int j = 0;j<7;j++) {
  		cout << u.get(j) << " ";
  	}
  	cout << endl;
  	cout << "Current size of ULList 1 is: " << u.size() << endl;
  	cout << "Popping all values from front" << endl;
  	for(int i = 0;i<7;i++) {
  		u.pop_front();
  	}
  	cout << "Current size of ULList 1 is: " << u.size() << endl;
  	cout << endl;
  	//test push_back starting with empty
  	cout << "Creating blank ULList 2" << endl;
  	ULListStr x = ULListStr();
  	cout << "Current size of ULList 2 is: " << x.size() << endl;
  	cout << "push_back 'test' 30 times" << endl;
  	for(int i = 0;i<30;i++) {
  		x.push_back("test");
  	}
  	for(int i = 0;i<30;i++) {
  		cout << i+1 << ": " << x.get(0) << endl;
  	}
  	cout << "Current size of ULList 2 is: " << x.size() << endl;
  	cout << "Popping all values from back" << endl;
  	for(int i = 0;i<30;i++) {
  		x.pop_back();
  	}
  	cout << "Current size of ULList 2 is: " << x.size() << endl;
  	
  	return 0;
}
