#include "Span.hpp"

Span::Span(unsigned int n) : _size(n){}

Span::Span(const Span &origin) {
	*this = origin;
}

Span::~Span() {}

Span& Span::operator= (const Span &origin){
	if(this == &origin)
		return *this;
	_size = origin.getSize();
	_vector = origin.getVector();
	return *this;
}

unsigned int Span::getSize() const {
	return _size;
}

std::vector<int> Span::getVector() const {
	return _vector;
}

void Span::addNumber(int n) {
	if(_size == _vector.size())
		throw Span::CannotAddException();
	_vector.push_back(n);
}

void Span::addNumbers(std::vector<int>::iterator bigin,std::vector<int>::iterator end) {
	if (_vector.size() + std::distance(bigin, end) > _size)
		throw CannotAddException();
	_vector.insert(_vector.end(),bigin,end);
}

int Span::shortestSpan() {
	if(_vector.size() < 2)
		throw Span::NotEnoughValuesException();
	int span = INT_MAX;
	std::sort(_vector.begin(),_vector.end());
	for (std::vector<int>::iterator it = _vector.begin(); (it + 1) != _vector.end(); ++it) {
		if(*(it + 1) - *it < span)
			span = *(it + 1) - *it;
	}
	return span;
}

int Span::longestSpan() {
	if(_vector.size() < 2)
		throw Span::NotEnoughValuesException();
	std::sort(_vector.begin(),_vector.end());
	std::vector<int>::iterator max = _vector.end() - 1;
	std::vector<int>::iterator min = _vector.begin();
	return *max - *min;
}

