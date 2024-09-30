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
	computorv2::Client client = computorv2::Client();

	client.addBuffer("a = 5\n");
	client.addBuffer("b = i\n");
	client.addBuffer("c = b\n");

	return (0);
}
