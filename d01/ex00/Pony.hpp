#ifndef PONY_H
# define PONY_H

#include <string>

class Pony
{
	public:
		std::string     name;
		int             age;
		int             weight;
		enum e_color
		{
						ORANGE,
						RED,
						BROWN,
						OTHER,
		}				color;
		
		Pony(std::string name, int age, int weight, e_color color);
		~Pony();
		void			jump(void) const;
};

#endif