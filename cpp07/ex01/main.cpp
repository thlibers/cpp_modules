#include "iter.hpp"

void printMultNum(int &value)
{
	std::cout << value << " ";
	value *= 2;
}

void printInt(const int &value)
{
	std::cout << value << " ";
}

void printString(const std::string &value)
{
	std::cout << value << " ";
}

int main(void)
{
	int numbers[] = {1, 2, 3, 4, 5};
	std::string words[] = {"aaa", "bbb", "cccc"};

	::iter(numbers, 5, printMultNum);
	std::cout << std::endl;
	::iter(numbers, 5, printInt);
	std::cout << std::endl;
	::iter(words, 3, printString);
	std::cout << std::endl;

	return (0);
}
