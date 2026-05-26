#include "Span.hpp"

const char*	Span::SpanFullException::what() const throw()
{
	return ("Span is full, cannot add more numbers");
}

const char*	Span::NoSpanException::what() const throw()
{
	return ("Not enough numbers to compute a span (need at least 2)");
}

Span::Span(unsigned int n) :
	_max(n)
{
}

Span::Span(Span const & other) :
	_max(other._max),
	_numbers(other._numbers)
{
}

Span &	Span::operator=(Span const & other)
{
	if (this != &other)
	{
		_max = other._max;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int number)
{
	if (_numbers.size() >= (size_t)_max)
		throw SpanFullException();
	_numbers.push_back(number);
}

// Sort a copy, scan consecutive pairs for min gap
int	Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	std::vector<int>	sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());

	int	shortest = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size() - 1; i++)
	{
		int	diff = sorted[i + 1] - sorted[i];
		if (diff < shortest)
			shortest = diff;
	}
	return (shortest);
}

int	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	int	minVal = *std::min_element(_numbers.begin(), _numbers.end());
	int	maxVal = *std::max_element(_numbers.begin(), _numbers.end());
	return (maxVal - minVal);
}
