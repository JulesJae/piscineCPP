#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const &src);
		~Fixed();

		Fixed				&operator=(Fixed const &rhs);

		bool				operator==(Fixed const &rhs) const;
		bool				operator!=(Fixed const &rhs) const;
		bool				operator<(Fixed const &rhs) const;
		bool				operator>(Fixed const &rhs) const;
		bool				operator>=(Fixed const &rhs) const;
		bool				operator<=(Fixed const &rhs) const;

		Fixed				operator+(Fixed const &rhs);
		Fixed				operator-(Fixed const &rhs);
		Fixed				operator*(Fixed const &rhs);
		Fixed				operator/(Fixed const &rhs);

		Fixed				&operator++();
		Fixed				operator++(int);
		Fixed				&operator--();
		Fixed				operator--(int);


		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float               toFloat() const;
		int                 toInt() const;

		static Fixed 		&min(Fixed &u, Fixed &v);
        const static Fixed	&min(const Fixed &u, const Fixed &v);
        static Fixed		&max(Fixed &u, Fixed &v);
        const static Fixed	&max(const Fixed &u, const Fixed &v);

	private:
		int					_rawBits;
		static const int	_bits;
};

std::ostream				&operator<<(std::ostream &o, Fixed const &rhs);

#endif
