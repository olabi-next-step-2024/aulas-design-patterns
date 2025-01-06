#include <iostream>
#include <vector>
#include <string>

// Permite que objetos sejam notificados sobre mudanças em outro objeto.

class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

class Subject {
private:
    std::vector<Observer*> observers;
public:
    void attach(Observer* obs) { observers.push_back(obs); }
    void notify(const std::string& message) {
        for (auto obs : observers) {
            obs->update(message);
        }
    }
};

class Subscriber : public Observer {
private:
    std::string name;
public:
    Subscriber(const std::string& name) : name(name) {}
    void update(const std::string& message) override {
        std::cout << name << " received: " << message << std::endl;
    }
};

int main() {
    Subject subject;

    Subscriber sub1("Alice");
    Subscriber sub2("Bob");

    subject.attach(&sub1);
    subject.attach(&sub2);

    subject.notify("New event published!");

    return 0;
}