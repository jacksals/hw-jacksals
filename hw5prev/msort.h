template <class T, class Comparator>
  void mergeSort (vector<T>& myArray, Comparator comp);


template<class T, class Comparator>
  void mergeSort(vector<T>& myArray, Comparator comp)
  {
    comp(myArray, 0, myArray.size());
    //something?
  }

  struct msorting {
    void operator()(const vector<int>& arr, int start, int end) const {
      if(start >= end)
      {
        return;
      }
      int mid = (start+end)/2;
      mergeSort(arr, 0, mid);
      mergeSort(arr, mid, end);
    }

  };