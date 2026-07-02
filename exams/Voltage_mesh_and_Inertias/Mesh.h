#ifndef Mesh_h
#define Mesh_h
#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
class Mesh {
    public:
        static Mesh Regular(int N, double L);
        static Mesh Random(int N, double L); //irregular grid of N points with xi, yi
                                    // and zi values uniformly extracted between −L/2 to L/2;
        Mesh(int N); //interactively asking
        Mesh(Mesh& m2){matrix_=m2.Matrix();} //copyctor

        ~Mesh() = default;

        //getters
        std::vector<std::vector<double>> Matrix() {return matrix_;}
        size_t N(){return  matrix_[0].size();}
    private:
        Mesh(std::vector<std::vector<double>>& matrix): matrix_(matrix) {}; //to have named costructor idiom
        std::vector<std::vector<double>> matrix_;
        size_t N_;

};
#endif