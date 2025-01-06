#include <iostream>
#include <stack>

template <typename T>
class PilhaOrdenada : public std::stack<T>
{
    std::stack<T> aux;
    PilhaOrdenada() {};
    ~PilhaOrdenada() {};
    PilhaOrdenada &sort()
    {
        return this;
    };
};

int main(int argc, char const *argv[])
{

    return 0;
}
