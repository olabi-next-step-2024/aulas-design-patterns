#include <iostream>
#include <memory>
#include <map>
#include <string>
#include <stdexcept>

class Service
{
public:
    virtual void execute() = 0;
    virtual ~Service() {}
};

class AuthService : public Service
{
public:
    void execute() override
    {
        std::cout << "Authentication service executing...\n";
    }
};

class LoggingService : public Service
{
public:
    void execute() override
    {
        std::cout << "Logging service executing...\n";
    }
};

class ServiceLocator
{
    std::map<std::string, std::shared_ptr<Service>> services;

public:
    void addService(const std::string &name, std::shared_ptr<Service> service)
    {
        services[name] = service;
    }

    std::shared_ptr<Service> getService(const std::string &name)
    {
        if (services.find(name) == services.end())
            throw std::runtime_error("Service not found: " + name);
        return services[name];
    }
};

int main()
{
    ServiceLocator locator;
    locator.addService("auth", std::make_shared<AuthService>());
    locator.addService("log", std::make_shared<LoggingService>());

    auto authService = locator.getService("auth");
    authService->execute();

    auto loggingService = locator.getService("log");
    loggingService->execute();
}
