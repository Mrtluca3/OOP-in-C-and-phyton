#ifndef BH_h
#define BH_h
#include <iostream>
#include <cmath>
double Chicomp(const double& m, const double& mirr);
double Mcomp(const double& mirr, const double& chi);
double Mirrcomp(const double& m, const double& chi);
class BH{

    private:
        double mirr_, m_, chi_;
        BH(const double& mirr, const double& m, const double& chi);  //to allow different init methods, we use Name Ctor idiom
    public: 
    //ctors
    static BH BH_mirr_m(const double& mirr, const double& m);
    static BH BH_mirr_chi(const double& mirr, const double& chi);
    static BH BH_m_chi(const double& m, const double& chi=1.);
    static BH BH_chi(const double& chi, const double& m=0.);
    //copyctor
    BH(const BH& b2){
        mirr_=b2.mirr_;
        m_= b2.m_;
        chi_=b2.chi_;
    }

    //dtors
    ~BH() =default;
    //print
    BH& Print(); 

    //getters
    double Mirr(){return mirr_;}
    double M(){return m_;}
    double Chi(){return chi_;}
    double E(){return m_-mirr_;}
    //setters //this may cause not precise phisical relation with the others
    // BH& SetMirr(double& mnew){mirr_=mnew; return  *this;}
    BH& SetM(const double& mnew){m_=mnew;
        mirr_=Mirrcomp(m_, chi_);;
        return *this;}
    BH& SetChi(const double& chinew){chi_=chinew;
        mirr_=Mirrcomp(m_, chi_);;        
        return *this;}

    // //Compute other
    // BH& ComputeChi();
    // BH& Computem();
    // BH& Computemirr();
    
};


#endif