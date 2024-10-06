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

// #include "sources/Client.cpp"
// #include "sources/IndependentVariable.cpp"
// #include "sources/Polynomial.cpp"
// #include "sources/Vector.cpp"
// #include "sources/computorv2.cpp"
// #include "sources/Complex.cpp"
// #include "sources/Matrix.cpp"
// #include "sources/UsualFunction.cpp"
// #include "sources/VirtualMachine.cpp"
// #include "sources/statment.cpp"



// std::ostream& operator<<(std::ostream& os, const computorv2::Object& obj)
// {
// 	os << obj.toString();
// 	return (os);
// }

int main(void)
{

	computorv2::IndependentVariable x("x");
	computorv2::UsualFunction ln("ln", x);

	computorv2::Polynomial P(&x);

	std::cout << computorv2::derivative(P, x).toString() << std::endl;
	// std::cout << computorv2::derivative(computorv2::add(computorv2::add(P, P), computorv2::mul(P, P))).toString() << std::endl;






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
