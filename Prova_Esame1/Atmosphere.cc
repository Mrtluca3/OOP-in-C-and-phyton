#include "Atmosphere.h"
#include "math.h"

Atmosphere::Atmosphere(){
    F_ten_=0;
    Ad_=0;
    Cd_=0;
}

Atmosphere::Atmosphere(const double& F_ten, const double& Ad, const double& Cd) {
    F_ten_ = F_ten;
    Ad_ = Ad;
    Cd_ = Cd;
}
Atmosphere::Atmosphere(const Atmosphere& A) { //Copy constructor
    F_ten_ = A.getF_ten();
    Ad_ = A.get_Ad();
    Cd_ = A.get_Cd();
} 

Atmosphere::~Atmosphere() {} //call the destructor

//getters
double Atmosphere::getF_ten() const { return F_ten_; }
double Atmosphere::get_Ad() const { return Ad_; }
double Atmosphere::get_Cd() const { return Cd_; }

double Atmosphere::getTemp() const { return T_; }
double Atmosphere::getDensity() const { return rho_; }
double Atmosphere::getViscosity() const { return mu_;}
double Atmosphere::getHeight() const { return h_;}

//setter
void Atmosphere::set_height(const double& h) { //Updates all values related to h
    h_ = h;
    if ((h_ >= 180e3) && (h_ < 1000e3)) {
        T_ = 900. + 2.5*(F_ten_ - 70.) + 1.5*Ad_;
        mu_ = 27. - 0.012 * (h/1000 - 200);
        rho_ = 6.e-10 * exp(-(h/1000 - 175 )*mu_/T_);
    } else if(h_ < 180e3){
        rho_ = 1000;
    } else
        rho_ = 0;
} 
