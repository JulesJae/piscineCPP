#include <iostream>
#include <fstream>

void	cat_file(char *filename)
{
	std::ifstream	file(filename);
	std::string		line;

	if (file.fail())
	{
		std::cout << "cato9tails: " << filename << ": Aucun fichier ou dossier de ce type\n";
		return ;
	}
	while (std::getline(file, line))
		std::cout << line << std::endl;
}

void	cat_console()
{
	std::string		line;

	while (1)
	{
		std::getline(std::cin, line);
		std::cout << line << std::endl;
	}
}

int		main(int ac, char *av[])
{
	int		i(1);

	if (ac > 1)
	{
		while (i < ac)
		{
			cat_file(av[i]);
			i++;
		}
	}
	else
		cat_console();
}