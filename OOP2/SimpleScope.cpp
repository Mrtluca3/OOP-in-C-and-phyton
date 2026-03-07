#include <iostream>
using namespace std;

int main() {
    // It is terrible coding!!!
    // double x = 1.2;
    int x=100;
    cout << "in main before scope, x: " << x << endl;
    cout << "in main before scope, &x: " << &x << endl;
    for(int i=0; i<3; ++i) { // just a local scope
        cout << "--> i: " << i << endl;

        x++;
        // double* pnt1= &x;
        int* pnt1= &x;
        cout << "in local scope before int, x: " << x << endl;
        cout << "in local scope before int, pnt1: " << pnt1 << endl;
        int x = 4;
        int* pnt2 = &x;
        cout << "in local scope after int, x: " << x << endl;
        cout << "in local scope after int, pnt2: " << pnt2 << endl;
    }

    //This will not work: it is outside the scope of i
    // cout << i << endl;
    cout << "in main after local scope, x: " << x << endl;

    return 0;
}
