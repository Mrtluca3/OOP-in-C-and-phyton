#ifndef Source_h
#define Source_h
#include "Mesh.h"
#include <iostream>
class Source {
    public:
        Source(Mesh& grid, std::string field="scalar");
        Source(Source& s2):grid_(s2.Grid()), scalar_(s2.Scalar()){}
        ~Source() = default;
        //getter
        double operator[](int i) {return scalar_[i];}

        Mesh Grid(){return grid_;}
        std::vector<double> Scalar(){return scalar_;}
    private:
        Mesh grid_;
        std::vector<double> scalar_;


};


#endif