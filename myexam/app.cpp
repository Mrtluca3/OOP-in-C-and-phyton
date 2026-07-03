#include <iostream>
#include "DualNumber.h"

int main() {
    DualNumber d1(3.0, 4.0);
    DualNumber d2; //default values for DualNumbers
    DualNumber d3 = d1; //copyctor

    std::cout << "d1: "<< d1 << std::endl;
    std::cout << "d2: "<<d2 << std::endl;
    std::cout << "d3: "<<d3 << std::endl;

    d3.setA(10.0).setB(5.0);
    std::cout << "d3 after setting a=10 and b=5: "<< d3 << "\n";

    std::cout << "Trying the getters " << d1.A() << " " << d1.B() << "\n";

    std::cout << "Trying the conjugate " << d1.conj() << "\n";

    std::cout << "(d1 + d2): " <<(d1 + d2) <<  std::endl;
    std::cout << "(d1 + 2.5): " <<(d1 + 2.5) <<  std::endl;
    std::cout << "(2.5 + d1): " <<(2.5 + d1) << std::endl ;

    std::cout << "(d1 * d2): " <<(d1 * d2) <<  std::endl;
    std::cout << "(d1 * 2.0): " <<(d1 * 2.0) <<  std::endl;
    std::cout << "(2.0 * d1): " <<(2.0 * d1) <<  std::endl;

    return 0;
}