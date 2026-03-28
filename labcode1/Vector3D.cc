#include <iostream>
#include "Vector3D.h"


//ctor 
int Vector3D::counter_=0;
Vector3D::Vector3D(double a, double b, double c, bool Spherical)
    {
        if (Spherical==false){
            v.push_back(a);
            v.push_back(b);
            v.push_back(c);
            vs.resize(3); 
            this->spherical();
        }
        else 
        {
            vs.push_back(a);
            vs.push_back(b);
            vs.push_back(c);
            v.resize(3); 
            this->cartesian();           
        }
        counter_++;
    }
Vector3D::Vector3D(const Vector3D& v2)
    {
        v = v2.get_v();
        vs= v2.get_vs();
        counter_++;
    }



void Vector3D::print(std::string comment) const{
        using namespace std;
        if (v.size()!=0){
        cout << comment<<endl;
        for(double d : v)
         {
            cout << d << " ";
         }
        cout << endl;
        }
        else {cout << "Zero size vector\n";}
    }

void Vector3D::print_spherical(std::string comment) const{
        using namespace std;
        if (vs.size()!=0){
        cout << comment<<endl;
        for(double d : vs)
         {
            cout << d << " ";
         }
        cout << endl;
        }
        else {cout << "Zero size vector\n";}
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


double Vector3D::angle( const Vector3D& v2) const {
    double d=this->dot(v2);
    return acos(d/ (this->magnitude() * v2.magnitude()));
}

void Vector3D::input_v() {
    for(double& d : v)
    {
        std::cin>>d;
        if (std::cin.fail()) {
         std::cout << "Error of input." << std::endl;
     }
    }
    this->spherical();
}
void Vector3D::input_vs() {
    for(double& d : v)
    {
        std::cin>>d;
        if (std::cin.fail()) {
         std::cout << "Error of input." << std::endl;
     }
    }
    this->cartesian();
}

//operators
Vector3D Vector3D::operator+(const Vector3D& v2) const
    {
        Vector3D v3=Vector3D();
        if (v.size() == v2.v.size())
        {
            for(unsigned long i=0; i<v.size(); i++)
             v3.v[i]= v[i]+ v2.v[i];
        }
        v3.spherical();
        return v3;
    } 
Vector3D Vector3D::operator-(const Vector3D& v2) const
    {
        Vector3D v3=Vector3D();
        if (v.size() == v2.v.size())
        {
            for(unsigned long i=0; i<v.size(); i++)
             v3.v[i]= v[i] - v2.v[i];
        }
        v3.spherical();
        return v3;
    } 
Vector3D& Vector3D::operator=(const Vector3D& v2) 
    {
        if (v.size() == v2.v.size())
        {
            for(unsigned long i=0; i<v.size(); i++)
             v[i]= v2.v[i];
        }
        this->spherical();
        return *this;
    }
Vector3D Vector3D::operator*(double d)
    {
        Vector3D v2;        
        for(unsigned long i=0; i<v.size(); i++)
            v2.v[i]= v[i]*d;
        v2.spherical();
        return v2;
    }
Vector3D Vector3D::operator/(double d)
    {
        Vector3D v2;
        double e=1./d;
        v2= this->operator*(e);
        v2.spherical();
        return v2;
    }
//r, theta, phi
Vector3D& Vector3D::cartesian(){
    v[0]=vs[0] * sin(vs[1]) * cos(vs[2]);
    v[1]=vs[0] * sin(vs[1]) * sin(vs[2]);
    v[2]=vs[0] * cos(vs[1]);
    return *this;
} 

Vector3D& Vector3D::spherical() {
    vs[0]=magnitude();
    if (vs[0] !=0.)
     {
        vs[1]=acos(v[2]/vs[0]);
        if(vs[1] !=0. && vs[1] !=M_PI)  
         vs[2]=atan2(v[1], v[0]);
        else
         vs[2]=0.;
     }
    else
     {
        vs[1]=0.;
        vs[2]=0.;
     }
    return *this;
}