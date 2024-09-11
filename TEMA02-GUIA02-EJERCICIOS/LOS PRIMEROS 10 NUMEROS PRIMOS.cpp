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
  int contador = 0;
  int numero = 2;

  cout << "Los primeros 10 números primos son: ";
  while (contador < 10) {
    if (esPrimo(numero)) {
      cout << numero << " ";
      contador++;
    }
    numero++;
  }
  cout << endl;
  return 0;
}