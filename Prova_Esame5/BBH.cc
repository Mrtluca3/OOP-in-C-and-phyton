#include "BBH.h"

#ifndef BBH_h
#define BBH_h
BBH::BBH() {
    chi1_.resize(3); //set the vector to an array of dimension 3 and full of zeros
    chi2_.resize(3);
    m1_=1;
    m2_=m1_;
} //default constructor

BBH::BBH(const BBH& B) {
    m1_ = B.getM1(); //copy the masses
    m2_ = B.getM2();
    for(int i=0; i<3; i++) { //copy the angular momenta
        chi1_.push_back(B.getChi1()[i]);
        chi2_.push_back(B.getChi2()[i]);
    }
} //copy constructor

BBH::BBH(double m1, double m2, const std::vector<double>& chi1, const std::vector<double>& chi2) {
    if((m1<5 || m1>100) || (m2<5 || m2>100)) { //check values if in range
        std::cout << "Masses should be in the range [5, 100] (in unit of Solar masses)" <<std::endl;
        exit(0);
    }
    m1_=m1;
    m2_=m2;
    if(chi1.size() != 3 || chi2.size() != 3) { //check array size
        std::cout << "The angular momenta must be in three dimensions! " <<std::endl;
        exit(0);
    }

    for(int i=0; i<3; i++) {
        if(fabs(chi1[i]) > 1.0 || fabs(chi2[i])>1.0) {//check if the values are in range
            std::cout << "Ang. momenta values should be in [-1,1]" << std::endl;
            exit(0);
        }
        chi1_.push_back(chi1[i]); //substitute the two arrays' values
        chi2_.push_back(chi2[i]);
    }
} //constructor - Notice m1,m2 are in unit of solar masses.

BBH::~BBH() {} //destructor

//methods
double BBH::ChiEff() {
    ChiE_=(m1_*chi1_[2]+m2_*chi2_[2])/(m1_+m2_);
    return ChiE_;
} //Changes chieff of the class

double BBH::ChirpMass() {
    Mc_= pow(m1_*m2_, 3/5.0)/pow(m1_+m2_, 1/5.0);
    return Mc_;
} //Changes the chirpmass of the class

//getters
double BBH::getM1() const { return m1_; }
double BBH::getM2() const { return m2_; }
std::vector<double> BBH::getChi1() const { return chi1_; }
std::vector<double> BBH::getChi2() const { return chi2_; }

//setters
void BBH::setM1(const double& M1) { 
    if((M1<5 || M1>100)) { //check if the values are in range
        std::cout << "Masses should be in the range [5, 100] (in unit of Solar masses)" <<std::endl;
        exit(0);
    }
    m1_=M1;
}
void BBH::setM2(const double& M2) { 
    if((M2<5 || M2>100)) { //check if the values are in range
        std::cout << "Masses should be in the range [5, 100] (in unit of Solar masses)" <<std::endl;
        exit(0);
    }
    m2_ = M2; 
}
void BBH::setChi1(const std::vector<double>& Chi1) {
    if(Chi1.size() != 3) { //Check the dimensionality
        std::cout << "The angular momenta must be in three dimensions! " <<std::endl;
        exit(0);
    }

    for(int i=0; i<3; i++) {
        if(fabs(Chi1[i]) > 1.0) { //check the values if are in range
            std::cout << "Ang. momenta values should be in [-1,1]" << std::endl;
            exit(0);
        }
        chi1_[i] = Chi1[i]; //substitute the values in array
    }
}
void BBH::setChi2(const std::vector<double>& Chi2) {
    if(Chi2.size() != 3) { //check the dimensionality
        std::cout << "The angular momenta must be in three dimensions! " <<std::endl;
        exit(0);
    }
    for(int i=0; i<3; i++) {
        if(fabs(Chi2[i]) > 1.0) { //check the values if are in range
            std::cout << "Ang. momenta values should be in [-1,1]" << std::endl;
            exit(0);
        }
        chi2_[i] = Chi2[i]; //substitute the values in array 
    }
}

void BBH::Print() {
    std::cout << "The binary system has the following parameters:\nm1: " << m1_ << " m2:" <<m2_ << std::endl; 
    std::cout << "Angular momenta1: ";
    for(int i = 0; i<3; i++)
        std::cout << chi1_[i] << "\t";
    std::cout << "\nAngular momenta2: ";
    for(int i = 0; i<3; i++)
        std::cout << chi2_[i] << "\t";
    std::cout << "\nEffective spin parameter: " << this->ChiEff() << "; Chirp Mass: " << this->ChirpMass() << "\n" << std::endl;
} //Prints all the informations about the binary system
#endif