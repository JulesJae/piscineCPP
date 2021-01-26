#ifndef INTERPRETER_HPP
# define INTERPRETER_HPP
# define ARRAY_SIZE 30000

# include <string>
# include <vector>
# include <map>
# include "IInstruction.hpp"
# include "InstructionsFactory.hpp"

class Interpreter
{
	public:
		Interpreter(char *fileName);
		Interpreter(Interpreter const &obj);
		virtual ~Interpreter();

		Interpreter			&operator=(Interpreter const &rhs);

		void				readFile();
		void				interpretCode();

		
	private:
		Interpreter();
		std::vector<IInstruction*>				_instructionsQueue;
		std::vector<IInstruction*>::iterator	_pins;
		char									_array[ARRAY_SIZE];
		char									*_ptr;
		bool									_ready;
		char									*_fileName;
		InstructionsFactory						_factory;

		void									_rewind();
		void									_advance();

};

#endif