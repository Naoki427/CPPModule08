#pragma once
#include <iostream>
#include <algorithm>

class NotFindInteger : public std::exception
{
	public:
		char const * what() const throw() 
		{
			return "The integer was not found in the container.";
		}
};

template <typename T>
typename T::iterator easyfind(T& container,int n) {
	typename T::iterator it = std::find(container.begin(),container.end(),n);
	if(it == container.end()) {
		throw NotFindInteger();
	} 
	return it;
}