#include <iostream>

using namespace std;

int mcd(int x, int y) {
  if (x < y) {
    swap(x, y);
  }

  while (y != 0) {
    int r = x % y;
    x = y;
    y = r;
  }
  return x; 
}

int mcm(int x, int y) {
  return (x * y) / mcd(x, y);
}

int main() {
  int x, y;

  cout << "Ingrese dos números enteros: ";
  cin >> x >> y;

  cout << "El MCD de " << x << " y " << y << " es: " << mcd(x, y) << endl;
  cout << "El MCM de " << x << " y " << y << " es: " << mcm(x, y) << endl;

  return 0;
}