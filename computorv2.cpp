#include <libc.h>

#include "include/Client.hpp"
#include "include/IndependentVariable.hpp"
#include "include/Object.hpp"
#include "include/UsualFunction.hpp"
#include "include/VirtualMachine.hpp"
#include "include/statment.hpp"
#include "include/Complex.hpp"
#include "include/Matrix.hpp"
#include "include/Polynomial.hpp"
#include "include/Vector.hpp"
#include "include/computorv2.hpp"

#include "sources/Client.cpp"
#include "sources/IndependentVariable.cpp"
#include "sources/Polynomial.cpp"
#include "sources/Vector.cpp"
#include "sources/computorv2.cpp"
#include "sources/Complex.cpp"
#include "sources/Matrix.cpp"
#include "sources/UsualFunction.cpp"
#include "sources/VirtualMachine.cpp"
#include "sources/statment.cpp"

/*
	computorv2::IndependentVariable x("x");
	computorv2::Polynomial          p(x);
	computorv2::Complex             z(1.0, 1.0);
	computorv2::UsualFunction       f("ln", x);

	wrong:
		std::cout << "computorv2::derivative(computorv2::mul(x, f), x) = " << computorv2::derivative(computorv2::mul(x, f), x) << std::endl;

	add, sub, mul, div, ... functions will evaluate polynomials.

*/

int main(void)
{
	computorv2::IndependentVariable x("x");
	computorv2::Polynomial          p(x);
	computorv2::Complex             z(1.0, 1.0);
	computorv2::UsualFunction       f("ln", x);

	/* -------------------------------------- */

	std::cout << "x = " << x << std::endl;
	std::cout << "p = " << p << std::endl;
	std::cout << "z = " << z << std::endl;
	std::cout << "f = " << f << std::endl;

	// std::cout << "dx / dx = " << computorv2::derivative(x, x) << std::endl;
	// std::cout << "dp / dx = " << computorv2::derivative(p, x) << std::endl;
	// std::cout << "dz / dx = " << computorv2::derivative(z, x) << std::endl;
	// std::cout << "df / dx = " << computorv2::derivative(f, x) << std::endl;

	std::cout << "computorv2::inverse(&x) = " << computorv2::inverse(&x)->toString() << std::endl;
	std::cout << "computorv2::inverse(&p) = " << computorv2::inverse(&p)->toString() << std::endl;
	std::cout << "computorv2::inverse(&z) = " << computorv2::inverse(&z)->toString() << std::endl;
	std::cout << "computorv2::inverse(&f) = " << computorv2::inverse(&f)->toString() << std::endl;
	std::cout << "computorv2::inverse(x)  = " << computorv2::inverse(x)  << std::endl;
	std::cout << "computorv2::inverse(p)  = " << computorv2::inverse(p)  << std::endl;
	std::cout << "computorv2::inverse(z)  = " << computorv2::inverse(z)  << std::endl;
	std::cout << "computorv2::inverse(f)  = " << computorv2::inverse(f)  << std::endl;

	std::cout << "computorv2::add(x, x) = " << computorv2::add(x, x) << std::endl;
	std::cout << "computorv2::add(x, p) = " << computorv2::add(x, p) << std::endl;
	std::cout << "computorv2::add(x, z) = " << computorv2::add(x, z) << std::endl;
	std::cout << "computorv2::add(x, f) = " << computorv2::add(x, f) << std::endl;
	std::cout << "computorv2::add(p, x) = " << computorv2::add(p, x) << std::endl;
	std::cout << "computorv2::add(p, p) = " << computorv2::add(p, p) << std::endl;
	std::cout << "computorv2::add(p, z) = " << computorv2::add(p, z) << std::endl;
	std::cout << "computorv2::add(p, f) = " << computorv2::add(p, f) << std::endl;
	std::cout << "computorv2::add(z, x) = " << computorv2::add(z, x) << std::endl;
	std::cout << "computorv2::add(z, p) = " << computorv2::add(z, p) << std::endl;
	std::cout << "computorv2::add(z, z) = " << computorv2::add(z, z) << std::endl;
	std::cout << "computorv2::add(z, f) = " << computorv2::add(z, f) << std::endl;
	std::cout << "computorv2::add(f, x) = " << computorv2::add(f, x) << std::endl;
	std::cout << "computorv2::add(f, p) = " << computorv2::add(f, p) << std::endl;
	std::cout << "computorv2::add(f, z) = " << computorv2::add(f, z) << std::endl;
	std::cout << "computorv2::add(f, f) = " << computorv2::add(f, f) << std::endl;

	std::cout << "computorv2::sub(x, x) = " << computorv2::sub(x, x) << std::endl;
	std::cout << "computorv2::sub(x, p) = " << computorv2::sub(x, p) << std::endl;
	std::cout << "computorv2::sub(x, z) = " << computorv2::sub(x, z) << std::endl;
	std::cout << "computorv2::sub(x, f) = " << computorv2::sub(x, f) << std::endl;
	std::cout << "computorv2::sub(p, x) = " << computorv2::sub(p, x) << std::endl;
	std::cout << "computorv2::sub(p, p) = " << computorv2::sub(p, p) << std::endl;
	std::cout << "computorv2::sub(p, z) = " << computorv2::sub(p, z) << std::endl;
	std::cout << "computorv2::sub(p, f) = " << computorv2::sub(p, f) << std::endl;
	std::cout << "computorv2::sub(z, x) = " << computorv2::sub(z, x) << std::endl;
	std::cout << "computorv2::sub(z, p) = " << computorv2::sub(z, p) << std::endl;
	std::cout << "computorv2::sub(z, z) = " << computorv2::sub(z, z) << std::endl;
	std::cout << "computorv2::sub(z, f) = " << computorv2::sub(z, f) << std::endl;
	std::cout << "computorv2::sub(f, x) = " << computorv2::sub(f, x) << std::endl;
	std::cout << "computorv2::sub(f, p) = " << computorv2::sub(f, p) << std::endl;
	std::cout << "computorv2::sub(f, z) = " << computorv2::sub(f, z) << std::endl;
	std::cout << "computorv2::sub(f, f) = " << computorv2::sub(f, f) << std::endl;

	std::cout << "computorv2::mul(x, x) = " << computorv2::mul(x, x) << std::endl;
	std::cout << "computorv2::mul(x, p) = " << computorv2::mul(x, p) << std::endl;
	std::cout << "computorv2::mul(x, z) = " << computorv2::mul(x, z) << std::endl;
	std::cout << "computorv2::mul(x, f) = " << computorv2::mul(x, f) << std::endl;
	std::cout << "computorv2::mul(p, x) = " << computorv2::mul(p, x) << std::endl;
	std::cout << "computorv2::mul(p, p) = " << computorv2::mul(p, p) << std::endl;
	std::cout << "computorv2::mul(p, z) = " << computorv2::mul(p, z) << std::endl;
	std::cout << "computorv2::mul(p, f) = " << computorv2::mul(p, f) << std::endl;
	std::cout << "computorv2::mul(z, x) = " << computorv2::mul(z, x) << std::endl;
	std::cout << "computorv2::mul(z, p) = " << computorv2::mul(z, p) << std::endl;
	std::cout << "computorv2::mul(z, z) = " << computorv2::mul(z, z) << std::endl;
	std::cout << "computorv2::mul(z, f) = " << computorv2::mul(z, f) << std::endl;
	std::cout << "computorv2::mul(f, x) = " << computorv2::mul(f, x) << std::endl;
	std::cout << "computorv2::mul(f, p) = " << computorv2::mul(f, p) << std::endl;
	std::cout << "computorv2::mul(f, z) = " << computorv2::mul(f, z) << std::endl;
	std::cout << "computorv2::mul(f, f) = " << computorv2::mul(f, f) << std::endl;

	std::cout << "computorv2::div(x, x) = " << computorv2::div(x, x) << std::endl;
	std::cout << "computorv2::div(x, p) = " << computorv2::div(x, p) << std::endl;
	std::cout << "computorv2::div(x, z) = " << computorv2::div(x, z) << std::endl;
	std::cout << "computorv2::div(x, f) = " << computorv2::div(x, f) << std::endl;
	std::cout << "computorv2::div(p, x) = " << computorv2::div(p, x) << std::endl;
	std::cout << "computorv2::div(p, p) = " << computorv2::div(p, p) << std::endl;
	std::cout << "computorv2::div(p, z) = " << computorv2::div(p, z) << std::endl;
	std::cout << "computorv2::div(p, f) = " << computorv2::div(p, f) << std::endl;
	std::cout << "computorv2::div(z, x) = " << computorv2::div(z, x) << std::endl;
	std::cout << "computorv2::div(z, p) = " << computorv2::div(z, p) << std::endl;
	std::cout << "computorv2::div(z, z) = " << computorv2::div(z, z) << std::endl;
	std::cout << "computorv2::div(z, f) = " << computorv2::div(z, f) << std::endl;
	std::cout << "computorv2::div(f, x) = " << computorv2::div(f, x) << std::endl;
	std::cout << "computorv2::div(f, p) = " << computorv2::div(f, p) << std::endl;
	std::cout << "computorv2::div(f, z) = " << computorv2::div(f, z) << std::endl;
	std::cout << "computorv2::div(f, f) = " << computorv2::div(f, f) << std::endl;

	return (0);
}

/*

	negation
	neg

	return (computorv2::mul(left, computorv2::pow(right, computorv2::Complex(-1.0, 0.0))));

*/
