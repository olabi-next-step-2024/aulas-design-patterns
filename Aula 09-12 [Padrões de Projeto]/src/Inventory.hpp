#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include "Product.hpp"
#include <memory>
#include <fstream>

// Vocês devem implementar a feature para que o sistema de Products seja feito utiizando leitura / escrita
// de arquivos.
class Inventory
{
public:
    std::vector<Product> db; // "Banco de dados" de Products

    Inventory(std::vector<Product> &ref) : db(ref) {};

    // void load()
    // {
    //     db.push_back(Product("Laptop", 50, 1500.0));
    //     db.push_back(Product("Mouse", 200, 25.0));
    //     db.push_back(Product("Keyboard", 150, 45.0));
    // }

    void show()
    {
        std::cout << "Current Inventory:" << std::endl;
        for (auto &item : db)
        {
            std::cout << " - " << item.getName() << ": " << item.getQuantity() << " units, $" << item.getPrice() << std::endl;
        }
    }
};

#endif