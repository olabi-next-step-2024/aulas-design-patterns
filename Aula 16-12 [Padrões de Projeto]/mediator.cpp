#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Mediator
{
public:
    virtual void sendMessage(const std::string &message, class User *sender) = 0;
    virtual void addUser(std::shared_ptr<class User> user) = 0;
    virtual ~Mediator() {}
};

class User
{
protected:
    Mediator *mediator;
    std::string name;

public:
    User(Mediator *med, const std::string &username) : mediator(med), name(username) {}
    virtual void receiveMessage(const std::string &message) = 0;
    virtual void sendMessage(const std::string &message) = 0;
    std::string getName() const { return name; }
};

class ChatMediator : public Mediator
{
    std::vector<std::shared_ptr<User>> users;

public:
    void addUser(std::shared_ptr<User> user) override
    {
        users.push_back(user);
    }
    void sendMessage(const std::string &message, User *sender) override
    {
        for (auto &user : users)
        {
            if (user.get() != sender)
            {
                user->receiveMessage(message);
            }
        }
    }
};

class ConcreteUser : public User
{
public:
    ConcreteUser(Mediator *med, const std::string &username) : User(med, username) {}
    void receiveMessage(const std::string &message) override
    {
        std::cout << name << " received: " << message << std::endl;
    }
    void sendMessage(const std::string &message) override
    {
        std::cout << name << " sends: " << message << std::endl;
        mediator->sendMessage(message, this);
    }
};

int main()
{
    ChatMediator chatMediator;

    auto user1 = std::make_shared<ConcreteUser>(&chatMediator, "Alice");
    auto user2 = std::make_shared<ConcreteUser>(&chatMediator, "Bob");
    auto user3 = std::make_shared<ConcreteUser>(&chatMediator, "Charlie");

    chatMediator.addUser(user1);
    chatMediator.addUser(user2);
    chatMediator.addUser(user3);

    user1->sendMessage("Hello, everyone!");
    user2->sendMessage("Hi Alice!");
    user3->sendMessage("Hey Alice and Bob!");
    return 0;
}
