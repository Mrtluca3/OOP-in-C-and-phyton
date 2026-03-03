#ifndef Sphere_h
#define Sphere_h

#include "RotatingSolidBody.h"

class Sphere : public RotatingSolidBody {
    public:
        Sphere();       //Di default mantiene tutto a 0
        Sphere(double Mass, double R);
        virtual ~Sphere();

        //Getter
        double KineticEnergy() const;     
        double Inertia() const;    
        double getR() const; 
        virtual void Print();       //Non puo' esser const perche' chiama delle funzioni non const.

        //Setter
        virtual void Spin(double w, double d);
        virtual void setd(const double& d);

    private:
        virtual void setI();
        virtual void setK();
        double R_ = 0, I_=0, K=0;
};

#endif