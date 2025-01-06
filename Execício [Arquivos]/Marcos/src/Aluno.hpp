#ifndef Aluno_HPP
#define Aluno_HPP
#include <map>
#include <iostream>
#include <numeric>
#include "Pessoa.hpp"

typedef std::map<std::string, double> disciplinas_t;

class Aluno : public Pessoa
{
private:
    std::string matricula;
    disciplinas_t disciplinas {};

public:
    Aluno(std::string matricula, std::string nome, int idade) : Pessoa(nome, idade), matricula(matricula) {}

    int getIdade() override {
        return idade;
    }

    std::string getNome() override {
        return nome;
    }
    
    std::string getMatricula(){ 
        return matricula;
    }

    void addDisciplinas(std::string materia, int nota)
    {
        disciplinas[materia] = nota;
    }

    double calcularMed()
    {
        if (disciplinas.empty())
        {
            return 0.0;
        }
        double somaTotal = std::accumulate(disciplinas.begin(), disciplinas.end(), 0,
                                           [](auto prev_sum, auto &entry)
                                           {
                                               return prev_sum + entry.second;
                                           });
        double media = somaTotal / disciplinas.size();
    }

    bool verificaAprovacao(double notaGeral)
    { 
        return notaGeral > 7.0;
    }

    friend std::ostream &operator<<(std::ostream& os, Aluno& aluno){
        os <<"Aluno: "<< aluno.getNome() <<" Matricula: "<< aluno.getMatricula() <<" Idade: "<< aluno .getIdade() << std::endl;
        return os;
        }
};

#endif