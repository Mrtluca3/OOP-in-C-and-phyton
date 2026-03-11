#include "RegularHexagon.h"

Hexagon::Hexagon(double t) : Shape() { //t è il lato dell"esagono
    Vertices_+=6;
    t_=t; 
    setSurface(); setPerimeter();
}

Hexagon::Hexagon(Hexagon& H) : Shape() { //t è il lato dell"esagono
    Vertices_+=6;
    t_=H.getSide(); 
    setSurface(); setPerimeter();
}

Hexagon::~Hexagon() {
    Vertices_-=6;
    std::cout << "Destructor called for Hexagon" << std::endl;
}

//Getters
double Hexagon::getSide() const {return t_; }
double Hexagon::getSurface() const { return S_; }
double Hexagon::getPerimeter() const { return P_; }
double Hexagon::getVolume() const { return 0; }
void Hexagon::Print() const { std::cout << "The regular hexagon has length " << t_ << " m; Surface: " << S_ << " m^2; Perimeter: " << P_ << " m." << std::endl; }

//Setters
void Hexagon::setSurface() { S_ = 3*std::sqrt(3)*0.5*t_;  this->setShapeSurface(S_); }
void Hexagon::setPerimeter() { P_ = 6*t_; }
void Hexagon::setVolume()  { }

