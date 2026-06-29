#ifndef Polynomial_h
#define Polynomial_h
#include "Function.h"
#include <vector>
#include <iostream>
#include <cmath>
class Polynomial: public Function{
    public:
    //ctor
    Polynomial(const std::vector<double>& v, const std::string& name);
    
    //setter
    Polynomial& Set(const std::vector<double>& v){
        v_=v; degree_=v.size()-1; return *this;
    }

    virtual double value(double x) const; //must be defined again
    // Derivative of the function calculated at a point along the x-axis
    virtual double deriv(double x) const;


    friend std::ostream& operator<<(std::ostream& os,const  Polynomial& p);

    //Primitive
    double Primitive(double x, double x0=0.);
    private:
    unsigned int degree_;
    std::vector<double> v_;
};

#endif