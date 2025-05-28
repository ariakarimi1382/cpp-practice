#include "confirmationOrder.h"
#include <iostream>


namespace seneca{
    ConfirmationOrder::ConfirmationOrder(){
        count = 0;
        size = 0;
        ToyArray = nullptr;
    }
    ConfirmationOrder& ConfirmationOrder::operator+=(const Toy& toy){
        for (size_t i = 0; i < count; i++){
            if (ToyArray[i] == &toy){
                return *this;
            }
        }
        if (size > count){
            ToyArray[count] = &toy;
            count++;
        }
        else if (size == count){
            size == 0 ? size++ : size *= 2;
            const Toy** temp = new const Toy*[size];
            if (count != 0){
                for (size_t j = 0; j < count; j++){
                temp[j] = ToyArray[j];
            }
            }
                
            delete [] ToyArray;
                
            ToyArray = temp;
                
            ToyArray[count] = &toy;
            count++;
                
        }
        
        return *this;
    }

    ConfirmationOrder& ConfirmationOrder::operator-=(const Toy& toy){
        
        bool valid = false;
        size_t idx = count;
        for (size_t i = 0; i < count && !valid; i++){
            if (ToyArray[i] == &toy){
                valid = true;
                idx = i;
            }
        }
        if (!valid){
            return *this;
        }
        // ToyArray only stores pointers to Toy objects that are managed elsewhere (you do not own them)
        //so you should not delete the object
        //delete ToyArray[idx];
        count--;
        for (size_t j = idx; j < count; j++){
            ToyArray[j] = ToyArray[j + 1];
        }
        return *this;
        
    }

    std::ostream& operator<<(std::ostream& os, const ConfirmationOrder& co) {
        os << "--------------------------" << std::endl;
        os << "Confirmations to Send" << std::endl;
        os << "--------------------------" << std::endl;
        if (co.count == 0) {
            os << "There are no confirmations to send!" << std::endl;
        } else {
            for (size_t i = 0; i < co.count; ++i) {
                if (co.ToyArray[i]) {
                    os << *(co.ToyArray[i]) << std::endl;
                }
            }
        }
        os << "--------------------------" << std::endl;
        return os;
    }

}