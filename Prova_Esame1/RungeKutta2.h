#include "FlySatellite.h"

#ifndef RK_h
#define RK_h
class RungeKutta2 : public FlySatellite {
    public:
    RungeKutta2(const double& dt, const int& N, const Planet& P, const Satellite& S, const Atmosphere& A); //Constructor
    virtual ~RungeKutta2();

    virtual void simulation();
};
#endif