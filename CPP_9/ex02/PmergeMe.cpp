#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <stdexcept>

// Default constructor
PmergeMe::PmergeMe()
{
}

// Copy constructor
PmergeMe::PmergeMe(PmergeMe const & other) :
	_vector_sequence(other._vector_sequence),
	_deque_sequence(other._deque_sequence)
{
}

// Copy assignment operator
PmergeMe & PmergeMe::operator=(PmergeMe const & other)
{
	if (this != &other)
	{
		_vector_sequence = other._vector_sequence;
		_deque_sequence = other._deque_sequence;
	}
	return (*this);
	// *this: updated object with copied sequences
}

// Destructor
PmergeMe::~PmergeMe()
{
}

// Parses a single string token as a strictly positive integer.
// Throws std::runtime_error if the token is not a valid positive integer.
int	PmergeMe::parsePositiveInteger(std::string const & token) const
{
	if (token.empty())
		throw std::runtime_error("empty token.");
	for (size_t index = 0; index < token.size(); index++)
	{
		if (!std::isdigit(token[index]))
			throw std::runtime_error("invalid character in: " + token);
	}
	std::istringstream token_stream(token);
	long	parsed_value;
	token_stream >> parsed_value;
	if (token_stream.fail() || parsed_value <= 0)
		throw std::runtime_error("not a positive integer: " + token);
	return (static_cast<int>(parsed_value));
	// parsed_value: positive integer parsed from the token
}

// Reads command-line arguments and fills both internal sequences.
// Throws std::runtime_error if any argument is invalid.
void	PmergeMe::parseArguments(int argument_count, char **argument_values)
{
	for (int index = 1; index < argument_count; index++)
	{
		int	value = parsePositiveInteger(std::string(argument_values[index]));
		_vector_sequence.push_back(value);
		_deque_sequence.push_back(value);
	}
}

// Prints all elements of a vector on a single line, space-separated.
void	PmergeMe::printVector(std::vector<int> const & sequence) const
{
	for (size_t index = 0; index < sequence.size(); index++)
	{
		if (index > 0)
			std::cout << " ";
		std::cout << sequence[index];
	}
	std::cout << std::endl;
}

// Prints all elements of a deque on a single line, space-separated.
void	PmergeMe::printDeque(std::deque<int> const & sequence) const
{
	for (size_t index = 0; index < sequence.size(); index++)
	{
		if (index > 0)
			std::cout << " ";
		std::cout << sequence[index];
	}
	std::cout << std::endl;
}

// Computes the k-th Jacobsthal number using the recurrence:
// J(0)=0, J(1)=1, J(k)=J(k-1)+2*J(k-2)
// Returns the k-th value.
size_t	PmergeMe::jacobsthal(size_t k) const
{
	if (k == 0)
		return (0);
	if (k == 1)
		return (1);
	size_t	previous_previous = 0;
	size_t	previous = 1;
	size_t	current = 0;
	for (size_t step = 2; step <= k; step++)
	{
		current = previous + 2 * previous_previous;
		previous_previous = previous;
		previous = current;
	}
	return (current);
	// current: k-th Jacobsthal number
}

// Builds the insertion order index list for pending_count elements.
// Uses Jacobsthal groups: group k covers indices from J(k-1) to J(k)-1,
// inserted in descending order within each group.
// Returns the ordered list of indices into the pending array.
std::vector<size_t>	PmergeMe::buildJacobsthalOrder(size_t pending_count) const
{
	std::vector<size_t>	insertion_order;

	size_t	group_index = 1;
	size_t	group_start = 0;

	while (group_start < pending_count)
	{
		size_t	group_end = jacobsthal(group_index + 1);
		if (group_end > pending_count)
			group_end = pending_count;
		size_t	position = group_end;
		while (position > group_start)
		{
			insertion_order.push_back(position - 1);
			position--;
		}
		group_start = jacobsthal(group_index + 1);
		group_index++;
	}
	return (insertion_order);
	// insertion_order: list of indices into pending in Jacobsthal insertion order
}

// ─────────────────────────────────────────────────────────────
//  VECTOR implementation of Ford-Johnson
// ─────────────────────────────────────────────────────────────

// Inserts value into main_chain at the correct sorted position,
// only searching up to bound_pos (exclusive) using binary search.
void	PmergeMe::binaryInsertVector(
	std::vector<int> & main_chain,
	int value,
	size_t bound_pos
) const
{
	size_t	low = 0;
	size_t	high = bound_pos;

	while (low < high)
	{
		size_t	mid = low + (high - low) / 2;
		if (main_chain[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	main_chain.insert(main_chain.begin() + low, value);
	// main_chain: value inserted at the correct sorted position
}

// Sorts a vector of pairs in-place so that the second elements are sorted.
// The pair sorting is done by recursively calling fordJohnsonVector on the
// list of second elements, then reordering the original pairs accordingly.
void	PmergeMe::sortPairsVector(std::vector<std::pair<int, int> > & pairs) const
{
	size_t	pair_count = pairs.size();
	if (pair_count <= 1)
		return;

	std::vector<int>	second_elements;
	for (size_t index = 0; index < pair_count; index++)
		second_elements.push_back(pairs[index].second);

	fordJohnsonVector(second_elements);

	std::vector<std::pair<int, int> >	sorted_pairs;
	std::vector<bool>					used(pair_count, false);

	for (size_t sorted_index = 0; sorted_index < pair_count; sorted_index++)
	{
		int	target_second = second_elements[sorted_index];
		for (size_t original_index = 0; original_index < pair_count; original_index++)
		{
			if (!used[original_index] && pairs[original_index].second == target_second)
			{
				sorted_pairs.push_back(pairs[original_index]);
				used[original_index] = true;
				break;
			}
		}
	}
	pairs = sorted_pairs;
	// pairs: reordered so that second elements are in ascending sorted order
}

// Inserts all pending elements into main_chain using the Jacobsthal order.
// For each pending[idx], the search is bounded by the position of
// pairs[idx+1].second in main_chain (since pending[idx] < pairs[idx+1].second).
void	PmergeMe::insertPendingVector(
	std::vector<int> & main_chain,
	std::vector<int> const & pending,
	std::vector<std::pair<int, int> > const & pairs
) const
{
	std::vector<size_t>	insertion_order = buildJacobsthalOrder(pending.size());

	for (size_t order_index = 0; order_index < insertion_order.size(); order_index++)
	{
		size_t	pending_index = insertion_order[order_index];
		int		value_to_insert = pending[pending_index];

		// Find upper bound: the position of the corresponding b_{pending_index+1}
		// in main_chain. We know value_to_insert < pairs[pending_index+1].second.
		size_t	search_bound = main_chain.size();
		if (pending_index + 1 < pairs.size())
		{
			int	upper_bound_value = pairs[pending_index + 1].second;
			for (size_t chain_index = 0; chain_index < main_chain.size(); chain_index++)
			{
				if (main_chain[chain_index] == upper_bound_value)
				{
					search_bound = chain_index + 1;
					break;
				}
			}
		}
		binaryInsertVector(main_chain, value_to_insert, search_bound);
	}
}

// Sorts the given vector in-place using the Ford-Johnson merge-insert algorithm.
// Handles sequences of size 0, 1 (base cases), and arbitrary sizes.
void	PmergeMe::fordJohnsonVector(std::vector<int> & sequence) const
{
	size_t	element_count = sequence.size();
	if (element_count <= 1)
		return;

	// Handle the straggler (last element when size is odd)
	bool	has_straggler = (element_count % 2 != 0);
	int		straggler = 0;
	if (has_straggler)
	{
		straggler = sequence.back();
		sequence.pop_back();
		element_count--;
	}

	// Step 1: form pairs (a_i, b_i) where a_i <= b_i
	std::vector<std::pair<int, int> >	pairs;
	for (size_t index = 0; index < element_count; index += 2)
	{
		int	first_element = sequence[index];
		int	second_element = sequence[index + 1];
		if (first_element > second_element)
			std::swap(first_element, second_element);
		pairs.push_back(std::make_pair(first_element, second_element));
	}

	// Step 2: recursively sort pairs by their second (larger) element
	sortPairsVector(pairs);

	// Step 3: build main chain = [a_0, b_0, b_1, ..., b_{n-1}]
	std::vector<int>	main_chain;
	main_chain.push_back(pairs[0].first);
	for (size_t index = 0; index < pairs.size(); index++)
		main_chain.push_back(pairs[index].second);

	// Step 4: collect pending = [a_1, a_2, ..., a_{n-1}]
	std::vector<int>	pending;
	for (size_t index = 1; index < pairs.size(); index++)
		pending.push_back(pairs[index].first);

	// Step 5: insert pending elements in Jacobsthal order
	insertPendingVector(main_chain, pending, pairs);

	// Step 6: insert straggler if present
	if (has_straggler)
		binaryInsertVector(main_chain, straggler, main_chain.size());

	sequence = main_chain;
	// sequence: sorted in ascending order using Ford-Johnson algorithm
}

// ─────────────────────────────────────────────────────────────
//  DEQUE implementation of Ford-Johnson
// ─────────────────────────────────────────────────────────────

// Inserts value into main_chain at the correct sorted position,
// only searching up to bound_pos (exclusive) using binary search.
void	PmergeMe::binaryInsertDeque(
	std::deque<int> & main_chain,
	int value,
	size_t bound_pos
) const
{
	size_t	low = 0;
	size_t	high = bound_pos;

	while (low < high)
	{
		size_t	mid = low + (high - low) / 2;
		if (main_chain[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	main_chain.insert(main_chain.begin() + low, value);
	// main_chain: value inserted at the correct sorted position
}

// Sorts a deque of pairs in-place so that the second elements are sorted.
// Recursively calls fordJohnsonDeque on the list of second elements,
// then reorders the original pairs accordingly.
void	PmergeMe::sortPairsDeque(std::deque<std::pair<int, int> > & pairs) const
{
	size_t	pair_count = pairs.size();
	if (pair_count <= 1)
		return;

	std::deque<int>	second_elements;
	for (size_t index = 0; index < pair_count; index++)
		second_elements.push_back(pairs[index].second);

	fordJohnsonDeque(second_elements);

	std::deque<std::pair<int, int> >	sorted_pairs;
	std::vector<bool>					used(pair_count, false);

	for (size_t sorted_index = 0; sorted_index < pair_count; sorted_index++)
	{
		int	target_second = second_elements[sorted_index];
		for (size_t original_index = 0; original_index < pair_count; original_index++)
		{
			if (!used[original_index] && pairs[original_index].second == target_second)
			{
				sorted_pairs.push_back(pairs[original_index]);
				used[original_index] = true;
				break;
			}
		}
	}
	pairs = sorted_pairs;
	// pairs: reordered so that second elements are in ascending sorted order
}

// Inserts all pending elements into main_chain using the Jacobsthal order.
// Search for each element is bounded by the position of pairs[idx+1].second
// in main_chain, since pending[idx] < pairs[idx+1].second by construction.
void	PmergeMe::insertPendingDeque(
	std::deque<int> & main_chain,
	std::deque<int> const & pending,
	std::deque<std::pair<int, int> > const & pairs
) const
{
	std::vector<size_t>	insertion_order = buildJacobsthalOrder(pending.size());

	for (size_t order_index = 0; order_index < insertion_order.size(); order_index++)
	{
		size_t	pending_index = insertion_order[order_index];
		int		value_to_insert = pending[pending_index];

		size_t	search_bound = main_chain.size();
		if (pending_index + 1 < pairs.size())
		{
			int	upper_bound_value = pairs[pending_index + 1].second;
			for (size_t chain_index = 0; chain_index < main_chain.size(); chain_index++)
			{
				if (main_chain[chain_index] == upper_bound_value)
				{
					search_bound = chain_index + 1;
					break;
				}
			}
		}
		binaryInsertDeque(main_chain, value_to_insert, search_bound);
	}
}

// Sorts the given deque in-place using the Ford-Johnson merge-insert algorithm.
// Handles sequences of size 0, 1 (base cases), and arbitrary sizes.
void	PmergeMe::fordJohnsonDeque(std::deque<int> & sequence) const
{
	size_t	element_count = sequence.size();
	if (element_count <= 1)
		return;

	// Handle the straggler (last element when size is odd)
	bool	has_straggler = (element_count % 2 != 0);
	int		straggler = 0;
	if (has_straggler)
	{
		straggler = sequence.back();
		sequence.pop_back();
		element_count--;
	}

	// Step 1: form pairs (a_i, b_i) where a_i <= b_i
	std::deque<std::pair<int, int> >	pairs;
	for (size_t index = 0; index < element_count; index += 2)
	{
		int	first_element = sequence[index];
		int	second_element = sequence[index + 1];
		if (first_element > second_element)
			std::swap(first_element, second_element);
		pairs.push_back(std::make_pair(first_element, second_element));
	}

	// Step 2: recursively sort pairs by their second (larger) element
	sortPairsDeque(pairs);

	// Step 3: build main chain = [a_0, b_0, b_1, ..., b_{n-1}]
	std::deque<int>	main_chain;
	main_chain.push_back(pairs[0].first);
	for (size_t index = 0; index < pairs.size(); index++)
		main_chain.push_back(pairs[index].second);

	// Step 4: collect pending = [a_1, a_2, ..., a_{n-1}]
	std::deque<int>	pending;
	for (size_t index = 1; index < pairs.size(); index++)
		pending.push_back(pairs[index].first);

	// Step 5: insert pending elements in Jacobsthal order
	insertPendingDeque(main_chain, pending, pairs);

	// Step 6: insert straggler if present
	if (has_straggler)
		binaryInsertDeque(main_chain, straggler, main_chain.size());

	sequence = main_chain;
	// sequence: sorted in ascending order using Ford-Johnson algorithm
}

// ─────────────────────────────────────────────────────────────
//  Main run: sort both containers, print results and timing
// ─────────────────────────────────────────────────────────────

// Sorts both internal sequences using Ford-Johnson, measures elapsed time
// for each container, and prints before/after/timing output to stdout.
void	PmergeMe::run() const
{
	size_t	element_count = _vector_sequence.size();

	// Print unsorted sequence
	std::cout << "Before: ";
	printVector(_vector_sequence);

	// --- Sort with std::vector ---
	std::vector<int>	sorted_vector(_vector_sequence);
	clock_t				vector_start = clock();
	fordJohnsonVector(sorted_vector);
	clock_t				vector_end = clock();
	double				vector_duration =
		static_cast<double>(vector_end - vector_start)
		/ CLOCKS_PER_SEC * 1000000.0;
	// vector_duration: elapsed microseconds for the vector sort

	// --- Sort with std::deque ---
	std::deque<int>		sorted_deque(_deque_sequence);
	clock_t				deque_start = clock();
	fordJohnsonDeque(sorted_deque);
	clock_t				deque_end = clock();
	double				deque_duration =
		static_cast<double>(deque_end - deque_start)
		/ CLOCKS_PER_SEC * 1000000.0;
	// deque_duration: elapsed microseconds for the deque sort

	// Print sorted sequence (from vector result)
	std::cout << "After: ";
	printVector(sorted_vector);

	// Print timing
	std::cout << "Time to process a range of " << element_count
		<< " elements with std::vector : " << vector_duration << " us" << std::endl;
	std::cout << "Time to process a range of " << element_count
		<< " elements with std::deque  : " << deque_duration << " us" << std::endl;
}
