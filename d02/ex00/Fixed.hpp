#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
    public:
        Fixed(void);
        Fixed(Fixed const &src);
        ~Fixed();

        Fixed				&operator=(Fixed const &rhs);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);

    private:
        int					_rawBits;
        static const int	bytes;
};

#endif
