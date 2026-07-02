#include "Voltage.h"


Voltage::Voltage(Mesh& grid, Source& charges): grid_(grid), charges_(charges){
    std::vector<double> volt_(grid.N(), 0.);
    for (int j=0; j<grid.N(); j++)
        for (int i=0; (i<grid.N()) ; i++)
            { 
                if(i!=j){
                double dx= (grid.Matrix()[0][i]-grid.Matrix()[0][j]);
                double dy= (grid.Matrix()[1][i]-grid.Matrix()[1][j]);
                double dz = (grid.Matrix()[2][i]-grid.Matrix()[2][j]);
                volt_[j]+= charges_[i] / sqrt(dx*dx+dy*dy+dz*dz);
                }
            }
    V_=volt_;
}

Voltage& Voltage::Print(){
    using namespace std;
    std::ofstream outFile("output.txt");
    for(size_t i=0; i<grid_.N(); i++)
        outFile << grid_.Matrix()[0][i] <<" "<< grid_.Matrix()[1][i] <<" "<< grid_.Matrix()[2][i] << " "<< V_[i] <<" " << charges_[i] << endl; 
    outFile.close();
    cout << "Created file.txt with the results" <<endl;
    return *this;
}
// Mesh grid_;
// Source charges_;
// std::vector<std::vector<double>> V_;