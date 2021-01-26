#include <iostream>

template< typename T >
void        iter(T arr[], int size, void (*fn)(T elem, int i))
{
	for (int i = 0; i < size; i++)
		(*fn)(arr[i], i);
}

template< typename T >
void        fn(T elem, int i)
{
	std::cout << "[" << i << "] => " << elem << "\n";
}

int         main()
{
	bool        b[6] = { true, false, true, false, false, false };
	std::string s[6] = {"Le", "CPP", "C'est", "Vraiment", "trop", "Funky"};
	int         i[8] = {12, 24, 65, 86, 45, 42, 765, 96059 };
	float       f[8] = {1.34, 2.4, 0.65, 0.0086, 0.45, 15.42, 76.5, 960.59 };

	::iter(b, 6, fn);
	std::cout << "\n";
	::iter(s, 6, fn);
	std::cout << "\n";
	::iter(i, 8, fn);
	std::cout << "\n";
	::iter(f, 6, fn);
	return (0);
}