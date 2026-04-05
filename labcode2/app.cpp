#include "RotatingSolidBody.h"
#include "Sphere.h"
#include "Rod.h"
#include "Rectangle.h"
int main(){
    RotatingSolidBody object(1);
    Sphere sphere_(2, 2);
    Rod rod_(3, 3);
    Rectangle rect_(4, 5, 6);

    using namespace std;
    cout << "My object " << object << endl; 
    //cout << " Sphere: " << sphere_ << " Rod: " << rod_ << " Rectangle: " << rect_ <<endl;
    object.Print();

    sphere_.Print();
    sphere_.Spin(0., 12);
    sphere_.Print(" Sphere after spinning: ");
    rod_.Print();
    rect_.Print();



    return 0;
}