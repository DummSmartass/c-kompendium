//
// Created by User on 31.05.2022.
//

#ifndef UNTITLED2_TESTFIELD_H
#define UNTITLED2_TESTFIELD_H


class Testfield
{
private:
    mutable int v1;// zmienna z mutable może być zmieniona nawet w funkcjach const
    int v2;

public:
    class testfield1
    {
    public:
        int a;
        int b;
        testfield1(int a1,int b1)// klasy mogą być zawarte wewnątrzklas
        {
            a=a1;
            b=b1;
        }
    };

    explicit Testfield(int v1, int v2);// explicite zapobiea niejawnej kowersji z pomocą tego konstuktora, kontruktor przyjmie tylko inty, nie przyjmie floatów, longów etc.

    void change(int a) const;

    int fun(const Testfield t)// pozwala używać wszystkich komponentów klasy w której jest zadeklarowna, jednocześnie nie bęąc funkcjątej kklasy
        // można zapisać funkcje w pliku.h, wtedy nie trzebateo robić w pliku cpp
    {
        return t.v1+t.v2;
    }

    // nadpisanie operaorów w klasie przykłady
    Testfield& operator--()
    {
         --v1;
         --v2;
         return *this;
    }

    const Testfield operator-() const
    {
        return Testfield(-v1,-v2);
    }

    const Testfield operator-(const Testfield& a) const
    {
        return Testfield(v1 - a.v1,v2 - a.v2);
    }








};


#endif //UNTITLED2_TESTFIELD_H
