#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

class Observer
{
public:
    virtual void update(const std::string &message) = 0;
    virtual ~Observer() {}
};

class ConcreteObserver : public Observer
{
    std::string name;

public:
    ConcreteObserver(const std::string &n) : name(n) {}
    void update(const std::string &message) override
    {
        std::cout << "Observer [" << name << "] received: " << message << std::endl;
    }
};

class Subject
{
    std::vector<std::weak_ptr<Observer>> observers;

public:
    void addObserver(const std::shared_ptr<Observer> &observer)
    {
        observers.push_back(observer);
    }
    void removeObserver(const std::shared_ptr<Observer> &observer)
    {
        observers.erase(std::remove_if(observers.begin(), observers.end(),
                                       [&observer](const std::weak_ptr<Observer> &weakObs)
                                       {
                                           auto obs = weakObs.lock();
                                           return obs == observer || !obs;
                                       }),
                        observers.end());
    }
    void notify(const std::string &message)
    {
        for (auto it = observers.begin(); it != observers.end();)
        {
            if (auto obs = it->lock())
            {
                obs->update(message);
                ++it;
            }
            else
            {
                it = observers.erase(it);
            }
        }
    }
};

int main()
{
    auto subject = std::make_shared<Subject>();

    auto observer1 = std::make_shared<ConcreteObserver>("Observer1");
    auto observer2 = std::make_shared<ConcreteObserver>("Observer2");
    auto observer3 = std::make_shared<ConcreteObserver>("Observer3");

    subject->addObserver(observer1);
    subject->addObserver(observer2);
    subject->addObserver(observer3);

    subject->notify("Event 1");

    subject->removeObserver(observer2);

    subject->notify("Event 2");
}
