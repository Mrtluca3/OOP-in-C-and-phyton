#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include "Satellite.h"
#include "Planet.h"
#include "Euler.h"
#include "RungeKutta2.h"

int main() {
    FILE* fileParams = fopen("params.ini", "r");
    if (!fileParams) {
        printf("Error: Cannot open params.ini\n");
        return 1;
    }

    int selection;
    int steps;
    double r0, dt, mass, surfkm2;
    
    fscanf(fileParams, "%d %d %lf %lf %lf %lf", &selection, &steps, &r0, &dt, &mass, &surfkm2);
    fclose(fileParams);

    const double G = 6.67e-11 * 1e-6;
    Planet earth;
    
    std::vector<double> pos = {r0, 0.0, 0.0};
    std::vector<double> vel = {0.0, std::sqrt(earth.Mass() * G / (r0)), 0.0};
    
    Satellite satellite(pos, vel, surfkm2, mass);

    if (selection == 1) {
        Euler integrator(satellite, earth, dt, steps);
        integrator.simulation();
    } else if (selection == 2) {
        RungeKutta2 integrator(satellite, earth, dt, steps);
        integrator.simulation();
    } else {
        printf("Error: Invalid method selection.\n");
        return 1;
    }

    return 0;
}