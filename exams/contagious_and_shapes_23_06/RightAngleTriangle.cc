#include "RightAngleTriangle.h"

RightAngleTriangle::RightAngleTriangle(const double& a, const double& b,const  double& c, const std::string& label): Triangle(a, b, c, label) { }

RightAngleTriangle RightAngleTriangle::ll(const double& l1, const double& l2,const std::string& label){
    return RightAngleTriangle(l1, l2, sqrt(l1*l1+l2*l2), label);
}
RightAngleTriangle RightAngleTriangle::hl(const double& h,const double& l,const std::string& label){
    return RightAngleTriangle(l, sqrt(h*h-l*l), h, label);
} 


