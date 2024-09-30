# include "../../sources/Function.cpp"
# include "../../sources/Object.cpp"
# include "../../sources/Rational.cpp"
# include "../../sources/IndependentVariable.cpp"
# include "../../sources/VirtualMachine.cpp"

int main(void)
{
	computorv2::VirtualMachine vm;

	vm.setVariableByName("x", new computorv2::Rational(2.0));
	vm.setConstantByName("y", new computorv2::Rational(3.0));
	// vm.setVariableByName("z", new computorv2::Complex(1.0, 1.0));

	std::cout << "x = " << *(vm.getVariableByName("x")) << std::endl;
	std::cout << "y = " << *(vm.getConstantByName("y")) << std::endl;
	// std::cout << "z = " << vm.getVariableByName("z")->toString() << std::endl;

	return (0);
}
