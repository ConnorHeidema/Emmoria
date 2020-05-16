#include "../../../inc/util/logger/Logger.hpp"

#include <iostream>

char const * const Logger::k_greenTextOpener = "\033[;32m";
char const * const Logger::k_yellowTextOpener = "\033[;33m";
char const * const Logger::k_redTextOpener = "\033[;31m";
char const * const Logger::k_colourTextCloser = "\033[0m";

LoggerType_t::LoggerType_t(char const * type) : m_typeName(type)
{}

void Logger::DebugLog(LoggerType_t loggerCompatible, char const * const message)
{
	#ifdef DEBUG
		std::cout << k_greenTextOpener << loggerCompatible.GetLogTag() << ": " << message << k_colourTextCloser << std::endl;
	#endif
}

void Logger::InfoLog(LoggerType_t loggerCompatible, char const * const message)
{
	#if defined(DEBUG) || defined(INFO)
		std::cout << loggerCompatible.GetLogTag() << ": " << message << std::endl;
	#endif
}

void Logger::WarningLog(LoggerType_t loggerCompatible, char const * const message)
{
	#if defined(DEBUG) || defined(INFO) || defined(WARN)
		std::cout << k_yellowTextOpener << loggerCompatible.GetLogTag() << ": " << message << k_colourTextCloser << std::endl;
	#endif
}

void Logger::ErrorLog(LoggerType_t loggerCompatible, char const * const message)
{
	#if defined(DEBUG) || defined(INFO) || defined(WARN) || defined(ERROR)
		std::cout << k_redTextOpener << loggerCompatible.GetLogTag() << ": " << message << k_colourTextCloser << std::endl;
	#endif
}
