#ifndef CLOTHING_H
#define CLOTHING_H
#include "product.h"

class Clothing : public Product {

public: 
	Clothing(std::string name, double price, int qty, std::string size, 
		std::string brand, std::set<std::string> );
	std::set<std::string> keywords() const;
	bool isMatch(std::vector<std::string>& searchTerms) const;
	std::string displayString() const;
	void dump(std::ostream& os) const;


private:
	std::string cSize;
	std::string cBrand;
	std::set<std::string> cKeywords;
};
#endif