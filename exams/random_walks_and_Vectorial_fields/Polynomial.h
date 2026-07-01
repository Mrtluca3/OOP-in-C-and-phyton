#ifndef Polynomial_h
#define Polynomial_h
#include "Function.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <numeric>
class Polynomial: public Function{
    public:
    //ctor
    Polynomial(const std::vector<double>& v, const std::string& name);
    Polynomial(Polynomial& p2):  Function(p2.name()),   
    v_(p2.V()) {}
    ~Polynomial() = default;
    //setter
    Polynomial& Set(const std::vector<double>& v){
        v_=v; return *this;
    }

    std::vector<double> V(){return  v_;}

    virtual double value(double x, double y, double z) const; //must be defined again
    // Derivative of the function calculated at a point along the x-axis
    virtual double deriv(double x, double y, double z, char var) const;


    friend std::ostream& operator<<(std::ostream& os,const  Polynomial& p);
    private:
    std::vector<double> v_; 
     
};

#endif