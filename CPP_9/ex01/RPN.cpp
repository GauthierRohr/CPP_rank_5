#include "RPN.hpp"
#include <stack>
#include <list>
#include <sstream>
#include <stdexcept>
#include <cctype>

// Default constructor
RPN::RPN()
{
}

// Copy constructor
RPN::RPN(RPN const & other)
{
	(void)other;
}

// Copy assignment operator
RPN & RPN::operator=(RPN const & other)
{
	(void)other;
	return (*this);
	// *this: unchanged (no state to copy)
}

// Destructor
RPN::~RPN()
{
}

// Checks whether the token is a single digit character (0-9).
// Returns true if it is a valid number token.
bool	RPN::isNumber(std::string const & token) const
{
	if (token.size() != 1)
		return (false);
	return (std::isdigit(token[0]));
	// true: token is a single-digit number
}

// Checks whether the token is one of the four supported operators.
// Returns true if it is +, -, *, or /.
bool	RPN::isOperator(std::string const & token) const
{
	if (token.size() != 1)
		return (false);
	char	symbol = token[0];
	return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
	// true: token is a recognized operator
}

// Applies the arithmetic operator to the two operands.
// Throws std::runtime_error on division by zero.
// Returns the integer result of the operation.
int	RPN::applyOperator(char operation, int left_operand, int right_operand) const
{
	if (operation == '+')
		return (left_operand + right_operand);
	if (operation == '-')
		return (left_operand - right_operand);
	if (operation == '*')
		return (left_operand * right_operand);
	if (operation == '/')
	{
		if (right_operand == 0)
			throw std::runtime_error("division by zero.");
		return (left_operand / right_operand);
	}
	throw std::runtime_error("unknown operator.");
	// result: integer result of the arithmetic operation
}

// Parses and evaluates a full RPN expression string.
// Uses std::stack<int, std::list<int>> to process tokens.
// Throws std::runtime_error on any invalid token or malformed expression.
int	RPN::evaluate(std::string const & expression) const
{
	std::stack<int, std::list<int> >	operand_stack;
	std::istringstream					expression_stream(expression);
	std::string							token;

	while (expression_stream >> token)
	{
		if (isNumber(token))
		{
			operand_stack.push(token[0] - '0');
		}
		else if (isOperator(token))
		{
			if (operand_stack.size() < 2)
				throw std::runtime_error("invalid expression.");
			int	right_operand = operand_stack.top();
			operand_stack.pop();
			int	left_operand = operand_stack.top();
			operand_stack.pop();
			int	result = applyOperator(token[0], left_operand, right_operand);
			operand_stack.push(result);
		}
		else
		{
			throw std::runtime_error("invalid token: " + token);
		}
	}

	if (operand_stack.size() != 1)
		throw std::runtime_error("invalid expression.");

	return (operand_stack.top());
	// result: final value left on the stack after full evaluation
}
