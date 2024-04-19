//
// Created by User on 03.06.2022.
//

#ifndef UNTITLED28_SEGMENT_H
#define UNTITLED28_SEGMENT_H


#include <ostream>

class Segment {
    double A,B;
public:
    Segment(double a, double b);
    //nadpisanie operatorów
    Segment operator*(const double d);
    Segment operator/(const double d);
    Segment operator+(const double d);
    Segment operator-(const double d);
    Segment operator+(const Segment se);
    friend std::ostream &operator<<(std::ostream &os, const Segment &segment);// przeciążanie operatora funkcją friend(bardzo przydatne)
    friend Segment operator*(const double d,const Segment &segment);
    friend Segment operator+(const double d,const Segment &segment);
    bool operator()(const double d);

};


#endif //UNTITLED28_SEGMENT_H
