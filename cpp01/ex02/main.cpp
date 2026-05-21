#include <string>
#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << &string << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << string << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	return 0;
}

//	une reference a plusieurs points positifs :
//	- pas besoin de dereferencer.
//	- Meme adresse memoire que la variable referencee.
//	- Ne peut pas etre mis a NULL.
//	- Pas d'enchainement de reference. (exemple ****ptr)