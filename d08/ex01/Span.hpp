#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <vector>

class Span
{
	public:
		Span(unsigned int n);
		Span(Span const &obj);
		virtual ~Span();

		Span			&operator=(Span const &rhs);

		void			addNumber(int i);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			printSortedArray();
		
	private:
		unsigned int		_maxSize;
		std::vector<int>	_v;
		unsigned int		_vIdx;
		bool				_sorted;

		Span();
	
};

#endif