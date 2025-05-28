#include "toy.h"
#include <string>
#include <iostream>
#include <iomanip>



namespace seneca{
    void Toy::update(int numItems){
        this->itemNum = numItems;
    }


    std::string trim(const std::string& str) {
        size_t start = str.find_first_not_of(" \t");
        size_t end = str.find_last_not_of(" \t");
        return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
        }
    Toy::Toy(const std::string& toy){
        //ID:NAME:NUM:PRICE

        std::string trimmedToy = trim(toy);
        size_t pos;

        // Extract ID
        pos = trimmedToy.find(':');
        id = std::stoi(trim(trimmedToy.substr(0, pos)));
        trimmedToy.erase(0, pos + 1);

        // Extract NAME
        pos = trimmedToy.find(':');
        name = trim(trimmedToy.substr(0, pos));
        trimmedToy.erase(0, pos + 1);

        // Extract NUM
        pos = trimmedToy.find(':');
        itemNum = std::stoi(trim(trimmedToy.substr(0, pos)));
        trimmedToy.erase(0, pos + 1);

        // Extract PRICE
        price = std::stod(trim(trimmedToy));

    }

        std::ostream& operator<<(std::ostream& os, const Toy& toy){
            os << "Toy " << std::setw(8) << std::right << toy.getID() << ": ";
            os << std::right << std::setfill('.') << std::setw(24) << toy.getName() << " ";
            os << std::setfill(' ') << std::right << std::setw(2) << toy.getQTY() << " items @ ";
            os << std::setw(6) << std::right << std::setprecision(2) << toy.getPrice() << "/item "
            << "subtotal: " << std::setw(7) << std::right << std::setprecision(2) << toy.getPrice() * toy.getQTY();
            os << "  tax: " << std::setw(6) << std::right << std::setprecision(2) << toy.getTax() << "  total: ";
            os << std::setw(6) << std::right << std::setprecision(2) <<(toy.getPrice() * (double)toy.getQTY()) + toy.getTax() << std::endl;
            return os;
        }

    Toy& Toy::operator=(const Toy& src){
        if (this != &src){
            id = src.id;
            name = src.name;
            itemNum = src.itemNum;
            price = src.price;
        }
        return *this;
    }
    Toy& Toy::operator=(Toy&& src) {
        if (this != &src) {
            id = src.id;
            name = std::move(src.name);
            itemNum = src.itemNum;
            price = src.price;
            // Reset source
            src.id = 0;
            src.name.clear();
            src.itemNum = 0;
            src.price = 0.0;
        }
        return *this;
    }

    Toy::Toy(const Toy& src){
        *this = src;
    }
    Toy::Toy(Toy&& src) {
        *this = std::move(src);
    }
}