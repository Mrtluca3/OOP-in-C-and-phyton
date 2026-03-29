#include "Vector3D.h"
#include <iostream>
int main()
{
    using namespace std;
    std::cout << "counter: " << Vector3D::counts() <<std::endl;    
    Vector3D v1=Vector3D::cartesian(0, 1);
    v1.print("v1");
    v1.print_spherical("v1 spherical");
    Vector3D v2=Vector3D::spherical(1, 0);
    v2.print("v2");
    v2.print_spherical("v2 spherical");
    Vector3D v3(v2);
    v3.print("v3");
    v3.print_spherical("v3 spherical");

    std::cout << "counter: " << Vector3D::counts() <<std::endl;
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

    Vector3D* vin= Vector3D::newVector3D(); //now vin is a pointer!

    // std::cout << "write the components of a vector Vin:"<< std::endl;
    //first option:
    // for (unsigned long i = 0; i < vin->get_v().size(); i++) {
    //  double d;
    //  std::cin >> d;
    //  vin->set(d, i);
    // }
    // vin->print(" vector after input1. Then second input");
    
    //second option:
    std::cout<< "Input spherical vector\n";
    vin->input_v_spherical();
    vin->print("Vector vin after input");
    std::cout << "counter: " << Vector3D::counts() <<std::endl;
    
    (v1+ (*vin)).print("v1+vin");
    (v1-v3).print("v1-v3");
    (v1 * 2).print("v1 *2");
    (v1 / 2).print("v1 /2");
    v1=v3;
    v1.print("v1=v3");
    delete vin;
    std::cout << "counter after delete of vin: " << Vector3D::counts() <<std::endl; 
    std::cout<<"v3.v.size() "<<v3.get_v().size() <<std::endl;
    return 0; 
}