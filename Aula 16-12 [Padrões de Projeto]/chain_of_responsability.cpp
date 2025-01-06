#include <iostream>
#include <string>
#include <memory>

class Handler
{
public:
    virtual ~Handler() = default;
    void setNext(std::shared_ptr<Handler> nextHandler)
    {
        next = nextHandler;
    }
    virtual bool handle(const std::string &user, const std::string &password)
    {
        if (next)
            return next->handle(user, password);
        return true;
    }

private:
    std::shared_ptr<Handler> next;
};

class PasswordHandler : public Handler
{
public:
    bool handle(const std::string &user, const std::string &password) override
    {
        if (password != "securepassword")
        {
            std::cout << "Password validation failed.\n";
            return false;
        }
        return Handler::handle(user, password);
    }
};

class PermissionHandler : public Handler
{
public:
    bool handle(const std::string &user, const std::string &password) override
    {
        if (user != "admin")
        {
            std::cout << "Permission validation failed.\n";
            return false;
        }
        return Handler::handle(user, password);
    }
};

class LoggingHandler : public Handler
{
public:
    bool handle(const std::string &user, const std::string &password) override
    {
        std::cout << "User: " << user << " is being validated.\n";
        return Handler::handle(user, password);
    }
};

int main()
{
    auto passwordHandler = std::make_shared<PasswordHandler>();
    auto permissionHandler = std::make_shared<PermissionHandler>();
    auto loggingHandler = std::make_shared<LoggingHandler>();

    loggingHandler->setNext(passwordHandler);
    passwordHandler->setNext(permissionHandler);

    std::string user = "admin";
    std::string password = "securepassword";

    if (loggingHandler->handle(user, password))
    {
        std::cout << "Authentication successful.\n";
    }
    else
    {
        std::cout << "Authentication failed.\n";
    }
    return 0;
}
