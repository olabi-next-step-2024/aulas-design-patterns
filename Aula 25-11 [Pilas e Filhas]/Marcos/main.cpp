#include <iostream>
#include "src/Pilha.hpp"
//{3 , 2 , 4 , 15 }
int main(int argc, char const *argv[])
{
    Pilha pilha;
    std::stack<int> pilhaOriginal{};
    pilhaOriginal.push(15);
    pilhaOriginal.push(4);
    pilhaOriginal.push(2);
    pilhaOriginal.push(3);
    pilhaOriginal.push(1);

    std::cout << " Pilha Original" << std::endl;
    std::stack<int> auxiliar = pilhaOriginal;
    while (!auxiliar.empty())
    {
        std::cout << "Valor : " << auxiliar.top() << std::endl;
        auxiliar.pop();
    }

    pilha.ordenaPilhaDescrescente(pilhaOriginal);
    std::stack<int> pilhaOrdenada = pilha.getPilhaOrdenada();
    puts("Pilha ordenada: ");
    
    while (!pilhaOrdenada.empty())
    {
        std::cout << "Valor : " << pilhaOrdenada.top() << std::endl;
        pilhaOrdenada.pop();
    }

    return 0;
}
