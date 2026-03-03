#include "BH.h"
#include <cmath>

BH::BH() {} //default constructor

BH BH::fromSpin(const double& chi) {
    if(chi > 1.0 || chi < 0.0) {
        std::cout << "Angular momenta must be inside [0,1]" <<std::endl;
        exit(0);
    }
    return BH(1, chi);
}

BH BH::fromMass(const double& mass) {
    return BH(mass, 1);
}

BH::BH(const double& mass, const double& chi) {
    if(chi > 1.0 || chi < 0.0) {
        std::cout << "Angular momenta must be inside [0,1]" <<std::endl;
        exit(0);
    }

    mass_ = mass;
    chi_ = chi;
    m_irr_=sqrt(mass_*mass_*(1+sqrt(1-chi_*chi_))/2.0);
    E_pen = mass_-m_irr_;
}

BH BH::fromMirrChi(const double& m_irr, const double& chi) {

    if(chi > 1.0 || chi < 0.0) {
        std::cout << "Angular momenta must be inside [0,1]" <<std::endl;
        exit(0);
    }
    double mass=sqrt(m_irr*m_irr*2.0/(1+sqrt(1-chi*chi)));
    return BH(mass, chi);
}

BH BH::fromMassMirr(const double& mass, const double& m_irr) {
    double chi = sqrt(1-(m_irr*m_irr*2/(mass*mass)-1)*(m_irr*m_irr*2/(mass*mass)-1));
    return BH(mass, chi);

}

BH::BH(const BH& B) {
    mass_ = B.getMass();
    m_irr_= B.getM_irr();
    chi_ = B.getChi();
    E_pen = B.getEpen();
} //copy constructor

BH::~BH() {} //destructor

void BH::Print() const {
    std::cout << "Mass (respect to the sun): "<< mass_ << "\n Angular momentum: " << chi_ << "\n Irreducible mass (respect to the Sun's mass): " << m_irr_ << "\n Energy: " << E_pen << std::endl; 
    std::cout << std::endl;

} //Print method

//getters
double BH::getMass() const { return mass_; }
double BH::getChi() const { return chi_; }
double BH::getM_irr() const { return m_irr_; }
double BH::getEpen() const { return E_pen; }


//setters
void BH::setMass(const double& mass) { 
    mass_ = mass;
    m_irr_=sqrt(mass_*mass_*(1+sqrt(1-chi_*chi_))/2.0);
    E_pen = mass_-m_irr_;
}

void BH::setChi(const double& chi) {
    chi_ = chi; 
    m_irr_=sqrt(mass_*mass_*(1+sqrt(1-chi_*chi_))/2.0);
    E_pen = mass_-m_irr_;
}

void BH::setM_irr(const double& m_irr) {
    m_irr_= m_irr; 
    mass_=sqrt(m_irr_*m_irr_*2.0/(1+sqrt(1-chi_*chi_)));
    E_pen = mass_-m_irr_;
}
