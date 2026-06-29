#ifndef Rational_h
#define Rational_h
#include "Function.h"
#include "Polynomial.h"
#include <cmath>
class Rational: public Function {
    public:
    Rational(const std::vector<double>& v1, const std::vector<double>& v2,  const std::string& name);
    
    virtual double deriv(double x) const;
    virtual double value(double x) const;

    //getter
    Polynomial& N(){return N_;}
    Polynomial& D(){return D_;}

    private:
    Polynomial N_;
    Polynomial D_;
};

#endif