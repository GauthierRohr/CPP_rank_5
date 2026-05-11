#include <iostream>
#include <string>
#include "whatever.hpp"

int	main()
{
	std::cout << "=> Test sujet : int <=" << std::endl;
	int	a = 2;
	int	b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	std::cout << std::endl;
	std::cout << "=> Test sujet : string <=" << std::endl;
	std::string	c = "chaine1";
	std::string	d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	std::cout << std::endl;
	std::cout << "=> Test : valeurs égales (retourne le second) <=" << std::endl;
	int	x = 5;
	int	y = 5;
	std::cout << "min( 5, 5 ) = " << ::min(x, y) << std::endl;
	std::cout << "max( 5, 5 ) = " << ::max(x, y) << std::endl;

	std::cout << std::endl;
	std::cout << "=> Test : float <=" << std::endl;
	float	f1 = 1.5f;
	float	f2 = 2.5f;
	::swap(f1, f2);
	std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;
	std::cout << "min( f1, f2 ) = " << ::min(f1, f2) << std::endl;
	std::cout << "max( f1, f2 ) = " << ::max(f1, f2) << std::endl;

	return (0);
}
