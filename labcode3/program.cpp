#include <iostream>
#include "RightHexagonalPrism.h"

int main(){
    RightHexagonalPrism A= RightHexagonalPrism(10., 1, 2, "My first abstract class") ;
    A.print();
    
    Shape* point = new RightHexagonalPrism(10., 1, 2, "My second abstract class");
    std::cout << point->Surface() << std::endl; 
    point->print();
    delete point;
    RightPrism* point2 = new RightHexagonalPrism(10., 1, 2, "My third abstract class");
    std::cout << point2->base()->Surface() << std::endl; 
    point2->base()->print();

    delete point2;
    point=nullptr;
    point2=nullptr;
    return 1;
}