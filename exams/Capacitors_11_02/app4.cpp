#include "Capacitor.h"
#include <iostream>
#include <fstream>
#include <random>
Capacitor Circuit(const Capacitor C1, const Capacitor C2, const Capacitor C3, const Capacitor C4 ){
        return ((C1||C2) + (C3||C4));
}
int main(){

    using namespace std;
    ofstream outFile("true.dat");
    // Initialize random device std::random_device
    random_device rd;
    // Initialize generator (Mersenne Twister)
    mt19937 gen(rd());

    // Define the distribution range [min, max]
    uniform_real_distribution<double> dist(1, 100);


    Capacitor C1;
    Capacitor C2, C3, C4;
    cout << C2.setC(10);
    cout << C3.setC(5);
    cout << C4.setC(15);
    
    // Generate numbers
    for (int i = 0; i < 1000; ++i) {
        C1.setC(dist(gen));
        // std::cout<< "C1||C2 " <<(C1||C2);
        // std::cout<< "C3||C4 " << (C3||C4);
        // std::cout<< "C1||C2 + C3||C4 " <<((C1||C2) +(C3||C4));
        // cout << Circuit(C1, C2, C3, C4);
        outFile << C1.C() << " " << Circuit(C1, C2, C3, C4).C() << endl;
    }
    outFile.close();
    cout << "Created file: true-dat in format C1 Ceq"<<endl;
    return 0;
}
