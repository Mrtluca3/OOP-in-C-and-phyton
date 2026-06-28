#include "Euler.h"
Euler::Euler(Satellite& satellite, Planet& planet, double dt, unsigned int N,  double t0): FlySatellite(satellite, planet)
    {
    dt_=dt;
    t0_=t0;
    N_=N;
}


void Euler::simulation(){
    using namespace std;

    for(unsigned int i=0; i<N(); i++){
        vector<vector<double>> f= Force(dt_*i+t0_);
        Sat().Pos()= Sat().Pos() + f[0] * dt_;
        Sat().Vel() = Sat().Vel() + f[1] * dt_;
        cout << Sat();
    }
} 
