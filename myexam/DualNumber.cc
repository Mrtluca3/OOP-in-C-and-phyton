#include "DualNumber.h"


DualNumber::DualNumber(const double a, const double b): a_(a), b_(b) {} //member initializer list


//copy ctor
DualNumber::DualNumber(const DualNumber& dn){
    a_=dn.A();
    b_=dn.B();
}
std::ostream& operator<<(std::ostream& os, const DualNumber& dn){
    if (dn.B() < 0)
        os << dn.A() << dn.B() << " eps ";
    else
        os << dn.A() << "+" << dn.B() << " eps ";
    return os;
}


//operators of + and *
DualNumber DualNumber::operator+(const DualNumber& dn){ //d+d
    return DualNumber(A()+dn.A(), B() + dn.B());
}


DualNumber DualNumber::operator+(const double& r){ //d+r
    return DualNumber(A()+r, B());
}

DualNumber DualNumber::operator*(const DualNumber& dn){ //d*d
    return DualNumber(A()*dn.A(), A()*dn.B() + dn.A() * B() );
}

DualNumber DualNumber::operator*(const double& r){ //d*r
    return DualNumber(A()*r, B()*r);
}



//global
DualNumber operator+(const double& r, const DualNumber& dn){ //r+d
    return DualNumber(dn.A()+r, dn.B());
}
DualNumber operator*(const double& r, const DualNumber& dn){ //r*d
    return DualNumber(dn.A()*r, dn.B()*r);
}
