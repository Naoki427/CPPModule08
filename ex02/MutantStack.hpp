#pragma once
#include <iostream>
#include <stack>
#include <deque>
#include <vector>

template <class T,typename Container = std::deque<T> >
class MutantStack :public std::stack<T,Container>
{
public:
	typedef typename Container::iterator iterator;
	MutantStack() {};
	~MutantStack(){};
	MutantStack(const MutantStack &origin){
		*this = origin;
	};
	MutantStack& operator = (const MutantStack &origin) {
		if (*this != origin)
			*this = origin;
		return (*this);
	};
	iterator begin(){
		return (this->c.begin());
	}; 
	iterator end() {
		return (this->c.end());
	}
};