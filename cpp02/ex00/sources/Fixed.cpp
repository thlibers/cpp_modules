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
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_numValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_numValue = raw;
}
