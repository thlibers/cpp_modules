#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <cstring>
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

class ScalarConverter
{
public:
	static void convert(std::string String);

private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &Cpy);
	ScalarConverter &operator=(const ScalarConverter &Cpy);
};

#endif