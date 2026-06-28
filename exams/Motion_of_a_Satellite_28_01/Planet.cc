#include "Planet.h"
Planet::Planet(const double& mass,const double& radius, const std::string& name, const double& F107, const double& Ap, const double& Cd){
    mass_=mass;
    radius_=radius;
    name_=name;
    atmosphere_=Atmosphere(F107, Ap, Cd);
}

Planet::Planet(const Planet& planet2){
    mass_=planet2.Mass();
    radius_=planet2.Radius();
    name_=planet2.Name();
    atmosphere_=Atmosphere(
                        planet2.atmosphere().F(),
                        planet2.atmosphere().Ap(),
                        planet2.atmosphere().Cd()
                        );
}