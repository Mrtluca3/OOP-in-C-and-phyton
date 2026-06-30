#ifndef Cone_h
#define Cone_h
#include "Shape.h"
#include "RightAngleTriangle.h"
class Cone : public Shape {
    public:
    Cone(const double& radius,const double& h, const std::string& label="Cone");
    ~Cone()=default;

    virtual void print();

    //gett
    double Surface(){return surf_;}
    double Volume(){return vol_;}


    private:
    double surf_, vol_;
    RightAngleTriangle rat_;
};

#endif