#include "Span.hpp"

const char*	Span::SpanFullException::what() const throw()
{
	return ("Span is full, cannot add more numbers");
}

const char*	Span::NoSpanException::what() const throw()
{
	return ("Not enough numbers to compute a span (need at least 2)");
}

// Constructeur : définit la capacité max
Span::Span(unsigned int n) :
	_max(n)
{
}

// Copie
Span::Span(Span const & other) :
	_max(other._max),
	_numbers(other._numbers)
{
}

// Affectation
Span &	Span::operator=(Span const & other)
{
	if (this != &other)
	{
		_max = other._max;
		_numbers = other._numbers;
	}
	return (*this);
}

// Destructeur
Span::~Span()
{
}

// Ajoute un nombre, throw si capacité atteinte
void	Span::addNumber(int number)
{
	if (_numbers.size() >= (size_t)_max)
		throw SpanFullException();
	_numbers.push_back(number);
}

// Trie une copie et cherche le plus petit écart entre deux consécutifs
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

// Plus grand écart = max - min
int	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	int	minVal = *std::min_element(_numbers.begin(), _numbers.end());
	int	maxVal = *std::max_element(_numbers.begin(), _numbers.end());
	return (maxVal - minVal);
}
