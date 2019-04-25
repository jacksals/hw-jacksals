#ifndef MOVIE_H
#define MOVIE_H

#include "product.h"

class Movie : public Product {

public: 
	Movie(std::string name, double price, int qty, 
		std::string rating,std::string genre);
	std::set<std::string> keywords() const;
	bool isMatch(std::vector<std::string>& searchTerms) const;
	std::string displayString() const;
	void dump(std::ostream& os) const;

private:
	std::string mGenre;
	std::string mRating;
	std::set<std::string> mKeywords;
};

#endif