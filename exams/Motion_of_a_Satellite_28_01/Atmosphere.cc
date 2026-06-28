#include "Atmosphere.h"
#include <cmath>
#include <iostream>
Atmosphere::Atmosphere(const double& F107, const double& Ap, const double& Cd){
    using namespace std;
    F_=F107; //in sfu units
    Ap_=Ap; 
    Cd_=Cd;
    //check on the values
    if (F_< 65) {
        cout << "F107 value is lower than 65, setting to lower bound of 65" << endl;
        F_=65;
    }
    else if (F_> 300) {
        cout << "F107 value is higher than 300, setting to upper bound of 300" << endl;
        F_=300;
    }

    if (Ap_< 0) {
        cout << "Ap value is negative, setting to lower bound of 0" << endl;
        Ap_=0;
    }
    else if (Ap_> 400) {
        cout << "Ap value is higher than 400, setting to upper bound of 400" << endl;
        Ap_=400;
    }

    if (Cd_< 0) {
        cout << "Cd value is negative, setting to lower bound of 0" << endl;
        Cd_=0;
    }
}

double Atmosphere::rho(const double& h) const {
    using namespace std;
    return 6*1e-10*exp(- (h-175)*Mu(h)/(Temperature())) / 1e-9;
}