#include "Polynomial.h"
#include <iostream>
#include "VectorField.h"
int main(){
    using namespace std;
    auto p = Polynomial({1, 2., 3., 4., 5., 6., 7., 8., 9., 10.}, "123");
    cout << p << p.Set({1, 2., 3., 4., 5., 6., 7., 8., 9., 11.}) << " new p: " << p;
    cout << " derivative in 1, 2, 3 'x': " << p.deriv(1., 2, 3, 'x') << " value in 1: " << p.value(1, 2, 3) << endl;

    cout << "\n--- START VECTORFIELD TESTS ---\n" << endl;

    // 2. Define 3 separate polynomials for the field components F = (Fx, Fy, Fz)
    // Coefficient mapping reference: 
    // {a0, a1_x, a2_y, a3_z, a4_x2, a5_y2, a6_z2, a7_xy, a8_xz, a9_yz}
    
    // Fx = x^2  -> a4 coefficient is set to 1.0
    Polynomial px({0, 0, 0, 0, 1.0, 0, 0, 0, 0, 0}, "Fx");
    // Fy = y^2  -> a5 coefficient is set to 1.0
    Polynomial py({0, 0, 0, 0, 0, 1.0, 0, 0, 0, 0}, "Fy");
    // Fz = z^2  -> a6 coefficient is set to 1.0
    Polynomial pz({0, 0, 0, 0, 0, 0, 1.0, 0, 0, 0}, "Fz");

    // 3. Instantiate the VectorField object F = (x^2, y^2, z^2)
    // The constructor takes parameters by value and executes 'new' internally
    VectorField field(px, py, pz);

    // 4. Set the verification evaluation point (x=1.0, y=2.0, z=3.0)
    double tx = 1.0;
    double ty = 2.0;
    double tz = 3.0;

    // 5. Test the VectorField stream insertion operator <<
    cout << "Vector Field Representation: " << field << endl;

    // 6. Test Divergence (div)
    // Theory: dFx/dx + dFy/dy + dFz/dz = 2x + 2y + 2z
    // Evaluation at (1, 2, 3): 2(1) + 2(2) + 2(3) = 2 + 4 + 6 = 12
    double divergence = field.div(tx, ty, tz);
    cout << "Divergence at (1, 2, 3): " << divergence << " (Expected: 12)" << endl;

    // 7. Test Curl (curl)
    // Theory: Since each component is independent (Fx only depends on x, etc.),
    // all cross-derivatives are zero. The expected curl vector is (0, 0, 0).
    vector<double> rotore = field.curl(tx, ty, tz);
    
    cout << "Curl at (1, 2, 3): (";
    for (size_t i = 0; i < rotore.size(); ++i) {
        cout << rotore[i];
        if (i < rotore.size() - 1) cout << ", ";
    }
    cout << ") (Expected: 0, 0, 0)" << endl;

    return 0;
} 
