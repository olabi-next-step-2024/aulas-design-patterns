#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP
#include <fstream>
#include <vector>
#include "Product.hpp"
#include <iostream>
#include <sstream>

class FileManager
{
public:
    void save_to_file(std::string &fileName, std::vector<Product> &products)
    {
        std::ofstream file(fileName);
        if (!file)
        {
            std::cerr << "Erro ao abrir o arquivo";
            return;
        }
        for (auto &product : products)
        {
            file << product.getName() << ";" << product.getPrice() << ";" << product.getQuantity() << ";" << "\n";
        }
    }

    /*

    Essa função faz a leitura
    @param fileName Recebe o caminho em que o arquivo está
    A leitura é feita no formato
    $QUANTITY$;$PRICE$
    */
    std::vector<Product> load_from_file(std::string fileName)
    {
        std::vector<Product> productDataBase;
        std::ifstream file(fileName);
        if (!file)
        {
            std::cout << "Erro ao abrir arquivo" << std::endl;
            return std::vector<Product>();
        }

        std::string line;
        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            std::string name;
            int quantity;
            double price;
            char delimiter = ';';

            std::getline(ss, name, delimiter);
            ss >> quantity >> delimiter >> price;
            productDataBase.emplace_back(name, quantity, price);
        }
        file.close();
        return productDataBase;
    }
};

#endif