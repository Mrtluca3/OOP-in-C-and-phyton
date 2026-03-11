#include "FlySatellite.h"

FlySatellite::FlySatellite(const double& dt, const int& N, const Planet& P, const Satellite& S, const Atmosphere& A) {
    dt_= dt;
    N_ = N;
    P_ = P;
    S_ = S;
    A_ = A;

} //Constructor

FlySatellite::~FlySatellite() {} //Destructor

double FlySatellite::getVectorMod(const std::vector<double>& v0) {
    double v0mod=0;
    for(int i=0; i < 3; i++)
        v0mod += v0[i]*v0[i];
    return sqrt(v0mod);
}

std::vector<double> FlySatellite::Function(const std::vector<double>& r0, const std::vector<double>& v0) {
    std::vector<double> func, h; //r0_ref is the position of the satellite from the surface level
    double D, v0_mod = this->getVectorMod(v0); 
    for(int i = 0; i<3; i++) //I see the problem from the Planet's center of mass frame of reference
        h.push_back(r0[i]-P_.getRadius()*r0[i]/this->getVectorMod(r0));
    double r0_mod = this -> getVectorMod(r0);
    
    A_.set_height(this->getVectorMod(h));
    for(int i = 0; i<3; i++) {
        D = -.5*A_.getDensity()*A_.get_Cd()*S_.getArea()*v0[i]*v0_mod;
        func.push_back(-G*P_.getMass()*r0[i]/(r0_mod*r0_mod*r0_mod) + D/S_.getMass());
    }
    for(int i=0; i<3; i++)
        func.push_back(v0[i]);

    return func;
}
