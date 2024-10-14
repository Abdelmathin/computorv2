
# include "../../sources/Client.cpp"
# include "../../sources/IndependentVariable.cpp"
# include "../../sources/OStream.cpp"
# include "../../sources/UsualFunction.cpp"
# include "../../sources/VirtualMachine.cpp"
# include "../../sources/Complex.cpp"
# include "../../sources/Matrix.cpp"
# include "../../sources/Polynomial.cpp"
# include "../../sources/Vector.cpp"
# include "../../sources/computorv2.cpp"
# include "../../sources/statment.cpp"

int main(void)
{
	const computorv2::Complex one(1.0, 0.0);
	const computorv2::IndependentVariable x("x");
	const computorv2::IndependentVariable y("y");
	const computorv2::IndependentVariable z("z");

	computorv2::Polynomial p("x");

	std::cout << computorv2::mul(p, one) << std::endl;
	exit(0);




	p = computorv2::add(p, x);
	p = computorv2::add(p, y);
	p = computorv2::add(p, z);

	std::map< std::string, const computorv2::Object*> vars;

	computorv2::variables(&p, vars);

	std::map< std::string, const computorv2::Object*>::iterator it = vars.begin();
	while (it != vars.end())
	{
		std::cout << it->first << " = " << it->second->toString() << std::endl;
		it++;
	}


	vars["y"] = &p;

	std::cout << p << std::endl;
	std::cout << computorv2::replace(&p, vars)->toString() << std::endl;



	// std::cout << sinx << std::endl;

	// std::map< computorv2::Object* , computorv2::Object* > vs;

	// computorv2::variables(&sinx, vs);
	// computorv2::replace(&sinx, vs);

	return (0);
}
