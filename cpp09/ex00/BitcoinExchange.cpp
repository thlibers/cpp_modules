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

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) : _rates(cpy._rates)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
	if (this != &cpy)
		_rates = cpy._rates;
	return (*this);
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		return;

	std::string line;
	if (!std::getline(file, line))
		return;

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		std::string::size_type comma = line.find(',');
		if (comma == std::string::npos)
			continue;
		std::string date = trim(line.substr(0, comma));
		std::string rateStr = trim(line.substr(comma + 1));
		if (!isValidDate(date))
			continue;
		char *end = NULL;
		errno = 0;
		double rate = std::strtod(rateStr.c_str(), &end);
		if (end == rateStr.c_str() || *end != '\0' || errno == ERANGE)
			continue;
		_rates[date] = rate;
	}
}

double BitcoinExchange::getRate(const std::string &date) const
{
	if (_rates.empty())
		return -1.0;

	std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);
	if (it == _rates.end())
	{
		--it;
		return it->second;
	}
	if (it->first == date)
		return it->second;
	if (it == _rates.begin())
		return -1.0;
	--it;
	return it->second;
}

double BitcoinExchange::convert(const std::string &date, double amount) const
{
	double rate = getRate(date);
	if (rate < 0.0)
		return -1.0;
	return amount * rate;
}
