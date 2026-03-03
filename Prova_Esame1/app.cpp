#include <iostream>
#include <fstream>
//Objects used for simulation
#include "Planet.h"
#include "Satellite.h"
#include "Atmosphere.h"

//Integration models
#include "RungeKutta2.h"
#include "Euler.h"

#define G 6.67e-11
int main() {
    std::vector<double> r0, v0;
    double r;
    double M_Planet, Radius, m_satellite, A, Cd, Ad, F10_7, dT;
    int N, integration;

    std::ifstream ifile;
    std::string ifname("params.ini");
    std::cout << "Getting data in " << ifname << std::endl;
    ifile.open( ifname );
    
    if(!ifile.is_open()){
        std::cout << "Can't find the file params.ini !" << std::endl;
        exit(0);
    }
    ifile >> r >> M_Planet >> Radius >> m_satellite >> A >> Cd >> Ad >> F10_7 >> dT >> N >> integration;
    std::cout << r << "\t" << M_Planet <<"\t" << Radius <<"\t" << m_satellite <<"\t" << A <<"\t" << Cd <<"\t" << Ad <<"\t" << F10_7 <<"\t" << dT <<"\t" << N <<"\t" << integration << std::endl;

    r0.push_back(r); r0.push_back(0); r0.push_back(0);
    //v0.push_back(0); v0.push_back(sqrt(G*M_Planet/(r+Radius))); v0.push_back(0);
    v0.push_back(0); v0.push_back(0); v0.push_back(0);

    Planet Earth(Radius, M_Planet);
    Satellite sat(m_satellite, A, r0, v0);
    Atmosphere atm(F10_7, Ad, Cd);
    FlySatellite* integ;
    if (integration) {
        integ = new Euler(dT, N, Earth, sat, atm);
        integ->simulation();
    }
    else {
        integ = new RungeKutta2(dT, N, Earth, sat, atm);
        integ->simulation();
    }
    delete integ;
    ifile.close();
    return 0;
}