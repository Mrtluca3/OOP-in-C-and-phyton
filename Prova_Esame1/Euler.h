#include "FlySatellite.h"

#ifndef Euler_h
#define Euler_h
class Euler : public FlySatellite {
    public:
    Euler(const double& dt, const int& N, const Planet& P, const Satellite& S, const Atmosphere& A); //Constructor
    virtual ~Euler();

    virtual void simulation();
};
#endif