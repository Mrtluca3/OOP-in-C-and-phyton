#include "RotatingSolidBody.h"


RotatingSolidBody::RotatingSolidBody(double mass){
    mass_=mass;
    omega_=0.;
    inertia_=0.;
    Kinetic_=0.;
    d_=0.;
}
//Print method
const RotatingSolidBody& RotatingSolidBody::Print() const{ 
    using namespace std;
    cout << "Mass[Kg]: " << mass_ << " Omega[Hz]: " << omega_ << " Inertia[Kg m^2]: "<<inertia_ <<endl;
    cout <<"Kinetic energy[J]: " << Kinetic_ <<" distance Rot-axis - CoM-axis[m]: " << d_ <<endl; 
    return *this;
}

std::ostream& operator<<(std::ostream& os, const RotatingSolidBody& solid){
    using namespace std;
    os << "Mass[Kg]: " << solid.mass_ << " Omega[Hz]: " << solid.omega_ << " Inertia[Kg m^2]: "<< solid.inertia_ <<endl;
    os <<"Kinetic energy[J]: " << solid.Kinetic_ <<" distance Rot-axis - CoM-axis[m]: " << solid.d_ <<endl; 
    return os;
}

//Spin method
RotatingSolidBody& RotatingSolidBody::Spin(double d, double omega){
    d_=d;
    omega_=omega;
    Kinetic_=0.5*omega_*omega_*(inertia_ + mass_ *d_*d_);
    return *this;
}

