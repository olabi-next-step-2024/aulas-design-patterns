#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <iostream>

class Product
{
    std::string name; // name do Product
    int quantity;     // Quantidade em estoque
    double price;     // Preço do Product
public:

    Product(std::string name, int quantity, double price)
        : name(name), quantity(quantity), price(price) {}

    std::string getName()
    {
        return name;
    }

    int getQuantity()
    {
        return quantity;
    }

    double getPrice()
    {
        return price;
    }
};

#endif