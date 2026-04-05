#include "RotatingSolidBody.h"

#ifndef Rectangle_h
#define Rectangle_h
class Rectangle : public RotatingSolidBody {
    public:
    Rectangle(double mass=0., double a=0., double b=0.);
    const Rectangle& Print(std::string comment="") const;
    protected:
    double a_;
    double b_;
};
#endif