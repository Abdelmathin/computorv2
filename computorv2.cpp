#include <iostream>
#include "include/utils.hpp"
#include "include/Object.hpp"
#include "sources/Rational.cpp"
#include "sources/VirtualMachine.cpp"
#include "sources/Object.cpp"
#include "sources/Polynomial.cpp"
#include "sources/utils.cpp"
#include "sources/Client.cpp"
#include "sources/Complex.cpp"
#include "include/computorv2.hpp"
#include "sources/computorv2.cpp"
#include <unistd.h>

void leaks(void)
{
	char buffer[1024];
	buffer[sprintf(buffer, "leaks %d\n", getpid())] = 0;
	system(buffer);
}

/*
	Polynomial
	.setIndependentVariableName("x");
	derivative
*/

int main(void)
{
	computorv2::Polynomial x; x.setName("x");

	std::cout << computorv2::derivative(computorv2::Rational(15)).toString() << std::endl;
	std::cout << computorv2::derivative(computorv2::Complex(1.0, 1.0)).toString() << std::endl;
	std::cout << computorv2::derivative(x).toString() << std::endl;


	// computorv2::Client client = computorv2::Client();
	// client.addBuffer("f(x) = x + x + 1\n");

	return (0);
}
