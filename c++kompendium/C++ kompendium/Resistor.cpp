//
// Created by User on 26.05.2022.
//

#include "Resistor.h"
#include <string>
Resistor::Resistor(): opor(0) {}

Resistor::Resistor(double opor) : opor(opor) {}

double Resistor::r() const
{
    return opor;
}

void Resistor::r(double opor) noexcept
{
    Resistor::opor = opor;
}
std::ostream& operator<<(std::ostream &os, const Resistor &resistor)
{
    return  os<<std::to_string(resistor.opor);// posyła do elementu typu osteram(do którego odwołanie dostajemy) string utworzony z zmiennej opór
}







