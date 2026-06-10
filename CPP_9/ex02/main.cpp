#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <climits>
#include <cerrno>
#include <cstdlib>

static std::vector<int> parseArgs(int ac, char **av)
{
	std::vector<int> nums;
	int i = 1;
	while (i < ac)
	{
		std::string token = av[i];
		if (token.empty())
			throw std::invalid_argument("empty token");
		size_t j = 0;
		while (j < token.size())
		{
			if (!std::isdigit(token[j]))
				throw std::invalid_argument("not a positive integer: " + token);
			j++;
		}
		errno = 0;
		long n = std::strtol(token.c_str(), NULL, 10);
		if (errno == ERANGE || n <= 0 || n > INT_MAX)
			throw std::out_of_range("out of range: " + token);
		nums.push_back(static_cast<int>(n));
		i++;
	}
	return nums;
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe sorter(parseArgs(ac, av));
		sorter.sortWithVect();
		sorter.sortWithDeque();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
