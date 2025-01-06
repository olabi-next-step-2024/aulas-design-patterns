#ifndef GRAFOAMIGOS_HPP
#define GRAFOAMIGOS_HPP

#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

class GrafoAmigos
{

private:
    std::map<int, std::set<int>> conexoes;

public:
    void addRelacao(int u, int v)
    {
        conexoes[u].insert(v);
        conexoes[v].insert(u);
    }

    std::set<int> obterVizinhos(int vertice)
    {
        return conexoes[vertice];
    }

    std::set<int> intersecao(int u, int v)
    {
        std::set<int> intersec;
        std::set_intersection(conexoes[u].begin(), conexoes[u].end(), conexoes[v].begin(), conexoes[v].end(), inserter(intersec, intersec.begin()));

        return intersec;
    }
    std::set<int> uniao(int u, int v)
    {
        std::set<int> uni;
        std::set_union(conexoes[u].begin(), conexoes[u].end(), conexoes[v].begin(), conexoes[v].end(), inserter(uni, uni.begin()));

        return uni;
    }

    double calcularProbabilidade(int u, int v)
    {
        
        std::set<int> intersec = intersecao(u, v);
        std::set<int> uni = uniao(u, v);

        double tamIntersecao = intersec.size();
        double tamUniao = uni.size();

        if (tamUniao == 0)
        {
            return 0.0;
        }
        return tamIntersecao / tamUniao;
    }
    

};

#endif