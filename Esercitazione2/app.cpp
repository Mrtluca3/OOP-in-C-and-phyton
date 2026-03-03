#include "Sphere.h"
#include "Rod.h"
#include "Rectangle.h"
#include <iomanip>

using namespace std;

int main() {
    int corpo;
    double Mass, w, d, I;
    cout << "Insert Mass of the body: " <<endl;
    cin >> Mass; 
    RotatingSolidBody* body = 0;

    cout << fixed << setprecision(2);

    cout << "Choose the body you want to implement: Sphere [1], Rod [2], Rectangle [3]" << endl;
    cin >> corpo;

    switch(corpo) {
        case 1: {
            double R;
            cout << "Insert Radius of the sphere: " <<endl;
            cin >> R;
            body = new Sphere(Mass, R);
            break;
        }
        case 2: {
            double L;
            cout << "Insert Length of the rod: " <<endl;
            cin >> L; 
            body = new Rod(Mass, L);
            break;
        }
        case 3: {
            double a, b;
            cout << "The two Lengths of the rectangle: " <<endl;
            cin >> a >> b; 
            body = new Rectangle(Mass, a, b);
            break;
        }
        default: 
            cout << "Non hai inseirto un valore valido" <<endl;
    }

    body->Print();
    cout << "Insert the frequency and distance of rotation from the c.m. Axis: " << endl;
    cin >> w >> d;
    body->Spin(w, d);
    body->Print(); //Vedo se inizia a ruotare

    body->setd(2); // Vedo se funziona setd
    body->setMass(30);
    body->Print();

    delete body;
    return 0;
}