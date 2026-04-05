#include "Rod.h"

Rod::Rod(double mass, double length)  : RotatingSolidBody(mass){
    length_=length;
    inertia_=mass_*length*length/12;
}
const Rod& Rod::Print(std::string comment) const {
    using namespace std;
    cout << comment << endl;
    cout << "This is a Rod of length[m]: " << length_ <<endl;
    this->RotatingSolidBody::Print();
    return *this;
}