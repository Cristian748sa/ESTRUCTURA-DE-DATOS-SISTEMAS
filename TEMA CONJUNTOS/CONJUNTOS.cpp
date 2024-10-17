#include <iostream>
using namespace std;

int estaEnArreglo(int elemento, int arreglo[], int tamanoArreglo) {
  for (int i = 0; i < tamanoArreglo; ++i) {
    if (arreglo[i] == elemento) {
      return true;
    }
  }
  return false;
}

// Función para calcular la unión de dos arreglos
void unionArreglos(int arreglo1[], int tamanoArreglo1, int arreglo2[], int tamanoArreglo2, int resultado[], int& tamanoResultado) {
  int indiceResultado = 0;
  for (int i = 0; i < tamanoArreglo1; ++i) {
    if (!estaEnArreglo(arreglo1[i], resultado, indiceResultado)) {
      resultado[indiceResultado++] = arreglo1[i];
    }
  }
  for (int i = 0; i < tamanoArreglo2; ++i) {
    if (!estaEnArreglo(arreglo2[i], resultado, indiceResultado)) {
      resultado[indiceResultado++] = arreglo2[i];
    }
  }
  tamanoResultado = indiceResultado;
}

// Función para calcular la intersección de dos arreglos
void interseccionArreglos(int arreglo1[], int tamanoArreglo1, int arreglo2[], int tamanoArreglo2, int resultado[], int& tamanoResultado) {
  int indiceResultado = 0;
  for (int i = 0; i < tamanoArreglo1; ++i) {
    if (estaEnArreglo(arreglo1[i], arreglo2, tamanoArreglo2)) {
      if (!estaEnArreglo(arreglo1[i], resultado, indiceResultado)) { // Evita duplicados
        resultado[indiceResultado++] = arreglo1[i];
      }
    }
  }
  tamanoResultado = indiceResultado;
}

// Función para calcular la diferencia de dos arreglos
void diferenciaArreglos(int arreglo1[], int tamanoArreglo1, int arreglo2[], int tamanoArreglo2, int resultado[], int& tamanoResultado) {
  int indiceResultado = 0;
  for (int i = 0; i < tamanoArreglo1; ++i) {
    if (!estaEnArreglo(arreglo1[i], arreglo2, tamanoArreglo2)) {
      resultado[indiceResultado++] = arreglo1[i];
    }
  }
  tamanoResultado = indiceResultado;
}

// Función para calcular el complemento de un arreglo
void complementoArreglo(int arreglo[], int tamanoArreglo, int universo[], int tamanoUniverso, int resultado[], int& tamanoResultado) {
  int indiceResultado = 0;
  for (int i = 0; i < tamanoUniverso; ++i) {
    if (!estaEnArreglo(universo[i], arreglo, tamanoArreglo)) {
      resultado[indiceResultado++] = universo[i];
    }
  }
  tamanoResultado = indiceResultado;
}

int main() {
  int a[] = {1, 1, 2};
  int b[] = {2, 3, 3};
  int universo[] = {1, 2, 3, 4};
  int tamanoA = 3; 
  int tamanoB = 3; 
  int tamanoUniverso = 4; 

  // Unión
  int union_ab[tamanoA + tamanoB];
  int tamanoUnion_ab = 0;
  unionArreglos(a, tamanoA, b, tamanoB, union_ab, tamanoUnion_ab);
  cout << "a u b = {";
  for (int i = 0; i < tamanoUnion_ab; ++i) {
    cout << union_ab[i] << (i < tamanoUnion_ab - 1 ? ", " : "");
  }
  cout << "}" << endl;

  // Intersección
  int intersection_ab[tamanoA];
  int tamanoIntersection_ab = 0;
  interseccionArreglos(a, tamanoA, b, tamanoB, intersection_ab, tamanoIntersection_ab);
  cout << "a intersección b = {";
  for (int i = 0; i < tamanoIntersection_ab; ++i) {
    cout << intersection_ab[i] << (i < tamanoIntersection_ab - 1 ? ", " : "");
  }
  cout << "}" << endl;

  // Diferencia a - b
  int difference_ab[tamanoA];
  int tamanoDifference_ab = 0;
  diferenciaArreglos(a, tamanoA, b, tamanoB, difference_ab, tamanoDifference_ab);
  cout << "a - b = {";
  for (int i = 0; i < tamanoDifference_ab; ++i) {
    cout << difference_ab[i] << (i < tamanoDifference_ab - 1 ? ", " : "");
  }
  cout << "}" << endl;

  // Diferencia b - a
  int difference_ba[tamanoB];
  int tamanoDifference_ba = 0;
  diferenciaArreglos(b, tamanoB, a, tamanoA, difference_ba, tamanoDifference_ba);
  cout << "b - a = {";
  for (int i = 0; i < tamanoDifference_ba; ++i) {
    cout << difference_ba[i] << (i < tamanoDifference_ba - 1 ? ", " : "");
  }
  cout << "}" << endl;

  // Unión de diferencias
  int union_differences[tamanoA + tamanoB];
  int tamanoUnion_differences = 0;
  unionArreglos(difference_ab, tamanoDifference_ab, difference_ba, tamanoDifference_ba, union_differences, tamanoUnion_differences);
  cout << "(a - b) u (b - a) = {";
  for (int i = 0; i < tamanoUnion_differences; ++i) {
    cout << union_differences[i] << (i < tamanoUnion_differences - 1 ? ", " : "");
  }
  cout << "}" << endl;

  // Complemento de a
  int complement_a[tamanoUniverso];
  int tamanoComplement_a = 0;
  complementoArreglo(a, tamanoA, universo, tamanoUniverso, complement_a, tamanoComplement_a);
  cout << "a complemento = {";
  for (int i = 0; i < tamanoComplement_a; ++i) {
    cout << complement_a[i] << (i < tamanoComplement_a - 1 ? ", " : "");
  }
  cout << "}" << endl;

  // Complemento de b
  int complement_b[tamanoUniverso];
  int tamanoComplement_b = 0;
  complementoArreglo(b, tamanoB, universo, tamanoUniverso, complement_b, tamanoComplement_b);
  cout << "b complemento = {";
  for (int i = 0; i < tamanoComplement_b; ++i) {
    cout << complement_b[i] << (i < tamanoComplement_b - 1 ? ", " : "");
  }
  cout << "}" << endl;

  return 0;
}