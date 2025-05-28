#ifndef SENECA_TOY_H
#define SENECA_TOY_H
#include <string>
#include <iostream>

namespace seneca {
    class Toy{

//         id: the id of the toy (a positive number).
//         name: the name of the toy.
//         number of items: the number of toys of this type to be ordered.
//         price: the price of this toy (without tax).
//         harmonized sales tax: assume the HST is equal to 13%

        int id{};
        std::string name{};
        unsigned itemNum{};
        double price{};
        const double HST {0.13};
    public:
        Toy(){};
        Toy(const std::string& toy);
        void update(int numItems);
        int getID() const {return id;};
        std::string getName() const {return name;};
        unsigned getQTY() const {return itemNum;};
        double getPrice() const {return price;};
        double getTax() const {return price * HST;};
        Toy(const Toy&);
        Toy& operator=(const Toy&);
        Toy& operator=(Toy&& src);
        Toy(Toy&& src);
    };

    std::ostream& operator<<(std::ostream&, const Toy&);
    
}

#endif