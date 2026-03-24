#include <iostream>
using namespace std;

#include "Datum.h"


int main() {
  const Datum d1( 1.2, 0.3 );
  Datum d2( -0.4, 0.4 );

  Datum d3=d1; 
  d3.print();

  Datum d4;
  d4.operator=(d2);
  // cout << "type of d3=d1 "<<   typeid(d3.operator=(d1)).name() << endl; 
  d4.print();
  cout << "Reference of d4: "<< &d4 << " Reference of d2 " << &d2 <<endl;
  cout << "Reference of d3: "<< &d3 << " Reference of d1" << &d1 <<endl;

  return 0;
}
