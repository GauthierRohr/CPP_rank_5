#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <iterator>

class Span
{
public:
	class SpanFullException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};

	Span(unsigned int n);
	Span(Span const & other);
	Span &	operator=(Span const & other);
	~Span();

	// Add number; throw if full
	void	addNumber(int number);

	// Bulk-insert from iterator range
	template <typename Iterator>
	void	addRange(Iterator begin, Iterator end)
	{
		size_t	count = (size_t)std::distance(begin, end);

		if (_numbers.size() + count > (size_t)_max)
			throw SpanFullException();
		_numbers.insert(_numbers.end(), begin, end);
	}

	// Smallest gap between any two numbers
	int	shortestSpan() const;

	// Largest gap (max - min)
	int	longestSpan() const;

private:
	unsigned int		_max;
	std::vector<int>	_numbers;
};

#endif
