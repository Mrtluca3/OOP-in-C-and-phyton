#include "RotatingSolidBody.h"

#ifndef Sphere_h
#define Sphere_h
class Sphere : public RotatingSolidBody{
    public:
    //ctor
    Sphere(double mass=0., double radius=0.);
    const Sphere& Print(std::string comment="") const;
    protected:
    double radius_;
};
#endif