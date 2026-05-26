#ifndef RPN_HPP
# define RPN_HPP

# include <string>

// Class that evaluates a Reverse Polish Notation expression.
// Uses std::stack<int, std::list<int>> as the underlying container.
class RPN
{
	public:
		RPN();
		RPN(RPN const & other);
		RPN & operator=(RPN const & other);
		~RPN();

		// Evaluate the RPN expression string and return the result.
		// Throws std::runtime_error on invalid input or malformed expression.
		int	evaluate(std::string const & expression) const;

	private:
		// Returns true if the token is a valid single-digit number (< 10).
		bool	isNumber(std::string const & token) const;

		// Returns true if the token is a valid operator (+ - * /).
		bool	isOperator(std::string const & token) const;

		// Applies the operator to the two operands and returns the result.
		// Throws std::runtime_error on division by zero.
		int	applyOperator(char operation, int left_operand, int right_operand) const;
};

#endif
