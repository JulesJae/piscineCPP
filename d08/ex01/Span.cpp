#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <exception>
#include <limits>

Span::Span() 
{
}

Span::Span(unsigned int n): _maxSize(n), _vIdx(0), _sorted(false)
{
	this->_v.reserve(n);
	std::cout << "span constructed, vector size: " << this->_v.size() << ", size = " << this->_maxSize << "\n";
}

Span::Span(Span const &obj)
{
	*this = obj;
}

Span::~Span()
{

}

void			Span::addNumber(int i)
{
	if (this->_vIdx == this->_maxSize)
		throw std::exception();
	this->_v.push_back(i);
	this->_vIdx++;
	this->_sorted = false;
}

void			Span::printSortedArray()
{
	if (!this->_sorted)
	{
		sort(this->_v.begin(), this->_v.end());
		this->_sorted = true;
	}
	for (unsigned int i = 0; i < this->_vIdx; i++)
		std::cout << "[" << i <<"] => " << this->_v[i] << " | ";
	std::cout << "\n";
}

unsigned int	Span::shortestSpan()
{
	long						difference(__LONG_LONG_MAX__);

	if (this->_vIdx == 0 || this->_vIdx == 1)
		throw std::exception();
	if (!this->_sorted)
	{
		sort(this->_v.begin(), this->_v.end());
		this->_sorted = true;
	}
	for (unsigned int i = 0; i < this->_vIdx - 1; i++)
		if (this->_v[i + 1] - this->_v[i] < difference)
			difference = this->_v[i + 1] - this->_v[i];
	return difference;
}

unsigned int	Span::longestSpan()
{
	if (this->_vIdx == 0 || this->_vIdx == 1)
		throw std::exception();
	if (!this->_sorted)
	{
		sort(this->_v.begin(), this->_v.end());
		this->_sorted = true;
	}
	return this->_v[this->_vIdx - 1] - this->_v[0];
}

Span			&Span::operator=(Span const &rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}
