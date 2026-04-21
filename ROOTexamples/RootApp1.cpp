#include  "TH1F.h"

int main() {

  TH1F h1("First", "Mytitle", 20, -6.0, +6.0);
  h1.FillRandom("gaus", 10000);
  h1.Print();

  return 0;
}
