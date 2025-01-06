#include <iostream>
#include <unordered_map>
#include "src/GrafoAmigos.hpp"

int main(int argc, char const *argv[])
{
    std::unordered_map<std::string, int> nome_id = {
        {"Romildo", 1},
        {"Marcos", 2},
        {"Ewelyn", 3},
        {"Laura", 4},
        {"Ana", 5},
        {"João", 6},
        {"Carlos", 7},
        {"Fernanda", 8},
        {"Beatriz", 9},
        {"Pedro", 10},
        {"Julia", 11},
        {"Gabriel", 12},
        {"Rafaela", 13},
        {"Lucas", 14},
        {"Isabela", 15}};

    std::unordered_map<int, std::string> id_nome;
    for (const auto& pair : nome_id) {
        id_nome[pair.second] = pair.first;
    }
    

    GrafoAmigos grafo;

    grafo.addRelacao(1, 2);
    grafo.addRelacao(1, 3);
    grafo.addRelacao(2, 4);
    grafo.addRelacao(3, 4);
    grafo.addRelacao(1, 5);
    grafo.addRelacao(1, 6);
    grafo.addRelacao(2, 7);
    grafo.addRelacao(2, 8);
    grafo.addRelacao(3, 9);
    grafo.addRelacao(3, 10);
    grafo.addRelacao(4, 11);
    grafo.addRelacao(4, 12);
    grafo.addRelacao(5, 6);
    grafo.addRelacao(5, 13);
    grafo.addRelacao(6, 14);
    grafo.addRelacao(6, 15);
    grafo.addRelacao(7, 8);
    grafo.addRelacao(7, 9);
    grafo.addRelacao(8, 10);
    grafo.addRelacao(8, 11);
    grafo.addRelacao(9, 12);
    grafo.addRelacao(9, 13);
    grafo.addRelacao(10, 14);
    grafo.addRelacao(10, 15);
    grafo.addRelacao(11, 12);
    grafo.addRelacao(11, 13);
    grafo.addRelacao(12, 14);
    grafo.addRelacao(12, 15);
    grafo.addRelacao(13, 14);
    grafo.addRelacao(13, 15);
    grafo.addRelacao(1, 7);
    grafo.addRelacao(2, 8);
    grafo.addRelacao(3, 9);
    grafo.addRelacao(4, 10);
    grafo.addRelacao(5, 11);
    grafo.addRelacao(6, 12);
    grafo.addRelacao(7, 13);
    grafo.addRelacao(8, 14);
    grafo.addRelacao(9, 15);
    grafo.addRelacao(10, 11);
    grafo.addRelacao(2, 12);
    grafo.addRelacao(3, 13);
    grafo.addRelacao(4, 14);
    grafo.addRelacao(5, 15);
    grafo.addRelacao(6, 7);

    int a = 3, b = 7;
    double probabilidade = grafo.calcularProbabilidade(a, b);

    std::cout<< "Intersecao dos vizinhos "<< a << "e " << b << std::endl;
    std::set<int> intersec= grafo.intersecao(a,b);
    for(int vizinho : intersec){
        std::cout<< vizinho<< " ";
    }
    std::cout<<std::endl;

    std::cout<< "Uniao dos vizinhos "<<  a << "e " << b <<std::endl;
    std::set<int> uni= grafo.uniao(a,b);
    for(int vizinho : uni){
        std::cout<< vizinho<< " ";
    }
    std::cout<<std::endl;

    std::cout << "Probabilidade de P( " << a <<"," << b <<" ): " << probabilidade*100 <<"%" << std::endl;

    return 0;
}
