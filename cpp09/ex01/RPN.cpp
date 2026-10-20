#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return *this;
}

RPN::~RPN()
{
}

bool RPN::isOperator(const std::string &token)
{
	return (token == "+" || token == "-" || token == "/" || token == "*");
}

bool RPN::isNumber(const std::string &token)
{
	if (token.empty())
		return false;
	std::string::size_type start = 0;
	if (token[0] == '-')
	{
		if (token.size() == 1)
			return false;
		start = 1;
	}
	else if (token[0] == '+')
		return false;
	for (std::string::size_type i = start; i < token.size(); ++i)
	{
		if (token[i] < '0' || token[i] > '9')
			return false;
	}
	return true;
}

double RPN::applyOperation(char op, double lhs, double rhs)
{
	switch (op)
	{
		case '+':
			return lhs + rhs;
		case '-':
			return lhs - rhs;
		case '*':
			return lhs * rhs;
		case '/':
			if (rhs == 0)
				throw std::runtime_error("division by zero");
			return lhs / rhs;
		default:
			throw std::runtime_error("invalid operator");
	}
}

double RPN::evaluate(const std::string &expression)
{
	std::istringstream stream(expression);
	std::stack<double> numbers;
	std::string token;

	while (stream >> token)
	{
		if (isNumber(token))
		{
			char *end = NULL;
			double value = std::strtod(token.c_str(), &end);
			if (end == token.c_str() || *end != '\0')
				throw std::runtime_error("invalid number");
			numbers.push(value);
		}
		else if (isOperator(token))
		{
			if (numbers.size() < 2)
				throw std::runtime_error("not enough operands");
			double rhs = numbers.top();
			numbers.pop();
			double lhs = numbers.top();
			numbers.pop();
			numbers.push(applyOperation(token[0], lhs, rhs));
		}
		else
			throw std::runtime_error("invalid token");
	}
	if (numbers.size() != 1)
		throw std::runtime_error("invalid expression");
	return numbers.top();
}
