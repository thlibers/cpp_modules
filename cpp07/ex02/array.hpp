#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array
{
private:
	T *data_;
	unsigned int size_;
public:
	Array() : data_(NULL), size_(0)
	{
	}

	Array(unsigned int n) : data_(new T[n]()), size_(n)
	{
	}

	Array(const Array &cpy) : data_(NULL), size_(0)
	{
		*this = cpy;
	}

	~Array()
	{
		delete[] data_;
	}

	Array &operator=(const Array &cpy)
	{
		if (this != &cpy)
		{
			delete[] data_;
			size_ = cpy.size_;
			if (size_ == 0)
				data_ = NULL;
			else
			{
				data_ = new T[size_];
				for (unsigned int i = 0; i < size_; i++)
					data_[i] = cpy.data_[i];
			}
		}
		return (*this);
	}
	
	T &operator[](unsigned int index)
	{
		if (index >= size_)
			throw std::out_of_range("Index out of bounds");
		return (data_[index]);
	}

	const T &operator[](unsigned int index) const
	{
		if (index >= size_)
			throw std::out_of_range("Index out of bounds");
		return (data_[index]);
	}

	unsigned int size(void) const
	{
		return (size_);
	}
};

#endif