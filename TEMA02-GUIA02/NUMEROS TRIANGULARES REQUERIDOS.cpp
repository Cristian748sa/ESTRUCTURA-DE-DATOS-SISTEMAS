#include <iostream>

using namespace std;

int triangular(int n) {
  if (n == 0) {
    return 0;
  } else {
    return n + triangular(n - 1);
  }
}

int main() {
  int n;
  cout << "Ingrese un número entero positivo: ";
  cin >> n;
  cout << "El " << n << "-ésimo número triangular es: " << triangular(n) << endl;
  return 0;
}