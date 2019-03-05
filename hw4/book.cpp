#include <iostream>
#include <set>
#include "book.h"
#include <sstream>
#include "util.h"

using namespace std;

Book::Book(string name, double price, int qty, string isbn ,
	string author, set<string> keywords):Product("book", name, price, qty)
{
	bAuthor = author;
	bIsbn = isbn;
	bKeywords = keywords;
}
//finds the keywords of this book
set<string> Book::keywords() const
{
	set<string> keywords = parseStringToWords(convToLower(name_));
    set<string> author_words = parseStringToWords(convToLower(bAuthor));
    set<string>::iterator it;
    for(it = author_words.begin(); it != author_words.end(); ++it)
    {
        keywords.insert(*it);
    }
    keywords.insert(convToLower(bIsbn));
	return keywords;
}
bool Book::isMatch(vector<string>& searchTerms) const
{
	return false;
}
//create string that contains product info
std::string Book::displayString() const
{
	string display = Product::getName();
	display += '\n';
	display += "Author: ";
	display += bAuthor;
	display += " ISBN: ";
	display += bIsbn;
	display += '\n';
	stringstream ss;
	string price;
	ss << Product::getPrice();
	ss >> price;
	display += price;
	display += " "; 
	stringstream ss2;
	string qty;
	ss2 << Product::getQty();
	ss2 >> qty;
	display += qty;
	display += " left.";
	display += '\n';
	return display;
}
//outputs the database format of the product info
void Book::dump(ostream& os) const
{
	os << Product::getName() << endl;
	os << Product::getPrice() << endl;
	os << Product::getQty() << endl;
	os << bIsbn << endl;
	os << bAuthor << endl;
}