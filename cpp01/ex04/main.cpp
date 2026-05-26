#include <string>
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	std::string line;
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (ac != 4)
		return 1;
	std::ifstream readFile(av[1]);
	if (readFile.fail())
		return 1;
	std::ofstream newfile("ytennah.txt", std::ios::trunc);
	if (newfile.fail())
		return 1;
	std::size_t index = 0;
	while (std::getline(readFile, line))
	{
		index = 0;
		while ((index = line.find(s1, index)) != std::string::npos)
		{
			line.erase(index, s1.size());
			line.insert(index, s2);
			index += s2.size();
		}
		newfile << line << std::endl;
	}
	return 0;
}

//	la fonction 'find' me donne la position de ma chaine dans une autre.
//	la fonction ''