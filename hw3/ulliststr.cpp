#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "ulliststr.h"

using namespace std;
ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(NULL == ptr){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(NULL == ptr){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(NULL == ptr){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

void ULListStr::push_back(const std::string& value)
{
  //if there are no Items in the list
  if(empty())
  {
    //allocate first Item
    head_ = new Item;
    
    //put the value at the back of the array
    head_->first = 0;
    (head_->val[head_->first]) = value;
    head_->last = head_->first + 1;
    head_->prev = NULL;
    //Item is head and tail because it is the only one
    tail_ = head_;
  }
  else
  {
    //If no space in back
    if(tail_->last > (ARRSIZE - 1))
    {
      Item *new_tail = new Item;
      tail_->next = new_tail;
      new_tail->prev = tail_;
      new_tail->next = NULL;
      tail_ = new_tail;
      tail_->first = 0;
      tail_->last = 1;
      (tail_->val[(tail_->last) - 1]) = value;
    }
    else
    {
      //Nominal add case
      (tail_->val[(tail_->last)]) = value;
      tail_->last += 1;
    }
  }
  size_++;
}

void ULListStr::push_front(const std::string& value)
{
  if(empty())
  {
    head_ = new Item;
    head_->first = ARRSIZE - 1; 
    head_->last = (head_->first) + 1;
    //add value to back of head array
    (head_->val[head_->first]) = value;
    tail_ = head_;
  }
  else
  {
    //if no space in front
    if(head_->first == 0)
    {
      Item *old_head = head_;
      head_ = new Item;
      head_->next = old_head;
      head_->prev = NULL;
      old_head->prev = head_;
      head_->first = ARRSIZE - 1;
      head_->last = ARRSIZE;
      (head_->val[head_->first]) = value;
    }
    else
    {
      //Nominal add case
      head_->first -= 1;
      (head_->val[head_->first]) = value;
    }
  }
  size_++;
}

void ULListStr::pop_front()
{
  //check if there even is a value to pop
  size_--;
  if(size_ == 0)
  {
    delete head_;
    head_=NULL;
    tail_=NULL;
    return;
  }
  //if front value is in its own item
  else if(head_->first == ARRSIZE - 1)
  {
    //if head is the only Item in the list
    if(head_->next == NULL)   
    {
      delete head_;          
      head_=NULL;
      tail_=NULL;
    }
    else 
    {
      Item* temp = head_->next;
      delete head_; 
      head_ = temp;             
      head_->prev = NULL;
      head_->first = 0;
    }
  }
  else
  {
    (head_->first) += 1;
  }
  
}

void ULListStr::pop_back()
{
  //check if there even is a value to pop
  size_--;
  if(size_ == 0)
  {
    delete head_;
    head_=NULL;
    tail_=NULL;
    return;
  }
  else if(tail_->last == 1)
  {
    if(tail_->prev == NULL)
    {
      delete tail_;
      tail_=NULL;
    }
    else
    {
      Item* temp = tail_->prev;
      delete tail_;
      tail_ = temp;
      tail_->next = NULL;
      tail_->last = ARRSIZE;
    }
  }
  else
  {
    (tail_->last) -=1;
  }
  
}
std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(loc <= size_ && loc >= 0) {
    size_t start = head_->first;
    size_t loc_in_arr = (loc+start)%ARRSIZE;
    size_t num_items = ((loc+start)/ARRSIZE);

    Item* curr;
    curr = head_;
    for(size_t i = 0; i<num_items;i++) {
      if(curr->next == NULL)
      {
        return NULL;
      }
      else
      {
        curr = curr->next;
      }
    }
    return &(curr->val[loc_in_arr]);
  }
  else {
    return NULL;
  }


}
std::string const & ULListStr::front() const
{

  return head_->val[head_->first];
}
std::string const & ULListStr::back() const
{
  return tail_->val[(tail_->last) - 1];
}


ULListStr::ULListStr (const ULListStr& other)
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
  appendContents(other);
}
ULListStr& ULListStr::operator= (const ULListStr& other)
{
  //self check
  if(this == &other)
  {
    return *this;
  }
  clear();
  appendContents(other);
  return *this;
}
ULListStr ULListStr::operator+ (const ULListStr& other) const
{
  //save original list
  ULListStr new_list = *this;
  new_list.appendContents(other);
  //return updated list
  return new_list;
}
ULListStr& ULListStr::operator-= (size_t num)
{
  while(num > 0)
  {
    pop_back();
    num--;
  }
  //return reference to list
  return *this;
}
string const & ULListStr::operator[] (size_t loc) const
{
  return get(loc);
}
string & ULListStr::operator[] (size_t loc)
{
  return *getValAtLoc(loc);
}
void ULListStr::appendContents(const ULListStr& other)
{
  
  Item* curr = other.head_;
  if(curr == NULL) 
  {
    return;
  }
  int idx = other.head_->first;
  while(curr != NULL)
  {
    //if we reach the end of the item
    if(curr->next != NULL && (unsigned int)idx == curr->last)
    {
      //update Item and index
      curr = curr->next;
      idx = curr->first;
    }
    //if at tail can't iterate through the end b/c Item may
    //not be full
    if(curr->next == NULL)
    {        
      for(unsigned int i = curr->first;i<curr->last;i++)
      {
        push_back(curr->val[i]);
      }
      break;
    }
    else
    {
      push_back(curr->val[idx]);
      idx++;
    }
  }
}