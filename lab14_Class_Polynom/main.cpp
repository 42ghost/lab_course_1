#include "polynom.h"

int main()
{
	// Sum
    double p1[] = {1, 3, 6, 4};
    Polynom P1(4, p1);
    
    double p2[] = {2, 4, 5, 3};
    Polynom P2(4, p2);

    Polynom P3 = P2 + P1;
    std::cout << P3 << '\n';

	// Pow
	std::cout << P3 << '\n';


	// Mul
    double p4[] = {1, 5, 6};
    Polynom P4(3, p4);
    double p5[] = {5, 2};
    Polynom P5(2, p5);
    double p6[] = {3, 0};
    Polynom P6(2, p6);

    Polynom P7 = P4 * P5 * P6;
    std::cout << P7 << '\n';

    return 0;
}
