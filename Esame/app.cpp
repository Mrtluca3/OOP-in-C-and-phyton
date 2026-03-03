#include <iostream>
#include "Particle.h"
#include "Barrier.h"


int main(void) {
    std::vector<double> p;
    p.resize(3); //Momenta full of zeros
    Particle electron, proton(938, 1, p); //I create an electron and a proton
    
    electron.Print(); //check if everything is working
    proton.Print();

    //show some methods functionalities
    for(int i=0; i<3; i++) //change momenta
        p[i]=5.5/sqrt(3); 
    
    electron.setMomenta(p);
    proton.setCharge(20);
    electron.Print(); //check if everything is working
    proton.Print();

    //Define the Barrier
    double rho=2.2, I=81;
    int A = 12, Z=6;
    Barrier Carbon(electron, rho, A, Z, I), hydrogen;
    //Do some checks and show how the methods work
    hydrogen.Print();
    hydrogen.getParticleInfo();
    hydrogen.setParticle(proton);
    hydrogen.getParticleInfo();
    Carbon.Print(); //Check if all infos are stored correctly
    Carbon.getParticleInfo(); 
    std::cout<< "Stopping power: " << Carbon.S() << " eV*g/cm^3" << std::endl;
    hydrogen.setParticle(electron);
    std::cout << hydrogen.S() << std::endl;

    return 0;
}