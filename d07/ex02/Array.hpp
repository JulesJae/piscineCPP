#include <exception>

template< typename T >
class Array
{
	public:
		Array()
		{
			this->_array = new T[0];
			this->_size = 0;
		}

		Array(unsigned int size)
		{
			this->_array = new T[size];
			this->_size = size;
		}

		Array(Array<T> &arr)
		{
			*this = arr;
		}

		~Array()
		{
			delete[] this->_array;
		}

		unsigned int	size() { return this->_size; }

		Array<T>		&operator=(Array<T> &rhs)
		{
			if (this == &rhs)
				return *this;
			if (this->_size >= 0)
				delete[] this->_array;
			this->_size = rhs.size();
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = rhs[i];
			return *this;
		}

		T				&operator[](unsigned int index)
		{
			if (index >= this->_size)
				throw std::exception();
			return this->_array[index];
		}

	private:
		T       		*_array;
		unsigned int	_size;

};