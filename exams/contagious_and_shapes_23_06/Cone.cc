#include "Cone.h"

Cone::Cone(const double& radius,const double& h,const std::string& label): Shape(label), rat_(RightAngleTriangle::ll(radius, h, label)) {
    surf_=M_PI*radius*(radius+rat_.h());
    vol_=radius*radius*h*M_PI/3.;
}


void Cone::print(){
    std::cout << "Print method of Cone with label: " << Label() << " and Volume: " << vol_ << " and surface: " << surf_ << std::endl;
    std::cout << "Properites of the RightAngle:" << std::endl;
    rat_.print();    
}