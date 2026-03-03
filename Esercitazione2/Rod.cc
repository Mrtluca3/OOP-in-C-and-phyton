#include "Rod.h"

Rod::Rod() : RotatingSolidBody() {}
Rod::Rod(double Mass, double L) : RotatingSolidBody(Mass) {L_= L; this->setI(); }
Rod::~Rod() {}

//Getter
double Rod::KineticEnergy() const { return K; }
double Rod::Inertia() const { return I_;}
double Rod::getL() const {return L_;}
void Rod::Print() {
    this->setI(); this->setK();
    std::cout << std::endl;
    std::cout << "The Rod has the following parameters: w=" << w_ << "Hz; Mass=" << Mass_ << "kg; d=" << d_ << "m" << "; L = " << L_  << "m" <<  std::endl;
    std::cout << "Kinetic energy of the rod: " << this->KineticEnergy() << "J, Inertia of the rod: " << this->Inertia()<< "kg*m^2"  << std::endl;
    std::cout << std::endl;
}

//Setter 
void Rod::setI() {
    I_ = L_*L_*Mass_*.08333 + d_*d_*Mass_;
}

void Rod::setK() {
    K = I_*w_*w_*.5; 
}

void Rod::Spin(double w, double d){
    w_=w; d_=d;
    this->setI(); 
    K = I_*w_*w_*.5;
}
void Rod::setd(const double& d) {
    d_=d;
    this->setI();
}