
#include <vector>
#include <string>
#include <cmath>
#ifndef Vector3D_h
#define Vector3D_h
using std::vector;
class Vector3D
{
    
    public:
    Vector3D(double a=0., double b=0., double c=0., bool Spherical=false);
    Vector3D(const Vector3D& v2);
    //dtor
    ~Vector3D(){}
    //getter
    inline double get(int index)const {return v.at(index);}
    inline double get_spherical(int index)const {return vs.at(index);}
    //setter
    inline void set(double value, int index)  {this->v.at(index)=value; 
    this->spherical();
    }
    inline void set_spherical(double value, int index)  {this->vs.at(index)=value;
    this->cartesian();
    }
    //scalar product
    double dot(const Vector3D& v2) const;
    //vector product
    Vector3D vect(const Vector3D& v2) const;
    //magnitude
    inline double magnitude()const {return sqrt(this->dot(*this));}
    //polar component
    double polar() const;
    //azimuthal component
    double azimuthal() const;
    double angle(const Vector3D& v2) const;
    
    void print(std::string comment="") const;
    void print_spherical(std::string comment="") const;

    void input_v();
    void input_vs();

    //operators:
    Vector3D operator+(const Vector3D& v2) const;//note: without Vector3D& v2 it is slower since it use copyctor so not same element 
    Vector3D operator-(const Vector3D& v2) const;
    Vector3D& operator=(const Vector3D& v2);
    Vector3D operator*(double d);
    Vector3D operator/(double d);

    //evaluate spherical->cartesian and cartesian->spherical
    Vector3D& cartesian(); 
    Vector3D& spherical(); 
    //getter of the vector
    vector<double> get_v() const {return v;}
    vector<double> get_vs() const {return vs;}

    private:
    vector<double> v;
    vector<double> vs;
    // void clear_v() {v.clear();}
};
#endif
