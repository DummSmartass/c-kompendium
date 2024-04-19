//
// Created by User on 26.05.2022.
//
//dalsza posiadówka wymagana

#ifndef UNTITLED26_RESISTOR_H
#define UNTITLED26_RESISTOR_H


#include <ostream>

class Resistor
{
    double opor;
public:
    Resistor();
    Resistor(double opor);

    double r() const;// zwracanie zmiennych typu double kiedy this jest const

    void r(double opor) noexcept; // pisząc noexcept po funkcji zapewniasz kompilator, że nie będzie tu wyrzucanych rzadnych błędów( z tego co wiem pozwala to zaoszczędzić na wydajności)

    //przeciążenie operatorów zainicjowane jesrt w klasie, ale nie będące jej funkcją
    //TO WAZNE
    // w analogiczny sposób można pzeciążać metody wewnątrz przestrzeni pomięzy funkcjami i strukturami a funkcjąamain w mainine

    friend std::ostream& operator<<(std::ostream &os, const Resistor &resistor);
    Resistor operator* (const Resistor &r1)
    {
        opor = ((r() * r1.r()) / (r() + r1.r()));
        return *this ;//zwraca  odniesienie do tego samego elementu
    }

    Resistor operator+ (const Resistor &r1)
    {
        Resistor result;
        result.r( r() + r1.r());
        return result;
    }
};


#endif //UNTITLED26_RESISTOR_H
