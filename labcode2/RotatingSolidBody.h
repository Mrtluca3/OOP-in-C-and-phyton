#include <iostream>
#include <cmath>

#ifndef RotatingSolidBody_h
#define RotatingSolidBody_h


class RotatingSolidBody{ // rotating solids with uniform density0
    public:
    //ctor
    RotatingSolidBody(double mass=0. ); //double omega=0., double inertia=0., double Kinetic=0., double distance=0.
    //dtor
    ~RotatingSolidBody(){}
    //getters
    inline double mass()const {return mass_;}
    inline double omega() const{return omega_;}
    inline double inertia() const{return inertia_;}
    inline double Kinetic() const{return Kinetic_;}
    inline double d() const {return d_;}
    //setters
    inline RotatingSolidBody& set_mass(double m) {mass_=m; return *this;}
    inline RotatingSolidBody& set_omega(double o) {omega_=o; return *this;}
    inline RotatingSolidBody& set_inertia(double i) {inertia_=i; return *this;}
    inline RotatingSolidBody& set_Kinetic(double k) {Kinetic_=k; return *this;}
    inline RotatingSolidBody& set_d(double dist)  {d_=dist; return *this;}

    //print method
    const RotatingSolidBody& Print() const;
    friend std::ostream& operator<<( std::ostream& os, const RotatingSolidBody& solid); //here const RotatingSolidBody& solid 
    //Spin method
    RotatingSolidBody& Spin(double d, double omega);

    protected: 
    double mass_, omega_, inertia_, Kinetic_;
    double d_; //distance  between rotation axis and CoM axis
};
#endif