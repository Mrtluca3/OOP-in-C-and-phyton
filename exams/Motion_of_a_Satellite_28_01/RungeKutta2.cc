#include "RungeKutta2.h"
RungeKutta2::RungeKutta2(Satellite& satellite, Planet& planet, double dt,  unsigned int N, double t0):  FlySatellite(satellite, planet){
    dt_=dt;
    t0_=t0;
    N_=N;
}


void RungeKutta2::simulation(){
    using namespace std;

    for(unsigned int i=0; i<N_; i++){
        vector<vector<double>> u = {Sat().Pos(), Sat().Vel()};
        vector<vector<double>> K1= Force(dt_*i+t0_);    
        vector<vector<double>> K2= Force(
            t0_+dt_*(i+0.5), 
            {u[0]+ K1[0]* dt_*0.5, u[1] +K1[1] * dt_*0.5}
        );
        Sat().Pos()= Sat().Pos() + K2[0] * dt_;
        Sat().Vel() = Sat().Vel() + K2[1] * dt_;
    
        cout << Sat();
    }
} 
