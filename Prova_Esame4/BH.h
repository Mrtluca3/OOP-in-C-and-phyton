#include <iostream>

#ifndef BH_h
#define BH_h

class BH {
    public:
    BH(); //Default constructor
    static BH fromSpin(const double& chi); //puts mass to 1
    static BH fromMass(const double& mass); //puts chi to 1
    BH(const double& mass, const double& chi); 
    static BH fromMassMirr(const double& mass, const double& m_irr);
    static BH fromMirrChi(const double& m_irr, const double& chi);
    BH(const BH& B); //copy constructor
    ~BH(); //destructor

    void Print() const; //Print method

    //getters
    double getMass() const;
    double getChi() const;
    double getM_irr() const;
    double getEpen() const;


    //setters
    void setMass(const double& mass);
    void setChi(const double& Chi);
    void setM_irr(const double& m_irr);

    private:
    double mass_=.0, chi_=.0, m_irr_=.0, E_pen;
};
#endif