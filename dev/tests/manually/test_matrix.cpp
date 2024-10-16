# include "../../include/Object.hpp"
# include "../../include/Matrix.hpp"
# include "../../sources/Matrix.cpp"
# include "../../sources/Complex.cpp"

int main(void)
{
	computorv2::Matrix m(3, 2);

	m.setElementAt(0, 0, 6.0);
	m.setElementAt(1, 0, 5.0);
	m.setElementAt(2, 0, 0.0);

	m.setElementAt(0, 1, 10.0);
	m.setElementAt(1, 1,  3.0);
	m.setElementAt(2, 1,  2.0);

	m.setElementAt(2, 1,  &m);

	// std::cout << m << std::endl;

	std::cout << computorv2::Matrix(
		1, 2,
		3, 4
	) << std::endl;

	std::cout << std::endl << computorv2::Matrix(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	) << std::endl;

	std::cout << std::endl << computorv2::Matrix(
		 1,  2,  3,  4,
		 5,  6,  7,  8,
		 9, 10, 11, 12,
		13, 14, 15, 16
	) << std::endl;

	return (0);
}
