#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <climits>
#include <cerrno>
#include <cstdlib>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::vector<int> nums;
	try
	{
		for (int i = 1; i < ac; i++)
		{
			std::string token = av[i];
			for (size_t j = 0; j < token.size(); j++)
			{
				if (!std::isdigit(token[j]))
					throw std::invalid_argument("not a positive integer: " + token);
			}
			if (token.empty())
				throw std::invalid_argument("empty token");
			errno = 0;
			long n = std::strtol(token.c_str(), NULL, 10);
			if (errno == ERANGE || n <= 0 || n > INT_MAX)
				throw std::out_of_range("out of range: " + token);
			nums.push_back(static_cast<int>(n));
		}
		PmergeMe sorter(nums);
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
