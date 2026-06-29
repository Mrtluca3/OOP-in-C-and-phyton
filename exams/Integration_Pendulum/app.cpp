#include "Rational.h"
#include "Polynomial.h"
#include <iostream>

int main(){
    using namespace std;
    auto p = Polynomial({1, 2., 3.}, "123");
    cout << p << p.Set({1., 1.}) << " new p: " << p;
    cout << " integral: "<< p.Primitive(1, 0.) << " derivative in 1: " << p.deriv(1.) << " value in 1: " << p.value(1) << endl;
    auto r = Rational({1, 2, 3}, {1, 2}, "Ratio 123");
    cout << r.N() << r.D()  << r.D().Set({1., 2., 3.}) << " new r: " << r.N() << r.D();
    cout  << " derivative in 2: " << r.deriv(2.) << " value in 2: " << r.value(2) << endl;

}