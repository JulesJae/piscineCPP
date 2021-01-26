#include "Pony.hpp"
#include <string>
#include <iostream>

Pony::Pony(std::string name, int age, int weight, e_color color):name(name), age(age), weight(weight), color(color)
{
	std::cout << "A PONY " << name << " has BEEN created, located at: " << this << std::endl;
}

Pony::~Pony()
{
	std::cout << name << " PONY has BEEN destroyed!\n";
}

void Pony::jump() const
{
	std::cout << "INCREDIBLE " << this->name << " just did an amazing JUMP\n";
}