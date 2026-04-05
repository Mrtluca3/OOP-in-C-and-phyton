#include "RotatingSolidBody.h"

#ifndef Rod_h
#define Rod_h
class Rod : public RotatingSolidBody{
    public:
    Rod(double mass=0., double length=0.);
    const Rod& Print(std::string comment="") const;
    protected:
    double length_;
};
#endif