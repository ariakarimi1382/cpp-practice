#ifndef SENECA_PROTEINDATABASE_H
#define SENECA_PROTEINDATABASE_H
#include <iostream>
#include <string>
//#include <chrono>
#include <iomanip>

namespace seneca {

    class ProteinDatabase{
        std::string* IDs{};
        std::string* acids{};
        int cnt{};
        std::string fileName{};
    public:
        size_t size();
        std::string operator[](size_t);
        std::string getUID(size_t);
        ProteinDatabase(){};
        ProteinDatabase(std::string);
        ~ProteinDatabase();                                      // Destructor
        ProteinDatabase(const ProteinDatabase&);                  // Copy constructor
        ProteinDatabase& operator=(const ProteinDatabase&);       // Copy assignment
        ProteinDatabase(ProteinDatabase&&);              // Move constructor
        ProteinDatabase& operator=(ProteinDatabase&&);
    };
}



#endif