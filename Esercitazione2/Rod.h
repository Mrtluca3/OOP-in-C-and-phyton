#ifndef Rod_h
#define Rod_h

#include "RotatingSolidBody.h"

class Rod : public RotatingSolidBody {
    public:
        Rod();       //Di default mantiene tutto a 0
        Rod(double Mass, double R);
        virtual ~Rod();

        //Getter
        virtual double KineticEnergy() const;     
        virtual double Inertia() const;    
        double getL() const; 
        virtual void Print();       //Non puo' esser const perche' chiama delle funzioni non const.

        //Setter
        virtual void Spin(double w, double d);
        virtual void setd(const double& d);

    private:
        virtual void setI();
        virtual void setK();
        double L_ = 0, I_=0, K=0;
};

#endif