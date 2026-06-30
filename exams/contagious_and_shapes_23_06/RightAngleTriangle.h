#ifndef RightAngleTriangle_h
#define RightAngleTriangle_h
#include "Triangle.h"

class RightAngleTriangle : public Triangle {
    private:
    RightAngleTriangle(const double& a, const double& b, const double& c,const std::string& label);

    public: 
    static RightAngleTriangle ll(const double& l1,const double& l2,const std::string& label="Right Angle Triangle");
    static RightAngleTriangle hl(const double& h,const double& l,const std::string& label="Right Angle Triangle"); 



    ~RightAngleTriangle()=default;
    double h(){return c();}
    double l1(){return a();}
    double l2(){return b();}

};
#endif