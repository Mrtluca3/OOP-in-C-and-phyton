#include "Capacitor.h"
#include <iostream>

int main(){
    using namespace std;
    Capacitor C1(1, 3, 3);
    cout << C1 <<endl;
    Capacitor C2(C1);
    cout << C2 <<endl;
    Capacitor C3= C1;
    cout << C3 <<endl;
    Capacitor C4;
    cout << C4 <<endl;
    C4=C1;
    cout << C4 <<endl;
    cout << "&C4 "<< &C4 << " $C1 " << &C1 <<endl;
    Capacitor& C5 = C1;
    cout <<"Prove of set method using C5 reference: "<<  C5;
    cout << "&C5 "<< &C5 << " &C1 " << &C1 <<endl;

    C5.setA(10);
    cout <<"Set A=10. C5 "<<C5;
    cout <<"And C1: "<< C1;
    

}