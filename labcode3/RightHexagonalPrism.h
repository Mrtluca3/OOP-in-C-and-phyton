#include "Shape.h"
#include "RightPrism.h"
#ifndef RightHexagonalPrism_h
#define RightHexagonalPrism_h
class RightHexagonalPrism: public RightPrism{
        public: 
        RightHexagonalPrism(const double& l=1., const double& a=1., const double& h=1., const std::string& name="Right Hexagoanl Prism");
        virtual void print();
        
        virtual double Perimeter(){return base()->Perimeter() *2 + 6* h(); }
        virtual double Surface(){return base()->Surface()*2+base()->Dimension()[3] * h() * 6; }
        
        virtual std::vector<double> Dimension(){return {Perimeter(), Surface(), Volume(), base()->Dimension()[3], base()->Dimension()[4]};}
        
        virtual ~RightHexagonalPrism() {
            delete base();
            resetbase();
            std::cout<< "Dtor RightHexagonalPrism: " << name() << std::endl; 
        }
         
};
#endif 
