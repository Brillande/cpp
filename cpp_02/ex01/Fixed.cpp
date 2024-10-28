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

Fixed::Fixed(const int n) 
{
	cout << "Int constructor called" << endl;
	this->value = n << bits;
}

Fixed::Fixed(const float f) : value(f) 
{
	cout << "Float constructor called" << endl;
	this->value = roundf(f * (1 << bits));
}

Fixed::~Fixed() 
{
	cout << "Destructor called" << endl;
}

Fixed&	Fixed::operator=(Fixed const &rSym) 
{
	cout << "Copy assignement operator called" << endl;
	if (this != &rSym)
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

float	Fixed::toFloat() const 
{
	return (float)this->value / (float)(1 << bits);
}

int		Fixed::toInt() const 
{
	return this->value >> bits;
}

ostream&	operator<<(ostream& o, Fixed const &rSym) 
{
	o << rSym.toFloat();
	return o;
}