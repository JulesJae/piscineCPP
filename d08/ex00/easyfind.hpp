#include <algorithm>
#include <exception>

template< typename Container >
int			easyfind(Container &container, int value)
{
	typename Container::iterator	finded(std::find(container.begin(), container.end(), value));

	if (finded == container.end())
		throw std::exception();
	return (*finded);
};