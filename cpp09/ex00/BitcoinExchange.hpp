#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <exception>

class BitcoinExchange
{
private:
	std::map<std::string, double> _rates;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &cpy);
	BitcoinExchange &operator=(const BitcoinExchange &cpy);
	~BitcoinExchange();
};

#endif
