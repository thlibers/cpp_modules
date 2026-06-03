#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_numValue = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	this->_numValue = 0;
}

Fixed::Fixed(const Fixed &tocpy)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &tocpy)
	{
		*this = tocpy;
	}
}

Fixed &Fixed::operator=(const Fixed &toass)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->_numValue = toass.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return(this->_numValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_numValue = raw;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_numValue = value << this->_bitsValue;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_numValue = static_cast<int>(roundf(value * (1 << this->_bitsValue)));	// 'roundf' arrondi au superieur
}
float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_numValue) / (1 << this->_bitsValue));
}

int Fixed::toInt(void) const
{
	return (this->_numValue >> this->_bitsValue);
}

std::ostream &operator<<(std::ostream& os, const Fixed &value)
{
	os << value.toFloat();
	return os;
}