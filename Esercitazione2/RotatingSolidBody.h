#ifndef RotatingSolidBody_h
#define RotatingSolidBody_h

#include <iostream>
#include <cmath>

class RotatingSolidBody{
    public:
        //Constructors & Destructors
        RotatingSolidBody();        //Di default mantiene tutto a 0
        RotatingSolidBody(double Mass);
        virtual ~RotatingSolidBody();
        //Getters
        double getMass() const;
        double getFreq() const;
        //Setters
        void setMass(const double& Mass);
        virtual void setd(const double& d) = 0;
        virtual void Spin(double w, double d) = 0;        //Let the Body Spin
        //Operators
        virtual void Print() = 0;
    protected: 
        //Metto questi due setter in protected (e nelle derivate in private) per non farlo usare all'utente
        virtual void setI() = 0;
        virtual void setK() = 0;
        double w_ = 0, d_ = 0, Mass_ = 0;
};
#endif