#include "../includes/Fixed.hpp"

// int main(void)
// {
// 	int i = 0;
// 	std::cout << i++ << std::endl;
// }

int main()
{
	Fixed 		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return 0;
}

// int main(void)
// {
//     Fixed        a;
//     Fixed        b(3.14f);
//     Fixed        c(23);

//     std::cout << "a : " << a << std::endl;
//     std::cout << "b : " << b << std::endl;
//     std::cout << "c : " << c << std::endl << std::endl;
//     std::cout << "++a : " << ++a << std::endl;
//     std::cout << "a : " << a << std::endl;
//     std::cout << "a++ : " << a++ << std::endl;
//     std::cout << "b + 3 : " << b + 3 << std::endl;
//     std::cout << "b * 0.33 : " << b * 0.3f << std::endl;
//     std::cout << "b / 0.33 : " << b / 0.3f << std::endl;
//     std::cout << "b - 0.33 : " << b - 0.3f << std::endl;
//     std::cout << "--c : " << --c << std::endl;
//     std::cout << "c-- : " << c-- << std::endl;
//     std::cout << "c : " << c << std::endl << std::endl ;
//     std::cout << "b (" << b << ") < c (" << c << ") : " << (b < c) << std::endl;
//     std::cout << "b (" << b << ") > c (" << c << ") : " << (b > c) << std::endl;
//     std::cout << "b (" << b << ") == c (" << c << ") : " << (b == c) << std::endl;
//     std::cout << "b (" << b << ") != c (" << c << ") : " << (b != c) << std::endl;
// }
