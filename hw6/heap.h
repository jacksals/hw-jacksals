#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
 public:
  /// Constructs an m-ary heap for any m >= 2
  Heap(int m, PComparator c = PComparator())
  {
    m_ = m;
    comp = c;
  }

  /// Destructor as needed
  ~Heap()
  {
  };

  /// Adds an item
  void push(const T& item);

  /// returns the element at the top of the heap 
  ///  max (if max-heap) or min (if min-heap)
  T const & top() const;

  /// Removes the top element
  void pop();

  /// returns true if the heap is empty
  bool empty() const;

 private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> myarray;
  void heapify(int idx);
  int m_;
  PComparator comp;

};
// Add implementation of member functions here
template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int idx)
{
  if((unsigned)idx > myarray.size()/m_)
  {
    return;
  }
  int count = 1;
  bool swap = false;
  while(count < m_)
  {
    if((unsigned) m_*idx + count < myarray.size())
    {
      if(!comp(myarray[idx], myarray[(m_*idx) + count]))
      {
        //at least one child is valid for swapping
        swap = true;
        break;
      }
      count++;
    }
    else
    {
      //root doesn't have complete set of children
      break;
    }
  }
  if(swap == true)
  {
    T swap = myarray[(m_*idx) + 1];
    int child = 2;
    int here = 1;
    while(child < m_)
    {
      if(!comp(swap, myarray[(m_*idx) + child]))
      {
        swap = myarray[(m_*idx) + child];
        here = child;
      }
      child++;
    }
    myarray[(m_*idx) + here] = myarray[idx];
    myarray[idx] = swap;
    heapify((m_*idx) + here);
  }
  // if(!PComparator(myarray[idx], myarray[(2*idx) + 1]) || 
  //   !PComparator(myarray[idx], myarray[(2*idx) + 2]))
  // {
  //   if(!PComparator(myarray[(2*idx) + 2], myarray[(2*idx) + 1]))
  //   {
  //     //swap right child and root
  //     T temp = myarray[idx];
  //     myarray[idx] = myarray[(2*idx) + 2];
  //     myarray[(2*idx) + 2] = temp;
  //     //call heapify on right child
  //     heapify((2*idx) + 2);
  //   }
  //   else
  //   {
  //     //swap left child and root
  //     T temp = myarray[idx];
  //     myarray[idx] = myarray[(2*idx) + 1];
  //     myarray[(2*idx) + 1] = temp;
  //     //call heapify on left child
  //     heapify((2*idx) + 1);
  //   }
  // }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::logic_error("can't top an empty heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return myarray.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::logic_error("can't pop an empty heap");
  }
  myarray[0] = myarray[myarray.size() - 1];
  myarray.pop_back();
  heapify(0);
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return myarray.empty();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  myarray.push_back(item);
  int element = myarray.size() - 1;
  if(element % m_ == 0)
  {
    element = (element/m_) - 1;
  }
  else
  {
    element = (element/m_);
  }
  heapify(element);
}


#endif

