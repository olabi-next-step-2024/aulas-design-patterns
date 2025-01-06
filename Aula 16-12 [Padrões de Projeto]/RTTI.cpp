#include <iostream>
#include <vector>
#include <memory>
#include <typeinfo>

class Animal
{
public:
    virtual void speak() const = 0;
    virtual ~Animal() {}
};

class Dog : public Animal
{
public:
    void speak() const override { std::cout << "Woof\n"; }
    void fetch() const { std::cout << "Fetching the ball\n"; }
};

class Cat : public Animal
{
public:
    void speak() const override { std::cout << "Meow\n"; }
    void climb() const { std::cout << "Climbing the tree\n"; }
};

class Bird : public Animal
{
public:
    void speak() const override { std::cout << "Chirp\n"; }
    void fly() const { std::cout << "Flying high\n"; }
};

void interactWithAnimal(const Animal &animal)
{
    animal.speak();
    if (const Dog *dog = dynamic_cast<const Dog *>(&animal))
    {
        dog->fetch();
    }
    else if (const Cat *cat = dynamic_cast<const Cat *>(&animal))
    {
        cat->climb();
    }
    else if (const Bird *bird = dynamic_cast<const Bird *>(&animal))
    {
        bird->fly();
    }
    else
    {
        std::cout << "Unknown animal type\n";
    }
}

int main()
{
    std::vector<std::shared_ptr<Animal>> zoo = {
        std::make_shared<Dog>(),
        std::make_shared<Cat>(),
        std::make_shared<Bird>()};

    for (const auto &animal : zoo)
    {
        interactWithAnimal(*animal);
    }
}
