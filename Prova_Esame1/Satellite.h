#include <vector>

#ifndef Satellite_h
#define Satellite_h
class Satellite {
    public:
    Satellite();
    Satellite(const double& m, const double& A, const std::vector<double>& r0, const std::vector<double>& v0);
    //r0 must be referred to the surface level
    Satellite(Satellite& S);

    ~Satellite(); // destructor
    

    //getters
    double getMass() const;
    double getArea() const;
    std::vector<double> getPosition() const; //Returns the position vector
    std::vector<double> getVelocity() const; //Returns the velocity vector

    //setters
    void setMass(const double& m);
    void setArea(const double& A);
    void setPosition(const std::vector<double>& r0);
    void setVelocity(const std::vector<double>& v0);

    
    private:
    double m_, A_;
    std::vector<double> r0_, v0_;
};
#endif