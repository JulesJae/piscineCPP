#include "Brain.hpp"
#include <sstream>

Brain::Brain()
{

}

std::string Brain::identifier() const
{
	std::ostringstream	string_stream;

	string_stream << std::hex << this;
	return string_stream.str();
}