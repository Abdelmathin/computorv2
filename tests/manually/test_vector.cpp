# include "../../sources/Client.cpp"
# include "../../sources/IndependentVariable.cpp"
# include "../../sources/OStream.cpp"
# include "../../sources/UsualFunction.cpp"
# include "../../sources/VirtualMachine.cpp"
# include "../../sources/Complex.cpp"
# include "../../sources/Matrix.cpp"
# include "../../sources/Polynomial.cpp"
# include "../../sources/computorv2.cpp"
# include "../../sources/statment.cpp"

int main(void)
{
	const computorv2::IndependentVariable a("a");
	const computorv2::IndependentVariable b("b");
	const computorv2::IndependentVariable c("c");
	const computorv2::IndependentVariable d("d");

	const computorv2::Complex a1(1.0, 0.0);
	const computorv2::Complex a2(2.0, 0.0);
	const computorv2::Complex a3(3.0, 0.0);
	const computorv2::Complex a4(4.0, 0.0);

	computorv2::Matrix X(2, 2);

	X.setElementAt(0, 0, &a1);
	X.setElementAt(0, 1, &a2);
	X.setElementAt(1, 0, &a3);
	X.setElementAt(1, 1, &a4);

	std::cout << X << std::endl;
	std::cout << "---------- cofactor ----------" << std::endl;
	std::cout << computorv2::cofactor(X) << std::endl;
	std::cout << "---------- transpose ----------" << std::endl;
	std::cout << computorv2::transpose(X) << std::endl;
	std::cout << "----------" << std::endl;
	// std::cout << computorv2::neg(X) << std::endl;
	// std::cout << computorv2::det(X)->toString() << std::endl;

// \vec{v} = \begin{bmatrix} X \\\ Y \end{bmatrix}


	// computorv2::Matrix X(
	// 	&x, &y,
	// 	&y, &x
	// );

	// std::cout << computorv2::determinant(X) << std::endl;

	// computorv2::Matrix m1(1, 2, 3, 4, 5, 0, 7, 8, 9);
	// computorv2::Matrix m2(1, 2, 3, 4, 5, 0, 7, 8, 9);

	// std::cout << computorv2::add(m1, m2) << std::endl;
	// std::cout << computorv2::sub(m1, m2) << std::endl;
	// std::cout << computorv2::mul(m1, m2) << std::endl;
	// std::cout << computorv2::div(m1, m2) << std::endl;
	// std::cout << computorv2::neg(m1) << std::endl;

	return (0);
}
