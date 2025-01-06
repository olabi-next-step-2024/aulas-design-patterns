#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


template <typename T>
class Array
{
    std::vector<T> elements;

public:
    void add(const T &element)
    {
        elements.push_back(element);
    }

    void remove(const T &element)
    {
        elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
    }

    void print() const
    {
        for (const auto &el : elements)
        {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
};


template <>
class Array<std::string>
{
    std::vector<std::string> elements;

public:
    void add(const std::string &element)
    {
        elements.push_back(element);
    }

    void remove(const std::string &element)
    {
        elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
    }

    void toUpperCase()
    {
        for (auto &el : elements)
        {
            std::transform(el.begin(), el.end(), el.begin(), ::toupper);
        }
    }

    void print() const
    {
        for (const auto &el : elements)
        {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    Array<int> intArray;
    intArray.add(1);
    intArray.add(2);
    intArray.add(3);
    intArray.print();
    intArray.remove(2);
    intArray.print();

    Array<std::string> stringArray;
    stringArray.add("hello");
    stringArray.add("world");
    stringArray.print();
    stringArray.toUpperCase();
    stringArray.print();

    return 0;
}
