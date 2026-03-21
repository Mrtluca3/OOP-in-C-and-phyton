#include "Vector3D.h"
#include <iostream>
int main()
{
    using namespace std;
    Vector3D v(1, 0);
    Vector3D v3(2, 2, 0);
    Vector3D vin;
    v.print("v1");
    v3.print("v3");

    std::cout <<"v.get(1): "<< v.get(1) << std::endl;
    std::cout << "setting 2nd element to 1 ";
    v.set(1, 1);
    std::cout << v.get(1) << std::endl;
    v.print("v new:");
    std::cout <<"vnew dot vnew: " <<v.dot(v) << " v magnitude "<< v.magnitude() <<endl;
    v.vect(v).print("vnew vector vnew");
    v.vect(v3).print("vnew vector v3");
    std::cout << "Angle between vnew and v3 " << v.angle(v3) <<endl;
    std::cout <<"vnew dot v3: " <<v.dot(v3) <<endl;
    // std::cout <<"azimuthal and polar component of v "<< v.azimuthal()<<" " << v.polar() << endl;
    // std::cout <<"azimuthal and polar component of v3 "<< v3.azimuthal()<< " " << v3.polar() << endl;
    std::cout << "write the components of a vector:"<< std::endl;
    for (unsigned long i = 0; i < vin.get_v().size(); i++) {
     double d;
     std::cin >> d;
     vin.set(d, i);


    }
    if (std::cin.fail()) {
        std::cout << "Error of input." << std::endl;
     }
    else {
        vin.print("Vin input vector:");
        std::cout << "Angle between vin and vnew " << vin.angle(v) <<endl;
    } 
    
    return 0; 
}