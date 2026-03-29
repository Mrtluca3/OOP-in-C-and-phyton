
#include <vector>
#include <string>
#include <cmath>
#ifndef Vector3D_h
#define Vector3D_h
using std::vector;
class Vector3D
{
    
    public:
    //ctor with static method
    static Vector3D cartesian(double x=0., double y=0., double z=0.);
    static Vector3D spherical(double r=0., double theta=0., double phi=0.);
    static Vector3D* newVector3D(double x=0., double y=0., double z=0.);
    //ctor copy
    Vector3D(const Vector3D& v2);
    //dtor
    ~Vector3D(){counter_--;}
    //getter
    inline double get(int index)const {return v.at(index);}
    inline double get_spherical(int index)const {Vector3D v2=tospherical();
        return v2.get_v()[index];
    }
    //setter
    inline void set(double value, int index)  {this->v.at(index)=value; 
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
    void input_v_spherical();

    //operators:
    Vector3D operator+(const Vector3D& v2) const;//note: without Vector3D& v2 it is slower since it use copyctor so not same element 
    Vector3D operator-(const Vector3D& v2) const;
    Vector3D& operator=(const Vector3D& v2);
    Vector3D operator*(double d);
    Vector3D operator/(double d);


    //getter of the vector
    vector<double> get_v() const {return v;}

    //getter of counter 
    static int counts() {
        return counter_;
    }
    private:
    //ctor
    Vector3D(double a=0., double b=0., double c=0.);
    //evaluate spherical->cartesian and cartesian->spherical
    Vector3D tocartesian() const; 
    Vector3D tospherical() const; 
    //static counter
    static int counter_;
    vector<double> v;
    // void clear_v() {v.clear();}
};
#endif
