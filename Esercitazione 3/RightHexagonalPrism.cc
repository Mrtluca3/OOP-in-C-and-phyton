#include "RightHexagonalPrism.h"

RightHexagon::RightHexagon(double t, double h) : Prism(h) { //t è il lato dell'esagono
    Vertices_+=6; // Gli altri 6 vengono costruiti in Hexagon
    t_=t; 
    H = new Hexagon(t);
    setSurface(); setPerimeter(); setVolume();
}

RightHexagon::RightHexagon(RightHexagon& RH) : Prism(RH.getH()) { //t è il lato dell'esagono
    Vertices_+=6; // Gli altri 6 vengono costruiti in Hexagon
    t_=RH.getSide(); 
    H = new Hexagon(t_);
    setSurface(); setPerimeter(); setVolume();
}

RightHexagon::~RightHexagon() {
    Vertices_-=6;
    std::cout << "Destructor called for RightHexagonalPrism" << std::endl;
    delete H;
}

//Getters
double RightHexagon::getSide() const { return H->getSide();}
double RightHexagon::getSurface() const { return S_; }
double RightHexagon::getPerimeter() const { return P_; }
double RightHexagon::getVolume() const { return V_; }
double RightHexagon::getH() const { return h_; }
void RightHexagon::Print() const { std::cout << "The right hexagonal prism has length " << t_ << " m; Surface: " << S_ << " m^2; Perimeter: " << P_ << " m; Volume: " << V_  << " m^3." << std::endl; }

//Setters
void RightHexagon::setSurface() { S_ = H->getSurface()*2 + t_*h_*6;  this->setShapeSurface(S_);}
void RightHexagon::setPerimeter() { P_ = H->getPerimeter()*2 + h_*6; }
void RightHexagon::setVolume() { V_ = H->getSurface()*h_; this->setShapeVolume(V_);}


