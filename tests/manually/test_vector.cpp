# include "../../include/Object.hpp"
# include "../../include/Vector.hpp"
# include "../../sources/Vector.cpp"
# include "../../sources/Complex.cpp"

int main(void)
{

	computorv2::Vector v = computorv2::Vector(1, 2);
	computorv2::Vector u = v;

	std::cout << v << std::endl;

	u = u;
	v = u;

	return (0);
}
