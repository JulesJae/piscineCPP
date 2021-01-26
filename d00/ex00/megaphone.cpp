#include <iostream>
#include <string>

std::string      toUpper(std::string min)
{
    unsigned long	i;
    std::string			maj;

    i = 0;
    maj = min;
    while (i < min.length())
    {
        maj[i] = toupper(min[i]);
        i++;
    }
    return maj;
}

int main(int ac, char *av[])
{
    int     i;

    i = 1;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else 
	{
    	while (i < ac)
    	{
    	    std::cout << toUpper(av[i]);
    	    i++;
    	}
	}
    std::cout << std::endl;
    return (0);
}