#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "product.h"
#include "db_parser.h"
#include "product_parser.h"
#include "util.h"
#include "mydatastore.h"
#include <map>
#include <set>
#include <string>
#include "msort.h"

using namespace std;
struct vectorSorter {
    bool operator()(pair<string, double> p1, pair<string, double> p2) {
        if(p1.second == p2.second)
        {
            return (p1.first).size() < (p2.first).size();
        }
        return p1.second > p2.second;
    }
};
struct ProdNameSorter {
    bool operator()(Product* p1, Product* p2) {
        return (p1->getName() < p2->getName());
    }
};
struct RatingSorter {
    bool operator()(Product* p1, Product* p2) {
        return (p1->avgRating() > p2->avgRating());
    }
};
struct DateSorter {
    bool operator()(Review* p1, Review* p2) {
        return (p1->date > p2->date);
    }    
};
void displayProducts(vector<Product*>& hits);

int main(int argc, char* argv[])
{
    if(argc < 2) {
        cerr << "Please specify a database file" << endl;
        return 1;
    }

    /****************
     * Declare your derived DataStore object here replacing
     *  DataStore type to your derived type
     ****************/
    MyDataStore ds;



    // Instantiate the individual section and product parsers we want
    ProductSectionParser* productSectionParser = new ProductSectionParser;
    productSectionParser->addProductParser(new ProductBookParser);
    productSectionParser->addProductParser(new ProductClothingParser);
    productSectionParser->addProductParser(new ProductMovieParser);
    UserSectionParser* userSectionParser = new UserSectionParser;
    ReviewSectionParser* reviewSectionParser = new ReviewSectionParser;

    // Instantiate the parser
    DBParser parser;
    parser.addSectionParser("products", productSectionParser);
    parser.addSectionParser("users", userSectionParser);
    parser.addSectionParser("reviews", reviewSectionParser);

    // Now parse the database to populate the DataStore
    if( parser.parse(argv[1], ds) ) {
        cerr << "Error parsing!" << endl;
        return 1;
    }

    cout << "=====================================" << endl;
    cout << "Menu: " << endl;
    cout << "  LOGIN username password" << endl;
    cout << "  LOGOUT" << endl;
    cout << "  AND r/n term term ...                  " << endl;
    cout << "  OR r/n term term ...                   " << endl;
    cout << "  ADD search_hit_number     " << endl;
    cout << "  VIEWCART                 " << endl;
    cout << "  BUYCART                   " << endl;
    cout << "  ADDREV seach_hit_number rating date review_text" << endl;
    cout << "  VIEWREV search_hit_number" << endl;
    cout << "  REC" << endl;
    cout << "  QUIT new_db_filename               " << endl;
    cout << "====================================" << endl;

    vector<Product*> hits;
    bool done = false;
    string username;
    while(!done) {
        cout << "\nEnter command: " << endl;
        string line;
        getline(cin,line);
        stringstream ss(line);
        string cmd;
        if((ss >> cmd)) {
            if( cmd == "AND") {
                string term;
                vector<string> terms;
                ss >> term;
                bool term_r = false;
                bool term_n = false;
                if(term == "r")
                {
                    term_r = true;
                }
                else if(term == "n")
                {
                    term_n = true;
                }
                else 
                {
                    term = convToLower(term);
                    terms.push_back(term);
                }
                while(ss >> term) {
                    term = convToLower(term);
                    terms.push_back(term);
                }
                hits = ds.search(terms, 0);
                if(term_r == true && (hits.size() != 0))
                {
                    RatingSorter rate;
                    mergeSort(hits, rate);
                }
                if(term_n == true && (hits.size() != 0))
                {
                    ProdNameSorter namesort;
                    mergeSort(hits, namesort);
                }
                displayProducts(hits);
            }
            else if ( cmd == "OR" ) {
                string term;
                vector<string> terms;
                ss >> term;
                bool term_r = false;
                bool term_n = false;
                if(term == "r")
                {
                    term_r = true;
                }
                else if(term == "n")
                {
                    term_n = true;
                }
                else 
                {
                    term = convToLower(term);
                    terms.push_back(term);
                }
                while(ss >> term) {
                    term = convToLower(term);
                    terms.push_back(term);
                }
                hits = ds.search(terms, 1);
                if(term_r == true)
                {
                    RatingSorter rate;
                    mergeSort(hits, rate);
                }
                if(term_n == true)
                {
                    ProdNameSorter namesort;
                    mergeSort(hits, namesort);
                }
                displayProducts(hits);
            }
            else if ( cmd == "QUIT") {
                string filename;
                if(ss >> filename) {
                    ofstream ofile(filename.c_str());
                    ds.dump(ofile);
                    ofile.close();
                }
                done = true;
            }
	    /* Add support for other commands here */
            else if(cmd == "LOGIN") {
                ss >> username;
                string password;
                ss >> password;
                if(password == "")
                {
                    username = "";
                    continue;
                }
                unsigned long long hashed_password = ds.hasher(password);
                bool found_user = false;
                bool password_valid = false;
                set<User*> users = ds.getUsers();
                set<User*>::iterator it;
                for(it = users.begin(); it != users.end(); ++it)
                {
                    if((*it)->getName() == username)
                    {
                        found_user = true;
                        if((*it)->getPassword() == hashed_password)
                        {
                            password_valid = true;
                        }
                    }
                }
                if(found_user == false || password_valid == false)
                {
                    username = "";
                    cout << "Invalid login credentials" << endl;
                }
                else
                {
                    cout << "User logged in" << endl;
                }
            }
            else if(cmd == "LOGOUT") {
                username = "";
            }
            else if(cmd == "ADD") {
                if(username == "")
                {
                    cout << "No current user" << endl;
                    continue;
                }
                int search_hit_number;
                ss >> search_hit_number;
                ds.addcart(username, search_hit_number, hits);
            }
            else if (cmd == "VIEWCART") {
                if(username == "")
                {
                    cout << "No current user" << endl;
                }
                ds.viewcart(username);
            }
            else if (cmd == "BUYCART") {
                if(username == "")
                {
                    cout << "No current user" << endl;
                }
                ds.buycart(username);
            }
            else if(cmd == "ADDREV") {
                if(username == "")
                {
                    continue;
                }
                int search_hit_number;
                ss >> search_hit_number;
                if((unsigned)search_hit_number < 1 || 
                    (unsigned)search_hit_number > hits.size())
                {
                    cout << "Invalid search hit number" << endl;
                    continue;
                }
                int rating = 0;
                ss >> rating;
                if(rating < 1 || rating > 5)
                {
                    cout << "Invaild rating" << endl;
                    continue;
                }
                string date;
                ss >> date;
                for(unsigned int i = 0;i<10;i++) {
                    if(i ==  4|| i == 7)
                    {
                        continue;
                    }
                    if(date[i] > 57 || date[i] < 48)
                    {
                        cout << "Invalid date formatting" << endl;
                        continue;
                    }
                }
                if(date[4] != '-' || date[7] != '-')
                {
                    cout << "Invalid date formatting" << endl;
                    continue;
                }
                else
                {
                    if(date[5] == '1')
                    {
                        //ascii value for less than 0 or greater than 2
                        if(date[6] > 50 || date[6] < 48)
                        {
                            cout << "Invalid date formatting" << endl;
                            continue;
                        }
                    }
                    if(date[5] == '0')
                    {
                        if(date[6] == '0')
                        {
                            cout << "Invalid date" << endl;
                            continue;
                        }
                    }
                    stringstream ss1(date);
                    int year, month, day;
                    ss1 >> year; //takes in year the first time
                    ss1 >> month;
                    int last_day;
                    if(month % 2 == 0 && month != 2)
                    {
                        last_day = 31;
                    }
                    else if(month == 2)
                    {
                        last_day = 28;
                    }
                    else
                    {
                        last_day = 30;
                    }
                    ss1 >> day;
                    day *= -1; //stringstream reads "-" as negative sign
                    if(day > last_day || day < 1)
                    {
                        cout << "Invalid date" << endl;
                        continue;
                    }
                }
                string reviewtext;
                getline(ss, reviewtext);
                int start_text = 0;
                int end_text = 0;
                bool found_char = false;
                for(unsigned int z = 0; z<reviewtext.length(); z++)
                {
                    if(found_char == false && (islower(reviewtext[z]) || isupper(reviewtext[z])))
                    {
                        start_text = z;
                        found_char = true;
                    }
                    if(islower(reviewtext[z]) || isupper(reviewtext[z]))
                    {
                        end_text = z;
                    }
                }
                string reviewtrim = reviewtext.substr(start_text, end_text);
                string pname = hits[search_hit_number - 1]->getName();
                ds.addReview(pname, rating, username, date, reviewtrim);      
            } 
            else if(cmd == "VIEWREV")
            {
                int search_hit_number;
                ss >> search_hit_number;
                if((unsigned)search_hit_number < 1 || (unsigned)search_hit_number > hits.size())
                {
                    cout << "Invalid search hit number" << endl;
                    continue;
                }
                vector<Review*> reviews = (hits[search_hit_number - 1])->getReviews();
                DateSorter date_sort;
                mergeSort(reviews, date_sort);
                for(unsigned int i = 0; i<reviews.size(); i++)
                {
                    cout << reviews[i]->rating << " ";
                    cout << reviews[i]->username << " ";
                    cout << reviews[i]->date << " ";
                    cout << reviews[i]->reviewText << endl;
                } 
            }
            else if(cmd == "REC")
            {
                vector<pair<string, double> > testing = ds.makeSuggestion(username);
                vectorSorter sorter;
                stable_sort(testing.begin(), testing.end(), sorter);
                ofstream ofile;
                ofile.open("rec.txt");
                cout << username << endl;
                ofile << username << '\n';
                for(unsigned int i = 0; i<testing.size(); i++)
                {
                    cout << setprecision(2) << fixed << testing[i].second << " " << testing[i].first << endl;
                    ofile << setprecision(2) << fixed << testing[i].second << " " << testing[i].first << '\n';
                }
                ofile.close();
            }
            else {
                cout << "Unknown command" << endl;
            }
        }

    }
    return 0;
}

void displayProducts(vector<Product*>& hits)
{
    int resultNo = 1;
    //std::sort(hits.begin(), hits.end(), ProdNameSorter());
    for(vector<Product*>::iterator it = hits.begin(); it != hits.end(); ++it) {
        cout << "Hit " << setw(3) << resultNo << endl;
        cout << (*it)->displayString() << endl;
        cout << endl;
        resultNo++;
    }
}