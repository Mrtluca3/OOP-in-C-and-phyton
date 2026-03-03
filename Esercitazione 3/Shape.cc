#include "Shape.h"

int Shape::Vertices_ = 0;

Shape::Shape() {}
Shape::~Shape() { std::cout<<"Destructor Called for shape"<< std::endl; }

void Shape::setShapeVolume(double V) {V_=V;}
void Shape::setShapeSurface(double S) {S_=S;}

double Shape::operator>(const Shape& R1) { 
    if (R1.V_ == 0 || this->V_ ==0 ) 
        return (bool) (this->S_ > R1.S_); 
    else
        return (bool) (this->V_ > R1.V_); 
}
bool Shape::operator<(const Shape& R1) { 
    if (R1.V_ == 0 || this->V_ ==0 ) 
        return (bool) (this->S_ > R1.S_); 
    else
        return (bool) (this->V_ > R1.V_); 
}



int Shape::getVertices() {
    return Vertices_;
}