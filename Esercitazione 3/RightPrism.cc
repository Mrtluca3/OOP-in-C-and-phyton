#include "RightPrism.h"

Prism::Prism(double h) { h_=h; } // Non chiamo il constructor di Shape perchè lo fa quando chiamo Hexagon
Prism::~Prism() { std::cout << "Destructor of RightPrism called" << std::endl; }
void Prism::setH(double h) { h_=h; }