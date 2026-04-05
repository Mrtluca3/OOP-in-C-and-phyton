#include "Rectangle.h"

Rectangle::Rectangle(double mass, double a, double b) : RotatingSolidBody(mass){
    a_=a;
    b_=b;
    inertia_ = mass_ * (a_*a_ +b_*b_)/12.;
}
const Rectangle& Rectangle::Print(std::string comment) const {
    using namespace std;
    cout << comment << endl;
    cout << "This is a rectangle of sides a[m]: "<< a_ << " and b[m]: "<< b_ << endl;
    this-> RotatingSolidBody::Print();
    return *this;
}