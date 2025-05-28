#ifndef SENECA_SHOPPINGCART_H
#define SENECA_SHOPPINGCART_H
#include "toy.h"
#include <string>
#include <iostream>
namespace seneca {

    class ShoppingCart{
        Toy** toyArray{};
        std::string name {};
        int age {};
        size_t count {};
    public:
        ShoppingCart(const std::string& name, int age, const Toy* toys[], size_t count);
        ~ShoppingCart();
        ShoppingCart(const ShoppingCart&);
        ShoppingCart& operator=(const ShoppingCart&);
        friend std::ostream& operator<<(std::ostream&, ShoppingCart&);

    };

    
}


#endif