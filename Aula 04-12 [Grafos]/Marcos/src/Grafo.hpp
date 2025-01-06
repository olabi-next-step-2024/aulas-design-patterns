#ifndef GRAFO_HPP
#define GRAFO_HPP
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>

class Grafo
{
protected:
    // std::unordered_map<int, std::unordered_set<int>> grafo;

public:
    double calcProbabilidade(std::unordered_map<int, std::unordered_set<int>>& grafo, int i, int j)
    {
        if (grafo.find(i) == grafo.end() || (grafo.find(j) == grafo.end()))
        {
            puts("OPS CAí AQUI!");
            return 0.0;
        }

        const auto &vizinhosI = grafo.at(i);
        const auto &vizinhosJ = grafo.at(j);

        std::vector<int> intersecao;
        std::set_intersection(vizinhosI.begin(), vizinhosI.end(),
                              vizinhosJ.begin(), vizinhosJ.end(),
                              std::back_inserter(intersecao));

        

        std::unordered_set<int> uniao(vizinhosI.begin(), vizinhosI.end());
        uniao.insert(vizinhosJ.begin(), vizinhosJ.end());

        double probabilidade = static_cast<double>(intersecao.size()) / uniao.size();
        return probabilidade;
    }
};

#endif