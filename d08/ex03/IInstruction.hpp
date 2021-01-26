#ifndef IINSTRUCTION_HPP
# define IINSTRUCTION_HPP

# include <string>

class IInstruction
{
	public:
		static enum		e_return {
			OK,
			REWIND,
			ADVANCE
		}			ret;

		virtual ~IInstruction(){};
		virtual int	exec() = 0;

		char			getType() { return this->_type; }

	protected:
		char			_type;
};

#endif