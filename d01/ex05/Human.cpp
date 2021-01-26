#include "Human.hpp"
#include <string>

Human::Human(): _brain(new Brain())
{
}

std::string Human::identifier() const
{
    return this->_brain->identifier();
}

Brain const &Human::getBrain()
{
    return *this->_brain;
}