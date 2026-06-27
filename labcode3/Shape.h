#include <iostream> // for cout
#include <cmath>
#include <vector>
#ifndef Shape_h
#define Shape_h
class Shape {
    public:
        Shape(const std::string& name); 
        virtual double Perimeter()=0;
        virtual double Surface()=0; 
        virtual double Volume()=0;
        virtual std::vector<double> Dimension()=0;
        virtual void print()=0;
        std::string name(){return name_;}

        virtual ~Shape(){std::cout<< "Dtor Shape: " << name_ << std::endl; } 
    private:
        std::string name_;
};
#endif