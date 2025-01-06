#ifndef PILHA_HPP
#define PILHA_HPP
#include <stack>
#include <queue>
#include <vector>
#include <iostream>

using std::stack;

// temp = 3
// principal = topo -> {3 , 2 , 4 , 15 }
//  auxiliar = {}
// ordenada = {}

// top = mostra e retorna
//  pop = apagar

class Pilha
{
private:
    stack<int> auxiliar{};

public:
    void ordenaPilhaDescrescente(stack<int> &principal)
    {
        while (!principal.empty())
        {
            int temp = principal.top();
            principal.pop();

            while (!auxiliar.empty() && auxiliar.top() > temp)
            {
                principal.push(auxiliar.top());
                auxiliar.pop();
            }
            auxiliar.push(temp);
        }

        while (!principal.empty())
        {
            principal.push(auxiliar.top());
            auxiliar.pop();
        }
    }

    std::stack<int> getPilhaOrdenada(){
        return auxiliar;
    }
};

#endif