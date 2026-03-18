
#include <vector>
#include <string>

#ifndef Vector3D_h
#define Vector3D_h
using std::vector;
class Vector3D
{
    
    public:
    Vector3D(double a=0., double b=0., double c=0.);
    Vector3D(const Vector3D& v2);
    //getter
    inline double get(int index)const {return this->v.at(index);}
    //setter
    inline void set(double value, int index)  {this->v.at(index)=value;}
    //scalar product
    double dot(const Vector3D& v2) const;
    //vector product
    Vector3D vect(const Vector3D& v2) const;
    //magnitude
    inline double magnitude()const {return this->dot(*this);}
    
    void print(std::string comment="") const;
    
    
    private:
    vector<double> v;

};
#endif
