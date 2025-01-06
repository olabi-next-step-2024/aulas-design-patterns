#ifndef ORD_HPP
#define ORD_HPP

#include <vector>
#include <iostream>
#include "Product.hpp"

// vamos refatorar essa classe aqui, porque ela ta fazendo 3 coisas

// Da pra separa ela em carrinho e order

class Order
{
public:
    std::string custName; // name do cliente

    Order(std::string custName) : custName(custName) {}

    void updateInventory() {
        // Buscar o produto no vector e substituir;
        // Como o objeto a ser utilizado é o mesmo no inventário e no carrinho,
        // Vocês terão que fazer muitas validações;
        // Como a estrutura de dados é um vector ao invés de uma map, vocês terão
        // outro problema para fazer a busca; o tempo tenderá a ser theta(M * N)
    }

    void process(std::vector<Product> &items)
    {
        std::cout << "Processing order for " << custName << std::endl;
        for (auto &item : items)
        {
            std::cout << " - " << item.getName() << " (" << item.getQuantity() << " units)" << std::endl;
            // updateInventory(item);
        }
    }
};

#endif