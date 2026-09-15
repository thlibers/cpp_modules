#include "../includes/Base.hpp"
#include <ctime>

int main(void)
{
	Base *ptr;

	std::srand(static_cast<unsigned int>(std::time(0)));
	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
	return (0);
}
