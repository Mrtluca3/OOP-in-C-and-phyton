#include "Mesh.h"
#include "Source.h"
#include "Voltage.h"
#include <iostream>

int main() {
    int N = 3;
    double L = 1;

    Mesh grid = Mesh::Regular(N, L);
    // grid = Mesh(N);
    // grid = Mesh::Random(N, L);
    Source charges(grid, "scalar");
    
    Voltage v(grid, charges);
    
    v.Print();

    return 0;
}