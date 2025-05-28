#ifndef SENECA_CONFIRMATIONORDER_H
#define SENECA_CONFIRMATIONORDER_H
#include "toy.h"
namespace seneca
{
    class ConfirmationOrder{
        const Toy** ToyArray{};
        size_t count{};
        size_t size{};
    public:
        ConfirmationOrder& operator+=(const Toy& toy);
        ConfirmationOrder& operator-=(const Toy& toy);
        ConfirmationOrder();
        friend std::ostream& operator<<(std::ostream& os, const ConfirmationOrder& co);
}; // namespace seneca
}



#endif