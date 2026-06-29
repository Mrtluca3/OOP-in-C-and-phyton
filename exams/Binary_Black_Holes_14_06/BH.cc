#include "BH.h"

double mirr_, m_, chi_;
BH::BH(const double& mirr, const double& m, const double& chi): mirr_(mirr), m_(m), chi_(chi){} //member list initializer

//ctors
BH BH::BH_mirr_m(const double& mirr, const double& m){
    return BH(mirr, m, Chicomp(m, mirr));    
}
BH BH::BH_mirr_chi(const double& mirr, const double& chi){
    return BH(mirr, Mcomp(mirr, chi), chi);
}
BH BH::BH_m_chi(const double& m, const double& chi){
    return BH(Mirrcomp(m,chi), m, chi);
}
BH BH::BH_chi(const double& chi, const double& m){
    return BH_m_chi(m ,chi);
}

//print
BH& BH::Print(){
    using namespace std;
    cout << "Black Hole with: m="<<m_<<", mirr="<<mirr_<<" chi="<<chi_ <<" Epensrose="<<E() <<endl;
    return *this;
}







double Chicomp(const double& m, const double& mirr){
    return sqrt(1.- (2. * (mirr*mirr) / (m*m) -1.)*(2. * (mirr*mirr) / (m*m) -1.));
}
double Mcomp(const double& mirr, const double& chi){
    return mirr / sqrt(0.5*(1+sqrt(1-chi*chi)));
}
double Mirrcomp(const double& m, const double& chi){
    return m*sqrt(0.5*(1+sqrt(1-chi*chi)));
}
