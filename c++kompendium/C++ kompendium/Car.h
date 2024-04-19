//
// Created by User on 20.07.2022.
//

#ifndef UNTITLED2_CAR_H
#define UNTITLED2_CAR_H

#include "Vechicle.h"

#include <iostream>
using namespace std;

class Car : virtual Vechicle // Tak wygląda dziedziczenie
{

public:
    int AmountOfWheels;

    Car(string name, int AmountOfWheels)
            : Vechicle(name)
    //pisząc konstruktor musisz klasy dizedziczącej musisz odwołać siędo konstruktora klasy nadrzędenj, tak to się robi
    {
        this->AmountOfWheels=AmountOfWheels;
    }

    void nameOfClass();

    // funkcje ze słowym kluczowym override to nadpisane fnkcje z klasy nadrzędnej
    // tylko w pliku .h pisze sięoverride
    void elements() /*override*/ {cout<<"at least "<<AmountOfWheels<<" wheels"<<endl;}
    void describe() /*override*/
    {
        cout<<"It is a car with "<<AmountOfWheels<<" wheeles named "<<Vechicle::name<<endl;
        //jak widać masz dostęp do zmiennych z klasy nadrzędnej(które nie są prywatne)
    }

};


#endif //UNTITLED2_CAR_H
