#include "Shape.h"

#ifndef RegularHexagon_h
#define RegularHexagon_h
class RegularHexagon: public Shape{
    public: 
        RegularHexagon(const std::string& name="Regular Hexagon", const double l=1., const double  a=1.);
        virtual double Perimeter();
        virtual double Surface(); 
        virtual double Volume(){return 0.; }
        virtual void print();
        virtual std::vector<double> Dimension(){return {Perimeter(), Surface(), Volume(), l_, a_};}
        virtual ~RegularHexagon() {std::cout<< "Dtor RegularHexagon: " << name() << std::endl; }
        double l(){return l_;}
        double a(){return a_;}
    private:
        double l_, a_;
};
#endif 
