#ifndef ESTACIONAMENTO_HPP
#define ESTACIONAMENTO_HPP
#include "Pilha.hpp"
#include "Garagem.hpp"
#include <iostream>
#include <stack>
#include <queue>
#include <array>
/**- Um estacionamento possui garagens organizadas como pilhas, onde cada uma comporta até N carros.
   Os clientes chegam em uma fila de espera para deixar seus veículos, informando o tempo estimado de permanência.
   Sua tarefa é desenvolver um sistema que:
   Atribua o carro a uma garagem com base no tempo estimado de saída, visando minimizar movimentações futuras.
   Reorganize os carros após M veículos serem adicionados, utilizando chofers para otimizar a disposição nas garagens.
   Dicas para Resolver:
   Pilha: Use para simular cada garagem, já que carros só podem sair pela entrada/saída (ordem LIFO).
   Fila: Armazene os carros enquanto aguardam serem designados a uma garagem.
   Reordenação: Crie uma função que, após M inserções, ajuste as pilhas para minimizar reposicionamentos futuros.
   Considere tempo estimado como critério principal.
*/

class Estacionamento
{
private:
    std::queue<int> tempEspera;
    std::array<int, Garagem> locacao;

public:
    Estacionamento(int Tamanho) :
};

#endif