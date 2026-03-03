#include "Barrier.h"

Barrier::Barrier() {
    rho_=1.0;
    A_=1;
    Z_=1;
    I_ = 13;
} //default constructor

Barrier::Barrier(const Particle& P, double rho, double A, double Z, double I) {
    p_=P; //set the wanted particle attributes
    if (rho<0.0) { //checking if it's a "possible" material
        std::cout << "Density must be positive" << std::endl;
        exit(0);
    }
    rho_ = rho; 

    if (I<0.0) { //check if the energy is positive
        std::cout << "Excitation energy must be positive" << std::endl;
        exit(0);
    }
    I_ = I; 

    if(A<0) { //checking if it's a "possible" material
        std::cout << "Atmoic mass must be positive" <<std::endl;
        exit(0);
    }
    A_=A;

    if(Z<0) { //checking if it's a "possible" material
        std::cout << "Atmoic number must be positive" <<std::endl;
        exit(0);
    }
    Z_=Z;

} //custom constructor
Barrier::~Barrier() {} //destructor





//Getters
double Barrier::getDensity() const { return rho_; }
int Barrier::getAtomicMass() const { return A_; }
int Barrier::getAtomicNumber() const { return Z_; }
double Barrier::getExcitationE() const { return I_;}
void Barrier::getParticleInfo() const { p_.Print(); }





//Setters
void Barrier::setDensity(double rho) { 
    if (rho<0.0) { //checking if it's a "possible" material
        std::cout << "Density must be positive" << std::endl;
        exit(0);
    }
    rho_ = rho; 
}
void Barrier::setAtomicMass(int A) {
    if(A<0) { //checking if it's a "possible" material
        std::cout << "Atmoic mass must be positive" <<std::endl;
        exit(0);
    }
    A_=A;
}
void Barrier::setAtomicNumber(int Z) {
    if(Z<0) { //checking if it's a "possible" material
        std::cout << "Atmoic number must be positive" <<std::endl;
        exit(0);
    }
    Z_=Z;
}
void Barrier::setExcitationE(double I) {
    if (I<0.0) { //check if the energy is positive
        std::cout << "Excitation energy must be positive" << std::endl;
        exit(0);
    }
    I_ = I; 
}
void Barrier::setParticle(const Particle& P) {
    p_ = P;
}





//Other Methods
double Barrier::S() {
    double temp1, temp2, beta; //I separate the calculation of S in 2 parts  
    beta = p_.beta();
    temp1 = ((e*e*e*e)*(p_.getCharge()*p_.getCharge())*Na*Z_*rho_)/(4*M_PI*eps0*eps0*(me*1.6e-13)*(beta*beta*A_));
    temp2 = log((2*me*1e6*beta*beta)/(I_*(1-beta*beta)))-beta*beta;
    return temp1*temp2/(e);
} //Stopping Power


void Barrier::Print() const {
    std::cout << "Barrier's informations:\nDensity: " << rho_ << "g/cm^3\nAtomic Mass: " << A_ << "\nAtomic Number: " << Z_ << "\nExcitation Energy: " << I_ <<"eV" << "\n" <<std::endl;
} //Gives the barrier's informations
