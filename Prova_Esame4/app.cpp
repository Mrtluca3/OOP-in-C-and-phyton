#include <iostream>
#include "BH.h"
#include "BBH.h"


int main(void) {
    double m1=3, m2=1, chi1=0.1, chi2=0.5, theta1 =M_PI, theta2=0.5; //create a bunch of variables used later to define black holes and binaries
    BH bh1 = BH::fromMass(10), bh2(m1,chi1), bh3(m2,chi2), bh4 = BH::fromMassMirr(20, 19.9997); //create a bunch of black holes
    BBH bhh(m1, m2,chi1,chi2, theta1,theta2), bhh2(bh2,bh3, theta1,theta2); //create two identical binary systems in two different ways

    //Use print method on all variables
    bh1.Print();
    bh2.Print();
    bh3.Print();
    bh4.Print();
    bhh.Print();
    bhh2.Print();

    return 0;
}