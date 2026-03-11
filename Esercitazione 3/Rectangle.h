#ifndef Rectangle_h
#define Rectangle_h
#include "Shape.h"

class Rectangle : public Shape {
    public:
        Rectangle(double a, double b);
        Rectangle(Rectangle& R);
        virtual ~Rectangle();

        //Getters
        virtual double getA() const;
        virtual double getB() const;
        virtual double getSurface() const;
        virtual double getPerimeter() const;
        virtual double getVolume() const; 
        virtual void Print() const;

    private:
        //Setters
        virtual void setSurface();
        virtual void setPerimeter();
        virtual void setVolume();
        //Parameters
        double a_, b_, P_, S_; //S sta per surface, P sta per perimeter
};

#endif