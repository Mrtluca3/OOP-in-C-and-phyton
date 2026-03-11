#include "RungeKutta2.h"


RungeKutta2::RungeKutta2(const double& dt, const int& N, const Planet& P, const Satellite& S, const Atmosphere& A) : FlySatellite(dt, N, P, S, A) {
    std::cout << "Using RungeKutta2" <<std::endl;
} //Constructor
RungeKutta2::~RungeKutta2() {}

void RungeKutta2::simulation() {
    std::vector<double> K1, K2, r0=S_.getPosition(), v0=S_.getVelocity(),r0_temp=S_.getPosition(), v0_temp=S_.getVelocity();
    double R_Planet = P_.getRadius();

    for(int i = 0; i<3; i++) //I see the problem from the Planet's center of mass frame of reference
        r0[i]=(r0[i]+P_.getRadius()*r0[i]/this->getVectorMod(r0));

    std::ofstream ofile;
    std::string ofname("sim.dat");
    std::cout << "storing data in " << ofname << std::endl;
    ofile.open( ofname );

    for(int i=0; i<N_; i++) {
        ofile << std::setprecision(2) << std::fixed ;
        ofile << r0[0] << "\t" << r0[1] << "\t" << r0[2] << "\t" << v0[0] << "\t" << v0[1] << "\t" << v0[2] << std::endl;
    
        K1 = this -> Function(r0, v0);
        for(int j=0; j<3; j++) {
            v0_temp[j]=(v0[j] + dt_*K1[j]/2);
            r0_temp[j]=(r0[j] + dt_*K1[j+3]/2);
        }
        K2 = this -> Function(r0_temp, v0_temp);
        for(int j=0; j<3; j++) {
            v0[j]=(v0[j] + dt_*K2[j]);
            r0[j]=(r0[j] + dt_*K2[j+3]);
        }
        S_.setPosition(r0);
        S_.setVelocity(v0);

    }

    ofile.close();
    std::cout << ofname << " output file successfully created" << std::endl;

}