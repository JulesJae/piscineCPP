#include <iostream>
#include <iomanip>
#include <limits>
#include <cfloat>

void	print_negative_inf()
{
	std::cout <<
	"char: impossible\n"
	<< "int : ipossible\n"
	<< "float: -inff\n"
	<< "double: -inf\n";
}

void	print_positive_inf()
{
	std::cout <<
	"char: impossible\n"
	<< "int : ipossible\n"
	<< "float: +inff\n"
	<< "double: +inf\n";
}

void	print_nan()
{
	std::cout <<
	"char: impossible\n"
	<< "int : ipossible\n"
	<< "float: nanf\n"
	<< "double: nan\n";
}

void	print_char(long value)
{
	std::cout << "char: ";
	if (value > 31 && value < 127)
		std::cout << static_cast<char>(value);
	else if (value < 32 && value >= 0)
		std::cout << "Non displayable";
	else
		std::cout << "Impossible";
	std::cout << std::endl;
}

void	print_int(long value)
{
	std::cout << "int: ";
	if (value < INT32_MIN || value > __INT32_MAX__)
		std::cout << "Impossible";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;
}

void	print_float(long double value)
{
	std::cout << "float: ";
	if (value < - FLT_MAX + 1 || value > FLT_MAX)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << std::setprecision(1) << std::fixed << static_cast<float>(value) << "f" << std::endl;;
}

void	print_double(long double value)
{
	std::cout << "double: ";
	if (value < -DBL_MAX + 1 || value > DBL_MAX)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << std::setprecision(1) << std::fixed << static_cast<double>(value) << std::endl;;
}

int		main(int ac, char *av[])
{
	std::string		value;
	long double		valueld;
	long			valuel;

	if (ac != 2)
	{
		std::cout << "Usage: ./convert litteral\n";
		return (0);
	}
	value = av[1];
	if (value == "-inff" || value == "-inf")
		print_negative_inf();
	else if (value == "inff" || value == "inf")
		print_positive_inf();
	else if (value == "nan" || value == "nanf")
		print_nan();
	else
	{
		if (value.size() == 1 && (std::isprint(value[0]) && !std::isdigit(value[0])))
			valueld = static_cast<long double>(value[0]);
		else
		{
			if (value.at(value.size() - 1) == 'f')
				value = value.substr(0, value.size() - 1);
			valueld = std::stold(value);
		}
		valuel = static_cast<long>(valueld);
		
		print_char(valuel);
		print_int(valuel);
		print_float(valueld);
		print_double(valueld);
	}
	return (0);
}