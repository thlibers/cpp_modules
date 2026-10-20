#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

bool PmergeMe::isValidNumber(const std::string &token, long &value)
{
	if (token.empty())
		return false;
	char *end = NULL;
	errno = 0;
	value = std::strtol(token.c_str(), &end, 10);
	if (end == token.c_str() || *end != '\0' || errno == ERANGE)
		return false;
	if (value <= 0)
		return false;
	return true;
}

static void mergeVector(std::vector<int> &array, std::size_t left, std::size_t mid, std::size_t right)
{
	std::vector<int> leftPart;
	std::vector<int> rightPart;
	for (std::size_t i = left; i <= mid; ++i)
		leftPart.push_back(array[i]);
	for (std::size_t i = mid + 1; i <= right; ++i)
		rightPart.push_back(array[i]);

	std::size_t i = 0;
	std::size_t j = 0;
	std::size_t k = left;
	while (i < leftPart.size() && j < rightPart.size())
	{
		if (leftPart[i] <= rightPart[j])
			array[k++] = leftPart[i++];
		else
			array[k++] = rightPart[j++];
	}
	while (i < leftPart.size())
		array[k++] = leftPart[i++];
	while (j < rightPart.size())
		array[k++] = rightPart[j++];
}

static void mergeSortVector(std::vector<int> &array, std::size_t left, std::size_t right)
{
	if (left >= right)
		return;
	std::size_t mid = left + (right - left) / 2;
	mergeSortVector(array, left, mid);
	mergeSortVector(array, mid + 1, right);
	mergeVector(array, left, mid, right);
}

std::vector<int> PmergeMe::sortVector(const std::vector<int> &input)
{
	std::vector<int> sorted = input;
	if (sorted.size() <= 1)
		return sorted;
	mergeSortVector(sorted, 0, sorted.size() - 1);
	return sorted;
}

static void mergeDeque(std::deque<int> &array, std::size_t left, std::size_t mid, std::size_t right)
{
	std::deque<int> leftPart;
	std::deque<int> rightPart;
	for (std::size_t i = left; i <= mid; ++i)
		leftPart.push_back(array[i]);
	for (std::size_t i = mid + 1; i <= right; ++i)
		rightPart.push_back(array[i]);

	std::size_t i = 0;
	std::size_t j = 0;
	std::size_t k = left;
	while (i < leftPart.size() && j < rightPart.size())
	{
		if (leftPart[i] <= rightPart[j])
			array[k++] = leftPart[i++];
		else
			array[k++] = rightPart[j++];
	}
	while (i < leftPart.size())
		array[k++] = leftPart[i++];
	while (j < rightPart.size())
		array[k++] = rightPart[j++];
}

static void mergeSortDeque(std::deque<int> &array, std::size_t left, std::size_t right)
{
	if (left >= right)
		return;
	std::size_t mid = left + (right - left) / 2;
	mergeSortDeque(array, left, mid);
	mergeSortDeque(array, mid + 1, right);
	mergeDeque(array, left, mid, right);
}

std::deque<int> PmergeMe::sortDeque(const std::deque<int> &input)
{
	std::deque<int> sorted = input;
	if (sorted.size() <= 1)
		return sorted;
	mergeSortDeque(sorted, 0, sorted.size() - 1);
	return sorted;
}
