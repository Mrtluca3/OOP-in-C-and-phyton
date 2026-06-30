#include "Triangle.h"

//ctor
Triangle::Triangle(const double& a, const double& b, const double& c, const std::string& label): Shape(label), a_(a), b_(b), c_(c) {
    gamma_= acos((a*a+b*b-c*c) / (2*a*b));
    beta_= acos((a*a-b*b+c*c) / (2*a*c));
    alpha_= acos((-a*a+b*b+c*c) / (2*c*b));
}
void Triangle::print(){
    std::cout << "Print method of Triangle with label: " << Label() << " and perimeter: " << Perimeter() << " and surface: " << Surface() << std::endl;
    std::cout << "Angles[rad]: " << alpha_ << " " << beta_ << " " << gamma_ << std::endl;
    std::cout << "Sides: " << a_ << " " << b_ << " " << c_ << std::endl;
}