# include "../../include/Object.hpp"
# include "../../include/IndependentVariable.hpp"
# include "../../include/utils.hpp"

# include "../../sources/IndependentVariable.cpp"

// ambiguous logic i + i
// -Wuninitialized

int main(void)
{
	computorv2::IndependentVariable x("x");

	std::cout << x.toString() << std::endl;

	return (0);
}
