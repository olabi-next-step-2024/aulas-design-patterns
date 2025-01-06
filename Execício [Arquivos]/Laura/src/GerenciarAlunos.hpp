#ifndef GERENCIARALUNOS_HPP
#define GERENCIARALUNOS_HPP

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include "Aluno.hpp"
#include <algorithm>


class GerenciarAlunos{
    private:
    std::vector<std::shared_ptr<Aluno>> alunos;

    public:

    void adicionarAluno(std::shared_ptr<Aluno>& aluno){
        alunos.push_back(aluno);
    }

    std::shared_ptr<Aluno> buscarPorNome(std::string nome) const {

        auto it= std::find_if(alunos.begin(), alunos.end(),[nome](const std::shared_ptr<Aluno> aluno){
            return aluno->getNome()==nome;
        });

        return (it!=alunos.end()) ? *it : nullptr;
    }

    std::shared_ptr<Aluno> buscarPorMatricula(int matricula){
        auto it= std::find_if(alunos.begin(), alunos.end(),[matricula](const std::shared_ptr<Aluno> aluno){
            return aluno->getMatricula()==matricula;
        });

        return (it!=alunos.end()) ? *it : nullptr;
    }
    void salvarEmArquivo(std::string nomeArquivo) const {

        std::ofstream arquivo(nomeArquivo, std::ofstream::out);

        // verifica se deu bom
        if(!arquivo){
            std::cout<< "Deu ruim"<< std::endl;
            return;
        }

        // salvar os alunos
        for (auto& aluno : alunos){
            arquivo << aluno->getNome() << ", " << aluno->getIdade() << ", " << aluno->getMatricula()<<"\n";
            arquivo << "Disciplinas: "<< std::endl;
        
            for (auto [disciplina, nota] : aluno->getDisciplinas()){
                arquivo<< disciplina << ": "<< nota << ", ";
            }
            arquivo<< "\n";

        }
        arquivo.close();
        std::cout<<" Arquivo salvo";
        
    }

};

#endif