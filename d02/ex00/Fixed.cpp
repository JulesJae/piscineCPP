#include "Fixed.hpp"
#include <iostream>

const int	Fixed::bytes = 8;

Fixed::Fixed(): _rawBits(0) 
{
	std::cout << "Default constructor for Fixed has been called\n";
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor for Fixed has been called\n";
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor for Fixed has been called\n";
}

Fixed		&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Assignment operator called\n";
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	return *this;
}

int 		Fixed::getRawBits() const 
{
	std::cout << "getRawBits member function called\n";
	return this->_rawBits; 
}

void 		Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->_rawBits = raw;
}

