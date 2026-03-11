#ifndef RightHex_h
#define RightHex_h
#include "RightPrism.h"
#include "RegularHexagon.h"

class RightHexagon : public Prism {
    public:
        RightHexagon(double t, double h);
        RightHexagon(RightHexagon& RH);
        virtual ~RightHexagon();

        //Getters
        virtual double getSide() const;
        virtual double getSurface() const;
        virtual double getPerimeter() const;
        virtual double getVolume() const;
        virtual double getH() const; 
        virtual void Print() const;

    private:
        //Setters
        virtual void setSurface();
        virtual void setPerimeter();
        virtual void setVolume();

        //Parameters
        Hexagon* H;
        double t_, P_, V_, S_; 
};

#endif