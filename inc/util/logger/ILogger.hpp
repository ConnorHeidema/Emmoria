#ifndef I_LOGGER_HPP
#define I_LOGGER_HPP

/**
 * This logger type should be defined in every class to log things
 * it enables each log to at least be rooted back to a particular class
 * relatively easily.
 */
class LoggerType_t
{
public:
	/**
	 * Creates the log type
	 * @param type Typically the same as the class name
	 * 			   an identifier for where the log is coming from
	 */
	LoggerType_t(char const * const type);

	/**
	 * Used in implementations to extract the type out for the log
	 */
	char const * GetLogTag()
	{
		return m_typeName;
	}
private:
	char const * const m_typeName;
};

/**
 * This class acts as the interface for any logger object made
 */
class ILogger
{
public:
	/**
	 * Shows a debug statement
	 * @param loggerCompatible : A logger type the message will be prefixed with
	 * @param message : The content of the logger message
	 */
	virtual void DebugLog(LoggerType_t loggerCompatible, char const * const message) = 0;

	/**
	 * Shows an info statement
	 * @param loggerCompatible : A logger type the message will be prefixed with
	 * @param message : The content of the logger message
	 */
	virtual void InfoLog(LoggerType_t loggerCompatible, char const * const message) = 0;

	/**
	 * Shows a warning statement
	 * @param loggerCompatible : A logger type the message will be prefixed with
	 * @param message : The content of the logger message
	 */
	virtual void WarningLog(LoggerType_t loggerCompatible, char const * const message) = 0;

	/**
	 * Shows an error statement
	 * @param loggerCompatible : A logger type the message will be prefixed with
	 * @param message : The content of the logger message
	 */
	virtual void ErrorLog(LoggerType_t loggerCompatible, char const * const message) = 0;
};

#endif
