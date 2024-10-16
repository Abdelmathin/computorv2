# include "../../sources/Client.cpp"
# include "../../sources/IndependentVariable.cpp"
# include "../../sources/Polynomial.cpp"
# include "../../sources/Vector.cpp"
# include "../../sources/computorv2.cpp"
# include "../../sources/Complex.cpp"
# include "../../sources/Matrix.cpp"
# include "../../sources/UsualFunction.cpp"
# include "../../sources/VirtualMachine.cpp"
# include "../../sources/statment.cpp"

int main(void)
{
	computorv2::IndependentVariable x("x");

	std::cout << "ln(x)      = " << computorv2::ln(x)      << std::endl;
	std::cout << "exp(x)     = " << computorv2::exp(x)     << std::endl;
	std::cout << "sin(x)     = " << computorv2::sin(x)     << std::endl;
	std::cout << "cos(x)     = " << computorv2::cos(x)     << std::endl;
	std::cout << "tan(x)     = " << computorv2::tan(x)     << std::endl;
	std::cout << "arcsin(x)  = " << computorv2::arcsin(x)  << std::endl;
	std::cout << "arccos(x)  = " << computorv2::arccos(x)  << std::endl;
	std::cout << "arctan(x)  = " << computorv2::arctan(x)  << std::endl;
	std::cout << "sinh(x)    = " << computorv2::sinh(x)    << std::endl;
	std::cout << "cosh(x)    = " << computorv2::cosh(x)    << std::endl;
	std::cout << "tanh(x)    = " << computorv2::tanh(x)    << std::endl;
	std::cout << "arcsinh(x) = " << computorv2::arcsinh(x) << std::endl;
	std::cout << "arccosh(x) = " << computorv2::arccosh(x) << std::endl;
	std::cout << "arctanh(x) = " << computorv2::arctanh(x) << std::endl;

	return (0);
}
