#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <utility>

// Class that sorts a sequence of positive integers using the Ford-Johnson
// merge-insert sort algorithm, implemented once with std::vector and once
// with std::deque. Displays timing information for both containers.
class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(PmergeMe const & other);
		PmergeMe & operator=(PmergeMe const & other);
		~PmergeMe();

		// Parse command-line arguments into the internal sequences.
		// Throws std::runtime_error on invalid input.
		void	parseArguments(int argument_count, char **argument_values);

		// Run the sort on both containers and display before/after + timing.
		void	run() const;

	private:
		std::vector<int>	_vector_sequence;
		std::deque<int>		_deque_sequence;

		// Parse a single string token as a positive integer.
		int		parsePositiveInteger(std::string const & token) const;

		// Print a vector sequence on one line (space-separated).
		void	printVector(std::vector<int> const & sequence) const;

		// Print a deque sequence on one line (space-separated).
		void	printDeque(std::deque<int> const & sequence) const;

		// --- Ford-Johnson sort for std::vector ---

		// Sort the given vector in-place using Ford-Johnson algorithm.
		void	fordJohnsonVector(std::vector<int> & sequence) const;

		// Build sorted pairs and recursively sort for vector.
		void	sortPairsVector(std::vector<std::pair<int, int> > & pairs) const;

		// Insert pending elements in Jacobsthal order into mainChain for vector.
		void	insertPendingVector(
			std::vector<int> & main_chain,
			std::vector<int> const & pending,
			std::vector<std::pair<int, int> > const & pairs
		) const;

		// Perform binary search insertion of value into main_chain up to bound_pos.
		void	binaryInsertVector(
			std::vector<int> & main_chain,
			int value,
			size_t bound_pos
		) const;

		// --- Ford-Johnson sort for std::deque ---

		// Sort the given deque in-place using Ford-Johnson algorithm.
		void	fordJohnsonDeque(std::deque<int> & sequence) const;

		// Build sorted pairs and recursively sort for deque.
		void	sortPairsDeque(std::deque<std::pair<int, int> > & pairs) const;

		// Insert pending elements in Jacobsthal order into mainChain for deque.
		void	insertPendingDeque(
			std::deque<int> & main_chain,
			std::deque<int> const & pending,
			std::deque<std::pair<int, int> > const & pairs
		) const;

		// Perform binary search insertion of value into main_chain up to bound_pos.
		void	binaryInsertDeque(
			std::deque<int> & main_chain,
			int value,
			size_t bound_pos
		) const;

		// --- Jacobsthal sequence helper ---

		// Returns the k-th Jacobsthal number (J(0)=0, J(1)=1, J(k)=J(k-1)+2*J(k-2)).
		size_t	jacobsthal(size_t k) const;

		// Build the insertion order for n pending elements using Jacobsthal sequence.
		std::vector<size_t>	buildJacobsthalOrder(size_t pending_count) const;
};

#endif
