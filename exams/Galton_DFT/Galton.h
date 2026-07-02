#ifndef GaltonBoard_h
#define Galton_h
#include <vector>
#include <random>
#include <iostream>

class Galton {
    public:
        Galton(int Nrows, double prob_dx=0.5); //Nrows

        Galton& Singlebead();
        
        Galton& Simulation(int Nexp=100);

        Galton& Reset();

        Galton& Print(); ///print with evident rows

        ~Galton() =default;
    private:
        std::vector<int> board_;
        unsigned int N_, N_exp_;
        double prob_;
        std::mt19937 gen_;
        std::uniform_real_distribution<> dist_;
};
#endif