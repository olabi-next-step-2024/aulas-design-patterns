#include <iostream>
#include <vector>
#include <memory>
#include <string>

class Module
{
public:
    virtual void execute() = 0;
    virtual std::string name() const = 0;
    virtual ~Module() {}
};

class CoreModule : public Module
{
public:
    void execute() override
    {
        std::cout << "Core functionality executing." << std::endl;
    }
    std::string name() const override
    {
        return "CoreModule";
    }
};

class LoggingModule : public Module
{
public:
    void execute() override
    {
        std::cout << "Logging: Action performed." << std::endl;
    }
    std::string name() const override
    {
        return "LoggingModule";
    }
};

class SecurityModule : public Module
{
public:
    void execute() override
    {
        std::cout << "Security: Verifying access." << std::endl;
    }
    std::string name() const override
    {
        return "SecurityModule";
    }
};

class Microkernel
{
    std::vector<std::unique_ptr<Module>> modules;

public:
    void addModule(std::unique_ptr<Module> module)
    {
        modules.push_back(std::move(module));
    }

    void executeAll()
    {
        for (const auto &module : modules)
        {
            std::cout << "Executing " << module->name() << ": ";
            module->execute();
        }
    }
};

int main()
{
    Microkernel kernel;
    kernel.addModule(std::make_unique<CoreModule>());
    kernel.addModule(std::make_unique<LoggingModule>());
    kernel.addModule(std::make_unique<SecurityModule>());

    kernel.executeAll();
    return 0;
}
