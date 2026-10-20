#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <cerrno>
# include <iomanip>

class BitcoinExchange
{
private:
	std::map<std::string, double> _rates;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &cpy);
	BitcoinExchange &operator=(const BitcoinExchange &cpy);
	~BitcoinExchange();

	void loadDatabase(const std::string &filename);
	double getRate(const std::string &date) const;
	double convert(const std::string &date, double amount) const;
};

#endif
