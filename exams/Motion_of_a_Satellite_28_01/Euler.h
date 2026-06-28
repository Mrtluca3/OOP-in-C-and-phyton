#ifndef Euler_h
#define Euler_h
#include "FlySatellite.h"
#include <iostream>
class Euler: public FlySatellite{
    public:
    Euler(Satellite& satellite, Planet& planet, double dt=1e-2, unsigned int N=100, double t0_=0.);
    virtual void simulation(); //abstract method
    

    //dtor
    virtual ~Euler() = default;
    //getters
    double& Dt() {return dt_;}
    unsigned int& N() {return N_;}
    private:
    double dt_;
    double t0_;
    unsigned int N_;
};

#endif