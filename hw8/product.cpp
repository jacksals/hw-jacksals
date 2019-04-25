#include <sstream>
#include <iomanip>
#include "product.h"

using namespace std;

Product::Product(const std::string category, const std::string name,
 double price, int qty) :
    name_(name),
    price_(price),
    qty_(qty),
    category_(category)
{

}

Product::~Product()
{

}


double Product::getPrice() const
{
    return price_;
}

std::string Product::getName() const
{
    return name_;
}

void Product::subtractQty(int num)
{
    qty_ -= num;
}

int Product::getQty() const
{
    return qty_;
}

/**
 * default implementation...can be overriden in a future
 * assignment
 */
bool Product::isMatch(std::vector<std::string>& searchTerms) const
{
    return false;
}

void Product::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << endl;
}
void Product::addRev(Review* r)
{
    reviews_.push_back(r);
}
std::vector<Review*> Product::getReviews()
{
    return reviews_;
}
double Product::avgRating()
{
    int sum = 0;
    for(unsigned int i = 0;i<reviews_.size();i++)
    {
        sum += reviews_[i]->rating;
    }
    double num = 0;
    if(reviews_.size() > 0)
    {
        num = (sum/reviews_.size());
    }
    return num;
}


