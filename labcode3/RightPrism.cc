#include "RightPrism.h"

RightPrism::RightPrism(const double& h, Shape* base, const std::string& name): Shape(name) {
    h_=h;
    base_=base;
    std::cout << "Ctor of RightPrism: " << name <<std::endl;

}
void RightPrism::print() {
    std::cout<< "Print of Right Prism " << name() << std::endl;

    std::cout<< "h= " << h_ << " base= " << base_->name() << " " << std::endl;
}
