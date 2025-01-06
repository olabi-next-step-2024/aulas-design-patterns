#ifndef ESTACIONAMENTO_HPP
#define ESTACIONAMENTO_HPP
#include <stack>
#include <iostream>
#include <vector>
#include "Garagem.hpp"

class Estacionamento
{

private:
    std::vector<Garagem> garagens;
    int numGaragens;

public:
    Estacionamento(int numGaragens)
    {
        this->numGaragens = numGaragens;

        for (int i = 0; i < numGaragens; ++i)
        {
            garagens.push_back(Garagem(5));
        }
    }
    Garagem definirGaragem(int tempoCarro)
    {
        std::vector<int> aux;
        for (int i = 0; i < numGaragens; ++i)
        {
            aux[i] = garagens[i].carrosQueSaemAntes(garagens[i].getPilhaCarros(), tempoCarro);
        }

        int menosMovimentos = aux[0];
        int escolhida=0;

        for (int i = 1; i < numGaragens; ++i)
        {
            if (menosMovimentos > aux[i])
            {
                menosMovimentos = aux[i];
                escolhida=i;
            }
        }
        std::cout<<"Garagem escolhida: "<< escolhida <<std::endl;
        return garagens[escolhida];
    }
};

#endif