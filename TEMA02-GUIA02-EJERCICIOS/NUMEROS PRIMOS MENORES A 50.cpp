#include <iostream>

using namespace std;

bool esPrimo(int n) {
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
  int N;
  cout << "Ingrese N: ";
  cin >> N;
  cout << "Los números primos menores a " << N << " son: ";
  for (int i = 2; i < N; i++) {
    if (esPrimo(i)) {
      cout << i << " ";
    }
  }
  cout << endl;
  return 0;
}