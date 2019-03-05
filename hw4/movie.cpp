#include <iostream>
#include <set>
#include "movie.h"
#include <sstream>
#include "util.h"

using namespace std;

Movie::Movie(string name, double price, int qty, string rating ,string genre):Product("movie", name, price, qty)
{
	mRating = rating;
	mGenre = genre;
}
//finds the keywords of this book
set<string> Movie::keywords() const
{
	set<string> keywords = parseStringToWords(convToLower(name_));
	keywords.insert(convToLower(mGenre));
	set<string>::iterator it;
	return keywords;
}
bool Movie::isMatch(vector<string>& searchTerms) const
{
	return false;
}
//create string that contains product info
std::string Movie::displayString() const
{
	string display = this->getName();
	display += '\n';
	display += "Genre: ";
	display += mGenre;
	display += " Rating: ";
	display += mRating;
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
void Movie::dump(ostream& os) const
{
	os << this->getName() << endl;
	os << this->getPrice() << endl;
	os << this->getQty() << endl;
	os << mGenre << endl;
	os << mRating << endl;
}