#ifndef LOGGER_HPP
# define LOGGER_HPP

#include <string>


class Logger
{
	typedef void (Logger::* fnMember)(std::string const &str) const;

	public:
		Logger(std::string const filename);
		void			log(std::string const &dest, std::string const &message);

	private:
		static fnMember		_fn[2];
		static std::string	_fnNames[2];
		std::string const 	_filename;
		void            	logToConsole(std::string const &str) const;
		void            	logToFile(std::string const &str) const;
		std::string     	*makeLogEntry(std::string const &str) const;
};

#endif
