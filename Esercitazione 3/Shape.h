#ifndef Shape_h
#define Shape_h
#include <iostream>
#include <cmath>

class Shape {
    public:
        Shape();
        virtual ~Shape();
        static int getVertices();
    //Getters
        virtual double getVolume() const =0;
        virtual double getPerimeter() const =0;
        virtual double getSurface() const =0; 
        virtual void Print() const=0; 
        
    //Operator
        virtual double operator>(const Shape& R);
        virtual bool operator<(const Shape& R);

    protected: 
    //Setters
        virtual void setPerimeter() =0;
        virtual void setVolume() = 0;
        virtual void setSurface() = 0;
        void setShapeVolume(double V); //Non viene posto =0 per permettere di storare l'informazione in questa classe genitore
        void setShapeSurface(double S);  //Non viene posto =0 per permettere di storare l'informazione in questa classe genitore
        static int Vertices_;
        double V_, S_; //Li definisco nella classe abstract poichè mi servono per il confronto
};


#endif