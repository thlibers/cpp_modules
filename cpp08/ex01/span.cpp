#include "span.hpp"
#include <algorithm>
#include <cstdlib>
#include <limits>

Span::Span(unsigned int n) : _N(n)
{
}

Span::~Span()
{
}

Span::Span(const Span &cpy) : _N(cpy._N), _storage(cpy._storage)
{
}

Span &Span::operator=(const Span &cpy)
{
	if (this != &cpy)
	{
		_N = cpy._N;
		_storage = cpy._storage;
	}
	return (*this);
}

//	Functions

void Span::addNumber(int value)
{
	if (_storage.size() >= _N)
		throw std::length_error("Span is full");
	_storage.push_back(value);
}

unsigned int Span::shortestSpan(void) const
{
	if (_storage.size() <= 1)
		throw std::length_error("Not enough numbers to find a span");
	std::vector<int> copy = _storage;
	std::sort(copy.begin(), copy.end());
	unsigned int minSpan = std::abs(copy[1] - copy[0]);
	for (std::vector<int>::size_type i = 1; i < copy.size(); i++)
	{
		unsigned int diff = static_cast<unsigned int>(std::abs(copy[i] - copy[i - 1]));
		if (diff < minSpan)
			minSpan = diff;
	}
	return (minSpan);
}

unsigned int Span::longestSpan(void) const
{
	if (_storage.size() <= 1)
		throw std::length_error("Not enough numbers to find a span");
	std::vector<int>::const_iterator minIt = std::min_element(_storage.begin(), _storage.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_storage.begin(), _storage.end());
	return (static_cast<unsigned int>(*maxIt - *minIt));
}
