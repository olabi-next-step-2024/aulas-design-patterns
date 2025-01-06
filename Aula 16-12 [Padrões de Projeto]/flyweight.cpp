#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

class Flyweight
{
    std::string sharedState;

public:
    Flyweight(const std::string &sharedState) : sharedState(sharedState) {}
    void operation(const std::string &uniqueState) const
    {
        std::cout << "Shared: " << sharedState << ", Unique: " << uniqueState << std::endl;
    }
    const std::string &getSharedState() const { return sharedState; }
};

class FlyweightFactory
{
    std::unordered_map<std::string, std::shared_ptr<Flyweight>> flyweights;

public:
    std::shared_ptr<Flyweight> getFlyweight(const std::string &sharedState)
    {
        if (flyweights.find(sharedState) == flyweights.end())
        {
            flyweights[sharedState] = std::make_shared<Flyweight>(sharedState);
        }
        return flyweights[sharedState];
    }
    void listFlyweights() const
    {
        std::cout << "Flyweights count: " << flyweights.size() << std::endl;
        for (const auto &pair : flyweights)
        {
            std::cout << "Flyweight with state: " << pair.first << std::endl;
        }
    }
};

class Context
{
    std::shared_ptr<Flyweight> flyweight;
    std::string uniqueState;

public:
    Context(const std::string &sharedState, const std::string &uniqueState, FlyweightFactory &factory)
        : flyweight(factory.getFlyweight(sharedState)), uniqueState(uniqueState) {}
    void operation() const
    {
        flyweight->operation(uniqueState);
    }
};

int main()
{
    FlyweightFactory factory;

    std::vector<Context> contexts = {
        Context("State1", "Unique1", factory),
        Context("State2", "Unique2", factory),
        Context("State1", "Unique3", factory),
        Context("State3", "Unique4", factory),
        Context("State2", "Unique5", factory)};

    for (const auto &context : contexts)
    {
        context.operation();
    }

    factory.listFlyweights();
}
