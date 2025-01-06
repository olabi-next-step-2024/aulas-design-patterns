#include <iostream>
#include "src/Cart.hpp"
#include "src/Order.hpp"
#include "src/Product.hpp"
#include "src/Inventory.hpp"
#include "src/FileManager.hpp"

int main(int argc, char const *argv[])
{
    FileManager fm;
    // A leitura dos arquivos será no padrão
    // $PREÇO$;$VALOR$;$
    std::vector<Product> products = fm.load_from_file("products");
    Inventory inv(products);
    inv.show();
    Cart cart("Romildo");
    cart.add(Product("BANANA", 10, 1.5));
    cart.add(Product("AMEIXA", 2, 9));
    cart.buy();

    return 0;
}
