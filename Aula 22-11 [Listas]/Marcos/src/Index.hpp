#ifndef INDEX_HPP
#define INDEX_HPP
#include <iostream>
#include <unordered_map>
#include <set>
using std::string;
class Index
{
// private:

public:
    std::unordered_map<string, int> wortToId;
    std::unordered_map<int, std::set<int>> indexInvertido;
    int nextWordId = 1;
    void processarArquivo(int docID, const std::set<string> &palavras)
    {
        for (const auto &palavra : palavras)
        {
            int wordId = getWordId(palavra);
            indexInvertido[wordId].insert(docID);
        }
    }

    int getWordId(const string &palavra)
    {

        if (wortToId.find(palavra) == wortToId.end())
        {
            wortToId[palavra] = nextWordId++;
        }
        return wortToId[palavra];
    }

    // const std::unordered_map<string, int> &getIndexInvertido
};
#endif