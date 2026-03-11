#include <vector>
#include <iostream>

#ifndef Particle_h
#define Particle_h
#define c 299792458 //meters per second

class Particle {
    public:
    Particle(); //default constructor, creates a still electron
    Particle(double mass, int z, const std::vector<double>& p); //custom constructor, mass should be in MeV/c^2, the momenta in MeV/c
    Particle(const Particle& P); //copy constructor
    ~Particle(); //destructor

    //getters
    double getMass() const; //returns the mass of the particle in MeV/c^2
    int getCharge() const; //returns the charge of the particle in units of 'e' (electron's charge)
    std::vector<double> getMomenta() const; //returns 3D vector with the values of momenta in MeV/c

    //setters
    void setMass(double mass); //to change the particle's mass, should be in MeV/c^2
    void setCharge(int z); //to change the particle's charge (it must be in units of 'e')
    void setMomenta(const std::vector<double>& p); //to change particle's 3-momenta, should be in MeV/c

    //Other Methods
    double beta() const; //returns velocity/(speed of light) of the particle
    void Print() const; //gives particle's informations
    private:
    double ModSq(const std::vector<double>& v) const; //returns the modulus squared of a vector, private since I don't want it to be accessible

    double mass_;
    int z_;  //z is the charge of the particle in unit of 'e' (electron's charge)
    std::vector<double> p_; //3-momenta of the particle
};

#endif