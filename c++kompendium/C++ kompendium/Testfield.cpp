//
// Created by User on 31.05.2022.
//
#include "Testfield.h"

void Testfield::change(int a) const
{
    v1=a;// zmienna mutable może być zmieniana w funkcji const
}
Testfield::Testfield(int v1, int v2) : v1(v1), v2(v2) {}


#include "Testfield.h"
