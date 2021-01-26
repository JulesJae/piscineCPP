#include <iostream>
#include "Array.hpp"

template< typename T>
void		printArray(Array<T> &arr)
{
	unsigned int	size(arr.size());

	for (unsigned int i = 0; i < size; i++)
		std::cout << "[" << i << "] => " << arr[i] << "\n";
}

int			main()
{
	Array<int>				i;
	Array<std::string>		s(4);
	Array<std::string>		s2(5);
	Array<float>			f(5);

	try
	{
		std::cout << "\n FLOAT ! \n\n";

		f[0] = 0.05;
		f[1] = 0.02;
		f[2] = 10.04;
		f[3] = 42.001;
		f[4] = 18.55;
		printArray(f);

		std::cout << "\n STR ! \n\n";

		s[0] = "Vive";
		s[1] = "Le";
		s[2] = "CPP";
		s[3] = "!!!";
		printArray(s);

		s2[0] = "On";
		s2[1] = "Est";
		s2[2] = "Vraiment";
		s2[3] = "Des";
		s2[4] = "Geekoss !!";

		std::cout << "\n Reaffectation ! \n\n";
		s = s2;
		printArray(s);
		f[5] = 2873.8;
		std::cout << "No problemos Oo\n";
	} catch (std::exception const &e)
	{
		std::cout << "Nice Catch\n";
	}
	
}