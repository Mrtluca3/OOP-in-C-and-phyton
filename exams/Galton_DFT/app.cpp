#include "Galton.h"

int main(){
    auto g1=Galton(10, 0.5);
    auto g2=Galton(20, 0.1);
    auto g3=Galton(60);
    
    
    g1.Singlebead().Print().Singlebead().Print().Singlebead().Print().Singlebead().Print();

    g1.Reset().Simulation(10).Print();
    g1.Reset().Print().Simulation(100).Print();
    g1.Reset().Print().Simulation(1000).Print();
    
    std::cout << "G2" << std::endl;
    
    g2.Singlebead().Print().Reset().Simulation(100).Print();

    std::cout << "G3" << std::endl;
    
    g3.Singlebead().Print().Reset().Simulation(1000000).Print();

    return 1;
}