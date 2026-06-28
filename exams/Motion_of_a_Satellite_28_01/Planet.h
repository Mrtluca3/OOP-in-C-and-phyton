#ifndef Planet_h
#define Planet_h

#include <iostream>
#include "Atmosphere.h"
class Planet{
    public: 
        //ctor
        Planet(const double& mass=5.972*1e24,const double& radius=6371, const std::string& name="Earth", const double& F107=182.5, const double& Ap=200, const double& Cd=2.);
        //copy ctor
        Planet(const Planet& planet2);
        
        //no position needed since no motion caused by satellite

        //getters
        inline const double& Mass() const {return mass_;}
        inline const double& Radius() const {return radius_;}
        inline const std::string& Name() const {return name_;}
        inline const Atmosphere& atmosphere() const {return atmosphere_;}
        //dtor
        ~Planet() = default; 
    private: 
        double mass_, radius_;
        std::string name_;
        Atmosphere atmosphere_;
};

#endif