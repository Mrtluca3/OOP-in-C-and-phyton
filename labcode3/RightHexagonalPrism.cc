#include "RightHexagonalPrism.h"
#include "RegularHexagon.h"
RightHexagonalPrism::RightHexagonalPrism(const double& l, const double& a, const double& h, const std::string& name): 
    RightPrism(h, new RegularHexagon("Hexagonal base of "+name, l, a), name){
    std::cout << "Ctor of RightHexagonalPrism: " << name <<std::endl;
}
void RightHexagonalPrism::print(){
    std::cout<< "Print of Right Hexagon Prism " << name() << std::endl;
    std::cout<< "Perimeter= " << Perimeter() << " Surface= " << Surface() << " Volume= " <<Volume() << std::endl;
    std::cout<< "h= " << h() << " Base name: " << base()->name() << std::endl;
    
    std::cout<< "Base characteristic: ";
    for(const auto& element : base()->Dimension()) {
    std::cout << element << " ";
    }
    std::cout << std::endl;

}