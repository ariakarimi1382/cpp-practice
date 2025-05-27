#include "Pair.h"


namespace seneca
{
    bool operator==(const Pair& lhs, const Pair& rhs) {
        return lhs.m_key == rhs.m_key;
    }

    Pair& Pair::operator=(const Pair& src){
        if (&src != this){
            m_key = src.m_key;
            m_value = src.m_value;
        }
        return *this;
    }
    Pair::Pair(const Pair& src){*this = src;}

    std::ostream& operator<<(std::ostream& os, const Pair& pair) {
        
        os << pair.getKey() << ": " << pair.getValue();
        return os;
    }
}