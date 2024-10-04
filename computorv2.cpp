// #include <iostream>
// #include "include/utils.hpp"
// #include "include/Object.hpp"
// #include "sources/Rational.cpp"
// #include "sources/VirtualMachine.cpp"
// #include "sources/IndependentVariable.cpp"
// #include "sources/Object.cpp"
// #include "sources/Polynomial.cpp"
// #include "sources/utils.cpp"
// #include "sources/Client.cpp"
// #include "sources/Complex.cpp"
// #include "sources/UsualFunction.cpp"
// #include "include/computorv2.hpp"
// #include "sources/computorv2.cpp"
// #include <unistd.h>

#include "sources/Object.cpp"
#include "sources/Rational.cpp"
#include "sources/Polynomial.cpp"
#include "sources/IndependentVariable.cpp"

int main(void)
{
	computorv2::Polynomial P("x");






	// computorv2::IndependentVariable x("x");


	// std::cout << computorv2::add(x, x) << std::endl;



	// computorv2::Rational x = 2.0;

	// computorv2::UsualFunction f = computorv2::UsualFunction("ln", &x);

	// std::cout << f.evaluate()->toString() << std::endl;




/*
	computorv2::isnull
	computorv2::isunity
	computorv2::isname
	computorv2::copy(object)
	computorv2::evaluate(object)
	computorv2::toString(object)

*/





	// computorv2::Polynomial x; x.setName("x");
	// std::cout << computorv2::add(x, x) << std::endl;

	// std::cout << computorv2::derivative(computorv2::Rational(15)).toString() << std::endl;
	// std::cout << computorv2::derivative(computorv2::Complex(1.0, 1.0)).toString() << std::endl;
	// std::cout << computorv2::derivative(x).toString() << std::endl;


	// computorv2::Client client = computorv2::Client();
	// client.addBuffer("f(x) = x + x + 1\n");

	return (0);
}
