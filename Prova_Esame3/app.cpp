#include "Matrix.h"

int main(void) {
    int Ncols=4;
    Matrix Id(3, 1.); //I create an identity matrix
    Id.Print();
    double** m1 = new double*[3];
    double vec[] = {1,3,4};
    for(int i=0; i<3;i++) { //I fill the matrix
        m1[i] = new double[Ncols];
        for(int j=0; j<Ncols; j++)
            m1[i][j]=rand()%4; 
    }
    Matrix m2(m1,3, Ncols), m3(m1,3,Ncols); //I create different matrices with one of the consturctor methods
    m2.Print(); //see the m2 matrix
    m2.Transpose(); //transpose
    m2.Print(); //see
    m2.setElement(0,0,200); //change one lement
    m2.setRow(2, vec); //change one row
    m2.Print(); //see
    m2.switchCol(0,2); //switch two Cols
    m2.Print(); //see
    m3.Print(); //I see m3
    (m2*m3).Print(); //Do the operations on these
    (Id+Id).Print();
    (Id-Id).Print();

    //I free the allocated memory
    delete* m1;
    return 0;
}