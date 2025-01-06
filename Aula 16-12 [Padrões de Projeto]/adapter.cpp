#include <iostream>
#include <string>

class Logger
{
public:
    virtual void logMessage(const std::string &message) = 0;
    virtual ~Logger() {}
};

class LegacyLogger
{
public:
    void writeLog(const std::string &log)
    {
        std::cout << "Legacy Log: " << log << std::endl;
    }
};

class LoggerAdapter : public Logger
{
    LegacyLogger &legacyLogger;

public:
    LoggerAdapter(LegacyLogger &logger) : legacyLogger(logger) {}
    void logMessage(const std::string &message) override
    {
        legacyLogger.writeLog(message);
    }
};

class Application
{
    Logger &logger;

public:
    Application(Logger &log) : logger(log) {}
    void run()
    {
        logger.logMessage("Application started.");
        logger.logMessage("Performing tasks...");
        logger.logMessage("Application finished.");
    }
};

int main()
{
    LegacyLogger legacyLogger;
    LoggerAdapter adapter(legacyLogger);
    Application app(adapter);
    app.run();
    return 0;
}
