#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

class PmergeMe
{
	std::vector<int> _vect;
	std::deque<int>  _deque;

	std::vector<size_t> jacobsthalOrder(size_t len);

	template <typename C>
	typename C::iterator binarySearch(C &chain, int val, int partner)
	{
		size_t lo = 0;
		size_t hi = 0;
		size_t i = 0;
		while (i < chain.size())
		{
			if (chain[i] == partner)
			{
				hi = i;
				break;
			}
			i++;
		}
		while (lo < hi)
		{
			size_t mid = lo + (hi - lo) / 2;
			if (chain[mid] < val)
				lo = mid + 1;
			else
				hi = mid;
		}
		return chain.begin() + lo;
	}

	template <typename C>
	C mergeInsert(C seq)
	{
		if (seq.size() <= 1)
			return seq;
		bool odd = seq.size() % 2 != 0;
		int straggler = -1;
		if (odd)
			straggler = seq.back();

		std::vector<std::pair<int, int> > pairs;
		size_t i = 0;
		while (i + 1 < seq.size())
		{
			if (seq[i] >= seq[i + 1])
				pairs.push_back(std::make_pair(seq[i], seq[i + 1]));
			else
				pairs.push_back(std::make_pair(seq[i + 1], seq[i]));
			i += 2;
		}

		C larger;
		C smaller;
		i = 0;
		while (i < pairs.size())
		{
			larger.push_back(pairs[i].first);
			smaller.push_back(pairs[i].second);
			i++;
		}

		larger = mergeInsert(larger);

		std::vector<size_t> order = jacobsthalOrder(smaller.size());
		i = 0;
		while (i < order.size())
		{
			size_t idx = order[i];
			typename C::iterator pos = binarySearch(larger, smaller[idx], pairs[idx].first);
			larger.insert(pos, smaller[idx]);
			i++;
		}
		if (odd)
		{
			typename C::iterator pos = std::lower_bound(larger.begin(), larger.end(), straggler);
			larger.insert(pos, straggler);
		}
		return larger;
	}

	template <typename C>
	void printContainer(C &c, std::string label)
	{
		std::cout << label;
		size_t i = 0;
		while (i < c.size())
		{
			if (i > 0)
				std::cout << " ";
			std::cout << c[i];
			i++;
		}
		std::cout << std::endl;
	}

public:
	PmergeMe(std::vector<int> args);
	PmergeMe(const PmergeMe &o);
	PmergeMe &operator=(const PmergeMe &o);
	~PmergeMe();
	void sortWithVect();
	void sortWithDeque();
};
