#include "PmergeMe.hpp"

static void printVector(const std::vector<int> &values)
{
	for (std::size_t i = 0; i < values.size(); ++i)
	{
		std::cout << values[i];
		if (i + 1 < values.size())
			std::cout << ' ';
	}
	std::cout << std::endl;
}

static std::deque<int> toDeque(const std::vector<int> &values)
{
	std::deque<int> result;
	for (std::size_t i = 0; i < values.size(); ++i)
		result.push_back(values[i]);
	return result;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::vector<int> before;
	for (int i = 1; i < argc; ++i)
	{
		long value = 0;
		if (!PmergeMe::isValidNumber(argv[i], value))
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		before.push_back(static_cast<int>(value));
	}

	std::cout << "Before: ";
	printVector(before);

	std::clock_t vectorStart = std::clock();
	std::vector<int> vectorSorted = PmergeMe::sortVector(before);
	std::clock_t vectorEnd = std::clock();

	std::clock_t dequeStart = std::clock();
	std::deque<int> dequeSorted = PmergeMe::sortDeque(toDeque(before));
	std::clock_t dequeEnd = std::clock();

	std::cout << "After: ";
	printVector(vectorSorted);

	double vectorTime = static_cast<double>(vectorEnd - vectorStart) / CLOCKS_PER_SEC * 1000000.0;
	double dequeTime = static_cast<double>(dequeEnd - dequeStart) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "Time to process a range of " << before.size() << " elements with std::vector : "
		<< vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << before.size() << " elements with std::deque : "
		<< dequeTime << " us" << std::endl;

	(void)dequeSorted;
	return 0;
}
