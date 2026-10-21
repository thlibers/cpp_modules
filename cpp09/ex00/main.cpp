#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	std::ifstream input(argv[1]);
	if (!input.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange exchange;
	exchange.loadDatabase("../data.csv");

	std::string line;
	if (!std::getline(input, line))
		return 0;

	while (std::getline(input, line))
	{
		if (line.empty())
			continue;
		std::string::size_type pipe = line.find('|');
		if (pipe == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, pipe));
		std::string valueStr = trim(line.substr(pipe + 1));
		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		double value = 0.0;
		if (!isValidInputValue(valueStr, value))
		{
			if (value < 0.0)
				std::cout << "Error: not a positive number." << std::endl;
			else
				std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		double rate = exchange.getRate(date);
		if (rate < 0.0)
		{
			std::cout << "Error: no data for date." << std::endl;
			continue;
		}

		double result = value * rate;
		std::cout << date << " => " << value << " = " << std::setprecision(10) << result << std::endl;
	}
	return 0;
}
