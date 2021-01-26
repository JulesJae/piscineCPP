#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

# define NUMBER_OF_SLOTS 4

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &obj);
		virtual ~MateriaSource();

		MateriaSource			&operator=(MateriaSource const &rhs);

		int						getIdx() const;
		void					learnMateria(AMateria *m);
		AMateria				*createMateria(std::string const &type);

		
	private:
		AMateria				*_materias[NUMBER_OF_SLOTS];
		int						_idx;
	
};

#endif