#include "Vector3D.h"

using namespace std;

int main() {
  int dimension, man;
  cout << "Inserisci la dimensione dell'array: ";
  cin >> dimension;
  double* vector_, *vector2_;
  vector_ = new double[dimension];
  vector2_ = new double[dimension];
  cout << "Vuoi valori randomici [1] o inserirli manualmente [0]? ";
  cin >> man;
  if(man == 0) {
    cout << "Inserisci i valori dell'array: " << endl;
    for(int i=0; i<dimension; i++)
      cin >> vector_[i];
    
    cout << "Inserisci i valori del secondo array: " << endl;
    for(int i=0; i<dimension; i++)
      cin >> vector2_[i];
    
  } else {
    for(int i=0; i<dimension; i++){
      vector_[i]= 1;
      vector2_[i]= 2;
    }
  }
  Vector3D v1(vector_, dimension), v2(vector2_, dimension), v3(dimension);
  Vector3D v4 = Vector3D::polarCoord(vector_, dimension);
  Vector3D v5 = v1;
  delete vector_;
  delete vector2_;

  cout << "Prodotto scalare:" << v1*v2 << endl;

  v3 = 5*v1;
  cout << "Prodotto per scalare: " << v3 << endl;

  v3 = v1/5;
  cout << "Divisione per scalare: " << v3 << endl;

  v3 = v1 + v2;
  cout << "Somma vettoriale: " << v3 << endl;;
  
  v3 = v1 - v2;
  cout << "Differenza vettoriale: " << v3 << endl;

  cout<< "Ampiezza del primo vettore: "<< v1.Magnitude() << endl;
  cout << "Angolo tra i due vettori: " << v1.angleVectors(v2) << endl;
  cout << "Angolo polare: " << v1.polarAngle() << endl;
  cout << "Angolo azimuthale: " << v1.azimuthAngle() << endl;
  cout << "Angolo polare del vettore in polarCoord: " << v4.polarAngle() << endl;
  cout << "Angolo azimuthale del vettore in polarCoord: " << v4.azimuthAngle() << endl;
  cout << "Istanze attive totali " << Vector3D::getActiveInst() << endl;
  return 0;
}
