#include <iostream>
#include <string>
#include <fstream>

void	replace(std::ifstream &input, std::ofstream &output, std::string &old, std::string &news)
{
	std::string		line;
	std::size_t		found;
	int				pos;

	while (std::getline(input, line))
	{
		pos = 0;
		while ((found = line.find(old, pos)) != std::string::npos)
		{
			pos = found + old.size();
			line.replace(found, old.size(), news);
		}
		output << line << std::endl;
	}
}

int		main(int ac, char *av[])
{
	std::ifstream	input_file;
	std::ofstream	output_file;
	std::string		oldstr;
	std::string		newstr;

	if (ac < 4)
	{
		std::cout << "usage: ./replace file old new" << std::endl;
		return (0);
	}
	input_file = std::ifstream(av[1]);
	if (input_file.fail())
	{
		std::cout << av[1] << ": can't read file\n";
		return (0);
	}
	oldstr = std::string(av[2]);
	newstr = std::string(av[3]);
	output_file = std::ofstream(std::string(av[1]) + ".replace");
	replace(input_file, output_file, oldstr, newstr);
	return (0);
}