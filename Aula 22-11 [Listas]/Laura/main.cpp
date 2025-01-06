#include <iostream>
#include "src/IndexadorArquivo.hpp"

#include <set>
#include <map>

int main()
{
    std::map<std::string, int> fileMap;
    fileMap["input/cranfield0001"] = 1;
    fileMap["input/cranfield0002"] = 2;
    fileMap["input/cranfield0003"] = 3;
    fileMap["input/cranfield0004"] = 4;
    fileMap["input/cranfield0005"] = 5;
    fileMap["input/cranfield0006"] = 6;
    fileMap["input/cranfield0007"] = 7;
    fileMap["input/cranfield0008"] = 8;
    fileMap["input/cranfield0009"] = 9;
    fileMap["input/cranfield0010"] = 10;
    fileMap["input/cranfield0011"] = 11;
    fileMap["input/cranfield0012"] = 12;
    fileMap["input/cranfield0013"] = 13;
    fileMap["input/cranfield0014"] = 14;
    fileMap["input/cranfield0015"] = 15;
    std::set<std::string> uniqueWords;
    // Aqui são dois pontos para voltar uma pasta
    std::string filename = "../input/cranfield0001";

    IndexadorArquivo arquivos;
    // O ideal seria essa função retornar o próprio set, não você
    // passar uma variável pra ser atualizada dentro pois não fica
    // claro o que tá sendo feito a primeira vista.

    // Outro ponto: a função não vai funcionar do jeito esperado
    // porque você não tá alterando a referência da variável, e sim uma cópia.
    arquivos.addPalavrasDicionario(filename, uniqueWords);
    std::cout << "Palavras unicas do arquivo" << std::endl;

    for (const auto &word : uniqueWords)
    {
        std::cout << word << std::endl;
    }
}