#include "Interpreter.class.hpp"
#include "InstructionsFactory.hpp"
#include "IInstruction.hpp"
#include <fstream>
#include <iostream>
#include <exception>

Interpreter::Interpreter(char *fileName) 
{
	this->_fileName = fileName;
	this->_ready = false;
	for (int i = 0; i < ARRAY_SIZE; i++)
		this->_array[i] = '\0';
	this->_ptr = this->_array;
}

Interpreter::Interpreter(Interpreter const &obj)
{
	*this = obj;
}

Interpreter::~Interpreter()
{

}

void				Interpreter::readFile()
{
	std::ifstream	fileStream(this->_fileName);
	IInstruction	*inst;
	char			character;

	if (fileStream)
	{
		while (fileStream.get(character))
		{
			inst = this->_factory.create(character, &this->_ptr);
			if (!inst)
				throw std::runtime_error("Invalid character detected");
			this->_instructionsQueue.push_back(inst);
		}
		std::cout << "Total Instructions in queue: " << this->_instructionsQueue.size() << "\n";
	}else
		throw std::runtime_error("Could not open file");
}

void				Interpreter::_rewind()
{
	int			bracket(1);
	char		type;
	std::vector<IInstruction*>::iterator	it(this->_instructionsQueue.begin());

	this->_pins--;
	while (!(bracket == 0 || this->_pins == it))
	{
		type = (*this->_pins)->getType();
		// std::cout << "tour rewind TYPE = " << type << " brackt = " << bracket << "\n";
		if (type == ']')
			bracket++;
		else if (type == '[')
			bracket--;
		if (bracket != 0)
			this->_pins--;
	}
	if (this->_pins == it)
		throw std::runtime_error("Unmatched bracket");
}

void				Interpreter::_advance()
{
	int			bracket = 1;
	char		type;
	std::vector<IInstruction*>::iterator	it(this->_instructionsQueue.end());

	this->_pins++;
	while (!(bracket == 0 || this->_pins == it))
	{
		type = (*this->_pins)->getType();
		if (type == '[')
			bracket++;
		else if (type == ']')
			bracket--;
		if (bracket != 0)
			this->_pins++;
	}
	if (this->_pins == it)
		throw std::runtime_error("Unmatched bracket");
}

void				Interpreter::interpretCode()
{
	int		ret;

	if (this->_instructionsQueue.empty())
		throw std::runtime_error("Call readFile() first");
	this->_pins = this->_instructionsQueue.begin();
	while (this->_pins != this->_instructionsQueue.end())
	{
		ret = (*this->_pins)->exec();
		if (ret == IInstruction::REWIND)
			this->_rewind();
		else if (ret == IInstruction::ADVANCE)
			this->_advance();
		this->_pins++;
	}
}

Interpreter			&Interpreter::operator=(Interpreter const &rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}
