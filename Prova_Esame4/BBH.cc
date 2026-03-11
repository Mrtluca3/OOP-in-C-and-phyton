#include "BBH.h"

//constructors and destructors 
BBH::BBH(double M1, double M2, double chi1, double chi2, double theta1, double theta2) {
    
    if(theta1 < 0.0 || theta1 > M_PI) {
        std::cout << "Angles must be between [0, pi]" << std::endl;
        exit(0);
    }    
    if(theta2 < 0.0 || theta2 > M_PI) {
        std::cout << "Angles must be between [0, pi]" << std::endl;
        exit(0);
    }
      
    bh1 = BH(M1, chi1);
    bh2 = BH(M2, chi2);
    theta1_=theta1;
    theta2_=theta2;
    chi_eff = (bh1.getChi()*bh1.getMass()*cos(theta1)+bh2.getChi()*bh2.getMass()*cos(theta2))/(bh2.getMass()+bh1.getChi());
} //angles must be in grades

BBH::BBH(const BH& bh1_, const BH& bh2_,  double theta1, double theta2) {
     
    if(theta1 < 0.0 || theta1 > M_PI) {
        std::cout << "Angles must be between [0, pi]" << std::endl;
        exit(0);
    }    
    if(theta2 < 0.0 || theta2 > M_PI) {
        std::cout << "Angles must be between [0, pi]" << std::endl;
        exit(0);
    }
      
    bh1 = bh1_;
    bh2 = bh2_;
    theta1_=theta1;
    theta2_=theta2;
    chi_eff = (bh1.getChi()*bh1.getMass()*cos(theta1)+bh2.getChi()*bh2.getMass()*cos(theta2))/(bh2.getMass()+bh1.getChi());
   
} //can build the class from black holes directly


BBH::BBH(const BBH& bbh) {
    bh1 = bbh.getBH1();
    bh2 = bbh.getBH2();
    theta1_ = bbh.getTheta1();
    theta2_ = bbh.getTheta2();
}

BBH::~BBH() {}

void BBH::Print() const {
    std::cout << "The first black hole has the following parameters: " << std::endl;
    bh1.Print();

    std::cout << "The second black hole has the following parameters:" << std::endl;
    bh2.Print();

    std::cout << "And are at angles: " << theta1_ << " rad; " << theta2_ << " rad; \nWith an effective angular momenta of " << chi_eff << std::endl;
    std::cout << std::endl;

}

//getters 
BH BBH::getBH1() const { return bh1; }
BH BBH::getBH2() const { return bh2; }
double BBH::getTheta1() const { return theta1_; }
double BBH::getTheta2() const { return theta2_; }

//setters
void BBH::setBH1(const BH& bh) { 
    bh1 = bh; 
    chi_eff = (bh1.getChi()*bh1.getMass()*cos(theta1_)+bh2.getChi()*bh2.getMass()*cos(theta2_))/(bh2.getMass()+bh1.getChi());
}
void BBH::setBH2(const BH& bh) {
    bh2 = bh;
    chi_eff = (bh1.getChi()*bh1.getMass()*cos(theta1_)+bh2.getChi()*bh2.getMass()*cos(theta2_))/(bh2.getMass()+bh1.getChi());

}
void BBH::setTheta1(const double& theta) { 
        
    if(theta < 0.0 || theta > M_PI) {
        std::cout << "Angles must be between [0, pi]" << std::endl;
        exit(0);
    }    

    theta1_ = theta; 
    chi_eff = (bh1.getChi()*bh1.getMass()*cos(theta1_)+bh2.getChi()*bh2.getMass()*cos(theta2_))/(bh2.getMass()+bh1.getChi());

}
void BBH::setTheta2(const double& theta) { 
    if(theta < 0.0 || theta > M_PI) {
        std::cout << "Angles must be between [0, pi]" << std::endl;
        exit(0);
    }    
    theta2_ = theta; 
    chi_eff = (bh1.getChi()*bh1.getMass()*cos(theta1_)+bh2.getChi()*bh2.getMass()*cos(theta2_))/(bh2.getMass()+bh1.getChi());

}