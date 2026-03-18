#include "Vector3D.h"
#include <iostream>
int main()
{
    using namespace std;
    Vector3D v(10, 1000);
    Vector3D v3(2, 2, 0);
    v.print("v1");
    v3.print("v3");

    std::cout <<"v.get(2): "<< v.get(2) << std::endl;
    std::cout << "setting 3rd element to 10 ";
    v.set(10, 2);
    std::cout << v.get(2) << std::endl;
    v.print("v new");
    std::cout <<"vnew dot vnew: " <<v.dot(v) << " v magnitude "<< v.magnitude() <<endl;
    v.vect(v).print("vnew vector vnew");
    v.vect(v3).print("vnew vector v3");
    std::cout <<"vnew dot v3: " <<v.dot(v3) <<endl;
    std::cout <<"azimuthal and polar component of v "<< v.azimuthal()<<" " << v.polar() << endl;
    std::cout <<"azimuthal and polar component of v3 "<< v3.azimuthal()<< " " << v3.polar() << endl;

    

    
    return 0; 
}