# include "../../include/Object.hpp"
# include "../../include/Complex.hpp"
# include "../../include/utils.hpp"

# include "../../sources/Complex.cpp"

int main(void)
{
	computorv2::Complex x;
	computorv2::Complex y = 1.0;
	computorv2::Complex z = computorv2::Complex(1.0, 1.0);

	std::cout << "x = " << x.toString() << std::endl;
	std::cout << "y = " << y.toString() << std::endl;
	std::cout << "z = " << z.toString() << std::endl;

	std::cout << "x.isnull() = " << x.isnull() << std::endl;
	std::cout << "y.isnull() = " << y.isnull() << std::endl;
	std::cout << "z.isnull() = " << z.isnull() << std::endl;

	std::cout << "x.isunity() = " << x.isunity() << std::endl;
	std::cout << "y.isunity() = " << y.isunity() << std::endl;
	std::cout << "z.isunity() = " << z.isunity() << std::endl;

	return (0);
}
