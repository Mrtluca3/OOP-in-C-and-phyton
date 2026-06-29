#include "BH.h"
#include "BBH.h"
int main()
{
    BH h1= BH::BH_mirr_m(1, sqrt(2));
    BH h2= BH::BH_mirr_chi(1, 1);
    BH h3= BH::BH_m_chi(0, 1);
    BH h31= BH::BH_m_chi(0);
    BH h4= BH::BH_chi(1);
    BH H2 = BH(h2);
    h1.Print().SetM(0.).Print().SetChi(1).Print();
    h2.Print();
    H2.Print(); //copy
    h3.Print();
    h31.Print();
    h4.Print();

    BBH bb1 = BBH(0, 1, 1, 1, M_PI,M_PI/2.);
    BBH bb2 = BBH(bb1);
    bb1.Print();
    bb2.Print();

}