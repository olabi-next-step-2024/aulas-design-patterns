#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "Pessoa.hpp"
#include <iostream>
#include <map>

// typedef std::map<std::string,double> Disciplinas;

class Aluno : public Pessoa
{
protected: // Se Aluno não for classe base para outra classe, os atributos protegidos terão na prática mesma comportamento que private
    int matricula;
    std::map<std::string, double> disciplinas;

public:
    Aluno(std::string nome, int idade, int matricula) : Pessoa(nome, idade), matricula(matricula)
    {}

    int getMatricula() const {
        return matricula;
    }
    
    std::map<std::string, double> getDisciplinas() const {
        return disciplinas;
    }

    void addDisciplina(std::string disciplina, double nota){
        disciplinas[disciplina]=nota;
    }

    double calcularMedia() const {
        double soma=0;
        if(disciplinas.empty()){
            return 0.0; // Como aqui está utilizando return, não precisa do else
        }else{
            for(auto const [disciplina, nota]: disciplinas){
                soma+=nota;
            }
            return soma/disciplinas.size();
        } 
    }
    bool aprovadoNaDisclipina(std::string disciplina){
        int notas; // notas não está sendo utilizado
        double nota = disciplinas[disciplina];
        if( nota < 7.0){ // Dá pra reduzir a return notaGeral > 7.0; pois irá verificar e retornar o resultado da comparação
            return false;
        }
        return true;
    }
    bool aprovadoGeral(){
        for(auto const [disciplina, nota]: disciplinas){
                if(nota<7.0){
                    std::cout<<"Reprovado"<< std::endl;
                    return false;
                }
            }
        return true;    
    }



    
};

#endif