# include "../../sources/Client.cpp"
# include "../../sources/IndependentVariable.cpp"
# include "../../sources/Polynomial.cpp"
# include "../../sources/Vector.cpp"
# include "../../sources/computorv2.cpp"
# include "../../sources/statment.cpp"
# include "../../sources/Complex.cpp"
# include "../../sources/Matrix.cpp"
# include "../../sources/UsualFunction.cpp"
# include "../../sources/VirtualMachine.cpp"

int main(void)
{

	computorv2::Client client = computorv2::Client();
	client.setFdIn(STDIN_FILENO);
	client.setFdOut(STDOUT_FILENO);
	client.setFdErr(STDOUT_FILENO);

	client.addBuffer("x = 7\n");
	client.addBuffer("y = 13\n");
	client.addBuffer("f(x) = 2 * x + x * x + 1\n");
	// client.addBuffer("g(x) = f'(x)\n");

	return (0);
}
