#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>

class Enemy
{
	public:
		Enemy(int hp, std::string const &type);
		Enemy(Enemy const &obj);
		virtual ~Enemy();

		Enemy			&operator=(Enemy const &rhs);

		int				getHP() const;
		std::string		getType() const;

		virtual void	getDamage(int damage);
		
	protected:
		int				hp;

	private:
		Enemy();
		std::string		_type;
	
};

#endif