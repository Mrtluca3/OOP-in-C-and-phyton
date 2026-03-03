#ifndef Hexagon_h
#define Hexagon_h
#include "Shape.h"


class Hexagon : public Shape {
    public:
        Hexagon(double t);
        Hexagon(Hexagon& H);
        virtual ~Hexagon();

        //Getters
        virtual double getSide() const;
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
        double t_, P_, S_;

};

#endif