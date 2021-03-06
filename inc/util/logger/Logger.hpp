#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "util/logger/ILogger.hpp"

#include <memory>

/**
 * The concrete implementation of the logger for most systems.
 * This logger will simply print to the console with varying
 * degrees of colour depending on the severity.
 */
class Logger : public ILogger
{
public:
	void DebugLog(LoggerType_t loggerCompatible, char const * const message) override;
	void InfoLog(LoggerType_t loggerCompatible, char const * const message) override;
	void WarningLog(LoggerType_t loggerCompatible, char const * const message) override;
	void ErrorLog(LoggerType_t loggerCompatible, char const * const message) override;

private:
	static char const * const k_greenTextOpener;
	static char const * const k_yellowTextOpener;
	static char const * const k_redTextOpener;
	static char const * const k_colourTextCloser;
};

static std::shared_ptr<Logger> s_pLogger = std::make_shared<Logger>();

#endif
