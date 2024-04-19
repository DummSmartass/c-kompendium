//
// Created by User on 03.06.2022.
//

#include "Segment.h"

Segment::Segment(double a, double b) : A(a), B(b) {}

Segment Segment::operator*(const double d) {
    return Segment(A*d, B*d);
}
Segment Segment::operator/(const double d){

    return Segment(A/d,B/d);
}

Segment Segment::operator+(const double d) {
    return Segment(A+d, B+d);
}

Segment Segment::operator-(const double d) {
    return Segment(A-d, B-d);
}
bool Segment::operator()(const double d) {
    return A<=d && B>=d;
}
Segment Segment::operator+(const Segment se) {
    double tmpA = A < se.A?A:se.A;
    double tmpB = B > se.B?B:se.B;
    return Segment(tmpA,tmpB);
}
//globalne
std::ostream &operator<<(std::ostream &os, const Segment &segment) {
    os << "[" << segment.A << "," << segment.B<<"]";
    return os;
}
Segment operator*(const double d,const Segment &segment){
    return Segment(segment.A*d, segment.B*d);
}
Segment operator+(const double d,const Segment &segment){
    return Segment(segment.A+d, segment.B+d);
}








