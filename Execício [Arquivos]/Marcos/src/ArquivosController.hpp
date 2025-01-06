#ifndef ArquivosController_HPP
#define ArquivosController_HPP

#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Aluno.hpp"

using std::string;

class ArquivosController {
    private:
    std::vector<std::shared_ptr<Aluno>> historico {};

    public:

    void carregarAluno(std::shared_ptr<Aluno>& aluno){
        historico.push_back(aluno);
    }


    std::shared_ptr<Aluno> buscaMatricula(string matricula){
        auto it = std::find_if(
            historico.begin(), 
            historico.end(), 
            [matricula](const std::shared_ptr<Aluno> aluno) {
                return (aluno->getMatricula() == matricula);
            });
        return *it;

    }

    std::shared_ptr<Aluno> buscaNome(string nome){
        auto it = std::find_if(historico.begin(), historico.end(), 
        [nome](const std::shared_ptr<Aluno> aluno){
            return aluno->getNome() == nome;
        });
        return *it;
    }

    void salvarNoArquivo(){
        std::ofstream arquivo("alunos.txt");
        if(!arquivo){
            std::cerr << "Erro ao abrir o arquivo"<<std::endl;
        }
        for(auto aluno : historico){
            arquivo << "Aluno: "<< aluno-> getNome() <<" Matricula: "<< aluno-> getMatricula() <<" Idade: "<< aluno -> getIdade() << std::endl;

        }
        arquivo.close();
    }

    void lerArquivo(string nomeArquivo){
        std::ifstream arquivo(nomeArquivo);
        if(!arquivo){
            std::cerr << "Erro ao abrir o arquivo para leitura" << std::endl;
        }

        std::string linha;
        while(std::getline(arquivo,linha)){
            std::cout<<linha<<std::endl;
        }
        arquivo.close();
    }

};
#endif