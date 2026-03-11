#ifndef RightPrism_h
#define RightPrism_h

#include "Shape.h"

class Prism : public Shape {
    public:
        Prism(double h);
        virtual ~Prism();
        //Getter
        virtual double getH() const =0; 
    protected:
        //Setter
        virtual void setH(double h); //Per ora inutilizzato, in futuro chissà
        //Parameters
        double h_;
};

#endif