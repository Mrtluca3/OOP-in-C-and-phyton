#include "VectorField.h"

VectorField::VectorField(Polynomial fx, Polynomial fy,Polynomial fz){
    fx_=new Polynomial(fx);
    fy_=new Polynomial(fy);
    fz_=new Polynomial(fz);
}

std::ostream& operator<<(std::ostream& os, const VectorField& p) {
    os << "F = " <<std::endl;
    
    // Explicitly call the global operator<< function for each component.
    // We pass the stream and the dereferenced pointer casted to Polynomial.
    operator<<(os, *static_cast<const Polynomial*>(p.fx_));
    
    operator<<(os, *static_cast<const Polynomial*>(p.fy_));
    
    operator<<(os, *static_cast<const Polynomial*>(p.fz_));
    
    return os;
}


double VectorField::div(double x, double y, double z){
    return fx_->deriv(x, y, z, 'x') + 
           fy_->deriv(x, y, z, 'y') + 
           fz_->deriv(x, y, z, 'z');
}
std::vector<double> VectorField::curl(double x, double y, double z){
    std::vector<double> result(3);
    
    // Component X: dFz/dy - dFy/dz
    result[0] = fz_->deriv(x, y, z, 'y') - fy_->deriv(x, y, z, 'z');
    
    // Component Y: dFx/dz - dFz/dx
    result[1] = fx_->deriv(x, y, z, 'z') - fz_->deriv(x, y, z, 'x');
    
    // Component Z: dFy/dx - dFx/dy
    result[2] = fy_->deriv(x, y, z, 'x') - fx_->deriv(x, y, z, 'y');
    
    return result;
}