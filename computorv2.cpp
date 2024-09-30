#include <iostream>
#include "include/utils.hpp"
#include "include/Object.hpp"
#include "sources/Function.cpp"
#include "sources/Rational.cpp"
#include "sources/VirtualMachine.cpp"
#include "sources/Object.cpp"
#include "sources/IndependentVariable.cpp"
#include "sources/utils.cpp"
#include "sources/Client.cpp"
#include "sources/Complex.cpp"

int main(void)
{
	computorv2::IndependentVariable u; u.setName("x");
	computorv2::IndependentVariable v; v.setName("x");

	std::cout << "u = " << u << std::endl;
	std::cout << "v = " << v << std::endl;

	std::cout << "(u + v) = " << (u + u) << std::endl;

	std::cout << "u = " << u << std::endl;
	std::cout << "v = " << v << std::endl;
	// std::cout << "v = " << computorv2::topower(v, 2) << std::endl;

	/*
		a * x^2 + d + b + (c * x^2)
	*/

	// computorv2::Client client = computorv2::Client();

	// client.addBuffer("f(x) = x + x + 1\n");

	return (0);
}
