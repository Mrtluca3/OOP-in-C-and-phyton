#ifndef Rectangle_h
#define Rectangle_h

#include "RotatingSolidBody.h"

class Rectangle : public RotatingSolidBody {
    public:
        Rectangle();       //Di default mantiene tutto a 0
        Rectangle(double Mass, double a, double b);
        virtual ~Rectangle();

        //Getter
        virtual double KineticEnergy() const;     
        virtual double Inertia() const;       
        double getA() const; 
        double getB() const; 
        virtual void Print();       //Non puo' esser const perche' chiama delle funzioni non const.

        //Setter
        virtual void Spin(double w, double d);
        virtual void setd(const double& d);

    private:
        virtual void setI(); 
        virtual void setK();
        double a_ = 0, b_=0, I_=0, K=0, ratio=0; //Ratio serve per mantenere il rapporto a/b costante una volta scelti (serve per ricavare esattamente a e b quando si usa setI)
};

#endif