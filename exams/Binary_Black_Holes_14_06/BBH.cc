#include "BBH.h"

BBH::BBH(const double& m1, const double& m2, const double& chi1, const double& chi2, const double& t1, const double& t2):
    b1_(BH::BH_m_chi(m1, chi1)), b2_(BH::BH_m_chi(m2, chi2)) //This is correct 
{
    t1_=t1; 
    t2_=t2;
    chieff_= (chi1*m1*cos(t1)+chi2*m2*cos(t2))/(m1+m2);
}
//copyctor
BBH::BBH(const BBH& bhh2):
    BBH(bhh2.B1().M(), bhh2.B1().Chi(), bhh2.B2().M(), bhh2.B2().Chi(), bhh2.T1(), bhh2.T2()) //completing
    {} //ctor delegation allowed only in member initilizer list
BBH& BBH::Print(){
    using namespace std;
    cout << "Blackholes: " << endl;
    b1_.Print();
    b2_.Print();
    cout << "theta1="<<t1_ <<" theta2="<<t2_ << " Chieff="<<chieff_   << endl;
    return *this;
}