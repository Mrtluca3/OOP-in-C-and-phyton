#include "Rectangle.h"

Rectangle::Rectangle(double a, double b) : Shape() {
    Vertices_+=4;
    a_=a; b_=b;
    setSurface(); setPerimeter();
}

Rectangle::Rectangle(Rectangle& R) : Shape() {
    Vertices_+=4;
    a_=getA(); b_=R.getB();
    setSurface(); setPerimeter();
}

Rectangle::~Rectangle() {
    Vertices_-=4;
    std::cout << "Destructor called for Rectangle" << std::endl;
}

//Getters
double Rectangle::getA() const {return a_;}
double Rectangle::getB() const {return b_;}
double Rectangle::getSurface() const { return S_; }
double Rectangle::getPerimeter() const { return P_; }
double Rectangle::getVolume() const { return 0; }

void Rectangle::Print() const { std::cout << "The rectangle has lengths: [" << a_ << ", " << b_ << "] m; Surface: " << S_ << " m^2; Perimeter: " << P_ << " m." << std::endl; }

//Setters
void Rectangle::setSurface() { S_ = a_*b_;  this->setShapeSurface(S_);}
void Rectangle::setPerimeter() { P_ = 2*(a_+b_); }
void Rectangle::setVolume()  { }


