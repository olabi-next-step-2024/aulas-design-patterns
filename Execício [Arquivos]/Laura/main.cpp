#include <iostream>
#include "src/Aluno.hpp"
#include "src/Pessoa.hpp"
#include "src/GerenciarAlunos.hpp"

int main(int argc, char const *argv[])
{
  GerenciarAlunos gerenciador;

  auto aluno1 = std::make_shared<Aluno>("João", 20, 101);
  aluno1->addDisciplina("matematica", 7.5);
  aluno1->addDisciplina("portugues", 5.5);

  auto aluno2 = std::make_shared<Aluno>("Tião", 18, 102);
  aluno2->addDisciplina("matematica", 8.0f);
  aluno2->addDisciplina("historia", 3.56f);  

  gerenciador.adicionarAluno(aluno1);
  gerenciador.adicionarAluno(aluno2);


  std::cout << "ALUNO: " <<(gerenciador.buscarPorNome("João"))->getNome()<< ", Matricula: " <<(gerenciador.buscarPorNome("João"))->getMatricula()<< std::endl;
  auto found = gerenciador.buscarPorMatricula(102);
  std::cout << "ALUNO: " << found->getNome() << ", Matricula: " << found->getMatricula()<< std::endl;

  gerenciador.salvarEmArquivo("alunos.txt");

}
