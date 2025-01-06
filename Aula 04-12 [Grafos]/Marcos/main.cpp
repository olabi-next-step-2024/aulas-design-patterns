// class Main{
//     int main(){

//     }
// };
#include <iostream>
#include "./src/Grafo.hpp"
#include <map>
#include <unordered_map>

int main(int argc, char const *argv[])
{
    Grafo grafo;
    std::map<std::string, int> nome_id = {
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

    // for(const auto& [nome,id] : id_nome){
    //     std::cout << nome << " - " << std::endl;
    // }
    /* code */
    std::unordered_map<int, std::unordered_set<int>> meu_grafo = {
        {1, {2, 3}},
        {2, {1, 3}},
        {3, {1, 2, 4}},
        {4, {3}},
        {5, {1, 6, 7}},
        {6, {5, 7, 8}},
        {7, {5, 6, 9}},
        {8, {6, 9, 10}},
        {9, {7, 8, 11}},
        {10, {8, 11, 12}},
        {11, {9, 10, 13}},
        {12, {10, 13, 14}},
        {13, {11, 12, 15}},
        {14, {12, 15}},
        {15, {13, 14, 1}}};

    std::string primeiroNome, segundoNome;
    std::cout << "Digite os nomes ao qual deseja pesquisar" << std::endl;

    std::cin >> primeiroNome;

    std::cin >> segundoNome;

    double probabilidade = grafo.calcProbabilidade(meu_grafo, nome_id[primeiroNome], nome_id[segundoNome]);
    // Elementos da origem
    for (auto &element : meu_grafo[nome_id[primeiroNome]]) {
        std::cout << element << " - ";
    }
    putchar('\n');
    for (auto &element : meu_grafo[nome_id[segundoNome]]) {
        std::cout << element << " - ";
    }   
    putchar('\n');
    std::cout << "A probabilidade "<< primeiroNome << " e "<< segundoNome << " serem amigos é de :" << probabilidade*100 << "%" << std::endl;
    return 0;
}
