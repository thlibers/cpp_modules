#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack() : std::stack<T>()
	{
	}

	~MutantStack()
	{
	}

	MutantStack(const MutantStack &other) : std::stack<T>(other)
	{
	}
	
	MutantStack &operator=(const MutantStack &other)
	{
		if (this != &other)
			std::stack<T>::operator=(other);
		return (*this);
	}

	iterator begin(void)
	{
		return (this->c.begin());
	}

	iterator end(void)
	{
		return (this->c.end());
	}

	iterator begin(void) const
	{
		return (this->c.begin());
	}

	iterator end(void) const
	{
		return (this->c.end());
	}

	iterator rbegin(void)
	{
		return (this->c.rbegin());
	}

	iterator rend(void)
	{
		return (this->c.rend());
	}

	iterator rbegin(void) const
	{
		return (this->c.rbegin());
	}

	iterator rend(void) const
	{
		return (this->c.rend());
	}
};

#endif
