#include "../include/Complex.hpp"
#include "../include/utils.hpp"
#include <iostream>
#include <sstream>

computorv2::Complex::Complex(void)
{
	this->clear();
}

computorv2::Complex::~Complex(void)
{
	this->clear();
}

computorv2::Complex::Complex(const computorv2::Complex& other)
{
	*this = other;
}

computorv2::Complex& computorv2::Complex::operator=(const computorv2::Complex& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_real = other._real;
		this->_imag = other._imag;
	}
	return (*this);
}

computorv2::Complex::Complex(double real, double image)
{
	this->clear();
	this->setReal(real);
	this->setImage(image);
}

std::string computorv2::Complex::getName(void) const
{
	return (this->_name);
}

double computorv2::Complex::getReal(void)  const
{
	return (this->_real);
}

double computorv2::Complex::getImage(void) const
{
	return (this->_imag);
}


void computorv2::Complex::setName(std::string name) 
{
	this->_name = name;
}

void computorv2::Complex::setReal(double real) 
{
	this->_real = real;
}

void computorv2::Complex::setImage(double imag)
{
	this->_imag = imag;
}


std::string computorv2::Complex::toString(void) const
{
	std::stringstream ss("");
	const double r = this->_real;
	const double m = this->_imag;
	if (!ISNULL(r) || ISNULL(m))
	{
		ss << r;
	}
	if (!ISNULL(m))
    {
        if (!ISNULL(r))
        {
            ss << " ";
        }
        if (!ISNULL(r) && (m > 0))
        {
            ss << "+";
        }
        if (m < 0)
        {
            ss << "-";
        }
        if (!ISNULL(r))
        {
            ss << " ";
        }
        const double aimg = ABS(m);
        if (!ISNULL(aimg - 1))
        {
            ss << aimg;
        }
        ss << this->_name;
    }
	return (ss.str());
}

void computorv2::Complex::clear(void)
{
	this->_name = "i";
	this->_real = 0.0;
	this->_imag = 0.0;
}

computorv2::Object* computorv2::Complex::copy(void) const
{
	return ( new computorv2::Complex(*this) );
}

bool computorv2::Complex::isnull(void) const
{
	return (ISNULL(this->getReal()) && ISNULL(this->getImage()));
}

computorv2::Complex operator+(const computorv2::Complex& left, const computorv2::Complex& right)
{
	computorv2::Complex res;
	res.setReal(left.getReal()   + right.getReal());
	res.setImage(left.getImage() + right.getImage());
	return (res);
}

computorv2::Complex operator-(const computorv2::Complex& left, const computorv2::Complex& right)
{
	computorv2::Complex res;
	res.setReal(left.getReal()   - right.getReal());
	res.setImage(left.getImage() - right.getImage());
	return (res);
}

computorv2::Complex operator-(const computorv2::Complex& left)
{
	return (computorv2::Complex(0.0, 0.0) - left);
}

computorv2::Complex operator*(const computorv2::Complex& left, const computorv2::Complex& right)
{
	const double lr = left.getReal();
	const double lm = left.getImage();
	const double rr = right.getReal();
	const double rm = right.getImage();
	return (
		computorv2::Complex(
			(lr * rr) - (lm * rm),
			(lr * rm) + (lm * rr)
		)
	);
}

computorv2::Complex operator*(const computorv2::Complex& left, double right)
{
	return (left * computorv2::Complex(right, 0.0));
}

computorv2::Complex operator*(double left, const computorv2::Complex& right)
{
	return (right * left);
}

computorv2::Complex operator/(const computorv2::Complex& left, const computorv2::Complex& right)
{
    if (right.isnull())
    {
        throw std::logic_error("Division By Zero!");
    }
    const double lr = left.getReal();
    const double lm = left.getImage();
    const double rr = right.getReal();
    const double rm = right.getImage();
    const double q = (rr * rr + rm * rm);
    return (
        computorv2::Complex(
            (lr * rr + lm * rm) / q,
            (lm * rr - lr * rm) / q
        )
    );
}

computorv2::Complex operator/(const computorv2::Complex& left, double right)
{
	return (left / computorv2::Complex(right, 0.0));
}

computorv2::Complex operator/(double left, const computorv2::Complex& right)
{
	return (computorv2::Complex(left, 0.0) / right);
}

bool operator==(const computorv2::Complex& left, const computorv2::Complex& right)
{
	if (ISNULL(left.getReal() - right.getReal()))
	{
		if (ISNULL(left.getImage() - right.getImage()))
		{
			return (true);
		}
	}
	return (false);
}
