#ifndef Voltage_h
#define Voltage_h
#include "Mesh.h"
#include "Source.h"
#include <cmath>
#include <fstream> // Required for file operations

class Voltage {
    public:
        Voltage(Mesh& grid, Source& charges);
        ~Voltage() = default;

        
        Voltage& Print();
    private:
        Mesh grid_;
        Source charges_;
        std::vector<double> V_;
};


#endif