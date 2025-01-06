#include <iostream>


template <int N>
struct Factorial
{
    static constexpr int value = N * Factorial<N - 1>::value;
};


template <>
struct Factorial<0>
{
    static constexpr int value = 1;
};


template <int N>
struct Summation
{
    static constexpr int value = N + Summation<N - 1>::value;
};

template <>
struct Summation<0>
{
    static constexpr int value = 0;
};

int main()
{
    constexpr int factorial_of_5 = Factorial<5>::value;
    constexpr int summation_of_10 = Summation<10>::value;

    std::cout << "Factorial of 5: " << factorial_of_5 << std::endl;
    std::cout << "Summation of 10: " << summation_of_10 << std::endl;

    return 0;
}
