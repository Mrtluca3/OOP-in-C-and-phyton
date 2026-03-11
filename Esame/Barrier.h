#include "Particle.h"

#ifndef Barrier_h
#define Barrier_h
#define eps0 8.854e-12 //vacuum permittivity
#define Na 6.022e23 //Avogadro's Number
#define me 0.511 //electron's mass in natural units
#define e 1.6e-19 //electron's charge

class Barrier {
    public:
    Barrier(); //default constructor, creates an electron in air (full of hydrogen)
    Barrier(const Particle& P, double rho, double A, double Z, double I); //custom constructor P is the particle, rho (g/cm^3) the material's density, A the material's atomic mass, Z the material's atomic number, I (eV) the material's excitation energy
    ~Barrier(); //destructor

    //Getters
    double getDensity() const; //returns material's density
    int getAtomicMass() const; //returns material's atomic mass
    int getAtomicNumber() const; // returns material's atomic number
    double getExcitationE() const; // returns material's excitation energy
    void getParticleInfo() const; // uses the print method of particle

    //Setters
    void setDensity(double rho); //set the material's density
    void setAtomicMass(int A); //set the material's atomic mass
    void setAtomicNumber(int Z); //set the material's atomic number
    void setExcitationE(double I); //set the material's excitation energy
    void setParticle(const Particle& P); //set the particle hitting the material

    //Other Methods
    double S(); //returns the stopping power of the material in eV*g/cm^3
    void Print() const; //Gives the barrier's informations
    
    private:
    double rho_, I_; 
    int A_, Z_;
    Particle p_;
    //rho is the density (g/cm^3) of the material
    //A the atomic mass of the material
    //Z is the charge of the material
    //I (eV) the excitation energy of the material
};

#endif