#include "Sphere.h"

Sphere::Sphere(double mass, double radius): RotatingSolidBody(mass){
    radius_=radius;  
    inertia_=0.4 * mass_ * radius_ * radius_;
}

const Sphere& Sphere::Print(std::string comment) const{
    using namespace std;
    cout << comment << endl;
    cout << "This is a sphere of radius[m]: "<< radius_ <<endl;
    this->RotatingSolidBody::Print();
    return *this; 
}