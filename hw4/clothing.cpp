#include <iostream>
#include <set>
#include "clothing.h"
#include <sstream>
#include "util.h"

using namespace std;

Clothing::Clothing(string name, double price, int qty, string size ,string brand, set<string> keywords):Product("clothing", name, price, qty)
{
	cBrand = brand;
	cSize = size;
}
//finds the keywords of this book
set<string> Clothing::keywords() const
{
	set<string> keywords = parseStringToWords(convToLower(name_));
    set<string> brand_words = parseStringToWords(convToLower(cBrand));
    set<string>::iterator it;
    for(it = brand_words.begin(); it != brand_words.end(); ++it)
    {
        keywords.insert(*it);
    }
	return keywords;
}
bool Clothing::isMatch(vector<string>& searchTerms) const
{
	return false;
}
//create string that contains product info
std::string Clothing::displayString() const
{
	string display = this->getName();
	display += '\n';
	display += "Size: ";
	display += cSize;
	display += " Brand: ";
	display += cBrand;
	display += '\n';
	stringstream ss;
	string price;
	ss << getPrice();
	ss >> price;
	display += price;
	display += " "; 
	stringstream ss2;
	string qty;
	ss2 << getQty();
	ss2 >> qty;
	display += qty;
	display += " left.";
	display += '\n';
	return display;
}
//outputs the database format of the product info
void Clothing::dump(ostream& os) const
{
	os << this->getName() << endl;
	os << this->getPrice() << endl;
	os << this->getQty() << endl;
	os << cSize << endl;
	os << cBrand << endl;
}