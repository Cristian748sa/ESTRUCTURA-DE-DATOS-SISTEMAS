#include <iostream>

using namespace std;

int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int main() {
  int n;
  cout << "Ingrese un número entero positivo: ";
  cin >> n;
  cout << "El factorial de " << n << " es: " << factorial(n) << endl;
  return 0;
}