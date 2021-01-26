#include "Logger.hpp"

int     main()
{
	Logger	logger("try.log");

	logger.log("logToConsole", "Console log");
	logger.log("logToFile", "FIle log");
	return (0);
}