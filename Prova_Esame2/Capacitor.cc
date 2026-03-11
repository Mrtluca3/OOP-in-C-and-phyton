#include "Capacitor.h"

Capacitor::Capacitor() {}

Capacitor::Capacitor(double A, double s, double epsr) {
    A_= A;
    s_ = s;
    epsr_ = epsr;
    C=eps0*epsr_*A_/s_;
}
Capacitor::Capacitor(Capacitor& Cond) {
    A_ = Cond.getA();
    s_ = Cond.getS();
    epsr_ = Cond.getEpsr();
    C=Cond.getC();
}
Capacitor::~Capacitor() {}

//redefine the two operators
Capacitor Capacitor::operator+(const Capacitor& Cond) const {
    Capacitor eq_cap;
    eq_cap.setC(Cond.getC() + this->getC());
    return eq_cap;
} //series sum

Capacitor Capacitor::operator||(const Capacitor& Cond) const {
    Capacitor eq_cap;
    eq_cap.setC(1/(1/Cond.getC() + 1/this->getC()));
    return eq_cap;
} //parallel sum

void Capacitor::operator=(const Capacitor& Cond) {
    A_ = Cond.getA();
    s_ = Cond.getS();
    epsr_ = Cond.getEpsr();
    C=Cond.getC();
}

//getters
double Capacitor::getA() const {return A_;}
double Capacitor::getS() const { return s_; }
double Capacitor::getEpsr() const {return epsr_;}
double Capacitor::getC() const {return C;}

//setters
void Capacitor::setA(double A) { A_ = A;     C=eps0*epsr_*A_/s_; }
void Capacitor::setS(double s) { s_ = s;     C=eps0*epsr_*A_/s_;}
void Capacitor::setEpsr(double Epsr) { epsr_ = Epsr;     C=eps0*epsr_*A_/s_;}
void Capacitor::setC(double Cond) { C = Cond; }
