#include "Mesh.h"

// Mesh Mesh::Regular(int N, double L){
//     std::vector<std::vector<double>> m_{3};
//     double dl=L/(N-1);
//     for (auto& v : m_) { 
//         v.reserve(N);
//         for(int i=0; i<N; i++)
//         {
//                 v.push_back(dl*i-L*0.5);
//         }
//     }
//     return Mesh(m_);
// }

Mesh Mesh::Regular(int N, double L) {
    int total_points = N * N * N;
    std::vector<std::vector<double>> matrix(3, std::vector<double>(total_points));
    
    double step = (N > 1) ? L / (N - 1) : 0.0;
    double start = -L / 2.0;
    
    int index = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                matrix[0][index] = start + i * step; // X
                matrix[1][index] = start + j * step; // Y
                matrix[2][index] = start + k * step; // Z
                index++;
            }
        }
    }
    return Mesh(matrix);
}


Mesh Mesh::Random(int N, double L){
    // 1. Obtain a random seed from the hardware
    std::random_device rd;
    // 2. Initialize the generator (Mersenne Twister) with the seed
    std::mt19937 gen(rd());
    // 3. Define the distribution
    std::uniform_real_distribution<> distr(-0.5*L, 0.5*L);
    std::vector<std::vector<double>> m_{3};
    for (auto& v : m_) { 
        v.reserve(N);
        for(int i=0; i<N; i++)
        {
            // Generate a number
            v.push_back(distr(gen));
        }
        // std::sort(v.begin(), v.end());
    }
    return Mesh(m_);
}
                           
Mesh::Mesh(int N){ //interactively asking
    using namespace std;
    std::vector<std::vector<double>> m_(3);
    cout << "interactive input: insert " << N << " values for each dimension" <<endl;
    for (auto& v : m_) { 
        double elem=0.;
        cout << "New Dimension, start typing... " << endl;

        v.reserve(N);
        for(int i=0; i<N; i++)
        {   
            while (!(std::cin >> elem)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Try again: ";
            }
            v.push_back(elem);
        }
        cout << endl;
        // std::sort(v.begin(), v.end());
    }
    matrix_=m_;
}