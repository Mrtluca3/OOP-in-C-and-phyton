#include "Rectangle.h"

Rectangle::Rectangle() : RotatingSolidBody() {}
Rectangle::Rectangle(double Mass, double a, double b) : RotatingSolidBody(Mass) {a_= a; b_=b; this->setI(); ratio = a/b; }
Rectangle::~Rectangle() {}

//Getter
double Rectangle::KineticEnergy() const {return K; }
double Rectangle::Inertia() const {return I_;}
double Rectangle::getA() const {return a_;}
double Rectangle::getB() const {return b_;}
void Rectangle::Print() {
    this->setI(); this->setK();
    std::cout << std::endl;
    std::cout << "The Rectangle has the following parameters: w=" << w_ << "Hz; Mass=" << Mass_ << "kg; d=" << d_ << "m" << "; L1 = " << a_  << "m" << "; L2 = " << b_  << "m" << std::endl;
    std::cout << "Kinetic energy of the rectangle: " << this->KineticEnergy() << "J, Inertia of the rectangle: " << this->Inertia()<< "kg*m^2"  << std::endl;
    std::cout << std::endl;
}

//Setter 
void Rectangle::setI() {
    I_ = (a_*a_ + b_*b_)*Mass_*.08333 + d_*d_*Mass_; 
}
void Rectangle::setK() {
    K = I_*w_*w_*.5; 
}

void Rectangle::Spin(double w, double d){
    w_=w; d_=d;
    this->setI(); this->setK(); //In teoria non e' necessario, ma magari in futuro aggiungo funzioni che richiedono K dopo Spin.
}

void Rectangle::setd(const double& d) {
    d_=d;
    this->setI();
}