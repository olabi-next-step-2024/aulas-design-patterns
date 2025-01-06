#include <iostream>
#include <string>
#include <memory>

class Component
{
public:
    virtual void operation() = 0;
    virtual ~Component() {}
};

class ConcreteComponent : public Component
{
public:
    void operation() override
    {
        std::cout << "Base operation\n";
    }
};

class Decorator : public Component
{
protected:
    std::shared_ptr<Component> component;

public:
    Decorator(std::shared_ptr<Component> comp) : component(comp) {}
    void operation() override
    {
        component->operation();
    }
};

class LoggingDecorator : public Decorator
{
public:
    LoggingDecorator(std::shared_ptr<Component> comp) : Decorator(comp) {}
    void operation() override
    {
        std::cout << "[Log] Starting operation\n";
        Decorator::operation();
        std::cout << "[Log] Ending operation\n";
    }
};

class AuthenticationDecorator : public Decorator
{
    std::string user;

public:
    AuthenticationDecorator(std::shared_ptr<Component> comp, const std::string &usr)
        : Decorator(comp), user(usr) {}

    void operation() override
    {
        if (authenticate())
        {
            std::cout << "[Auth] User authenticated: " << user << "\n";
            Decorator::operation();
        }
        else
        {
            std::cout << "[Auth] Authentication failed for user: " << user << "\n";
        }
    }

private:
    bool authenticate()
    {
        return user == "admin";
    }
};

class CachingDecorator : public Decorator
{
public:
    CachingDecorator(std::shared_ptr<Component> comp) : Decorator(comp) {}

    void operation() override
    {
        std::cout << "[Cache] Checking cache\n";
        if (!inCache())
        {
            std::cout << "[Cache] Cache miss, delegating to base component\n";
            Decorator::operation();
            updateCache();
        }
        else
        {
            std::cout << "[Cache] Cache hit\n";
        }
    }

private:
    bool inCache()
    {
        return false;
    }

    void updateCache()
    {
        std::cout << "[Cache] Updating cache\n";
    }
};

int main()
{
    auto baseComponent = std::make_shared<ConcreteComponent>();
    auto logging = std::make_shared<LoggingDecorator>(baseComponent);
    auto auth = std::make_shared<AuthenticationDecorator>(logging, "admin");
    auto caching = std::make_shared<CachingDecorator>(auth);

    caching->operation();
}
