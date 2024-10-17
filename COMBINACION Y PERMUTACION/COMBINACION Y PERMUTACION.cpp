//CRISTIAN JOSE RODRIGUEZ ROJAS
#include <iostream>
using namespace std;

//Función para calcular el factorial de un número
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

//Función para calcular permutaciones sin repetición
int permutaciones_sin_repeticion(int n, int r) {
    if (r == n) {
        return factorial(n);
    } else if (r < n) {
        return factorial(n) / factorial(n - r);
    } else {
        return 0; 
    }
}

//Función para calcular permutaciones con repetición
int permutaciones_con_repeticion(int n, int r) {
    int resultado = 1;
    for (int i = 0; i < r; i++) {
        resultado *= n;
    }
    return resultado;
}

//Función para calcular combinaciones sin repetición
int combinaciones_sin_repeticion(int n, int r) {
    if (r == n) {
        return 1; 
    } else if (r < n) {
        return factorial(n) / (factorial(r) * factorial(n - r));
    } else {
        return 0; 
    }
}

int main() {
    int n, r, opcion;
    cout << "Ingresa el valor de n: "; cin >> n;
    cout << "Ingresa el valor de r: "; cin >> r;
    cout << "\nElige una opción:" << endl;
    cout << "1. Permutación" << endl;
    cout << "2. Combinación" << endl;
    cin >> opcion;

    if (opcion == 1) {
        cout << "\nElige una opción:" << endl;
        cout << "1. Sin repetición" << endl;
        cout << "2. Con repetición" << endl;
        cin >> opcion;

        if (opcion == 1) {
            cout << "El número de permutaciones sin repetición de " << n << " elementos tomados de " << r << " es: "
                 << permutaciones_sin_repeticion(n, r) << endl;
        } else if (opcion == 2) {
            cout << "El número de permutaciones con repetición de " << n << " elementos tomados de " << r << " es: "
                 << permutaciones_con_repeticion(n, r) << endl;
        } else { cout << "Opción inválida." << endl;}
    } else if (opcion == 2) {
        cout << "El número de combinaciones sin repetición de " << n << " elementos tomados de " << r << " es: "
             << combinaciones_sin_repeticion(n, r) << endl;} 
          else { cout << "Opción inválida." << endl;}
    return 0;
}