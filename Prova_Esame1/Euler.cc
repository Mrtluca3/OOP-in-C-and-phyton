#include "Euler.h"


Euler::Euler(const double& dt, const int& N, const Planet& P, const Satellite& S, const Atmosphere& A) : FlySatellite(dt, N, P, S, A) {
    std::cout << "Using Euler" <<std::endl;
} //Constructor
Euler::~Euler() {}

void Euler::simulation() {
    std::vector<double> func, r0=S_.getPosition(), v0=S_.getVelocity();
    double R_Planet = P_.getRadius();
    std::ofstream ofile;
    std::string ofname("sim.dat");
    std::cout << "storing data in " << ofname << std::endl;
    ofile.open( ofname );
    for(int i = 0; i<3; i++) //I see the problem from the Planet's center of mass frame of reference
        r0[i]=(r0[i]+P_.getRadius()*r0[i]/this->getVectorMod(r0));

    for(int i=0; i<N_; i++) {
        ofile << std::setprecision(2) << std::fixed ;
        ofile << r0[0] << "\t" << r0[1]  << "\t" << r0[2] << "\t" << v0[0] << "\t" << v0[1] << "\t" << v0[2] << std::endl;
        //I print the position not anymore from the Earth com view
        func = this -> Function(r0, v0);
        for(int j=0; j<3; j++) {
            v0[j]=(v0[j] + dt_*func[j]);
            r0[j]=(r0[j] + dt_*func[j+3]);
        }
        S_.setPosition(r0);
        S_.setVelocity(v0);

    }

    ofile.close();
    std::cout << ofname << " output file successfully created" << std::endl;

}