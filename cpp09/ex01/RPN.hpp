#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <sstream>
# include <iostream>
# include <cstdlib>
# include <stdexcept>

class RPN				//	Reverse Polish Notation
{
public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	static double evaluate(const std::string &expression);

private:
	static bool isOperator(const std::string &token);
	static bool isNumber(const std::string &token);
	static double applyOperation(char op, double lhs, double rhs);
};

#endif
