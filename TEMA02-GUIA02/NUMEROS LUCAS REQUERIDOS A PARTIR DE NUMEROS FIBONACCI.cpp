#include <iostream>

using namespace std;

int lucas(int n) {
  if (n == 0) {
    return 2;
  } else if (n == 1) {
    return 1;
  } else {
    return lucas(n - 1) + lucas(n - 2);
  }
}

int main() {
  int n;
  cout << "Ingrese un número entero positivo: ";
  cin >> n;
  cout << "El " << n << "-ésimo número Lucas es: " << lucas(n) << endl;
  return 0;
}