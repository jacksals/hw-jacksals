#include <iostream>
#include <vector>
#include "msort.h"

using namespace std;

int main() {
  vector<int> mynums = { 4, 3, 5, 1, 2, 6};
  test<int> t;
  for(int i = 0;i<mynums.size();i++)
  {
    cout << mynums[i] << endl;
  }
  cout << endl;
  mergeSort(mynums, t);
  for(int i = 0;i<mynums.size();i++)
  {
    cout << mynums[i] << endl;
  }
  // vector<int> mywords = { "zebraherds", "jack" };
  // for(int i = 0;i<mywords.size();i++)
  // {
  //   cout << mywords[i] << endl;
  // }
  // cout << endl;
  // mergeSort(mywords, w);
  // for(int i = 0;i<mywords.size();i++)
  // {
  //   cout << mywords[i] << endl;
  // }
    return 0;
  
}