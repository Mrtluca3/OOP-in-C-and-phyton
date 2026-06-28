
#ifndef Rectangle_h
#define Rectangle_h
#include "Shape.h"

class Rectangle: public Shape{
    public: 
        Rectangle(const double l1=1., const  double l2=2., const std::string& name="Rectangle");
        virtual double Perimeter();
        virtual double Surface(); 
        virtual double Volume(){return 0.; }
        virtual void print();
        virtual std::vector<double> Dimension(){return {Perimeter(), Surface(), Volume(), l1_, l2_};}
        virtual ~Rectangle() {
            std::cout<< "Dtor Rectangle: " << name() << std::endl; 
            vertices-=4;
        }
        double l1(){return l1_;}
        double l2(){return l2_}
    private:
        double l1_, l2_;
};
#endif 
