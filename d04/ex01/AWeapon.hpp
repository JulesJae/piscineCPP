#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <string>

class AWeapon
{
	public:
		AWeapon(std::string const &name, int apcost, int damage);
		AWeapon(AWeapon const &obj);
		virtual ~AWeapon();

		AWeapon			&operator=(AWeapon const &rhs);

		std::string		getName() const;
		int				getAPCost() const;
		int				getDamage() const;

		virtual void	attack() const = 0;

	protected:
		int				apcost;
		int				damage;

	private:
		AWeapon();
		std::string		_name;
};

#endif