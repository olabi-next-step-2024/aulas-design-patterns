#include <iostream>
#include <map>
#include "src/ArquivoController.hpp"
#include "src/Index.hpp"

int main(int argc, char const *argv[]){
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

    ArquivoController gerenciador;
    Index index;

    gerenciador.lerArquivo("../input/cranfield0001");
    index.processarArquivo(1,gerenciador.getPalavras());
    for (auto [key, _set]: index.indexInvertido) {
        std::cout << key << ':';
        for (auto &element: _set) {
            std::cout << element << " - ";
        }
        putchar('\n');
    }
    
}