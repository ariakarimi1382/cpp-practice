#ifndef SENECA_PAIR_H
#define SENECA_PAIR_H
#include <string>
#include <ostream>


namespace seneca {
    class Pair
    {
        std::string m_key{};
        std::string m_value{};
    public:
        const std::string& getKey() const {return m_key; }
        const std::string& getValue() const { return m_value; }
        Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value }{};
        Pair() = default; // Add this line
        
        Pair& operator=(const Pair&);
        Pair(const Pair&);
        ~Pair(){};
        
        // Friend declaration for operator==
        friend bool operator==(const Pair& lhs, const Pair& rhs);
        friend std::ostream& operator<<(std::ostream& os, const Pair& pair);

        // TODO: Add here the missing prototypes for the members
        //           that are necessary if this class is to be used
        //           with the template classes described below.
        //       Implement them in the Pair.cpp file.
        
    };
}


#endif