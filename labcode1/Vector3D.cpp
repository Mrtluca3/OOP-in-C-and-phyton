#include "Vector3D.h"
#include <iostream>
int main()
{
    using namespace std;
    Vector3D v(1, 0);
    Vector3D v3(2, 2, 0);
    Vector3D v4(v3);
    v4.print("v4");
    v4.print_spherical("v4 spherical");

    v.print("v1");
    v.print_spherical("v1 spherical");

    v3.print("v3");

    // std::cout <<"v.get(1): "<< v.get(1) << std::endl;
    // std::cout << "setting 2nd element to 1 ";
    // v.set(1, 1);
    // std::cout << v.get(1) << std::endl;
    // v.print("v new:");
    // std::cout <<"vnew dot vnew: " <<v.dot(v) << " v magnitude "<< v.magnitude() <<endl;

    // v.vect(v).print("vnew vector vnew");
    // v.vect(v3).print("vnew vector v3");
    // std::cout << "Angle between vnew and v3 " << v.angle(v3) <<endl;
    // std::cout <<"vnew dot v3: " <<v.dot(v3) <<endl;
    // // std::cout <<"azimuthal and polar component of v "<< v.azimuthal()<<" " << v.polar() << endl;
    // std::cout <<"azimuthal and polar component of v3 "<< v3.azimuthal()<< " " << v3.polar() << endl;

    Vector3D* vin=new Vector3D; //now vin is a pointer!

    // std::cout << "write the components of a vector Vin:"<< std::endl;
    //first option:
    // for (unsigned long i = 0; i < vin->get_v().size(); i++) {
    //  double d;
    //  std::cin >> d;
    //  vin->set(d, i);
    // }
    // vin->print(" vector after input1. Then second input");
    
    //second option:
    // vin->input_v();
    // vin->print(" vector after input. Then delete");
    delete vin;

    std::cout<<"v3.v.size() "<<v3.get_v().size() <<std::endl;
    (v+v3).print("v1+v3");
    (v-v3).print("v1-v3");
    (v * 2).print("v1 *2");
    (v / 2).print("v1 /2");
    v=v3;
    v.print("v=v3");
    return 0; 
}