#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main(void)
{
	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(4);
	numbers.push_back(7);
	numbers.push_back(9);

	std::cout << *easyfind(numbers, 7) << std::endl;
	try
	{
		easyfind(numbers, 42);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::list<int> values;
	values.push_back(10);
	values.push_back(20);
	values.push_back(30);

	std::cout << *easyfind(values, 20) << std::endl;
	return (0);
}
