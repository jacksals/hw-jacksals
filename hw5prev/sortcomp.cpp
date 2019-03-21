#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

//descending 
struct Comp2 {
  bool operator()(std::string a, std::string b)
  {
    // Complete the code
    ////////////////are size a/b same?
    for(unsigned int i = 0;i<a.size();i++)
    {
      if(a[i] < b[i])
      {
        return true;
      }
      if(a[i] > b[i])
      {
        return false;
      }
    }
    return false;
  }
};
//case-insensitive
struct Comp3 {
  bool operator()(std::string a, std::string b)
  {
    // Complete the code
    for(unsigned int i = 0;i<a.size();i++)
    {
      if(a[i] < 133 && a[i] > 100)
      {
        a[i] = a[i] + 42;
      }
      if(b[i] < 133 && b[i] > 100)
      {
        b[i] = b[i] + 42;
      }
      if(a[i] < b[i])
      {
        return false;
      }
      if(a[i] > b[i])
      {
        return true;
      }
    }
    return false;
  }
};
//whitespace
struct Comp4 {
  bool operator()(std::string a, std::string b)
  {
    // Complete the code
    unsigned int j = 0;
    unsigned int k = 0;
    while(a[j] == 32)
    {
      j++;
    }
    while(b[k] == 32)
    {
      k++;
    }
    for(unsigned int i = 0;i<a.size();i++)
    {
      if(a[i + j] < b[i + k])
      {
        return true;
      }
      if(a[i + j] > b[i + k])
      {
        return false;
      }
    }
    return false;
  }
};

void outputWords(std::ostream& ostr, const std::vector<std::string>& words)
{
  for(unsigned i = 0; i < words.size()-1; i++){
    ostr << words[i] << ":";
  }
  if(words.size() > 0){
    ostr << words.back();
  }
  ostr << endl;
}

int main(int argc, char* argv[])
{
  if(argc < 2){
    cout << "Provide an output file name." << endl;
    return 1;
  }
  ofstream ofile(argv[1]);
  if(ofile.fail()) {
    cout << "Cannot open file for writing." << endl;
    return 1;
  }
  vector<string> mywords =
    { "abc", "Acc", "aBc", "Zxy", "zyx", "  efg" };

  // Sort mywords in normal alphabetic/lexicographic string
  // comparison order.  Ascending from smallest to largest
  // (i.e. a to z).  This should still be case sensitive.
  vector<string> order1 = mywords;
  std::sort(order1.begin(), order1.end());
  outputWords(ofile, order1);

  // Sort mywords in normal alphabetic/lexicographic string
  // comparison order but descending from largest to smallest
  // (i.e. z to a).  This should still be case sensitive
  vector<string> order2 = mywords;
  Comp2 c2;
  std::sort(order2.begin(), order2.end(), c2);
  outputWords(ofile, order2);


  // Sort mywords in normal alphabetic/lexicographic string
  // comparison order.  Ascending from smallest to largest
  // (i.e. a to z) but case INSENSITIVE (i.e. abc < Abd)
  vector<string> order3 = mywords;
  Comp3 c3;
  std::sort(order3.begin(), order3.end(), c3);
  outputWords(ofile, order3);

  // Sort mywords in normal alphabetic/lexicographic string
  // comparison order.  Ascending from smallest to largest
  // (i.e. a to z), case sensitive and ignoring
  // spaces (only ' ') before the word.
  vector<string> order4 = mywords;
  Comp4 c4;
  std::sort(order4.begin(), order4.end(), c4);
  outputWords(ofile, order4);

  ofile.close();
  return 0;
}

