#ifndef BBH_h
#define BBH_h
#include "BH.h"
#include "cmath"
class BBH {
    public:
        //ctor
        BBH(const double& m1, const double& m2, const double& chi1, const double& chi2, const double& t1, const double& t2);
        //copyctor
        BBH(const BBH& bhh2);
        //getter
        double Chieff() {return chieff_;}
        BH B1() const {return b1_;}
        BH B2() const {return b2_;}
        double T1() const {return t1_;}
        double T2() const {return t2_;}
        //Print method
        BBH& Print();
    private:
        BH b1_, b2_;
        double t1_, t2_;
        double chieff_;

};
#endif