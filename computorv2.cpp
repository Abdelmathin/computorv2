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

	std::cout << "dx / dx = " << computorv2::derivative(x, x) << std::endl;
	std::cout << "dp / dx = " << computorv2::derivative(p, x) << std::endl;
	std::cout << "dz / dx = " << computorv2::derivative(z, x) << std::endl;
	std::cout << "df / dx = " << computorv2::derivative(f, x) << std::endl;




	return (0);
}
