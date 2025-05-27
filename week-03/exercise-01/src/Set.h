#ifndef SENECA_SET_H
#define SENECA_SET_H
#include "Collection.h"


namespace seneca {
    template <typename T>
    class Set : public Collection<T, 100> {
    public:
        bool add(const T& item) override;
        ~Set() override;
    };

        template <typename T>
    bool Set<T>::add(const T& item){
    // this->size() tells the compiler to look in the base class template for size.
    // Without this->, the compiler may not find the member in the template base class and will give an error.
        for (size_t i = 0; i < this->size(); i++){
            if ((*this)[i] == item)
            return false;
        }

        return Collection<T, 100>::add(item);
    }


    template<>
    bool Set<double>::add(const double& item){
        // Ensure Set<double> inherits from Collection<double, 100>
        for (size_t i = 0; i < this->size(); i++){
            if(std::fabs((*this)[i] - item) <= 0.01)
                return false;
        }
        return Collection<double, 100>::add(item);
    }

    template <typename T>
    Set<T>::~Set() {}

}


#endif