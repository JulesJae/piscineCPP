#include <ctime>
#include <iostream>
#include <string>

struct Data
{
	std::string		s1;
	int				n;
	std::string		s2;
};

void    *serialize()
{
    char	*serialize;
	int		*intValue;

	serialize = new char[16 + sizeof(int)]();
	for (int i = 0; i < 7; i++)
	{
		int		random(std::rand() % 127);

		if (!std::isprint(random))
			random += ' ';
		serialize[i] = random;
	}
	serialize[7] = '\0';
	// std::cout << "mot = " << serialize << "\n";
	intValue = reinterpret_cast<int*>(&serialize[8]);
	*intValue = random();
	// std::cout << "intvalue = " << *intValue << "\n";
	for (unsigned long i = 8 + sizeof(int); i < 16 + sizeof(int) - 1; i++)
	{
		int		random(std::rand() % 127);

		if (!std::isprint(random))
			random += ' ';
		serialize[i] = random;
	}
	serialize[16 + sizeof(int) - 1] = '\0';
	// std::cout << "mot = " << &serialize[8 + sizeof(int)] << "\n";
	return serialize;
}

Data	*deserialize(void *raw)
{
	char	*serialize;
	Data	*data(new Data());

	serialize = reinterpret_cast<char*>(raw);
	data->s1 = std::string(serialize, 8);
	data->n = *reinterpret_cast<int*>(serialize + 8);
	data->s2 = std::string(serialize + 8 + sizeof(int), 8);
	return data;
}

int     main(void)
{
	void	*vdata;
	Data	*data;

	std::srand(std::time(nullptr));
	vdata = serialize();
	data = deserialize(vdata);
	std::cout << "s1 = " << data->s1 << " n = " << data->n << " s2 = " << data->s2 << std::endl;
    return (0);
}