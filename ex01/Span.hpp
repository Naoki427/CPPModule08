#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime> 
class Span
{
private:
	unsigned int _size;
	std::vector<int> _vector;
	Span( void );
public:
	Span(unsigned int n);
	Span(const Span &origin);
	virtual ~Span();
	Span& operator = (const Span &origin);
	unsigned int getSize() const;
	std::vector<int> getVector() const;
	void addNumber(int n);
	void addNumbers(std::vector<int>::iterator bigin,std::vector<int>::iterator end);
	int shortestSpan();
	int longestSpan();
	class CannotAddException : public std::exception
	{
		public:
			char const * what() const throw()
			{
				return "Cannot add more elements: maximum capacity reached.";
			} 
	};
	class NotEnoughValuesException : public std::exception
	{
		public:
			char const * what() const throw()
			{
				return "Not enough values to calculate interval: at least two values are needed.";
			} 
	};
	
};