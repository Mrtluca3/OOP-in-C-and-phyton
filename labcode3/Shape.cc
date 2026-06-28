#include "Shape.h"
int Shape::vertices =0;
Shape::Shape(const std::string& name){
    name_=name;
    std::cout << "Ctor of Shape: " << name <<std::endl;
    std::cout << "Number of vertices: " << vertices << std::endl;
}