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

	const_iterator begin(void) const
	{
		return (this->c.begin());
	}

	const_iterator end(void) const
	{
		return (this->c.end());
	}

	reverse_iterator rbegin(void)
	{
		return (this->c.rbegin());
	}

	reverse_iterator rend(void)
	{
		return (this->c.rend());
	}

	const_reverse_iterator rbegin(void) const
	{
		return (this->c.rbegin());
	}

	const_reverse_iterator rend(void) const
	{
		return (this->c.rend());
	}
};

#endif
