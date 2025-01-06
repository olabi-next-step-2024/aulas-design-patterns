#ifndef PILHA_HPP
#define PILHA_HPP
#include <stack>
#include <iostream>


class Pilha{

public:
    std::stack<int> ordenar(std::stack<int> pilha){ 
        
        std::stack<int> pilhaAux;
        std::stack<int> pilhaNova;
        // pilhaAux.push(pilha.top());
        
        while(!pilha.empty()){
            int aux= pilha.top();
            pilha.pop();
            while(!pilhaAux.empty() && pilhaAux.top()> aux){
                pilha.push(pilhaAux.top());
                pilhaAux.pop(); 
            }
            pilhaAux.push(aux);
        }
        return pilhaAux;

    }


};

#endif