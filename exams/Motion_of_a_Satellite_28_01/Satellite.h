#ifndef Satellite_h
#define Satellite_h
#include <vector>
#include <cmath>
#include <iostream>
#include <numeric>
class Satellite {
    public:
        //ctor
        Satellite(const std::vector<double>& pos, const std::vector<double>& vel, const double& A,  const double& m);
        //copy ctor
        Satellite(const Satellite& sat2);

        //dtor
        ~Satellite() = default;
        //getters
        std::vector<double>& Pos(){return pos_;}
        std::vector<double>& Vel(){return vel_;}
        double& A(){return A_;}
        double& mass(){return m_;}
        //const getters
        std::vector<double> Pos() const { return pos_; }
        std::vector<double> Vel() const { return vel_; }
        double A() const { return A_; }
        double mass() const { return m_; }

        //Module
        double Posmodule(){return std::sqrt(std::inner_product(pos_.begin(), pos_.end(), pos_.begin(), 0.0));}
        double Velmodule(){return std::sqrt(std::inner_product(vel_.begin(), vel_.end(), vel_.begin(), 0.0));}
        
    
    private:
        std::vector<double> pos_;
        std::vector<double> vel_;
        double A_; //cross section
        double m_; //mass

};
std::ostream& operator<<(std::ostream& os, const Satellite& s);


#endif