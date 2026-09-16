#include "span.hpp"
#include <iostream>
#include <vector>

int main(void)
{
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span big(10000);
	std::vector<int> values;
	for (int i = 0; i < 10000; ++i)
		values.push_back(i);
	big.addNumbers(values.begin(), values.end());
	std::cout << big.shortestSpan() << std::endl;
	try
	{
		Span tooSmall(1);
		tooSmall.addNumber(5);
		tooSmall.addNumber(7);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
