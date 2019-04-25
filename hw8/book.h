#ifndef BOOK_H
#define BOOK_H

#include "product.h"
#include <string>
#include <set>

class Book : public Product {

public: 
	Book(std::string name, double price, int qty, std::string isbn, 
		std::string author, std::set<std::string> );
	std::set<std::string> keywords() const;
	bool isMatch(std::vector<std::string>& searchTerms) const;
	std::string displayString() const;
	void dump(std::ostream& os) const;

private:
	std::string bAuthor;
	std::string bIsbn;
	std::set<std::string> bKeywords;
};

#endif