#ifndef FlySatellite_h
#define FlySatellite_h
#include "Satellite.h"
#include "Planet.h"
#include <vector>
#include <cmath>
class FlySatellite{
    public:
    FlySatellite(Satellite& satellite, Planet& planet);
    virtual void simulation()=0; //abstract method
    
    
    // std::vector<std::vector<double>> Force(double ti, std::vector<std::vector<double>> u = {sat_.Pos(), sat_.Vel()}) const; //to do in source file
    std::vector<std::vector<double>> Force(double ti, std::vector<std::vector<double>> u) const;
    std::vector<std::vector<double>> Force(double ti) const { return Force(ti, {sat_.Pos(), sat_.Vel()}); }
    
    std::vector<double> Dvector(std::vector<std::vector<double>> u) const;
    std::vector<double> Dvector() const { return Dvector({sat_.Pos(), sat_.Vel()}); }
    
    //dtor
    virtual ~FlySatellite() = default;
    //getters
    Satellite& Sat() {return sat_;}
    Planet& Plan() {return plan_;}
    const double G=6.67 * 1e-11 * 1e-6; //N km^2 kg^-2 
    private:
    Satellite sat_;
    Planet plan_;
};

//scalar * vector
inline std::vector<double> operator*(double scalar, const std::vector<double>& vettor) {
    std::vector<double> ris;
    ris.reserve(vettor.size());
    for (double comp : vettor) {
        ris.push_back(scalar * comp);
    }
    return ris;
}

// Overload for Vector * Double
inline std::vector<double> operator*(const std::vector<double>& vettor, double scalar) {
    std::vector<double> ris;
    ris.reserve(vettor.size());
    
    for (double comp : vettor) {
        ris.push_back(comp * scalar);
    }
    
    return ris;
}
inline std::vector<double> operator+(const std::vector<double>& v1, const std::vector<double>& v2) {
    std::vector<double> result;
    result.reserve(v1.size());

    for (size_t i = 0; i < v1.size(); ++i) {
        result.push_back(v1[i] + v2[i]);
    }

    return result;
}
#endif