#include <iostream>

using namespace std;

// Función para calcular el factorial de un número
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

// Función para calcular el número de permutaciones
int permutaciones(int n, int r) {
  return factorial(n) / factorial(n - r);
}

// Función para calcular el número de combinaciones
int combinaciones(int n, int r) {
  return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
  int n, r;

  cout << "Ingresa el valor de n: ";
  cin >> n;

  cout << "Ingresa el valor de r: ";
  cin >> r;

  cout << "El número de permutaciones de " << n << " elementos tomados de " << r << " en " << r << " es: " 
       << permutaciones(n, r) << endl;

  cout << "El número de combinaciones de " << n << " elementos tomados de " << r << " en " << r << " es: " 
       << combinaciones(n, r) << endl;

  return 0;
}