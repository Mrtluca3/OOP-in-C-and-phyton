#ifndef DualNumber_h
#define DualNumber_h
#include <iostream>
class DualNumber {
    public:
    //ctor
    DualNumber(const double a=1., const double b=1.);
    //copy ctor
    DualNumber(const DualNumber& dn);
    //dtor
    ~DualNumber() =default;

    //getter
    double A() const {return a_;}
    double B() const {return b_;}
    //setter
    DualNumber& setA(const double a){a_=a; return *this;}
    DualNumber& setB(const double b){b_=b; return *this;}

    //operator to print
    friend std::ostream& operator<<(std::ostream& os, const DualNumber& dn);

    //Conjugation
    DualNumber conj() const {return DualNumber(a_, -b_);}

    //operators of + and *
    DualNumber operator+(const DualNumber& dn); //d+d
    DualNumber operator+(const double& r); //d+r
    
    DualNumber operator*(const DualNumber& dn); //d*d
    DualNumber operator*(const double& r); //d*r


    private:
    double a_, b_;


};
//global function to operate
DualNumber operator+(const double& r, const DualNumber& dn); //r+d
DualNumber operator*(const double& r, const DualNumber& dn); //r*d
#endif