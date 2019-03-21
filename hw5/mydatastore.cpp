#include <iostream>
#include "mydatastore.h"
#include <vector>

using namespace std;

MyDataStore::~MyDataStore()
{
	set<Product*>::iterator it;
	for(it = products.begin(); it != products.end(); ++it)
	{
		delete *it;
	}
	set<User*>::iterator it2;
	for(it2 = users.begin();it2 != users.end(); ++it2)
	{
		delete *it2;
	}
}

void MyDataStore::addProduct(Product* p)
{
	set<string> keys = p->keywords();
	//iterate thru map to see if keyword already in map. If so, add to set corresponding to word
	set<string>::iterator it;
	for(it = keys.begin();it != keys.end(); ++it)
	{
		if(map_prod.size() == 0)
		{
			set<Product*> setp;
			setp.insert(p);
			map_prod.insert(make_pair(*it, setp));
		}
		//if key is in map, add product to set corresponding to key
		map<string, set<Product*>>::iterator it2;
		for(it2 = map_prod.begin();it2 != map_prod.end(); ++it2)
		{
			//if key is already in map
			if(map_prod.find(*it) != map_prod.end())
			{
				(map_prod.at(*it)).insert(p);
			}
			else
			{
				//if key not in map, insert key wit
				set<Product*> setp;
				setp.insert(p);
				map_prod.insert(make_pair(*it, setp));
			}
		}
	}
	products.insert(p);
}
void MyDataStore::addUser(User* u)
{
	vector<Product*> cart;
	users_to_cart.insert(make_pair(u->getName(), cart));
	users.insert(u);
}
vector<Product*> MyDataStore::search(vector<string>& terms, int type)
{
	vector<Product*> answers;
	//AND
	if(type == 0)
	{
		string prev_term;
		set<Product*> set_prod;
		//iterate thru terms
		for(unsigned int i = 0;i<terms.size();i++)
		{
			bool found_term = false;
			map<string, set<Product*>>::iterator it;
			for(it = map_prod.begin(); it != map_prod.end(); ++it)
			{
				//find each term in map of products
				if(map_prod.find(terms[i]) != map_prod.end())
				{
					found_term = true;
					//only call setIntersection if we have another set to compare to
					if(!set_prod.empty() && terms[i] != prev_term)
					{
						set_prod = setIntersection(set_prod, map_prod.at(terms[i]));
						if(set_prod.empty())
						{
							vector<Product*> empty;
							return empty;
						}
					}
					//when grabbing the first set
					else if(set_prod.empty())
					{
						set_prod = map_prod.at(terms[i]);
						prev_term = terms[i];
					}
				}
				if(found_term == false)
				{
					vector<Product*> empty;
					return empty;
				}
			}
			
		}
		set<Product*>::iterator it;
		for(it = set_prod.begin();it != set_prod.end(); ++it)
		{
			answers.push_back(*it);
		}
	}
	//OR
	if(type == 1)
	{
		set<Product*> set_prod;
		//iterate thru terms
		for(unsigned int i = 0;i<terms.size();i++)
		{
			//find each term in map of products
			if(map_prod.find(terms[i]) != map_prod.end())
			{
				//only call setIntersection if we have another set to compare to
				if(!set_prod.empty())
				{
					set_prod = setUnion(set_prod, map_prod.at(terms[i]));
				}
				//when grabbing the first set
				else
				{
					set_prod = map_prod.at(terms[i]);
				}
			}
		}
		set<Product*>::iterator it;
		for(it = set_prod.begin();it != set_prod.end(); ++it)
		{
			answers.push_back(*it);
		}
	}
	return answers;
}
void MyDataStore::dump(ostream& ofile)
{
	ofile << "<products>" << endl;
	set<Product*>::iterator it;
	for(it = products.begin(); it != products.end(); ++it)
	{
		(*it)->dump(ofile);
	}
	ofile << "</products>" << endl;
	ofile << "<users>" << endl;
	set<User*>::iterator it2;
	for(it2 = users.begin(); it2 != users.end(); ++it2)
	{
		(*it2)->dump(ofile);
	}
	ofile << "</users>" << endl;

	ofile << "<reviews>" << endl;
	set<Product*>::iterator it3;
	for(it3 = products.begin(); it3 != products.end(); ++it3)
	{
		vector<Review*> reviews_list = ((*it3)->getReviews());
		for(unsigned int i = 0; i<reviews_list.size(); i++)
		{
			ofile << (*it3)->getName() << endl;
			ofile << reviews_list[i]->rating << " ";
			ofile << reviews_list[i]->username << " ";
			ofile << reviews_list[i]->date << " ";
			ofile << reviews_list[i]->reviewText << endl;
		} 
	}
	ofile << "</reviews>" << endl;
}
void MyDataStore::buycart(string buy_username)
{
    map<string, vector<Product*>>::iterator it;
    for(it = users_to_cart.begin(); it != users_to_cart.end(); ++it)
    {
        //found user
        if(users_to_cart.find(buy_username) != users_to_cart.end())
        {
            User* myuser;
            set<User*>::iterator it2;
            for(it2 = users.begin(); it2 != users.end(); it2++)
            {
                if((*it2)->getName() == buy_username)
                {
                    myuser = (*it2);
                    break;
                }
            }
            vector<int> bought_items;
        	vector<Product*> print = users_to_cart.at(buy_username);
            for(unsigned int i = 0; i<print.size(); i++)
            {
                if((print[i])->getPrice() < myuser->getBalance() && (print[i])->getQty() > 0)
                {
                    (print[i])->subtractQty(1);
                    myuser->deductAmount( (print[i])->getPrice() );
                    bought_items.push_back(i);
                }
            }
            for(unsigned int j = 0; j<bought_items.size();j++)
            {
            	users_to_cart.at(myuser->getName()).erase((users_to_cart.at(myuser->getName())).begin() + bought_items[j]);
            }
        }
        else
        {
            cout << "Invalid username" << endl;
            return;
        }
    }
}
void MyDataStore::viewcart(string view_user)
{
	map<string, vector<Product*>>::iterator it;
	for(it = users_to_cart.begin(); it != users_to_cart.end(); ++it)
    {
        //user found
        if(users_to_cart.find(view_user) != users_to_cart.end())
        {
            vector<Product*> print = users_to_cart.at(view_user);
            for(unsigned int i = 0; i<print.size();i++)
            {
                cout << i + 1 << ": " << (print[i])->getName() << endl;
            }
            return;
        }
        //username not found
        else
        {
            cout << "Invalid username" << endl;
            return;
        }
    }
}
void MyDataStore::addcart(string username, int search_hit_number, vector<Product*> hits)
{
	map<string, vector<Product*>>::iterator it;
	for(it = users_to_cart.begin(); it != users_to_cart.end(); ++it)
	{
	    //user found
	    if(users_to_cart.find(username) != users_to_cart.end())
	    {
	        //check if search_hit_number is valid
	        int hit_num = 0;
	        bool hit_valid = false;
	        for(vector<Product*>::iterator it2 = hits.begin(); it2 != hits.end(); ++it2) 
	        {
	            hit_num++;
	            //if valid, put product of search_hit_number in cart
	            if(hit_num == search_hit_number)
	            {
	                (users_to_cart.at(username)).push_back(*it2);
	                hit_valid = true;
	                return;
	            }
	        }
	        //search_hit_number invalid
	        if(hit_valid == false)
	        {
	        	cout << "Invalid Request" << endl;
	        	break;
	    	}
	    }
	    //username not found
	    else
	    {
	        cout << "Invalid Request" << endl;
	        break;
	    }
	}
}
void MyDataStore::addReview(const string& prodName, int rating,
                          const string& username,
                          const string& date,
                          const string& review_text)
{
	set<Product*>::iterator it;
	for(it = products.begin();it != products.end(); ++it)
	{
		if((*it)->getName() == prodName) /////////////////will prodName be lowercase? possibly use search
		{
			Review* r = new Review(rating, username, date, review_text);
			(*it)->addRev(r);
		}
	}
}
set<User*> MyDataStore::getUsers()
{
	return users;
}