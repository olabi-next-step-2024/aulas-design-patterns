#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>

class Pessoa
{
protected:
    std::string nome;
    int idade;

public:
    Pessoa(std::string nome, int idade) : nome(nome), idade(idade) {}
    int getIdade() const {
      return idade;
    }
    std::string getNome() const {
      return nome;
    }
};

#endif