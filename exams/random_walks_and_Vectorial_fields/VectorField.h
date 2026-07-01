#ifndef VectorField_h
#define VectorField_h
#include "Polynomial.h"
#include "Function.h"
class VectorField {
    public:
    VectorField(Polynomial fx, Polynomial fy,Polynomial fz);
    ~VectorField(){
        delete fx_;
        delete fy_;
        delete fz_;
        fx_=nullptr;
        fy_=nullptr;
        fz_=nullptr;
    };

    friend std::ostream& operator<<(std::ostream& os,const  VectorField& p);


    double div(double x, double y, double z);
    std::vector<double> curl(double x, double y, double z);

    private:
    Function* fx_=nullptr;
    Function* fy_=nullptr;
    Function* fz_=nullptr;

};


#endif