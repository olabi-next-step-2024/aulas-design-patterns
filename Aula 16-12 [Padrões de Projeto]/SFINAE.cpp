#include <iostream>
#include <type_traits>
#include <vector>
#include <list>

template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
void process(T value)
{
    std::cout << "Processing numeric value: " << value << std::endl;
}

template <typename T, typename = void>
struct is_iterable : std::false_type
{
};

template <typename T>
struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>())), decltype(std::end(std::declval<T>()))>> : std::true_type
{
};

template <typename T, typename = std::enable_if_t<is_iterable<T>::value>>
void process(const T &container)
{
    std::cout << "Processing container: ";
    for (const auto &item : container)
        std::cout << item << " ";
    std::cout << std::endl;
}

int main()
{
    process(42);
    process(3.14);

    std::vector<int> vec = {1, 2, 3, 4};
    process(vec);

    std::list<std::string> lst = {"Hello", "World"};
    process(lst);
}
