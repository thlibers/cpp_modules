#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <cstdlib>
# include <cerrno>
# include <iostream>
# include <stdexcept>
# include <ctime>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	static std::vector<int> sortVector(const std::vector<int> &input);
	static std::deque<int> sortDeque(const std::deque<int> &input);
	static bool isValidNumber(const std::string &token, long &value);
};

#endif
