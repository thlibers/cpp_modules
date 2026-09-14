#include "../includes/Serializer.hpp"
#include <iostream>

int main(void)
{
	Data data;
	Data *original = &data;
	Data *restored;
	uintptr_t raw;

	data.test1 = 6234;
	data.test2 = "jdhwhjdf";
	data.test3 = 3.14f;
	data.test4 = true;
	raw = Serializer::serialize(original);
	restored = Serializer::deserialize(raw);
	std::cout << original << std::endl;
	std::cout << restored << std::endl;
	return 0;
}
