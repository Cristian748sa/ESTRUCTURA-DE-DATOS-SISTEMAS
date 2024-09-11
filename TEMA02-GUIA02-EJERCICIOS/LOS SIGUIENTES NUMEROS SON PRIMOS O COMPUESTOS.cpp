#include <iostream>

using namespace std;

int esPrimo(int n) {
  if (n <= 1) {
    return false; 
  }
  for (int d = 2; d * d <= n; d++) {
    if (n % d == 0) {
      return false; 
    }
  }
  return true; 
}

int main() {
  int numero;
  cout << "Ingrese los números: ";
  while (true) {
    cin >> numero;
    if (esPrimo(numero)) {
      cout << numero << " es primo" << endl;
    } else {
      cout << numero << " es compuesto" << endl;
    }
  }
  return 0;
}