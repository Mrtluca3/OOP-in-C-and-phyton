#ifndef Triangle_h
#define Triangle_h
#include "Shape.h"
#include <cmath>
class Triangle : public Shape {
    private:
        double alpha_, beta_, gamma_;
        double a_, b_, c_;

    public:
        //ctor
        Triangle(const double& a, const double& b, const double& c,const std::string& label="Triangle");
        //dtor
        ~Triangle() = default;


        virtual void print();
        double Perimeter(){return a_+b_+c_;}
        double Surface(){return a_*b_*sin(gamma_)*0.5;}
        double c(){return c_;}
        double a(){return a_;}
        double b(){return b_;}


};

#endif