#include "Rational.h"

Rational::Rational(const std::vector<double>& v1, const std::vector<double>& v2,  const std::string& name): Function(name), 
N_(v1, "Numerator"),
D_(v2, "Denominator")
{}
    
double Rational::deriv(double x) const{
    double d=D_.value(x);
    double n=N_.value(x);
    if (d!=0.) return (N_.deriv(x) * d -  D_.deriv(x) * n)/(d*d);
    return INFINITY; 
}

double Rational::value(double x) const{
    double d=D_.value(x);
    double n=N_.value(x);
    if (d!=0.) return n/d;
    return INFINITY; 
}
