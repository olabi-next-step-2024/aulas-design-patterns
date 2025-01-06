#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>

class Pessoa
{
protected:
    std::string nome;
    int idade;

public:
    Pessoa(std::string nome, int idade) : nome(nome), idade(idade) {};

    virtual std::string getNome() = 0;

    virtual int getIdade()  = 0;
};
#endif