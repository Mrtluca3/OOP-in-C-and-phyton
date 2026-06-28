#include "FlySatellite.h"
FlySatellite::FlySatellite(Satellite& satellite, Planet& planet): 
    sat_(Satellite(satellite)), 
    plan_(Planet(planet))
    {

    }

std::vector<std::vector<double>> FlySatellite::Force(double ti, std::vector<std::vector<double>> u) const {
    std::vector<double> posit=u[0];
    std::vector<double> veloc=u[1];
    double mod=std::sqrt(std::inner_product(posit.begin(), posit.end(), posit.begin(), 0.0));
    mod = 1.0 / mod;
    
    // 1. Calculate vdot and rdot vectors
    std::vector<double> vdot = (-G * plan_.Mass() * mod * mod * mod) * posit + Dvector(u);
    std::vector<double> rdot = veloc;
    return {rdot, vdot};
}


std::vector<double> FlySatellite::Dvector(std::vector<std::vector<double>> u) const {
    double fact;
    std::vector<double> posit=u[0];
    std::vector<double> veloc=u[1];
    double mod=std::sqrt(std::inner_product(veloc.begin(), veloc.end(), veloc.begin(), 0.0));
    const double modpos=std::sqrt(std::inner_product(posit.begin(), posit.end(), posit.begin(), 0.0));

    fact=-0.5* plan_.atmosphere().rho(modpos-plan_.Radius()) * mod * sat_.A() * plan_.atmosphere().Cd();
    return fact * veloc;
    

}
