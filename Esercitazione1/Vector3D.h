
#ifndef Vector3D_h
#define Vector3D_h

#include <iostream>
#include <cmath>
#include <stdexcept>

class Vector3D {
 public:
  Vector3D(); //Default constructor, crea un vettore vuoto di dimensione 3
  Vector3D(const int dimension); //Constructor in cui viene scelta la dimensione
  Vector3D(const Vector3D& array); // copy constructor
  Vector3D(double* array, const int dimension); // Constructor che permette anche l'inserimento dell'array
  static Vector3D polarCoord(double* array, const int dimension); //richiede un vettore 3D con [r, theta, phi], gli angoli vanno in gradi
  ~Vector3D(); //Destructor
  //Setter
  void setVector(double* array); 
  //Getter
  double* getVector() const;
  int getDim() const;
  static int getActiveInst(); //Restituisce il numero delle istanze attive 
  //Operazioni
  Vector3D operator+(const Vector3D& array) const;
  Vector3D operator-(const Vector3D& array) const;
  const Vector3D operator=(const Vector3D& array);
  double operator*(const Vector3D& array) const; //Prodotto scalare tra due vettori
  Vector3D operator/(const double& scalar) const;
  Vector3D vecProd(const Vector3D& array, const Vector3D& array2) const; //Restituisce il prodotto vettoriale tra due vettori 3D
  friend Vector3D operator*(const double& scalar, const Vector3D& array); //Moltiplicazione per scalare
  friend std::ostream& operator<<(std::ostream& os, const Vector3D& array); //Restituisce i valori del vettore
  double Magnitude() const;
  double angleVectors(const Vector3D& array) const; //Restituisce l'angolo compreso tra due vettori
  double polarAngle() const;
  double azimuthAngle() const;
 private:
  int dimension_;
  double* vector_; 
  static int counter_;
};

#endif