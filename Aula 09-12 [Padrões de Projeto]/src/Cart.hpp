#ifndef CART_HPP
#define CART_HPP

#include <iostream>
#include "Order.hpp"

class Cart
{
private:
    std::vector<Product> items {};
    std::string custName;

public:
    Cart(std::string custName) : custName(custName) {};

    void add(Product product)
    {
        items.push_back(product);
    }

    void buy()
    {
        Order order(custName);
        order.process(items);
    }

    // void updateInventory(Product item)
    // {
    //     std::cout << "Updating inventory for " << item.name << std::endl;
    // }
};

#endif