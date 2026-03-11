#include "Sphere.h"

Sphere::Sphere() : RotatingSolidBody() {}
Sphere::Sphere(double Mass, double R) : RotatingSolidBody(Mass) {R_= R; this->setI();}
Sphere::~Sphere() {}

//Getter
        
double Sphere::KineticEnergy() const {   return K; }
double Sphere::Inertia() const { return I_;}
double Sphere::getR() const {return R_;}
void Sphere::Print() {
    this->setI(); this->setK();
    std::cout << std::endl;
    std::cout << "The sphere has the following parameters: w=" << w_ << "Hz; Mass=" << Mass_ << "kg; d=" << d_ << "m" << "; R = " << R_  << "m" << std::endl;
    std::cout << "Kinetic energy of the sphere: " << this->KineticEnergy() << "J, Inertia of the sphere: " << this->Inertia()<< "kg*m^2"  << std::endl;
    std::cout << std::endl;
}

//Setters
void Sphere::setI() { 
    I_ = R_*R_*Mass_*.4 + d_*d_*Mass_; 
} 

void Sphere::setK(){
    K = I_*w_*w_*.5;
}

void Sphere::Spin(double w, double d){
    w_=w; d_=d;
    this->setI();
    K = I_*w_*w_*.5;
}
void Sphere::setd(const double& d) {
    d_=d;
    this->setI();
}