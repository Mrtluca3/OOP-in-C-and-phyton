#include "Shape.h"
Shape::Shape(const std::string& name){
    name_=name;
    std::cout << "Ctor of Shape: " << name <<std::endl;
}