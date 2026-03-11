#include <iostream>
using namespace std;

class Datum {
  public:
    Datum() { }

    Datum(double x, double y) {
      value_ = x;
      error_ = y;
    }

    Datum(const Datum& datum) {
      value_ = datum.value_;
      error_ = datum.error_;
    }

    void print() {
      cout << "datum: " << value_
           << " +/- " << error_
           << endl;
    }
 //private:  //of course if commenting this, I'm making a big big mistake
    double value_;
    double error_;
};


int main() {

  Datum d1;
  d1.print();

  Datum d2(0.23,0.212);
  d2.print();

  Datum d3(d2);
  d3.print();
  cout << &d2 << "\t" <<&d3 << endl;
  d3.value_=400;
  cout << d3.value_ << " " << d2.value_ <<endl;
  return 0;
}
