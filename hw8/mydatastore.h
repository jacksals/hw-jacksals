#include <iostream>
#include "util.h"
#include "book.h"
#include "clothing.h"
#include "movie.h"
#include "user.h"
#include "datastore.h"
#include <map>
#include <utility>
#include <vector>
#include "review.h"


class MyDataStore : public DataStore {
public:
	~MyDataStore();
	void addProduct(Product* p);
	void addUser(User* u);
	std::vector<Product*> search(std::vector<std::string>& terms, int type);
	void dump(std::ostream& ofile);
	void buycart(std::string buy_username);
	void viewcart(std::string view_user);

	void addcart(std::string username, int search_hit_number, 
		std::vector<Product*> hits);
	void addReview(const std::string& prodName, int rating,
                          const std::string& username,
                          const std::string& date,
                          const std::string& review_text);
	std::set<User*> getUsers();
	unsigned long long hasher(std::string p);
	std::vector<std::pair<std::string, double> > makeSuggestion(std::string currentUser);
private:
	double basicSim(std::string userA, std::string userB);
	double refinedSim(std::string myuser, std::string otheruser);
	std::set<Product*> products;
	std::set<User*> users;
	std::map<std::string, std::vector<Product*>> users_to_cart;
	std::map<std::string, std::set<Product*>> map_prod;
};