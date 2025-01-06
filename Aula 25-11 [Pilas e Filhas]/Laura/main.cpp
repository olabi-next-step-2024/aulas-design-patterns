#include <iostream>
#include "src/Pilha.hpp"
#include <stack>

int main(int argc, char const *argv[])
{
    Pilha organizacao;

    std::stack<int> pilha;
    
    pilha.push(100);
    pilha.push(10);
    pilha.push(35);
    pilha.push(30);
    pilha.push(40);

    std::stack<int> nova = organizacao.ordenar(pilha);
    std::cout<< "Pilha Original" << std::endl;

    while(!pilha.empty()){
        std::cout<< pilha.top()<< ", ";
        pilha.pop();
    }
    std::cout<< "\n" << std::endl;
    std::cout<< "Pilha nova" << std::endl;
    while(!nova.empty()){
        std::cout<< nova.top()<< ", ";
        nova.pop();
    }

    return 0;
}
