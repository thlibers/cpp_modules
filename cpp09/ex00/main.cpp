#include "BitcoinExchange.hpp"

static std::string trim(const std::string &input)
{
	std::string::size_type start = 0;
	std::string::size_type end = input.size();

	while (start < end && (input[start] == ' ' || input[start] == '\t'))
		++start;
	while (end > start && (input[end - 1] == ' ' || input[end - 1] == '\t'))
		--end;
	return input.substr(start, end - start);
}

static bool isValidDate(const std::string &date)
{
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9')
			return false;
	}

	int year = 0;
	int month = 0;
	int day = 0;
	std::istringstream stream(date);
	char dash = 0;
	stream >> year >> dash >> month >> dash >> day;
	if (!stream || dash != '-')
		return false;
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	int maxDay = 31;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		maxDay = 30;
	else if (month == 2)
	{
		bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		maxDay = leap ? 29 : 28;
	}
	return day <= maxDay;
}

static bool isValidInputValue(const std::string &valueStr, double &value)
{
	if (valueStr.empty())
		return false;
	char *end = NULL;
	errno = 0;
	value = std::strtod(valueStr.c_str(), &end);
	if (end == valueStr.c_str() || *end != '\0' || errno == ERANGE)
		return false;
	if (value < 0.0 || value > 1000.0)
		return false;
	return true;
}

static std::string findDatabasePath(void)
{
	std::string candidates[3];
	candidates[0] = "data.csv";
	candidates[1] = "../data.csv";
	candidates[2] = "./data.csv";
	for (int i = 0; i < 3; ++i)
	{
		std::ifstream file(candidates[i].c_str());
		if (file.is_open())
			return candidates[i];
	}
	return "data.csv";
}

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
	exchange.loadDatabase(findDatabasePath());

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
			std::cout << "Error: bad input => " << line << std::endl;
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
