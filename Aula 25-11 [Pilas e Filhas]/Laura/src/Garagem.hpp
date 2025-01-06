#ifndef GARAGEM_HPP
#define GARAGEM_HPP
#include <stack>
#include <iostream>

class Garagem
{

private:
    std::stack<int> pilhaCarros;
    int capacidade;

public:
    Garagem(int capacidade) : capacidade(capacidade) {}

    void addCarroPilha(int tempo)
    {
        pilhaCarros.push(tempo);
    }

    int carrosQueSaemAntes(std::stack<int> pilhaCarros, int tempoCarro)
    {
        int cont = 0;
        while (!pilhaCarros.empty())
        {
            if(pilhaCarros.top() < tempoCarro){
                cont++;
                pilhaCarros.pop();
            }
        }
        return cont;
    }

    std::stack<int> ordenar(std::stack<int> pilha)
    {

        std::stack<int> pilhaAux;
        std::stack<int> pilhaNova;
        // pilhaAux.push(pilha.top());

        while (!pilha.empty())
        {
            int aux = pilha.top();
            pilha.pop();
            while (!pilhaAux.empty() && pilhaAux.top() > aux)
            {
                pilha.push(pilhaAux.top());
                pilhaAux.pop();
            }
            pilhaAux.push(aux);
        }
        return pilhaAux;
    }

    std::stack<int> getPilhaCarros() const
    {
        return pilhaCarros;
    }

    void setPilhaCarros(std::stack<int> pilhaCarros)
    {
        this->pilhaCarros = pilhaCarros;
    }
};

#endif