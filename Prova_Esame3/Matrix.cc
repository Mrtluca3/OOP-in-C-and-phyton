#include "Matrix.h"

Matrix::Matrix(int N) {
    Ncols_=N;
    Nrows_ = N;
    els_ = new double*[Nrows_];
    for(int i =0; i<Nrows_; i++) { //I span over the rows
        els_[i] = new double[Ncols_];
        for(int j=0; j<Ncols_; j++) //I span over the columns
            els_[i][j] = 0.0;
    } 
} //Constructor

Matrix::Matrix(int N, double elem) {
    Ncols_=N;
    Nrows_ = N;
    els_ = new double*[Nrows_];
    for(int i =0; i<Nrows_; i++) { //I span over the rows
        els_[i] = new double[Ncols_];
        for(int j=0; j<Ncols_; j++) //I span over the columns
            if(i!=j)
                els_[i][j] = 0.0;
            else
                els_[i][j] = elem;
    } 
} //Constructor

Matrix::Matrix(int Ncols, int Nrows) {
    Ncols_=Ncols;
    Nrows_ = Nrows;

    els_ = new double*[Nrows_];
    for(int i =0; i<Nrows_; i++) { //I span over the rows
        els_[i] = new double[Ncols_];
        for(int j=0; j<Ncols_; j++) //I span over the columns
            els_[i][j] = 0;
    } 
} //Constructor

Matrix::Matrix(double** els, int Nrows, int Ncols) {
    Nrows_ = Nrows;
    Ncols_ = Ncols;
    els_ = new double*[Nrows_];
    for(int i =0; i<Nrows_; i++) { //I span over the rows
        els_[i] = new double[Ncols_];
            for(int j=0; j<Ncols_; j++) //I span over the columns
                els_[i][j] = els[i][j];
    } 
} //Constructor

Matrix::Matrix(Matrix& M) {
    Ncols_ = M.getNcols();
    Nrows_ = M.getNrows();
    els_ = new double*[Nrows_];
    for(int i=0; i< Nrows_; i++) {
        els_[i] = new double[Ncols_];
        for(int j=0; j< Ncols_; j++)
            els_[i][j] = M.getElement(i, j);
    }
} //copy constructor

Matrix::~Matrix() {
    //I free the allocated memory for the matrix 
    delete* els_;
} //Destructor


void Matrix::Print() const {
    for(int i=0; i<Nrows_; i++) {
        for(int j=0; j<Ncols_; j++)
            std::cout << els_[i][j] << "\t";
        std::cout << std::endl;
    }
    std::cout << std::endl;
} 

//getters
int Matrix::getNcols() const { return Ncols_; }
int Matrix::getNrows() const { return Nrows_; }
double Matrix::getElement(int R, int C) const {return els_[R][C];} //returns an element to that index; R stands for row, C for column
const double* Matrix::getRow(int R) const {return els_[R];} //returns a row, asks for what row index
double** const Matrix::getMatrix() const {return els_;} //returns the Matrix::Matrix



//setters 
void Matrix::setElement(int R, int C, double elem) { els_[R][C] = elem;} //replacec an element to that index; R stands for row, C for column, elem for element value

void Matrix::setRow(int R, double* vec) {
    for(int i=0; i<Ncols_; i++)
        els_[R][i] = vec[i];
} //replaces a row, asks for what row index and an the array to replace with

void Matrix::setCol(int C, double* vec) {
    for(int i=0; i<Ncols_; i++)
        els_[i][C] = vec[i];
} //replaces a column, asks for what column index and an the array to replace with


void Matrix::setMatrix(double** els, int Nrows, int Ncols) {
    //I free the allocated memory for the matrix 
    delete* els_;
    
    //create a new matrix
    Nrows_ = Nrows;
    Ncols_ = Ncols;
    els_ = new double*[Nrows_];
    for(int i =0; i<Nrows_; i++) { //I span over the rows
        els_[i] = new double[Ncols_];
            for(int j=0; j<Ncols_; j++) //I span over the columns
                els_[i][j] = els[i][j];
    } 
} //replaces the Matrix
void Matrix::setNcols(int N) { Ncols_ = N; } //sets the number of columns
void Matrix::setNrows(int N) { Nrows_ = N;} //sets the number of rows

void Matrix::switchElem(int R1, int C1, int R2, int C2) {
    double temp = els_[R1][C1]; //save one of the two elements

    //switch the two elements
    els_[R1][C1] = els_[R2][C2];
    els_[R2][C2] = temp;
} //Switch a particular element

void Matrix::switchCol(int C1, int C2) {
    double* vec = new double[Nrows_]; 
    for(int i=0; i< Nrows_; i++) // I save one column temporarly
        vec[i] = els_[i][C1];

    for(int i=0; i< Nrows_; i++) { // I switch the two columns
        els_[i][C1] = els_[i][C2];
        els_[i][C2] = vec[i];
    }
    delete[] vec;
} //Switch two columns, asks for columns indices

void Matrix::switchRow(int R1, int R2) {
    double* vec = new double[Ncols_]; 
    for(int i=0; i< Ncols_; i++) // I save one column temporarly
        vec[i] = els_[R1][i];

    for(int i=0; i< Ncols_; i++) { // I switch the two columns
        els_[R1][i] = els_[R2][i];
        els_[R2][i] = vec[i];
    }
    delete[] vec;
} //Switch two rows, asks for rows indices

void Matrix::Transpose() {
    double** temp = new double*[Ncols_]; //Matrix with inverted dimensions, temporary
    int temp_Ncols = Ncols_;
    for(int i =0; i<Ncols_; i++) { //I span over the rows
        temp[i] = new double[Nrows_]; //Matrix with inverted dimensions, temporary    
        for(int j=0; j<Nrows_; j++) //I span over the columns
                temp[i][j] = els_[j][i];
    }    

    //Replace the informations about the current matrix
    this->setNcols(Nrows_);
    this->setNrows(temp_Ncols);
    this->setMatrix(temp, Nrows_, Ncols_);
    
    //I remove temp
    delete* temp;
}

//operators
Matrix Matrix::operator+(Matrix& m) const {
    if(m.getNcols() != this->getNcols() && m.getNrows() != this-> getNrows()){
        std::cout << "Matrices dimensions must be the same" << std::endl;
        exit(0);
    }
    double** temp;
    temp = new double*[Nrows_];
    for(int i =0; i<Nrows_; i++) { //I span over the rows
        temp[i] = new double[Ncols_];
            for(int j=0; j<Ncols_; j++) //I span over the columns
                temp[i][j] = this->getElement(i,j) + m.getElement(i,j); //I sum the elements
    } 
    Matrix m1(temp, Nrows_, Ncols_);
    delete* temp;
    return m1;
} //Sum of two matrices

Matrix Matrix::operator-(Matrix& m) const {
 if(m.getNcols() != this->getNcols() && m.getNrows() != this-> getNrows()){
        std::cout << "Matrices dimensions must be the same" << std::endl;
        exit(0);
    }
    double** temp;
    temp = new double*[Nrows_];
    for(int i =0; i<Nrows_; i++) { //I span over the rows
        temp[i] = new double[Ncols_];
            for(int j=0; j<Ncols_; j++) //I span over the columns
                temp[i][j] = this->getElement(i,j) - m.getElement(i,j); //I subtract the elemtns
    } 
    Matrix m1(temp, Nrows_, Ncols_);
    delete* temp;
    return m1;
} //Subtraction of two matrices

Matrix Matrix::operator*(Matrix& m) const {
     if(m.getNrows() != this->getNcols()){
        std::cout << "Matrix 1 columns and Matrix 2 rows must be the same number" << std::endl;
        exit(0);
    }
    double** temp;
    temp = new double*[Nrows_];
    for(int i =0; i<Nrows_; i++) { //I span over the rows
        temp[i] = new double[m.getNcols()];
            for(int j=0; j<m.getNcols(); j++){ //I span over the columns
                temp[i][j]=0;
                for(int k=0; k<Ncols_; k++) //I do row times column
                    temp[i][j] += this->getElement(i,k) * m.getElement(k,j);
            } 
    }
    Matrix m1(temp, Nrows_, m.getNcols());
    delete* temp;
    return m1;
} //Multiplication of two matrices

void Matrix::operator=(Matrix& M) {
    Ncols_ = M.getNcols();
    Nrows_ = M.getNrows();
    els_ = new double*[Nrows_];
    for(int i=0; i< Nrows_; i++) {
        els_[i] = new double[Ncols_];
        for(int j=0; j< Ncols_; j++)
            els_[i][j] = M.getElement(i, j);
    }
} //Copy operator of a matrix
