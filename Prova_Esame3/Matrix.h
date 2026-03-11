#include <vector>
#include <iostream>

#ifndef Matrix_h
#define Matrix_h
class Matrix {
    public:
    Matrix(int N); //Constructor, builds a square matrix full of zeros
    Matrix(int N, double elem); //Constructor, builds a square diagonal matrix with elem on the diagonal
    Matrix(int Nrows, int Ncols); //Constructor, builds a rectangular matrix full of zeros
    Matrix(double** els, int Nrows, int Ncols);
    Matrix(Matrix& M); //copy constructor
    ~Matrix(); //Destructor

    void Print() const; //Prints the whole matrix

    //getters
    int getNcols() const;
    int getNrows() const;
    double getElement(int R, int C) const; //returns an element to that index; R stands for row, C for column
    const double* getRow(int R) const; //returns a row, asks for what row index
    const double* getColumn(int C) const; //returns a column, asks for what column index
    double** const getMatrix() const; //returns the matrix

    //setters 
    void setElement(int R, int C, double elem); //replacec an element to that index; R stands for row, C for column, elem for element value
    void setRow(int R, double* vec); //replaces a row, asks for what row index and an the array to replace with
    void setCol(int C, double* vec);//replaces a column, asks for what column index and an the array to replace with
    void setMatrix(double** els, int Nrows, int Ncols); //replaces the matrix

    void switchElem(int R1, int C1, int R2, int C2); //Switch a particular element
    void switchCol(int C1, int C2); //Switch two columns, asks for columns indices
    void switchRow(int R1, int R2); //Switch two rows, asks for rows indices
    void Transpose(); //Transpose the matrix 

    //operators
    Matrix operator+(Matrix& m) const; //Sum of two matrices
    Matrix operator-(Matrix& m) const; //Subtraction of two matrices
    Matrix operator*(Matrix& m) const; //Multiplication of two matrices
    void operator=(Matrix& m); //Copy operator of a matrix

    private:
    //The following I don't want to be accessible externally, if used improperly can cause memory leaks
    Matrix();
    void setNcols(int N); //sets the number of columns
    void setNrows(int N); //sets the number of rows
    
    int Ncols_, Nrows_;
    double** els_;
};

#endif