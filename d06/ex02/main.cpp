#include <iostream>

class Base
{
	public:
		virtual ~Base(){};
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

void		identify_from_pointer(Base *p)
{
	A	*a = dynamic_cast<A*>(p);
	B	*b = dynamic_cast<B*>(p);
	C	*c = dynamic_cast<C*>(p);

	if (a != nullptr)
		std::cout << "A\n";
	else if (b != nullptr)
		std::cout << "B\n";
	else if (c != nullptr)
		std::cout << "C\n";
}

void		identify_from_reference(Base &r)
{
	try
	{
		A	&a = dynamic_cast<A&>(r);
		r = dynamic_cast<Base&>(a);
		std::cout << "A\n";
	}catch (const std::exception &e)
	{
		try
		{
			B	&b = dynamic_cast<B&>(r);
			r = dynamic_cast<Base&>(b);
			std::cout << "B\n";
		}
		catch(const std::exception& e)
		{
			try
			{
				C	&c = dynamic_cast<C&>(r);
				r = dynamic_cast<Base&>(c);
				std::cout << "C\n";
			}
			catch(const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		
	}
}

int			main()
{
	A	a;
	B	b;
	C	c;

	std::cout << "\n PTR\n\n";
	identify_from_pointer(&b);
	identify_from_pointer(&c);
	identify_from_pointer(&a);
	std::cout << "\n REFERENCE\n\n";
	identify_from_reference(a);
	identify_from_reference(b);
	identify_from_reference(c);
}