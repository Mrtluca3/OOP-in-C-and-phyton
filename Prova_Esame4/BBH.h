#include "BH.h"

#ifndef BBH_h
#define BBH_h

class BBH {
    public:
    //constructors and destructors 
    BBH(double M1, double M2, double chi1, double chi2, double theta1, double theta2); //angles must be in grades
    BBH(const BH& bh1_, const BH& bh2_,  double theta1, double theta2); //can build the class from black holes directly
    BBH(const BBH& bbh);
    ~BBH();
    void Print() const;
    
    //getters 
    BH getBH1() const;
    BH getBH2() const;
    double getTheta1() const;
    double getTheta2() const;

    //setters
    void setBH1(const BH& bh1);
    void setBH2(const BH& bh1);
    void setTheta1(const double& theta1);
    void setTheta2(const double& theta1);



    private:
    BH bh1, bh2;
    double theta1_, theta2_, chi_eff;

};

#endif