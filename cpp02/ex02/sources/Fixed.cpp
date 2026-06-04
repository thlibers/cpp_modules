#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->_numValue = 0;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
	this->_numValue = 0;
}

Fixed::Fixed(const Fixed &value)
{
	// std::cout << "Copy constructor called" << std::endl;
	if (this != &value)
	{
		*this = value;
	}
}

Fixed &Fixed::operator=(const Fixed &value)
{
	// std::cout << "Copy assignement operator called" << std::endl;
	this->_numValue = value.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	return(this->_numValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_numValue = raw;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_numValue = value << this->_bitsValue;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_numValue = static_cast<int>(roundf(value * (1 << this->_bitsValue)));
}

//	Conversion

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_numValue) / (1 << this->_bitsValue));
}

int Fixed::toInt(void) const
{
	return (this->_numValue >> this->_bitsValue);
}

//	ostream

std::ostream &operator<<(std::ostream& os, const Fixed &value)
{
	os << value.toFloat();
	return os;
}

//	Comparison operators

Fixed Fixed::operator>(const Fixed &value)
{
	if (this->toFloat() > value.toFloat())
	{
		return true;
	}
	return false;
}

Fixed Fixed::operator<(const Fixed &value)
{
	if (this->toFloat() < value.toFloat())
	{
		return true;
	}
	return false;
}

Fixed Fixed::operator>=(const Fixed &value)
{
	if (this->toFloat() >= value.toFloat())
	{
		return true;
	}
	return false;
}

Fixed Fixed::operator<=(const Fixed &value)
{
	if (this->toFloat() <= value.toFloat())
	{
		return true;
	}
	return false;
}

Fixed Fixed::operator==(const Fixed &value)
{
	if (this->toFloat() == value.toFloat())
	{
		return true;
	}
	return false;
}

Fixed Fixed::operator!=(const Fixed &value)
{
	if (this->toFloat() != value.toFloat())
	{
		return true;
	}
	return false;
}

//	Arithmetic operators

Fixed Fixed::operator+(const Fixed &value)
{
	return (this->toFloat() + value.toFloat());
}

Fixed Fixed::operator-(const Fixed &value)
{
	return (this->toFloat() - value.toFloat());
}

Fixed Fixed::operator*(const Fixed &value)
{
	return (this->toFloat() * value.toFloat());
}

Fixed Fixed::operator/(const Fixed &value)
{
	return (this->toFloat() / value.toFloat());
}

//	Increment/Decrement

Fixed Fixed::operator++(void)
{
	this->_numValue++;
	return *this;
}

Fixed Fixed::operator--(void)
{
	this->_numValue--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed postIncr = *this;
	this->_numValue++;
	return postIncr;
}

Fixed Fixed::operator--(int)
{
	Fixed postDecr = *this;
	this->_numValue--;
	return postDecr;
}

//	Functions

Fixed &Fixed::min(Fixed &value1, Fixed &value2)
{
	if (value1.toFloat() < value2.toFloat())
	{
		return value1;
	}
	return value2;
}

const Fixed &Fixed::min(const Fixed &value1, const Fixed &value2)
{
	if (value1.toFloat() < value2.toFloat())
	{
		return value1;
	}
	return value2;
}

Fixed &Fixed::max(Fixed &value1, Fixed &value2)
{
	if (value1.toFloat() < value2.toFloat())
	{
		return value2;
	}
	return value1;
}

const Fixed &Fixed::max(const Fixed &value1, const Fixed &value2)
{
	if (value1.toFloat() < value2.toFloat())
	{
		return value2;
	}
	return value1;
}
