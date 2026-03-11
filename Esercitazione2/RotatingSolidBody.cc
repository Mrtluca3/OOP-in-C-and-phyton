#include "RotatingSolidBody.h"

RotatingSolidBody::RotatingSolidBody() {}
RotatingSolidBody::RotatingSolidBody(double Mass) { Mass_ = Mass; }
RotatingSolidBody::~RotatingSolidBody() {};


//Getters
double RotatingSolidBody::getMass() const { return Mass_; }
double RotatingSolidBody::getFreq() const { return w_; }
void RotatingSolidBody::setMass(const double& Mass) { Mass_ = Mass; }



