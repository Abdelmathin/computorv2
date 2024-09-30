# include <iostream>

# include "include/utils.hpp"
# include "include/Object.hpp"
# include "sources/Function.cpp"
# include "sources/Rational.cpp"
# include "sources/VirtualMachine.cpp"
# include "sources/Object.cpp"
# include "sources/IndependentVariable.cpp"
# include "sources/utils.cpp"

int main(void)
{
	computorv2::VirtualMachine vm;
	computorv2::statment st;

	vm.setVariableByName("x", new computorv2::Rational(1.4));
	vm.setVariableByName("z", new computorv2::Rational(2.3));

	computorv2::statment_init(&st);
	st._pos = 0;
	st._str = "    a(here) = 5\nb = 11\nx + a = ?";
	st._str = "    =a1here2 = ?\nb = 11\nx + a = ?";
	st._len = 32;
	st._vm  = &vm;
	computorv2::statment_parse(&st);

	std::cout << *(st._result) << std::endl;

	return (0);
}
