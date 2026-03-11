#include <iostream>
#include <random>
#include <fstream>
#include "Capacitor.h"

int main(void) {
    srand(0);
    Capacitor c1, c2, c3, c4, c5;
    c2.setC(10); c3.setC(5); c4.setC(15);
    std::ofstream ofile;
    std::string ofname("true.dat");
    std::cout << "storing data in " << ofname << std::endl;
    ofile.open( ofname );

    for(int i=0; i<1e3; i++) {
        c1.setC((rand())%100 + 1);
        c5 = ((c1||c2) + (c3||c4));
        ofile << c1.getC() << "\t" << c5.getC() << std::endl;
    }

    ofile.close();
    std::cout << ofname << " output file successfully created" << std::endl;

    return 0;
}