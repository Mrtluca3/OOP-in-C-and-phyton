#include "Rectangle.h"
Rectangle::Rectangle(const double l1, const double l2, const std::string& name,): Shape(name) {
    l1_=l1;
    l2_=l2;
    std::cout << "Ctor of Rectangle: " << name <<std::endl;
} 

//here you need the type of the function
double Rectangle::Perimeter(){return l1_+l2_+l1_+l2_}
double Rectangle::Surface(){return l1_*l2_}; 

void Rectangle::print(){
    std::cout<< "Print of Rectangle " << name() << std::endl;
    std::cout<< "Perimeter= " << Perimeter() << " Surface= " << Surface() << " Volume= " <<Volume() << std::endl;
    std::cout<< "l1= " << l1_ << " l2= " << l2_ << std::endl;
}