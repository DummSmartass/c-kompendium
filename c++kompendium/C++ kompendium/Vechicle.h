//
// Created by User on 20.07.2022.
//

#ifndef UNTITLED2_VECHICLE_H
#define UNTITLED2_VECHICLE_H

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////
//NIE WIEM CZEMU KIIEDY ODKOMENTOWUJE virtual I override WSZYTSKO PRZESTAJE DZIALAC
////////////////////////////////////////////////////////////////////////////////////

class Vechicle
{

public:
    string name;

    Vechicle(string name): name(name) {}
    void nameOfClass();
    // virtual to typ funkcji możliwych do nadpisania w funkcjach dziedziczących
    /*virtual*/ void describe(){cout<<"It moves"<<endl;}
    /*virtual*/ void elements();
};


#endif //UNTITLED2_VECHICLE_H
