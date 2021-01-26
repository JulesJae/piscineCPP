#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() 
{
	for (int i = 0; i < NUMBER_OF_SLOTS; i++)
		this->_materias[i] = nullptr;
	this->_idx = 0;
	std::cout << "Materia source has been constructed\n";
}

MateriaSource::MateriaSource(MateriaSource const &obj)
{
	*this = obj;
}

MateriaSource::~MateriaSource()
{
	std::cout << "Materia source has been constructed\n";
}

int						MateriaSource::getIdx() const { return this->_idx; }

void					MateriaSource::learnMateria(AMateria *m)
{
	this->_materias[this->_idx] = m->clone();
	this->_idx++;
}

AMateria				*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < this->_idx; i++)
		if (this->_materias[i]->getType() == type)
			return this->_materias[i]->clone();
	std::cout << type << ": don't learn\n";
	return nullptr;
}

MateriaSource			&MateriaSource::operator=(MateriaSource const &rhs)
{
	for (int i = 0; i < this->_idx; i++)
		delete this->_materias[i];
	for (int i = 0; i < rhs.getIdx(); i++)
		this->_materias[i] = rhs._materias[i]->clone();
	this->_idx = rhs.getIdx();
	return *this;
}
