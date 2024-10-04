#include "../include/computorv2.hpp"
#include "../include/Object.hpp"
#include "../include/Rational.hpp"
#include "../include/Polynomial.hpp"
#include "../include/utils.hpp"
#include <sstream>
#include <unistd.h>

/* Rational (add) */
computorv2::Rational computorv2::add(const computorv2::Rational& left, const computorv2::Rational& right)
{
	computorv2::Rational res;
	res.setValue(left.getValue() + right.getValue());
	return (res);
}

/* Complex (add) */
computorv2::Complex computorv2::add(const computorv2::Complex& left, const computorv2::Rational& right)
{
	computorv2::Complex res;
	res.setReal(left.getReal() + right.getValue());
	res.setImage(left.getImage());
	return (res);
}

computorv2::Complex computorv2::add(const computorv2::Rational& left, const computorv2::Complex& right)
{
	return (computorv2::add(right, left));
}

computorv2::Complex computorv2::add(const computorv2::Complex& left, const computorv2::Complex& right)
{
	computorv2::Complex res;
	res.setReal(left.getReal()   + right.getReal());
	res.setImage(left.getImage() + right.getImage());
	return (res);
}

/* Polynomial (add) */
// computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
// {
// 	computorv2::Polynomial res;
// 	return (res);
// }

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::Rational& right)
{
	computorv2::Polynomial res(left);
	const computorv2::Object* freeterm = computorv2::add(left.getFreeTerm(), &right);
	res.setFreeTerm(freeterm);
	delete (freeterm);
	return (res);
}

computorv2::Polynomial computorv2::add(const computorv2::Rational& left, const computorv2::Polynomial& right)
{
	return (computorv2::add(right, left));
}

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
	computorv2::Polynomial res(left);
	const computorv2::Object* freeterm = computorv2::add(left.getFreeTerm(), &right);
	res.setFreeTerm(freeterm);
	delete (freeterm);
	return (res);
}

computorv2::Polynomial computorv2::add(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
	return (computorv2::add(right, left));
}


computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
	if ((left.getName() == right.getName()) && (computorv2::eql(left.getExponent(), right.getExponent())))
	{
		computorv2::Polynomial res;
		const computorv2::Object* coefficient = computorv2::add(left.getCoefficient(), right.getCoefficient());
		const computorv2::Object* freeterm    = computorv2::add(left.getFreeTerm(), right.getFreeTerm());
		res.setCoefficient(coefficient);
		res.setName(left.getName());
		res.setExponent(left.getExponent());
		res.setFreeTerm(freeterm);
		delete (coefficient);
		delete (freeterm);
		return (res);
	}
	computorv2::Polynomial res(left);
	const computorv2::Object* freeterm = computorv2::add(left.getFreeTerm(), &right);
	res.setFreeTerm(freeterm);
	delete (freeterm);
	return (res);
}

/* Object (add) */

computorv2::Object* computorv2::add(const computorv2::Object* left, const computorv2::Object* right)
{
	if (!left)
	{
		throw std::logic_error("left is NULL!");
	}
	if (!right)
	{
		throw std::logic_error("left is NULL!");
	}
	if (IS_RATIONAL(left))
	{
		if (IS_RATIONAL(right))
			return (computorv2::add(*AS_RATIONAL(left), *AS_RATIONAL(right)).copy());
		else if (IS_COMPLEX(right))
			return (computorv2::add(*AS_RATIONAL(left), *AS_COMPLEX(right)).copy());
		else if (IS_POLYNOMIAL(right))
			return (computorv2::add(*AS_RATIONAL(left), *AS_POLYNOMIAL(right)).copy());
	}
	else if (IS_COMPLEX(left))
	{
		if (IS_RATIONAL(right))
			return (computorv2::add(*AS_COMPLEX(left), *AS_RATIONAL(right)).copy());
		else if (IS_COMPLEX(right))
			return (computorv2::add(*AS_COMPLEX(left), *AS_COMPLEX(right)).copy());
		else if (IS_POLYNOMIAL(right))
			return (computorv2::add(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).copy());
	}
	else if (IS_POLYNOMIAL(left))
	{
		if (IS_RATIONAL(right))
			return (computorv2::add(*AS_POLYNOMIAL(left), *AS_RATIONAL(right)).copy());
		else if (IS_COMPLEX(right))
			return (computorv2::add(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).copy());
		else if (IS_POLYNOMIAL(right))
			return (computorv2::add(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).copy());
	}
	std::stringstream ss("");
	ss << "Can't add objects!";
	ss << ", left->getType() = "  << left->getType();
	ss << ", right->getType() = " << right->getType();
	ss << std::endl;
	throw std::logic_error(ss.str());
	return (NULL);
}

/* Rational (mul) */
computorv2::Rational computorv2::mul(const computorv2::Rational& left, const computorv2::Rational& right)
{
	computorv2::Rational res;
	res.setValue(left.getValue() * right.getValue());
	return (res);
}

/* Complex (mul) */
computorv2::Complex computorv2::mul(const computorv2::Complex& left, const computorv2::Rational& right)
{
	computorv2::Complex res;
	res.setReal(left.getReal()   * right.getValue());
	res.setImage(left.getImage() * right.getValue());
	return (res);
}

computorv2::Complex computorv2::mul(const computorv2::Rational& left, const computorv2::Complex& right)
{
	return (computorv2::mul(right, left));
}

computorv2::Complex computorv2::mul(const computorv2::Complex& left, const computorv2::Complex& right)
{
	computorv2::Complex res;
	res.setReal((left.getReal()  * right.getReal() ) - (left.getImage() * right.getImage()));
	res.setImage((left.getReal() * right.getImage()) + (left.getImage() * right.getReal() ));
	return (res);
}

/* Polynomial (mul) */
computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::Rational& right)
{
	computorv2::Polynomial res(left);
	const computorv2::Object* coefficient = computorv2::mul(left.getCoefficient(), &right);
	const computorv2::Object* freeterm    = computorv2::mul(left.getFreeTerm(), &right);
	res.setCoefficient(coefficient);
	res.setFreeTerm(freeterm);
	delete (coefficient);
	delete (freeterm);
	return (res);
}

computorv2::Polynomial computorv2::mul(const computorv2::Rational& left, const computorv2::Polynomial& right)
{
	return (computorv2::mul(right, left));
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
	computorv2::Polynomial res(left);
	const computorv2::Object* coefficient = computorv2::mul(left.getCoefficient(), &right);
	const computorv2::Object* freeterm    = computorv2::mul(left.getFreeTerm(), &right);
	res.setCoefficient(coefficient);
	res.setFreeTerm(freeterm);
	delete (coefficient);
	delete (freeterm);
	return (res);
}

computorv2::Polynomial computorv2::mul(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
	return (computorv2::mul(right, left));
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
	if (left.getName() == right.getName())
	{
		computorv2::Polynomial first  ; first.setName(left.getName());
		computorv2::Polynomial second ; second.setName(left.getName());
		computorv2::Polynomial third  ; third.setName(left.getName());

		computorv2::Object* coefficient = NULL;
		computorv2::Object* exponent    = NULL;

		coefficient = computorv2::mul(left.getCoefficient(), right.getCoefficient());
		first.setCoefficient(coefficient);
		delete (coefficient);

		coefficient = computorv2::mul(left.getCoefficient(), right.getFreeTerm());
		second.setCoefficient(coefficient);
		delete (coefficient);

		coefficient = computorv2::mul(left.getFreeTerm(), right.getCoefficient());
		third.setCoefficient(coefficient);
		delete (coefficient);

		exponent = computorv2::add(left.getExponent(), right.getExponent());
		first.setExponent(exponent);
		second.setExponent(left.getExponent());
		third.setExponent(right.getExponent());
		delete (exponent);

		computorv2::Polynomial tmp   = computorv2::add(computorv2::add(first, second), third);
		computorv2::Object* freeterm = computorv2::mul(left.getFreeTerm(), right.getFreeTerm());
		computorv2::Object* tmp_res  = computorv2::add(AS_OBJECT(&tmp), freeterm);
		computorv2::Polynomial res(*(AS_POLYNOMIAL(tmp_res)));
		delete (tmp_res);
		delete (freeterm);
		return (res);
	}
	computorv2::Polynomial res(left);
	const computorv2::Object* coefficient = computorv2::mul(left.getCoefficient(), &right);
	const computorv2::Object* freeterm    = computorv2::mul(left.getFreeTerm(), &right);
	res.setCoefficient(coefficient);
	res.setFreeTerm(freeterm);
	delete (coefficient);
	delete (freeterm);
	return (res);
}

computorv2::Object* computorv2::mul(const computorv2::Object* left, const computorv2::Object* right)
{
	if (!left)
	{
		throw std::logic_error("left is NULL!");
	}
	if (!right)
	{
		throw std::logic_error("left is NULL!");
	}
	if (IS_RATIONAL(left))
	{
		if (IS_RATIONAL(right))
			return (computorv2::mul(*AS_RATIONAL(left), *AS_RATIONAL(right)).copy());
		else if (IS_COMPLEX(right))
			return (computorv2::mul(*AS_RATIONAL(left), *AS_COMPLEX(right)).copy());
		else if (IS_POLYNOMIAL(right))
			return (computorv2::mul(*AS_RATIONAL(left), *AS_POLYNOMIAL(right)).copy());
	}
	else if (IS_COMPLEX(left))
	{
		if (IS_RATIONAL(right))
			return (computorv2::mul(*AS_COMPLEX(left), *AS_RATIONAL(right)).copy());
		else if (IS_COMPLEX(right))
			return (computorv2::mul(*AS_COMPLEX(left), *AS_COMPLEX(right)).copy());
		else if (IS_POLYNOMIAL(right))
			return (computorv2::mul(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).copy());
	}
	else if (IS_POLYNOMIAL(left))
	{
		if (IS_RATIONAL(right))
			return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_RATIONAL(right)).copy());
		else if (IS_COMPLEX(right))
			return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).copy());
		else if (IS_POLYNOMIAL(right))
			return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).copy());
	}
	std::stringstream ss("");
	ss << "MultiplicationError: ";
	ss << ", left->getType()  = " << left->getType();
	ss << ", right->getType() = " << right->getType();
	ss << std::endl;
	throw std::logic_error(ss.str());
	return (NULL);
}

/* Rational-Rational (eql) */
bool computorv2::eql(const computorv2::Rational& left, const computorv2::Rational& right)
{
	if (ISNULL(left.getValue() - right.getValue()))
	{
		return (true);
	}
	return (false);
}

/* Object (eql) */
bool computorv2::eql(const computorv2::Object* left, const computorv2::Object* right)
{
	if (!left)
	{
		throw std::logic_error("left is NULL!");
	}
	if (!right)
	{
		throw std::logic_error("left is NULL!");
	}
	switch (OBJECT_TYPE(left))
	{
		case COMPUTORV2_TYPE_RATIONAL:
		{
			switch (OBJECT_TYPE(right))
			{
				case COMPUTORV2_TYPE_RATIONAL:
					return (computorv2::eql(*AS_RATIONAL(left), *AS_RATIONAL(right)));
			}
		}
	}
	std::stringstream ss("");
	ss << "ComparisonError: ";
	ss << ", left->getType()  = " << left->getType();
	ss << ", right->getType() = " << right->getType();
	ss << std::endl;
	throw std::logic_error(ss.str());
	return (false);
}

/* derivative (Object) */
computorv2::Polynomial derivative(const computorv2::Object* obj)
{
	if (!obj)
	{
		throw std::logic_error("Error: Null pointer passed to derivative function.");
	}
	if (IS_RATIONAL(obj))
		return (computorv2::derivative(*AS_RATIONAL(obj)));
	if (IS_COMPLEX(obj))
		return (computorv2::derivative(*AS_COMPLEX(obj)));
	if (IS_POLYNOMIAL(obj))
		return (computorv2::derivative(*AS_POLYNOMIAL(obj)));
	std::stringstream ss("");
	ss << "DerivativeError: ";
	ss << ", obj->getType()  = " << obj->getType();
	ss << std::endl;
	throw std::logic_error(ss.str());
	return (computorv2::Polynomial());
}

/* derivative (Rational) */
computorv2::Polynomial computorv2::derivative(const computorv2::Rational& obj)
{
	computorv2::Polynomial res;
	const computorv2::Rational zero(0.0);
	res.setCoefficient(&zero);
	res.setExponent(&zero);
	res.setFreeTerm(&zero);
	return (res);
}

/* derivative (Complex) */
computorv2::Polynomial computorv2::derivative(const computorv2::Complex& obj)
{
	computorv2::Polynomial res;
	const computorv2::Rational zero(0.0);
	res.setCoefficient(&zero);
	res.setExponent(&zero);
	res.setFreeTerm(&zero);
	return (res);
}

/* derivative (Polynomial) */
computorv2::Polynomial computorv2::derivative(const computorv2::Polynomial& obj)
{
	computorv2::Polynomial res;
	return (res);
}
