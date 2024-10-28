#include "Fixed.hpp"

using namespace std;

Fixed::Fixed() : value(0) 
{
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(Fixed const &src) 
{
	cout << "Copy constructor called" << endl;
	*this = src;
}

Fixed::~Fixed() 
{
	cout << "Destructor called" << endl;
}

Fixed&	Fixed::operator=(Fixed const &rSym) 
{
	cout << "Copy assignement operator called" << endl;
	this->value = rSym.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const 
{
	cout << "getRawBits member function called" << endl;
	return this->value;
}

void	Fixed::setRawBits(int const raw) 
{
	this->value = raw;
}