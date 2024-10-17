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

// Funcion para calcular la union de dos arreglos sin duplicados
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

// Funcion para calcular la interseccion de dos arreglos
void interseccionArreglos(int arreglo1[], int tamanoArreglo1, int arreglo2[], int tamanoArreglo2, int resultado[], int& tamanoResultado) {
  int indiceResultado = 0;
  for (int i = 0; i < tamanoArreglo1; ++i) {
    if (estaEnArreglo(arreglo1[i], arreglo2, tamanoArreglo2)) {
      if (!estaEnArreglo(arreglo1[i], resultado, indiceResultado)) {
        resultado[indiceResultado++] = arreglo1[i];
      }
    }
  }
  tamanoResultado = indiceResultado;
}

// Funcion para calcular la diferencia de dos arreglos sin duplicados
void diferenciaArreglos(int arreglo1[], int tamanoArreglo1, int arreglo2[], int tamanoArreglo2, int resultado[], int& tamanoResultado) {
  int indiceResultado = 0;
  for (int i = 0; i < tamanoArreglo1; ++i) {
    if (!estaEnArreglo(arreglo1[i], arreglo2, tamanoArreglo2) && !estaEnArreglo(arreglo1[i], resultado, indiceResultado)) {
      resultado[indiceResultado++] = arreglo1[i];
    }
  }
  tamanoResultado = indiceResultado;
}

// Funcion para calcular el complemento de un arreglo
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
  int tamanoA, tamanoB, tamanoUniverso;

  // Ingresar tamaño del conjunto universo
  cout << "Ingrese el tamaño del universo: ";
  cin >> tamanoUniverso;
  int universo[tamanoUniverso];
  cout << "Ingrese los elementos del universo: ";
  for (int i = 0; i < tamanoUniverso; ++i) {
    cin >> universo[i];
  }

  // Ingresar tamaño y elementos del conjunto A
  cout << "Ingrese el tamaño del conjunto A: ";
  cin >> tamanoA;
  int a[tamanoA];
  cout << "Ingrese los elementos del conjunto A: ";
  for (int i = 0; i < tamanoA; ++i) {
    cin >> a[i];
  }

  // Ingresar tamaño y elementos del conjunto B
  cout << "Ingrese el tamaño del conjunto B: ";
  cin >> tamanoB;
  int b[tamanoB];
  cout << "Ingrese los elementos del conjunto B: ";
  for (int i = 0; i < tamanoB; ++i) {
    cin >> b[i];
  }

  // Union
  int union_ab[tamanoA + tamanoB];
  int tamanoUnion_ab = 0;
  unionArreglos(a, tamanoA, b, tamanoB, union_ab, tamanoUnion_ab);
  cout << "a u b = {";
  for (int i = 0; i < tamanoUnion_ab; ++i) {
    cout << union_ab[i] << (i < tamanoUnion_ab - 1 ? ", " : "");
  }
  cout << "}" << endl;

  // Interseccion
  int intersection_ab[tamanoA];
  int tamanoIntersection_ab = 0;
  interseccionArreglos(a, tamanoA, b, tamanoB, intersection_ab, tamanoIntersection_ab);
  cout << "a ∩ b = {";
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

  // Union de diferencias (a - b) u (b - a)
  int union_differences[tamanoDifference_ab + tamanoDifference_ba];
  int tamanoUnion_differences = 0;
  unionArreglos(difference_ab, tamanoDifference_ab, difference_ba, tamanoDifference_ba, union_differences, tamanoUnion_differences);
  cout << "(a - b) u (b - a) = {";
  for (int i = 0; i < tamanoUnion_differences; ++i) {
    cout << union_differences[i] << (i < tamanoUnion_differences - 1 ? ", " : "");
  }
  cout << "}" << endl;

  // Complemento de A
  int complemento_a[tamanoUniverso];
  int tamanoComplemento_a = 0;
  complementoArreglo(a, tamanoA, universo, tamanoUniverso, complemento_a, tamanoComplemento_a);
  cout << "a' = {";
  for (int i = 0; i < tamanoComplemento_a; ++i) {
    cout << complemento_a[i] << (i < tamanoComplemento_a - 1 ? ", " : "");
  }
  cout << "}" << endl;

  // Complemento de B
  int complemento_b[tamanoUniverso];
  int tamanoComplemento_b = 0;
  complementoArreglo(b, tamanoB, universo, tamanoUniverso, complemento_b, tamanoComplemento_b);
  cout << "b' = {";
  for (int i = 0; i < tamanoComplemento_b; ++i) {
    cout << complemento_b[i] << (i < tamanoComplemento_b - 1 ? ", " : "");
  }
  cout << "}" << endl;

  return 0;
}


