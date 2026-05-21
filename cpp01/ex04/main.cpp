#include <string>
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	std::string line;
	std::string s1 = av[2];
	std::string s2 = av[3];
	int index = 0;

	if (ac != 4)
		return 1;
	std::ifstream readFile("test.txt");
	if (readFile.fail())
		return 1;
	while (std::getline(readFile, line));
	{
		index = line.find(s1, index);
		line.erase(index, index + s1.size());
		line.insert(index, s2);
		index += s2.size();
	}
	return 0;
}

//	la fonction 'find' me donne la position de ma cahine dans une autre.
//	la fonction ''