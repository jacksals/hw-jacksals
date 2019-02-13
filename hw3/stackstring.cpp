#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "stackstring.h"

using namespace std;
StackString::StackString()
{

}
StackString::~StackString()
{
	
}
bool StackString::empty() const
{
	return list_.size() == 0;
}
size_t StackString::size() const
{
	return (size_t)list_.size();
}
void StackString::push(const std::string& val)
{
	list_.push_back(val);
}
const std::string& StackString::top() const
{
	if(empty()) 
	{
		throw "Stack is empty";
	}
	else
	{
		return list_.back();
	}
}
void StackString::pop()
{
	if(!empty()) {
		list_.pop_back();
	}
}