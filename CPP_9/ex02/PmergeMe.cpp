#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<int> args) : _vect(args), _deque(args.begin(), args.end())
{
	printContainer(_vect, "Before: ");
}

PmergeMe::PmergeMe(const PmergeMe &o) : _vect(o._vect), _deque(o._deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &o)
{
	if (this != &o)
	{
		_vect = o._vect;
		_deque = o._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

// J(n) = J(n-1) + 2*J(n-2) → 0, 1, 1, 3, 5, 11, 21...
// Builds insertion order: group k covers [J(k-1), J(k)[, inserted descending.
std::vector<size_t> PmergeMe::jacobsthalOrder(size_t len)
{
	std::vector<size_t> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	while (jacob.back() < len)
		jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);

	std::vector<size_t> order;
	order.push_back(0);
	for (size_t k = 2; k < jacob.size(); k++)
	{
		size_t hi = std::min(jacob[k], len) - 1;
		size_t lo = jacob[k - 1];
		for (size_t idx = hi; idx >= lo && idx < len; idx--)
		{
			if (idx != 0)
				order.push_back(idx);
			if (idx == 0)
				break;
		}
	}
	return order;
}

void PmergeMe::sortWithVect()
{
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	_vect = mergeInsert(_vect);
	clock_gettime(CLOCK_MONOTONIC, &end);
	printContainer(_vect, "After:  ");
	double elapsed = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_nsec - start.tv_nsec) / 1e3;
	std::cout << "Time to process a range of " << _vect.size()
		<< " elements with std::vector : " << elapsed << " us" << std::endl;
}

void PmergeMe::sortWithDeque()
{
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	_deque = mergeInsert(_deque);
	clock_gettime(CLOCK_MONOTONIC, &end);
	double elapsed = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_nsec - start.tv_nsec) / 1e3;
	std::cout << "Time to process a range of " << _deque.size()
		<< " elements with std::deque  : " << elapsed << " us" << std::endl;
}
