#include <iostream>

using namespace std;

double armonico(int n) {
  if (n == 1) {
    return 1;
  } else {
    return 1.0 / n + armonico(n - 1);
  }
}

int main() {
  int n;
  cout << "Ingrese un número entero positivo: ";
  cin >> n;
  cout << "El " << n << "-ésimo número armónico es: " << armonico(n) << endl;
  return 0;
}