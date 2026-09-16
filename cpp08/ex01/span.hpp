#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <iterator>

class Span
{
private:
	unsigned int _N;
	std::vector<int> _storage;

public:
	Span(unsigned int n);
	~Span();
	Span(const Span &cpy);
	Span &operator=(const Span &cpy);
	void addNumber(int value);
	template <typename InputIterator>
	void addNumbers(InputIterator begin, InputIterator end)
	{
		while (begin != end)
		{
			addNumber(*begin);
			++begin;
		}
	}
	unsigned int shortestSpan(void) const;
	unsigned int longestSpan(void) const;
};

#endif
