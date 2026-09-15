#include "array.hpp"
#include <iostream>
#include <string>

int main(void)
{
	Array<int> ints(3);
	ints[0] = 10;
	ints[1] = 20;
	ints[2] = 30;
	Array<int> copyInts(ints);
	copyInts[1] = 99;
	std::cout << "ints[1] = " << ints[1] << std::endl;
	std::cout << "copyInts[1] = " << copyInts[1] << std::endl;
	Array<std::string> strings(2);
	strings[0] = "salut";
	strings[1] = "bonjour";
	std::cout << strings[0] << " " << strings[1] << std::endl;
	Array<int> empty;
	std::cout << "empty size = " << empty.size() << std::endl;
	try
	{
		std::cout << ints[5] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}
	return (0);
}