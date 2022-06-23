#include "Fraction.h"

int main()
{
	Fraction f = 0.5;
	f.show_simple_fraction();
	f.show_decimal();
	std::cout << f << "\n";
	Fraction f1 = 0.1;
	f += f1;
	f1.show_simple_fraction();
	std::cout << f << "\n";

	std::cout << double(f) + 0.4 << "\n";
}


