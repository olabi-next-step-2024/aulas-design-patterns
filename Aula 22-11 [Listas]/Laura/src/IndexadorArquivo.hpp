#ifndef INDEXADORARQUIVO_HPP
#define INDEXADORARQUIVO_HPP

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <sstream>

class IndexadorArquivo
{

public:
    int addPalavrasDicionario(std::string filename, std::set<std::string> &uniqueWords)
    {
        // seria interessante dividir esse método, separando a lógica da leitura do arquivo
        // da formatação e split das palavras
        std::ifstream inputFile(filename);
        if (!inputFile.is_open())
        {
            std::cout << "Erro ao abrir arquivo" << std::endl;
            return 0;
        }
        std::string line;
        int lineNum = 0;
        bool foundText = false;

        while (std::getline(inputFile, line))
        {

            lineNum++;
            std::transform(line.begin(), line.end(), line.begin(), ::tolower); // min
            // de linha pra word

            if (!foundText)
            {
                if (line.find("<text>") != std::string::npos)
                {
                    foundText = true;
                }
                else
                {
                    continue;
                }
            }

            std::stringstream iss(line);
            std::string word;
            while (iss >> word)
            {
                if (!word.empty())
                { // stringstream ignora espaços em branco, pular linha.. assim não retorna string vazia. Não é necessária  averificação
                    uniqueWords.insert(word);
                    // std::cout<< word<< std::endl;
                }
            }
        }
        inputFile.close();
        return 0;
    }


};

#endif
