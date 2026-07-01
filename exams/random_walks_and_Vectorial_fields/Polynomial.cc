#include "Polynomial.h"

//ctor
Polynomial::Polynomial(const std::vector<double>& v, const std::string& name): 
    Function(name),   
    v_(v) {
        
    }

double Polynomial::value(double x, double y, double z) const {//must be defined again
    double res=v_[0];
    // [ [a4, a7/2,  a8/2], 
    //   [a7/2, a5,  a9/2],
    //   [a8/2, a9/2, a6]    
    std::vector<double> v = {x, y, z};
    
    std::vector<std::vector<double>> matrix = {
        {v_[4], 0.5*v_[7], 0.5*v_[8]},
        {0.5*v_[7], v_[5], 0.5*v_[9]},
        {0.5*v_[8], 0.5*v_[9], v_[6]}
    };
    std::vector<double> result(matrix.size());
    // vecotr* matrix-vector
    for (size_t i = 0; i < matrix.size(); ++i) {
        // std::inner_product fa il prodotto scalare tra la riga i-esima e il vettore v
        result[i] = std::inner_product(matrix[i].begin(), matrix[i].end(), v.begin(), 0.0);
    }


    res+= std::inner_product(v.begin(), v.end(), v_.begin(), 0.0);
    res+= std::inner_product(v.begin(), v.end(), result.begin(), 0.0);
    return res;
}


double Polynomial::deriv(double x, double y, double z, char var) const {
    double res=0;
    switch (var) {
            case 'x': // d/dx
                return v_[1] + 2*v_[4]*x + v_[7]*y + v_[8]*z;
            case 'y': // d/dy
                return v_[2] + 2*v_[5]*y + v_[7]*x + v_[9]*z;
            case 'z': // d/dz
                return v_[3] + 2*v_[6]*z + v_[8]*x + v_[9]*y;
            default:
                return 0.;
        }
    }

std::ostream& operator<<(std::ostream& os, const  Polynomial& p){
    os << p.name() << std::endl;
    os << " Vectors: ";
    for (auto s : p.v_){
        os << s << " " ;
    }  
    os << std::endl;
    return os;
}



