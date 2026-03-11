#include "Satellite.h"
#include <iostream>

Satellite::Satellite(){
    m_=0;
    A_=0;
    for(int i = 0; i <3; i++) {
        r0_.push_back(0);
        v0_.push_back(0);
    }
}

Satellite::Satellite(const double& m, const double& A, const std::vector<double>& r0, const std::vector<double>& v0) {
    m_ = m; 
    A_ = A;
    if(r0.size() != 3 || v0.size() != 3) {
        std::cout << "The position or velocity array size should be of length 3!" << std::endl;
        exit(0);
    } 
    for(int i = 0; i <3; i++) {
        r0_.push_back(r0[i]);
        v0_.push_back(v0[i]);
    }
}

Satellite::Satellite(Satellite& S) {
    m_ = S.getMass();
    A_ = S.getArea();
    for(int i = 0; i <3; i++) {
        r0_.push_back(S.getPosition()[i]);
        v0_.push_back(S.getVelocity()[i]);
    }
}

Satellite::~Satellite() {} // destructor


//getters
double Satellite::getMass() const { return m_; }
double Satellite::getArea() const {return A_;}
std::vector<double> Satellite::getPosition() const {return r0_;}
std::vector<double> Satellite::getVelocity() const {return v0_;}



//setters
void Satellite::setMass(const double& m) {m_ = m;}
void Satellite::setArea(const double& A) {A_ = A;}
void Satellite::setPosition(const std::vector<double>& r0) {
    if(r0.size() != 3) {
        std::cout << "The position array size should be of length 3!" << std::endl;
        exit(0);
    } 
    for(int i = 0; i <3; i++) 
        r0_.push_back(r0[i]);
}
void Satellite::setVelocity(const std::vector<double>& v0) {
    if(v0.size() != 3) {
        std::cout << "The position array size should be of length 3!" << std::endl;
        exit(0);
    } 
    for(int i = 0; i <3; i++) 
        v0_.push_back(v0[i]);
}
