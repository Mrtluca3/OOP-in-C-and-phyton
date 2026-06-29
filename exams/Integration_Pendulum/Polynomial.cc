#include "Polynomial.h"

//ctor
Polynomial::Polynomial(const std::vector<double>& v, const std::string& name): 
    Function(name),   
    v_(v),    
    degree_(v.size()-1) 
    {}

double Polynomial::value(double x) const {//must be defined again
    double res=0.;
    for(unsigned int i=0; i<degree_; i++){
        res+=v_[i]* std::pow(x, i);
    }
    return res;
}


double Polynomial::deriv(double x) const {
    double res=0.;
    for(unsigned int i=0; i<degree_-1; i++){
        res+=  (i+1)* v_[i+1]* std::pow(x, i);
    }
    return res;

}

double Polynomial::Primitive(double x, double x0){
    double res=0.;
    if (x0==0.)
    {
        for(unsigned int i=0; i<degree_; i++){
        res+=  v_[i] / (i+1)*  (std::pow(x, i+1));
        }
        return res;
    }    
    for(unsigned int i=0; i<degree_; i++){
        res+=  v_[i] / (i+1)*  (std::pow(x, i+1) - std::pow(x0, i+1));
    }
    return res;
}

std::ostream& operator<<(std::ostream& os, const  Polynomial& p){
    os << p.name() << " Degree: " << p.degree_ << std::endl;
    os << " Vectors: ";
    for (auto s : p.v_){
        os << s << " " ;
    }  
    os << std::endl;
    return os;
}
