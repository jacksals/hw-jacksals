#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <functional>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <unordered_map>
#include <utility>
template <
         typename T,
         typename TComparator = std::equal_to<T>,
         typename PComparator = std::less<double>,
         typename Hasher = std::hash<T> >
class Heap
{
public:
    /// Constructs an m-ary heap. M should be >= 2
    Heap(int m = 2,
         const PComparator& c = PComparator(),
         const Hasher& hash = Hasher(),
         const TComparator& tcomp = TComparator()  );

    /// Destructor as needed
    ~Heap();

    /// Adds an item with the provided priority
    void push(double pri, const T& item);

    /// returns the element at the top of the heap
    ///  max (if max-heap) or min (if min-heap)
    T const & top() const;

    /// Removes the top element
    void pop();

    /// returns true if the heap is empty
    bool empty() const;

    /// decreaseKey reduces the current priority of
    /// item to newpri, moving it up in the heap
    /// as appropriate.
    void decreaseKey(double newpri, const T& item);

private:
    /// Add whatever helper functions you need below
    void heapify(int idx);
    void heapup(int idx);



    // These should be all the data members you need.
    std::vector< std::pair<double, T> > store_;
    int m_;
    PComparator c_;
    std::unordered_map<T, size_t, Hasher, TComparator> keyToLocation_;

};

// Complete
template <typename T, typename TComparator, typename PComparator, typename Hasher >
Heap<T,TComparator,PComparator,Hasher>::Heap(
    int m,
    const PComparator& c,
    const Hasher& hash,
    const TComparator& tcomp ) :

    store_(),
    m_(m),
    c_(c),
    keyToLocation_(100, hash, tcomp)

{

}

// Complete
template <typename T, typename TComparator, typename PComparator, typename Hasher >
Heap<T,TComparator,PComparator,Hasher>::~Heap()
{

}

template <typename T, typename TComparator, typename PComparator, typename Hasher >
void Heap<T,TComparator,PComparator,Hasher>::push(double priority, const T& item)
{
    // You complete.
    store_.push_back({priority, item});
    keyToLocation_.insert({item, store_.size() -1});
    heapup(store_.size() - 1);
}

template <typename T, typename TComparator, typename PComparator, typename Hasher >
void Heap<T,TComparator,PComparator,Hasher>::decreaseKey(double priority, const T& item)
{
    // You complete
    // typename std::unordered_map<T, size_t, Hasher, TComparator>::iterator it = keyToLocation_.find(item);
    // int idx = it->second;
    if(keyToLocation_.find(item) == keyToLocation_.end())
    {
        return;
    }
    int idx = keyToLocation_[item];
    store_[idx].first = priority;
    heapup(idx);
}

template <typename T, typename TComparator, typename PComparator, typename Hasher >
T const & Heap<T,TComparator,PComparator,Hasher>::top() const
{
    // Here we use exceptions to handle the case of trying
    // to access the top element of an empty heap
    if(empty()) {
        throw std::logic_error("can't top an empty heap");
    }

    // You complete
    return (store_.front()).second;
}

/// Removes the top element
template <typename T, typename TComparator, typename PComparator, typename Hasher >
void Heap<T,TComparator,PComparator,Hasher>::pop()
{
    if(empty()) {
        throw std::logic_error("can't pop an empty heap");
    }
    // You complete
    keyToLocation_.erase(store_[0].second);
    store_[0] = store_[store_.size() - 1];
    store_.pop_back();
    heapify(0);

}

/// returns true if the heap is empty
template <typename T, typename TComparator, typename PComparator, typename Hasher >
bool Heap<T,TComparator,PComparator,Hasher>::empty() const
{
    return store_.empty();
}

template <typename T, typename TComparator, typename PComparator, typename Hasher >
void Heap<T,TComparator,PComparator,Hasher>::heapify(int idx)
{
  if((unsigned)idx > store_.size()/m_)
  {
    return;
  }
  int count = 1;
  bool swap = false;
  while(count <= m_)
  {
    if((unsigned) m_*idx + count < store_.size())
    {
      if(!c_(store_[idx].first, store_[(m_*idx) + count].first))
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
    std::pair<double, T> swap = store_[(m_*idx) + 1];
    int child = 2;
    int here = 1;
    while(child <= m_ && (unsigned)((m_*idx) + child) < store_.size())
    {
      if(!c_(swap.first, store_[(m_*idx) + child].first))
      {
        swap = store_[(m_*idx) + child];
        here = child;
      }
      child++;
    }
    keyToLocation_[store_[m_*idx + here].second] = idx;
    keyToLocation_[store_[idx].second] = (m_*idx)/m_;
    store_[(m_*idx) + here] = store_[idx];
    store_[idx] = swap;

    heapify((m_*idx) + here);
  }
}
template <typename T, typename TComparator, typename PComparator, typename Hasher >
void Heap<T,TComparator,PComparator,Hasher>::heapup(int idx)
{
  if((idx - 1)/m_ == idx)
  {
    return;
  }
  else
  {
    if(c_(store_[idx].first, store_[(idx - 1)/m_].first))
    {
      keyToLocation_[store_[idx].second] = (idx-1)/m_;
      keyToLocation_[store_[(idx-1)/m_].second] = idx;
      std::pair<double, T> temp = store_[idx];
      store_[idx] = store_[(idx - 1)/m_];
      store_[(idx - 1)/m_] = temp;

      heapup((idx - 1)/m_);
    }
  }
}


#endif

