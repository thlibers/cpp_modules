#ifndef FIXED_HPP
# define FIXED_HPP

#include <cstring>
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>

class Fixed
{
private:
	int _numValue;
	static const int _bitsValue = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &tocpy);
	Fixed &operator=(const Fixed &toass);
	int getRawBits(void) const;
	void setRawBits(int const raw);

	Fixed(const int value);
	Fixed(const float value);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream& os, const Fixed &value);

#endif