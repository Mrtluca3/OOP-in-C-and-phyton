#include "Satellite.h"

Satellite::Satellite(const std::vector<double>& pos, const std::vector<double>& vel, const double& A, const double& m):
    pos_(pos), // Member Initializer List
    vel_(vel){
        A_=A;
        m_=m;
    }
Satellite::Satellite(const Satellite& sat2){
    pos_=sat2.Pos();
    vel_=sat2.Vel();
    A_=sat2.A();
    m_=sat2.mass();
}
std::ostream& operator<<(std::ostream& os, const Satellite& s){
    const auto& p = s.Pos();
    const auto& v = s.Vel();
    
    os << p[0] << " " << p[1] << " " << p[2] << " "
       << v[0] << " " << v[1] << " " << v[2] << std::endl;
       
    return os;
}

