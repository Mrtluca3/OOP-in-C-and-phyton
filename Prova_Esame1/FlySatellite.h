#include "Planet.h"
#include "Satellite.h"
#include "Atmosphere.h"

#include <iostream>
#include <fstream>
#include <vector>

#ifndef FlySatellite_h
#define FlySatellite_h
class FlySatellite {
    public:
    FlySatellite(const double& dt, const int& N, const Planet& P, const Satellite& S, const Atmosphere& A); //Constructor
    virtual ~FlySatellite(); //Destructor

    virtual void simulation()=0; //Function that will simulate the motion of the satellite
    static double getVectorMod(const std::vector<double>& v0);

    protected:
    virtual std::vector<double> Function(const std::vector<double>& r0, const std::vector<double>& v0);
    double dt_, G=6.67e-11; 
    int N_;
    Planet P_;
    Satellite S_;
    Atmosphere A_;
};
#endif