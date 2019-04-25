#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct test {
  bool operator()(T& a, T& b)
  {
    return a < b;
  }
};


template<class T, class Comparator>
  void mergeSort(vector<T>& myArray, Comparator comp)
  {
    if(myArray.size() == 0)
    {
      return;
    }
      mergeHelper(myArray, 0, myArray.size() - 1, comp);
  }

template<class T, class Comparator>
  void mergeHelper(vector<T>& myArray, int s, int e, Comparator comp)
  {
    if(s == e)
    {
      return;
    }
    else 
    {
      int m = (s + e)/2;
      int ind_s = s;
      int ind_e = m + 1;
      mergeHelper(myArray, s, m, comp);
      mergeHelper(myArray, m + 1, e, comp);
      vector<T> other;
      while(ind_s <= m && ind_e <= e)
      {
        if(comp(myArray[ind_s], myArray[ind_e]))
        {
          other.push_back(myArray[ind_s]);
          ind_s++;
        }
        else
        {
          other.push_back(myArray[ind_e]);
          ind_e++;
        }
      }

      if(ind_s <= m)
      {
        for(int j = ind_s; j<=m;j++)
        {
          other.push_back(myArray[j]);
        }
      }
      else
      {
        for(int k = ind_e;k<=e; k++)
        {
          other.push_back(myArray[k]);
        }
      }

      for(unsigned int i = 0;i<other.size();i++)
      {
        myArray[s+ i] = other[i];
      }
    }
  }