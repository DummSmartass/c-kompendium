//
// Created by sasharz on 13.05.2022.
//

#ifndef UNTITLED_TRIANGLE_H
#define UNTITLED_TRIANGLE_H
#include <iostream>
// elementy powyrzej stanowią baze pliku.h

//Alt + insert


// w tym pliku deklaruje się istnienie zmiennych i funkcji danych klas, a strałki zlewej strony pozwalają do nich nawigować
using namespace std;
class Triangle // klasanazwaklasy
{
public: // elementy publiczne
    int a; // zapisane elementy publiczne
protected: // elementy protected
    int b; // zapisane  elementy protected
private: // elementy prywatne
    int c=1; // zapisane elementy prywatne + ustawianie wartości domyślnej

public: // elementy publicznezne
    Triangle() ;// konstrukto bez zmiennych - przypisuje zmiennym wewnatrzklasy wartości
    Triangle(int a, int b, int c); //konstruktor z trzema wmiennymi - przypisuje zmiennym wewnatrzklasy wartości

    ~Triangle();// destruktor - destruktor wywoływany jest w przypadku usónięciaobiektu
    //pamiętaj, że potrzeba urzywać destruktorów jak obiek tworzy np listy albo arraye, trzeba je odręnbnie usówać za pomocą delete[]

    int getA() const; // getA - zwraca wartość zmiennej a, const po funkcji oznacza, że tafunkcjanie zmieni elementu naktórym jest wykonywana
    void setA(int a); // setA - przypisuje wartość zmiennej a
    int getB() volatile;// funkcje volotile, nie optymalizują programu, ale są przydatne w multi thereadinu, bo zawsze odwołują się do piewotnej zmiennej ergo wiedzą o zmiannach jeje wartości, nawet jako dzieją sie one w trakcie ich wykonywania + działają jak const
    void setB(int b);
    int getC() const;
    void setC(int c);

    operator double () const// dzięki temu funkcje przyjmujące double terazmogą przyjmować triangle
    {
        return a+b+c;
    }

    static void into(Triangle t); // - funkcja statyczne to funkcje dostępne w innych klasach,tak je się deklaruje

};


#endif //UNTITLED_TRIANGLE_H