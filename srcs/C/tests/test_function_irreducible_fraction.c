
#include "computorv1_isnull.c"
#include "computorv1_isinteger.c"
#include "computorv1_fraction_part.c"
#include "computorv1_irreducible_fraction.c"
#include <stdio.h>

int main(void)
{

	t_fraction fraction;
	fraction = computorv1_irreducible_fraction( 997.0 / 991.0 ); printf("%.0f / %.0f\n", fraction.numerator, fraction.denominator);
	fraction = computorv1_irreducible_fraction(2.8333333333); printf("%.0f / %.0f\n", fraction.numerator, fraction.denominator);
	fraction = computorv1_irreducible_fraction(2.8333333333); printf("%.0f / %.0f\n", fraction.numerator, fraction.denominator);
	fraction = computorv1_irreducible_fraction(1.0 / 4) ; printf("%.0f / %.0f\n", fraction.numerator, fraction.denominator);
	fraction = computorv1_irreducible_fraction(9.0 / 8) ; printf("%.0f / %.0f\n", fraction.numerator, fraction.denominator);
	fraction = computorv1_irreducible_fraction(-7.0 / 8) ; printf("%.0f / %.0f\n", fraction.numerator, fraction.denominator);
	fraction = computorv1_irreducible_fraction(11.0 / 8); printf("%.0f / %.0f\n", fraction.numerator, fraction.denominator);
	fraction = computorv1_irreducible_fraction(17.0 / 23); printf("%.0f / %.0f\n", fraction.numerator, fraction.denominator);
	fraction = computorv1_irreducible_fraction(3.0 / 4); printf("%.0f / %.0f\n", fraction.numerator, fraction.denominator);
	return (0);
}
