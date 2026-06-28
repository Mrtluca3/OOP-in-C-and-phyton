#include "RegularHexagon.h"

RegularHexagon::RegularHexagon(const std::string& name, const double l, const double a): Shape(name){
    a_=a;
    l_=l;
    vertices += 6; 
    std::cout << "Ctor of RegularHexagon: " << name <<std::endl;
    std::cout << "Number of vertices: " << vertices << std::endl;
}

double RegularHexagon::Perimeter(){return 6.*l_; }
double RegularHexagon::Surface(){return 3*a_*l_; }
void RegularHexagon::print(){
    std::cout<< "Print of Regular Hexagon " << name() << std::endl;
    std::cout<< "Perimeter= " << Perimeter() << " Surface= " << Surface() << " Volume= " <<Volume() << std::endl;
    std::cout<< "l= " << l_ << " a= " << a_ << std::endl;
}
