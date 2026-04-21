#include "TMath.h"
#include "Math/Vector4D.h"
#include "Math/Vector3D.h"
#include "Math/Vector4Dfwd.h"
#include "Math/LorentzVector.h"
#include "Math/Boost.h"

#include <iostream>

using std::cout;
using std::endl;
using namespace ROOT::Math;

const double to_degrees = (180.0/3.141592653589793238463);

int main() {

  // Create the B meson 4-momentum in the LAB frame
  //PtEtaPhiEVector p4_B;
  double m_B = 5.279; // GeV
  double p_B = 0.300; // GeV
  // Flat metric, (- - - +) signature: m^2 = -p^2 + E^2
  PtEtaPhiEVector p4_B(p_B, 0, 0, sqrt(p_B*p_B+m_B*m_B));

  // Create the pion 4-momentum in the B rest frame
  double m_pi = 0.140; // GeV
  double p_pi = 0.100; // GeV
  PtEtaPhiEVector p4_pi;
  // Flat metric, (- - - +) signature: m^2 = -p^2 + E^2
  p4_pi.SetPxPyPzE(0, p_pi, 0, sqrt(m_pi*m_pi+p_pi*p_pi));

  /*
     Print to screen 4-momenta as we have them
     As a reminder:
     * Hadron colliders measure physical momenta in terms of momentum transverse
       to the beam axis (z-axis); the TRANSVERSE MOMENTUM is denoted by p_T
     * p_x = p_T * cos(phi) 
       p_y = p_T * sin(phi) 
       p_z = m_T * sinh(eta) 
       E = m_T * cosh(eta) 
       where m_T = sqrt(p_T^2 + m^2) is the TRANSVERSE MASS
     * eta is the PSEUDORAPIDITY: eta = -ln[tan(theta/2)]; differences in eta
       are Lorentz invariants under boosts along the longitudinal axis
  */
  cout << "--> LAB p4 B: " << endl;
  cout << "(P, eta, phi, E) = " << p4_B << endl;
  cout << "(x, y, z, t) = (" << p4_B.X() << ", " << p4_B.Y() << ", " << p4_B.Z() << ", " << p4_B.t() << ")" << endl;
  cout << "--> CoM p4 pi: " << endl;
  cout << "(P, eta, phi, E) = " << p4_pi << endl;
  cout << "(x, y, z, t) = (" << p4_pi.X() << ", " << p4_pi.Y() << ", " << p4_pi.Z() << ", " << p4_pi.t() << ")" << endl;

  // The TLorentzVector class provides the Beta() and Gamma() methods to
  // compute the boost parameters: we compare them to their definitions
  cout << "--> boost parameters of B reference frame" << endl;
  cout << "\t beta: " << p4_B.Beta() << "\t"
       << "\t p/E: " << p4_B.P()/p4_B.E() << "\n"
       << "\t gamma: " << p4_B.Gamma() << "\t"
       << "\t E/m: " << p4_B.E()/m_B << "\n"
       << "\t beta*gamma: " << p4_B.Beta()*p4_B.Gamma() << "\t"
       << "\t p/m: " << p_B/m_B
       << endl;

  // Boost parameters of the B frame in the LAB frame can be accessed
  // with the BoostVector method
  cout << "--> boost vector of the B meson" << endl;
  // The beta vector for the boost that would bring this vector into its center of mass frame (zero momentum)
  XYZVector LBoost = -p4_B.BoostToCM();
  cout << "(x, y, z) = (" << LBoost.X() << ", " << LBoost.Y() << ", " << LBoost.Z() << ")" << endl;
  cout << "(r, theta, phi) = (" << LBoost.r() << ", " << LBoost.Theta()*to_degrees << ", " << LBoost.Phi()*to_degrees << ")" << endl;

  // Let's boost the pion to the LAB frame
  cout << "--> now boost the pion to LAB" << endl;
  PxPyPzE4D p4_pi_boosted(p4_pi.X(), p4_pi.Y(), p4_pi.Z(), p4_pi.T());
  PxPyPzE4D p4_pi_boost(p4_B.X(), p4_B.Y(), p4_B.Z(), p4_B.T());
  //DisplacementVector3D LBoost = -p4_B.BoostToCM();
  //XYZTVector p4_pi_boost(p4_pi.X(), p4_pi.Y(), p4_pi.Z(), p4_pi.T());
  //p4_pi_boosted(LBoost.X(), LBoost.Y(), LBoost.Z(), 0);
  p4_pi_boosted = Boost::operator()(p4_pi_boost);
  p4_pi_boosted = p4_pi(p4_pi_boost);
  cout << "--> LAB p4 pi: " << endl;
  //cout << "(P, eta, phi, E) = " << p4_pi_boosted.X(),  /<< endl;
  cout << "(X, Y, Z, T) = " << p4_pi_boosted.X() << " " << p4_pi_boosted.Y() << " " << p4_pi_boosted.Z() << " " << p4_pi_boosted.T() << endl;

  // Exit
  return 0;
}
