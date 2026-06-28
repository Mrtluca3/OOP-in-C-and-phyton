#ifndef Capacitor_h
#define Capacitor_h
#include <iostream>
class Capacitor{
    public:
        //default ctor
        Capacitor() = default;

        //ctor
        Capacitor(const double& A,const double& s, const double& er);
        //copy Ctor
        Capacitor(const Capacitor& C2);
        //Overloading assign operator
        Capacitor& operator=(const Capacitor& C2);

        //dtor
        ~Capacitor() = default;
        //getters
        double A() const {return A_;}
        double s() const {return s_;}
        double er() const {return er_;}
        double C() const {return C_;}

        //Compute C: maybe private
        Capacitor& computeC(){C_ = e0_*er_*A_/s_; return *this;}



        //setters
        Capacitor& setA(const double& newA){A_=newA;  return computeC();}
        Capacitor& sets(const double& news){s_=news;  return computeC();}
        Capacitor& seter(const double& newer){er_=newer;  return computeC();}
        Capacitor& setC(const double& newC){C_=newC;  return *this;}
        
        //print
        friend std::ostream& operator<<(std::ostream& os, const Capacitor& Cap);

        //operator
        Capacitor operator+(const Capacitor& Cap) const;
        Capacitor operator||(const Capacitor& Cap) const;
    private:
        double e0_=8.854 * 1e-12; //F/m
        double er_=0., A_=0., s_=1.;
        double C_=0.;

};

#endif