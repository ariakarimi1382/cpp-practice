#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include "Pair.h"
#include <iostream>


namespace seneca {

    template <typename T, unsigned CAPACITY>
    class Collection {
        static T defaultVal;
        size_t sizeVal{};
        T array[CAPACITY];
    public: 
        size_t size() const;
        void display(std::ostream& os = std::cout);
        virtual bool add(const T& item);
        T& operator[](unsigned i);
        virtual ~Collection(){};
        Collection(){};
    };
    template <typename T, unsigned CAPACITY>
    T Collection<T, CAPACITY>::defaultVal{};

    template<>
    Pair Collection<Pair, 100>::defaultVal{"No Key", "No Value"};





        template<typename T, unsigned CAPACITY>
    size_t Collection<T, CAPACITY>::size() const {
        return sizeVal;
    }

    template<typename T, unsigned CAPACITY>
    void Collection<T, CAPACITY>::display(std::ostream& os){
        for (size_t i = 0; i < sizeVal; i++){
            os << array[i] << std::endl;
        }
    }
    template<typename T, unsigned CAPACITY>
    T& Collection<T, CAPACITY>::operator[](unsigned i){
        return i < sizeVal ? array[i] : defaultVal;
    }
    template<typename T, unsigned CAPACITY>
    bool Collection<T, CAPACITY>::add(const T& item){
        if (sizeVal <= CAPACITY){
            array[sizeVal] = item;
            
            sizeVal++;
            return true;
        } else {
            return false;
        }
    }
}

// ...existing code...





#endif