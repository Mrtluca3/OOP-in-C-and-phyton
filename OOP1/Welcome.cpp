// Tutorial 2: Welcome.cpp
// This application welcomes the user to C++ programming.
#include <iostream> // required to perform C++ stream I/O
#include "Foo.h"
using namespace std; // for accessing C++ Standard Library members

// function main begins program execution
int main()
{
   int I=0;
   cout << "Welcome to C++ programming! Input a number" << endl; // display message
   cin >> I;
   if (cin.fail())
    cout << "input failed.\n" <<endl;
   cout << "I set to " << I << endl;
   // return 0; // that program ended successfully

} // end function main


 /**************************************************************************
  * (C) Copyright 1992-2005 by Deitel & Associates, Inc. and               *
  * Pearson Education, Inc. All Rights Reserved.                           *
  * DISCLAIMER: The authors and publisher of this book have used their     *
  * best efforts in preparing the book. These efforts include the          *
  * development, research, and testing of the theories and programs        *
  * to determine their effectiveness. The authors and publisher make       *
  * no warranty of any kind, expressed or implied, with regard to these    *
  * programs or to the documentation contained in these books. The authors *
  * and publisher shall not be liable in any event for incidental or       *
  * consequential damages in connection with, or arising out of, the       *
  * furnishing, performance, or use of these programs.                     *
  **************************************************************************/
