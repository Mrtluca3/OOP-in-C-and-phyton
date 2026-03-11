#include "Particle.h"


Particle::Particle() {
    mass_ = 0.511; //electron's mass
    z_ = -1; //electron's charge
    p_.resize(3); //I make p vector 3D; the particle is standing still
} //default constructor

Particle::Particle(double mass, int z, const std::vector<double>& p) {
    if (mass<0.0) { //check if the mass is physical
        std::cout << "The particle's mass must be positive" <<std::endl;
        exit(0);
    }
    mass_ = mass;
    z_ = z;
    if (p.size() !=3) { //check the momenta dimensionality if it's correct
        std::cout << "The momenta's vector needs to be three dimensional" <<std::endl;
        exit(0);
    }
    for(int i=0; i<3; i++) 
        p_.push_back(p[i]);
} //custom constructor

Particle::Particle(const Particle& P) {
    mass_ = P.getMass();
    z_ = P.getCharge();
    for(int i=0; i<3; i++)
        p_.push_back(P.getMomenta()[i]);
} //copy constructor
Particle::~Particle() {} //destructor





//getters
double Particle::getMass() const { return mass_; } //returns the mass of the particle
int Particle::getCharge() const { return z_; } //returns the charge of the particle in units of 'e' (electron's charge)
std::vector<double> Particle::getMomenta() const { return p_;} //returns 3D vector with the values of momenta




//setters
void Particle::setMass(double mass) {
    if (mass<0.0) { //check if the mass is physical
        std::cout << "The particle's mass must be positive" <<std::endl;
        exit(0);
    }
    mass_ = mass;
} //to change the particle's mass
void Particle::setCharge(int z) { z_ = z; } //to change the particle's charge (it must be in units of 'e')
void Particle::setMomenta(const std::vector<double>& p) {
    if (p.size() !=3) { //check the momenta dimensionality if it's correct
        std::cout << "The momenta's vector needs to be three dimensional" <<std::endl;
        exit(0);
    }
    for(int i=0; i<3; i++) 
        p_[i] = p[i];
} //to change particle's 3-momenta





//Other Methods
double Particle::beta() const {
    return sqrt(ModSq(p_)/(ModSq(p_)+mass_*mass_)); //since are inputed in natural units, I don't need c
} //returns velocity/(speed of light) of the particle

double Particle::ModSq(const std::vector<double>& v) const {
    double temp =.0; //temporary variable that will store the modulus squared
    for(int i=0; i<v.size(); i++)
        temp += v[i]*v[i];
    return temp; 
} //returns the modulus squared of a vector, private since I don't want it to be accessible

void Particle::Print() const {
    std::cout<< "The particle has the following attributes: \nMass: " << mass_ <<"MeV/c^2\nCharge: " << z_ << "e\nMomentum: ";
    for(int i=0; i<3; i++) 
        std::cout<< p_[i] <<' ';
    std::cout<<"MeV/c\nBeta: " <<beta() << "\n" <<std::endl;
    
}//gives, particle's informations
