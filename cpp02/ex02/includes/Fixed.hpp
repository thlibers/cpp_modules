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
	Fixed(const Fixed &value);
	Fixed &operator=(const Fixed &value);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	Fixed(const int value);
	Fixed(const float value);
	float	toFloat(void) const;
	int		toInt(void) const;

	Fixed operator>(const Fixed &value);
	Fixed operator<(const Fixed &value);
	Fixed operator>=(const Fixed &value);
	Fixed operator<=(const Fixed &value);
	Fixed operator==(const Fixed &value);
	Fixed operator!=(const Fixed &value);

	Fixed operator+(const Fixed &value);
	Fixed operator-(const Fixed &value);
	Fixed operator*(const Fixed &value);
	Fixed operator/(const Fixed &value);

	Fixed operator++(void);
	Fixed operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

	static			Fixed &min(Fixed &value1, Fixed &value2);
	static const	Fixed &min(const Fixed &value1, const Fixed &value2);
	static			Fixed &max(Fixed &value1, Fixed &value2);
	static const	Fixed &max(const Fixed &value1, const Fixed &value2);
};

std::ostream &operator<<(std::ostream& os, const Fixed &value);

#endif