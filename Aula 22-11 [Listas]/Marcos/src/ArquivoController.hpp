#ifndef ArquivosController_HPP
#define ARQUIVOSCONTROLLER_HPP
#include <memory>
#include <fstream>
#include <iostream>
#include <vector>
#include <set>

using std::string;

class ArquivoController
{
private:
    std::set<string> palavras{};

public:
    void lerArquivo(string NomeArquivo)
    {
        std::ifstream arquivo(NomeArquivo);
        if (!arquivo)
        {
            std::cerr << "Erro ao abrir arquivo pra leitura";
        }
        // Modificar esta parte do codigo para a ultilizacao do stringstream
        string linha;
        while (std::getline(arquivo, linha, ' '))
        {
            palavras.emplace(linha);
        }
        arquivo.close();

        for (string palavra : palavras)
        {
            std::cout << palavra << std::endl;
        }
    }

    const std::set<string> &getPalavras() const
    {
        return palavras;
    }

    bool contemPalavra(const string &palavra) const
    {
        return palavras.find(palavra) != palavras.end();
    }
};

#endif