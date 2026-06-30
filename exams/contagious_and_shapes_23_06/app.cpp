#include "RightAngleTriangle.h"
#include "Cone.h"
#include <iostream>

int main(){
    Triangle t1(12., 16., 20.);
    auto t2 =RightAngleTriangle::ll(12., 16., "t2 with ll");
    auto t3 =RightAngleTriangle::hl(5., 4., "t3 with hl");
    auto cone=Cone(12., 16., "Cone1");

    t1.print();
    t2.print();
    t3.print();
    cone.print();
}