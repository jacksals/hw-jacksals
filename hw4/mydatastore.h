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


class MyDataStore : public DataStore {
public:
	void addProduct(Product* p);
	void addUser(User* u);
	std::vector<Product*> search(std::vector<std::string>& terms, int type);
	void dump(std::ostream& ofile);
	void buycart(std::string buy_username);
	void viewcart(std::string view_user);

	void addcart(std::string username, int search_hit_number, std::vector<Product*> hits);

private:
	//use either set with pointers to users or map with user name and value
	std::set<Product*> products;
	std::set<User*> users;
	std::map<std::string, std::vector<Product*>> users_to_cart;
	std::map<std::string, std::set<Product*>> map_prod;
};