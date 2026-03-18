#include <iostream>
#include "Vector3D.h"


    //ctor 
    Vector3D::Vector3D(double a, double b, double c)
    {
        this->v.push_back(a);
        this->v.push_back(b);
        this->v.push_back(c);
    }
    Vector3D::Vector3D(const Vector3D& v2)
    {
        Vector3D(v2.v.at(0), v2.v.at(1), v2.v.at(2));
    }

    void Vector3D::print(std::string comment) const{
        using namespace std;
        cout << comment<<endl;
        for(double d : this->v)
         {
            cout << d << " ";
         }
        cout << endl;
    }
    //scalar product
    double Vector3D::dot(const Vector3D& v2) const {
        double s=0.;
        for (unsigned long i=0; i<v2.v.size(); i++)
        {
            s+=this->v.at(i) * v2.v.at(i);
        }
        return s;
    }

    //vector product
    Vector3D Vector3D::vect(const Vector3D& v2) const {
        Vector3D v3;
        for (unsigned long i=0; i<v2.v.size(); i++)
        {
            v3.v.at(i)= this->v.at((i+1)%3) * v2.v.at((i+2)%3) - this->v.at((i+2)%3) * v2.v.at((i+1)%3);
        }
        return v3;
    }
    
double Vector3D::polar() const{
    if(v.at(0)==0 && v.at(1)==0 && v.at(2)==0)
     return 0.;
    else if(v.at(0)==0 && v.at(1)==0)
    {
        double theta=acos(v.at(2)/magnitude());
        return -v.at(2)*sin(theta);
    }
    else
    {
      double phi=atan2(v.at(1), v.at(0));
      double theta=acos(v.at(2)/magnitude());
      return (v.at(0)*cos(phi)+ v.at(1)*sin(phi) ) *cos(theta) -v.at(2)*sin(theta);
    }

}
    //azimuthal component
double Vector3D::azimuthal() const
{
    if(v.at(0)==0 && v.at(1)==0)
     return 0.;
    else 
    {
      double phi=atan2(v.at(1), v.at(0));
      return -v.at(0)* sin(phi)+v.at(1) * cos(phi); 
    }
} 

