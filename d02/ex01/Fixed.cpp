#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_bits = 8;

Fixed::Fixed(): _rawBits(0) 
{
	std::cout << "Default constructor for Fixed has been called\n";
}

Fixed::Fixed(int const value)
{
	this->_rawBits = value << Fixed::_bits;
}

Fixed::Fixed(float const value)
{
	this->_rawBits = (int)roundf(value * (1 << Fixed::_bits));
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

bool		Fixed::operator==(Fixed const &rhs)  const
{
	std::cout << "Equality operator called\n";
	return this->_rawBits == rhs.getRawBits();
}

bool		Fixed::operator!=(Fixed const &rhs)  const
{
	std::cout << "Unequality operator called\n";
	return this->_rawBits != rhs.getRawBits();
}

bool		Fixed::operator<=(Fixed const &rhs)  const
{
	std::cout << "Less than or equal operator called\n";
	return this->_rawBits <= rhs.getRawBits();
}

bool		Fixed::operator>=(Fixed const &rhs) const
{
	std::cout << "Greater or equal operator called\n";
	return this->_rawBits >= rhs.getRawBits();
}

bool		Fixed::operator>(Fixed const &rhs) const
{
	std::cout << "Greater operator called\n";
	return this->_rawBits > rhs.getRawBits();
}

bool		Fixed::operator<(Fixed const &rhs) const
{
	std::cout << "Lower operator called\n";
	return this->_rawBits < rhs.getRawBits();
}

Fixed		Fixed::operator+(Fixed const &rhs)
{
	std::cout << "Addition operator called\n";
	return Fixed(this->_rawBits + rhs.getRawBits());
}

Fixed		Fixed::operator-(Fixed const &rhs)
{
	std::cout << "Soustraction operator called\n";
	return Fixed(this->_rawBits - rhs.getRawBits());
}

Fixed		Fixed::operator*(Fixed const &rhs)
{
	Fixed	ret;

	std::cout << "Multiplication operator called\n";
	ret.setRawBits((this->_rawBits * rhs.getRawBits()) >> Fixed::_bits);
	return ret;
}

Fixed		Fixed::operator/(Fixed const &rhs)
{
	Fixed	ret;

	std::cout << "Division operator called\n";
	ret.setRawBits((this->_rawBits << Fixed::_bits) / rhs.getRawBits());
	return ret;
}

Fixed		&Fixed::operator++()
{
	this->_rawBits++;
	return *this;
}

Fixed		Fixed::operator++(int)
{
	Fixed	ret(*this);

	this->_rawBits++;
	return ret;
}

Fixed		&Fixed::operator--()
{
	this->_rawBits--;
	return *this;
}

Fixed		Fixed::operator--(int)
{
	Fixed	ret(*this);

	this->_rawBits--;
	return ret;
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

int			Fixed::toInt() const
{
	return this->_rawBits >> Fixed::_bits;
}

float		Fixed::toFloat() const
{
	return ((float)this->_rawBits / (float)(1 << Fixed::_bits));
}

Fixed 		&Fixed::min(Fixed &u, Fixed &v) 
{ 
	return (u < v ? u : v); 
}

const Fixed &Fixed::min(const Fixed &u, const Fixed &v) 
{ 
	return (u < v ? u : v); 
}

Fixed 		&Fixed::max(Fixed &u, Fixed &v) 
{ 
	return (u > v ? u : v); 
}

const Fixed &Fixed::max(const Fixed &u, const Fixed &v) 
{ 
	return (u > v ? u : v); 
}



std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}
