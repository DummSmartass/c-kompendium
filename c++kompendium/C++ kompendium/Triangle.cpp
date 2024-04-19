//
// Created by sasharz on 13.05.2022.
//

#include "Triangle.h"

// tu się pisze klase ze zmiennymi i funkcjami

Triangle::Triangle() //zapisująć funkcje z danej klasy nalezy to zrobić odwołując się przez :: Nazwa_klasy::nazwa_funnkcji
{
    a=5;
    b=4;
    c=10;
}

Triangle::~Triangle()
{
}

Triangle::Triangle(int a, int b, int c) : a(a), b(b), c(c) {}// alternatywna metoda  tworzenia konstruktora

int Triangle::getA() const // inline powoduje poprawe wydajności, dlczego? Niemam pojęcia
{
    return a;
}
void Triangle::setA(int a)
{
    Triangle::a = a;
}
int Triangle::getB() volatile
{
    return b;
}
void Triangle::setB(int b)
{
    Triangle::b = b;
}
int Triangle::getC() const
{
    return c;
}
void Triangle::setC(int c)
{
    Triangle::c = c;
}

void Triangle::into(Triangle t) // nie pisze się static w zapisie funkcji static, bo ta cecha jest już określona w pliku klasy ..h
{
    cout<<t.a<<" "<<t.b<<" "<<t.c<<endl;
}