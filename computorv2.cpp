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

	neg


>>>>>>>
computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::Polynomial& right)


*/

int main(void)
{
	computorv2::IndependentVariable x("x");
	computorv2::IndependentVariable y("y");
	computorv2::Polynomial          p(x);
	computorv2::Complex             z(1.0, 1.0);
	computorv2::UsualFunction       f("ln", x);

	/* -------------------------------------- */

	computorv2::Polynomial w(f);

	std::cout << "x = " << x << std::endl;
	std::cout << "p = " << p << std::endl;
	std::cout << "z = " << z << std::endl;
	std::cout << "f = " << f << std::endl;

	std::cout << "d(" << x.toString() << ") / dx = " << computorv2::drv(x, x) << std::endl;
	std::cout << "d(" << p.toString() << ") / dx = " << computorv2::drv(p, x) << std::endl;
	std::cout << "d(" << z.toString() << ") / dx = " << computorv2::drv(z, x) << std::endl;
	std::cout << "d(" << f.toString() << ") / dx = " << computorv2::drv(f, x) << std::endl;

	std::cout << "computorv2::inv(&x) = " << computorv2::inv(&x)->toString() << std::endl;
	std::cout << "computorv2::inv(&p) = " << computorv2::inv(&p)->toString() << std::endl;
	std::cout << "computorv2::inv(&z) = " << computorv2::inv(&z)->toString() << std::endl;
	std::cout << "computorv2::inv(&f) = " << computorv2::inv(&f)->toString() << std::endl;
	std::cout << "computorv2::inv(x)  = " << computorv2::inv(x)  << std::endl;
	std::cout << "computorv2::inv(p)  = " << computorv2::inv(p)  << std::endl;
	std::cout << "computorv2::inv(z)  = " << computorv2::inv(z)  << std::endl;
	std::cout << "computorv2::inv(f)  = " << computorv2::inv(f)  << std::endl;

	std::cout << "computorv2::add(x, x) = " << computorv2::add(x, x) << std::endl;
	std::cout << "computorv2::add(x, p) = " << computorv2::add(x, p) << std::endl;
	std::cout << "computorv2::add(x, z) = " << computorv2::add(x, z) << std::endl;
	std::cout << "computorv2::add(x, f) = " << computorv2::add(x, f) << std::endl;
	std::cout << "computorv2::add(x, y) = " << computorv2::add(x, f) << std::endl;
	std::cout << "computorv2::add(p, x) = " << computorv2::add(p, x) << std::endl;
	std::cout << "computorv2::add(p, p) = " << computorv2::add(p, p) << std::endl;
	std::cout << "computorv2::add(p, z) = " << computorv2::add(p, z) << std::endl;
	std::cout << "computorv2::add(p, f) = " << computorv2::add(p, f) << std::endl;
	std::cout << "computorv2::add(p, y) = " << computorv2::add(p, f) << std::endl;
	std::cout << "computorv2::add(z, x) = " << computorv2::add(z, x) << std::endl;
	std::cout << "computorv2::add(z, p) = " << computorv2::add(z, p) << std::endl;
	std::cout << "computorv2::add(z, z) = " << computorv2::add(z, z) << std::endl;
	std::cout << "computorv2::add(z, f) = " << computorv2::add(z, f) << std::endl;
	std::cout << "computorv2::add(z, y) = " << computorv2::add(z, f) << std::endl;
	std::cout << "computorv2::add(f, x) = " << computorv2::add(f, x) << std::endl;
	std::cout << "computorv2::add(f, p) = " << computorv2::add(f, p) << std::endl;
	std::cout << "computorv2::add(f, z) = " << computorv2::add(f, z) << std::endl;
	std::cout << "computorv2::add(f, f) = " << computorv2::add(f, f) << std::endl;
	std::cout << "computorv2::add(f, y) = " << computorv2::add(f, f) << std::endl;

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

	// exit(0);

	const computorv2::Polynomial e1 = computorv2::add(computorv2::div(computorv2::add(computorv2::mul(computorv2::add(computorv2::add(computorv2::add(x, computorv2::mul(x, x)), computorv2::add(x, computorv2::add(x, x))), computorv2::add(x, x)), x), x), x), z);
	const computorv2::Polynomial e2 = computorv2::add(computorv2::add(computorv2::div(computorv2::mul(computorv2::add(computorv2::add(computorv2::add(x, computorv2::mul(x, x)), computorv2::add(x, computorv2::add(x, x))), computorv2::add(x, x)), x), x), x), z);
	const computorv2::Polynomial e3 = computorv2::div(computorv2::add(computorv2::div(computorv2::div(computorv2::add(computorv2::div(computorv2::add(x, computorv2::mul(z, f)), computorv2::div(x, computorv2::add(x, f))), computorv2::add(f, x)), x), x), x), z);
	const computorv2::Polynomial e4 = computorv2::add(computorv2::mul(f, computorv2::mul(f, x)), computorv2::div(f, x));
	const computorv2::Polynomial e5 = computorv2::div(computorv2::sub(z, computorv2::add(computorv2::mul(f, p), x)), 2.0);
	const computorv2::Polynomial e6 = computorv2::mul(computorv2::div(x, f), computorv2::mul(computorv2::mul(computorv2::mul(computorv2::mul(computorv2::mul(computorv2::mul(computorv2::mul(computorv2::mul(computorv2::div(x, f), computorv2::div(x, f)), computorv2::mul(computorv2::div(x, f), computorv2::div(x, f))), computorv2::mul(computorv2::div(x, f), computorv2::div(x, f))), computorv2::mul(computorv2::div(x, f), computorv2::div(x, f))), computorv2::mul(computorv2::div(x, f), computorv2::div(x, f))), computorv2::mul(computorv2::div(x, f), computorv2::div(x, f))), computorv2::mul(computorv2::div(x, f), computorv2::div(x, f))), computorv2::mul(computorv2::div(x, f), computorv2::div(x, f))));
	const computorv2::Polynomial e7 = computorv2::mul(computorv2::add(x, f), computorv2::mul(computorv2::add(computorv2::add(computorv2::mul(computorv2::mul(computorv2::mul(computorv2::mul(computorv2::mul(computorv2::div(x, f), computorv2::div(x, f)), computorv2::mul(computorv2::div(x, f), computorv2::div(x, f))), computorv2::mul(computorv2::div(x, f), computorv2::add(x, f))), computorv2::mul(computorv2::div(x, f), computorv2::div(x, f))), computorv2::mul(computorv2::div(x, f), computorv2::div(x, f))), computorv2::mul(computorv2::div(x, f), computorv2::div(x, f))), computorv2::sub(computorv2::div(x, f), computorv2::div(x, f))), computorv2::mul(computorv2::sub(x, f), computorv2::div(x, f))));
	const computorv2::Polynomial e8 = computorv2::mul(computorv2::add(x, z), computorv2::mul(computorv2::add(computorv2::add(computorv2::mul(computorv2::mul(computorv2::mul(computorv2::mul(computorv2::mul(computorv2::div(x, f), computorv2::div(x, f)), computorv2::mul(computorv2::div(x, f), computorv2::div(x, f))), computorv2::mul(computorv2::div(x, f), computorv2::add(x, f))), computorv2::mul(computorv2::div(x, f), computorv2::div(x, z))), computorv2::mul(computorv2::div(x, f), computorv2::div(x, f))), computorv2::mul(computorv2::div(x, f), computorv2::div(x, f))), computorv2::sub(computorv2::div(x, f), computorv2::div(x, f))), computorv2::mul(computorv2::sub(x, z), computorv2::div(x, f))));
	std::cout << "e1 = " << e1 << std::endl;
	std::cout << "e2 = " << e2 << std::endl;
	std::cout << "e3 = " << e3 << std::endl;
	std::cout << "e4 = " << e4 << std::endl;
	std::cout << "e5 = " << e5 << std::endl;
	std::cout << "e6 = " << e6 << std::endl;
	std::cout << "e7 = " << e7 << std::endl;
	std::cout << "e8 = " << e8 << std::endl;
	return (0);
}
