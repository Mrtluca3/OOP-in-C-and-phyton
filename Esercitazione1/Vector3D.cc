#include "Vector3D.h"

int Vector3D::counter_ = 0;

Vector3D::Vector3D() { //Di default e' 3D
  dimension_=3;
  vector_ = new double[dimension_];
  counter_++;
}

Vector3D::Vector3D(const Vector3D& array) {
  vector_=array.getVector();
  dimension_=array.getDim();
  counter_++;
}

Vector3D::Vector3D(const int dimension) {
  dimension_ = dimension;
  vector_ = new double[dimension_];
  counter_++;
} //Non permetto di inizializzare la classe senza specificare la dimensione

Vector3D::Vector3D(double* array, const int dimension){ //Posso inizializzarla insieme a un vettore
  vector_ = new double[dimension]; //Non utilizzo mai delete, sperando che il destructor lo rimuovera' a tempo debito
  for(int i=0; i<dimension; i++) 
    vector_[i] = array[i]; 
  dimension_ = dimension;
  counter_++;
}

Vector3D::~Vector3D(){counter_--;} // Destructor

Vector3D Vector3D::polarCoord(double* array, const int dimension) {
  if(dimension != 3)
    throw std::invalid_argument( "Non posso definire le coordinate polari per un vettore non 3D" );
  double theta=array[1]*M_PI/180, phi=array[2]*M_PI/180;
  double polar[] = {array[0]*cos(theta)*sin(phi), array[0]*sin(theta)*sin(phi), array[0]*cos(theta)};
  return Vector3D(polar, dimension);
}

void Vector3D::setVector(double* array) { //Setter, permette di cambiare il vettore, se la dimensione della classe Vector3D e l'array non coincidono, vengono inseriti solo i primi valori corrispondente alla dimensione del Vector3D.
  for(int i=0;i<dimension_; i++)
    vector_[i] = array[i];
}

//Getters 
double* Vector3D::getVector() const {return vector_;} 
int Vector3D::getDim() const {return dimension_;}
int Vector3D::getActiveInst(){return counter_;}

Vector3D Vector3D::operator+(const Vector3D& array) const { // Definisco la somma tra due vettori
  double* temp = new double[dimension_]; //Creo un nuovo vettore temporaneo per storare le informazioni sulla somma
  for(int i=0; i<dimension_; i++) //Sommo componente per componente
    temp[i]=(vector_[i] + array.getVector()[i]);
  Vector3D vector2(temp, dimension_);
  delete[] temp;
  return vector2; //ritorno il vettore
}

Vector3D Vector3D::operator-(const Vector3D& array) const { // Definisco la differenza tra due vettori
  double* temp = new double[dimension_]; //Creo un nuovo vettore temporaneo per storare le informazioni sulla somma
  for(int i=0; i<dimension_; i++) //Sommo componente per componente
    temp[i]=(vector_[i] - array.getVector()[i]);
  Vector3D vector2(temp, dimension_);
  delete[] temp;
  return vector2; //ritorno il vettore
}

const Vector3D Vector3D::operator=(const Vector3D& array) { //Modifico l'operatore uguale
  vector_=array.getVector();
  dimension_=array.getDim();
  return (*this);
}

double Vector3D::operator*(const Vector3D& array) const { //Ridefinisco l'operazione per due vettori, corrisponde al prodotto scalare
    double scalar=0;
    double* vector2 = array.getVector();
    for(int i=0; i<dimension_; i++){
      scalar += vector_[i]*vector2[i];
    }
    return scalar;
}

Vector3D Vector3D::operator/(const double& scalar) const { //Ridefinisco l'operazione divisione per scalare
  Vector3D vector(dimension_);
  for(int i=0; i<dimension_; i++)
    vector.getVector()[i] = vector_[i] / scalar;
  return vector;
}

Vector3D Vector3D::vecProd(const Vector3D& array, const Vector3D& array2) const { //Definisco il prodotto vettoriale
  if (array.getDim() != 3) 
    throw std::invalid_argument( "Non ho voglia di generalizzare il prodotto vettoriale! Usa un vettore in 3D." );
  double v1=array.getVector()[0], v2=array.getVector()[1], v3=array.getVector()[2];
  double w1=array2.getVector()[0], w2=array2.getVector()[1], w3=array2.getVector()[2];

  double vector[] = {v2*w3-w2*v3, w1*v3-w3*v1, v1*w2-w1*v2};
  return Vector3D(vector, array.getDim());
}

double Vector3D::Magnitude() const{ // Restituisco l'ampiezza
  return std::sqrt((*this)*(*this));
}

double Vector3D::angleVectors(const Vector3D& array) const { //restituisco l'angolo tra due vettori
  double angle = array*(*this)/(this->Magnitude() * array.Magnitude());
  if(angle > 1) //Necessario nelle situazioni in cui errori di macchina causano il valore di essere >1 di poco
    angle=1;
  return std::acos(angle)*180/M_PI;
}

double Vector3D::polarAngle() const{ //Restituisco l'angolo polare
  double angle = 0;
  if(dimension_ != 3) 
    throw std::invalid_argument(  "Non posso dare l'angolo polare in coordinate Cartesiane per un vettore non 3D" );
  else 
    angle = atan(vector_[1]/vector_[0])*180/M_PI;
  return angle;
}

double Vector3D::azimuthAngle() const{ //Restituisco l'angolo azimuthale
  double angle = 0;
  if(dimension_ != 3) 
    throw std::invalid_argument( "Non posso dare l'angolo azimuthale in coordinate Cartesiane per un vettore non 3D" );
  else 
    angle = acos(vector_[2]/this->Magnitude())*180/M_PI;
  return angle;
}

//metodo globale
Vector3D operator*(const double& scalar, const Vector3D& array) { //Ridefinisco l'operazione per vettore e double, da' prodotto con scalare
  Vector3D vector(array.dimension_);
  for(int i=0; i<array.dimension_; i++)
    vector.getVector()[i] = array.getVector()[i] * scalar;
  return vector;
}

std::ostream& operator<<(std::ostream& os, const Vector3D& array) { //Ritorna i valori del vector
  os << "[";
  for(int i=0; i<array.getDim(); i++)
    if(i!=array.getDim()-1)
      os << array.getVector()[i] << ',';
    else
      os << array.getVector()[i] << "]";
  return os;
}
