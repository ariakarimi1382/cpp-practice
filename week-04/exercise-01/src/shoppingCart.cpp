#include "shoppingCart.h"
#include <string>


namespace seneca
{
    ShoppingCart::ShoppingCart(const std::string& name, int age, const Toy* toys[], size_t count){
        this->name = name;
        this->age = age;
        this->count = count;
        toyArray = new Toy*[count];
        for (int i = 0; i < count; i++){
            // Toy(*toys[i]); is using the copy constructor in the toy class to create an rvalue object of the parameter objects
            // and then that rvalue is copied in the toyArray 
            toyArray[i] = new Toy(*toys[i]);
        }
    }

    ShoppingCart::~ShoppingCart(){
        for (int i = 0; i < count; i++){
            delete toyArray[i];
        }
        delete [] toyArray;
    }

    ShoppingCart& ShoppingCart::operator=(const ShoppingCart& src){
        if (&src != this){
            if (toyArray != nullptr){
                for (int i = 0; i < count; i++){
                delete toyArray[i];
                }
                delete [] toyArray;
            }
            toyArray = new Toy*[src.count];
            for (int i = 0; i < src.count; i++){
                toyArray[i] = new Toy(*src.toyArray[i]);
            }
            name = src.name;
            age = src.age;
            count = src.count;
        }
        return *this;
    }
    ShoppingCart::ShoppingCart(const ShoppingCart& src){
        *this = src;
    }

     std::ostream& operator<<(std::ostream& os, ShoppingCart& src){
        static int CALL_CNT = 0;
        CALL_CNT++;

        os << "--------------------------" << std::endl;
        os << "Order " << CALL_CNT << ": ";

        // Invalid cart: toyArray is nullptr or negative age or empty name
        if (src.toyArray == nullptr || src.age < 0 || src.name.empty()) {
            os << "This shopping cart is invalid." << std::endl;
            os << "--------------------------" << std::endl;
            return os;
        }

        os << "Shopping for " << src.name << " " << src.age << " years old (" << src.count << " toys)" << std::endl;
        os << "--------------------------" << std::endl;

        if (src.count == 0) {
            os << "Empty shopping cart!" << std::endl;
            os << "--------------------------" << std::endl;
            return os;
        }

        for (size_t i = 0; i < src.count; ++i) {
            if (src.toyArray[i]) {
                os << *src.toyArray[i] << std::endl;
            }
        }
        os << "--------------------------" << std::endl;
        return os;
    }
} // namespace seneca
