#include "Logger.hpp"
#include <iostream>
#include <fstream>
#include <ctime>


Logger::fnMember Logger::_fn[2] = {
	&Logger::logToConsole,
	&Logger::logToFile,
};

std::string Logger::_fnNames[2] = {
	"logToConsole",
	"logToFile",
};

Logger::Logger(std::string const filename): _filename(filename) {}

void Logger::log(std::string const &dest, std::string const &message)
{
	int		i(0);

	while (i < 2)
	{
		if (Logger::_fnNames[i] == dest)
		{
			(this->*(Logger::_fn)[i])(message);
			break;
		}
		i++;
	}
}

std::string *Logger::makeLogEntry(std::string const &str) const
{
	std::string     *log;
	time_t          rawtime;
	tm              *timeinfo;
	char			buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
	log = new std::string(buffer);
	*log += " __";
	*log += str;
	return log;
}

void Logger::logToConsole(std::string const &str) const
{
	std::string	*log;

	log = this->makeLogEntry(str);
	std::cout << *log << std::endl;
	delete log;
}

void Logger::logToFile(std::string const &str) const
{
	std::string		*log;
	std::ofstream	file(this->_filename, std::ios::app);

	log = this->makeLogEntry(str);
	file << *log << std::endl;
	delete log;
}

