#include "Capacitor.h"
#include <iostream>
Capacitor::Capacitor(const double& A,const double& s, const double& er){
    A_=A;
    s_=s;
    er_=er;
    this->computeC();
}
Capacitor::Capacitor(const Capacitor& C2){
    A_=C2.A_; //Function member can access all the private data members of the same class
    s_=C2.s_;
    er_=C2.er_;
    C_=C2.C_;
}

// assignment operator
Capacitor& Capacitor::operator=(const Capacitor& C2){
    A_=C2.A_;
    s_=C2.s_;
    er_=C2.er_;
    C_ = C2.C_;
    return *this; 
}
std::ostream& operator<<(std::ostream& os, const Capacitor& Cap){
    os << "A="  << Cap.A_ << ", s=" <<Cap.s_ << ", er=" << Cap.er_ << ", C=" << Cap.C_ << std::endl;
    return os; 
}

Capacitor Capacitor::operator+(const Capacitor& Cap) const {
    Capacitor c=Capacitor();
    c.setC(1./(1./this->C() + 1./Cap.C()));
    // std::cout <<c.C() <<std::endl;    
    return c;
}
Capacitor Capacitor::operator||(const Capacitor& Cap) const{
    Capacitor c=Capacitor();
    c.setC(this->C() + Cap.C());
    // std::cout <<c.C()<<std::endl;
    return c;
}
