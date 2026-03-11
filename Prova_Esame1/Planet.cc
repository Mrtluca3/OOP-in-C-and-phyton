#include "Planet.h"

Planet::Planet() {
    R_ = 0;
    M_ = 0;
} //constructor
Planet::Planet(double R, double M) {
    R_ = R;
    M_ = M;
} //constructor
Planet::Planet(Planet& P) {
    R_ = P.getRadius();
    M_ = P.getMass();
} //copy constructor
Planet::~Planet() {} //destructor

//Getters
double Planet::getMass() const { return M_; }
double Planet::getRadius() const { return R_; }

//Setters 
void Planet::setMass(const double& M) {M_ = M;}
void Planet::setRadius(const double& R) {R_ = R;}