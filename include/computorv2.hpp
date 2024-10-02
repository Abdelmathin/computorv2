#pragma once

#include "utils.hpp"
#include "Object.hpp"
#include "Complex.hpp"
#include "Rational.hpp"
#include "Polynomial.hpp"

namespace computorv2
{
	/* Rational (add) */
	computorv2::Rational   add(const computorv2::Rational& left, const computorv2::Rational& right);

	/* Complex (add) */
	computorv2::Complex    add(const computorv2::Complex& left, const computorv2::Rational& right);
	computorv2::Complex    add(const computorv2::Rational& left, const computorv2::Complex& right);
	computorv2::Complex    add(const computorv2::Complex& left, const computorv2::Complex& right);


	/* Polynomial (add) */
	computorv2::Polynomial add(const computorv2::Polynomial& left, const computorv2::Rational& right);
	computorv2::Polynomial add(const computorv2::Rational& left, const computorv2::Polynomial& right);
	computorv2::Polynomial add(const computorv2::Polynomial& left, const computorv2::Complex& right);
	computorv2::Polynomial add(const computorv2::Complex& left, const computorv2::Polynomial& right);
	computorv2::Polynomial add(const computorv2::Polynomial& left, const computorv2::Polynomial& right);

	/* Object (add) */
	computorv2::Object*    add(const computorv2::Object* left, const computorv2::Object* right);

	/* Rational (mul) */
	computorv2::Rational   mul(const computorv2::Rational& left, const computorv2::Rational& right);

	/* Complex (mul) */
	computorv2::Complex    mul(const computorv2::Complex& left, const computorv2::Rational& right);
	computorv2::Complex    mul(const computorv2::Rational& left, const computorv2::Complex& right);
	computorv2::Complex    mul(const computorv2::Complex& left, const computorv2::Complex& right);

	/* Polynomial (mul) */
	computorv2::Polynomial mul(const computorv2::Polynomial& left, const computorv2::Rational& right);
	computorv2::Polynomial mul(const computorv2::Rational& left, const computorv2::Polynomial& right);
	computorv2::Polynomial mul(const computorv2::Polynomial& left, const computorv2::Complex& right);
	computorv2::Polynomial mul(const computorv2::Complex& left, const computorv2::Polynomial& right);
	computorv2::Polynomial mul(const computorv2::Polynomial& left, const computorv2::Polynomial& right);
	computorv2::Object*    mul(const computorv2::Object* left, const computorv2::Object* right);

	/* Rational-Rational (eql) */
	bool                   eql(const computorv2::Rational& left, const computorv2::Rational& right);

	/* Object (eql) */
	bool                   eql(const computorv2::Object* left, const computorv2::Object* right);

	/* derivative (Object) */
	computorv2::Polynomial derivative(const computorv2::Object* obj);

	/* derivative (Rational) */
	computorv2::Polynomial derivative(const computorv2::Rational& obj);

	/* derivative (Complex) */
	computorv2::Polynomial derivative(const computorv2::Complex& obj);

	/* derivative (Polynomial) */
	computorv2::Polynomial derivative(const computorv2::Polynomial& obj);
}
