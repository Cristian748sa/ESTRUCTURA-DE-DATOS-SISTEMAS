// convertir de base 2 a base 16
#include <iostream>

using namespace std;

int main()
{
    string valorBaseDos;
    string hexNumber = "";
    
    cout << "Ingresa valor en base 2: ";
    cin >> valorBaseDos;
    
    // Asegurar que la longitud sea un múltiplo de 4 agregando ceros a la izquierda
    while (valorBaseDos.size() % 4 != 0) {
        valorBaseDos = "0" + valorBaseDos;
    }

    // Mapeo de valores binarios a hexadecimales
    char hexDigits[] = "0123456789ABCDEF";

    // Convertir de base 2 a base 16
    int n = valorBaseDos.size();
    for (int i = 0; i < n; i += 4) {
        int decimalValue = 0;
        for (int j = 0; j < 4; j++) {
            decimalValue = decimalValue * 2 + (valorBaseDos[i + j] - '0');
        }
        hexNumber += hexDigits[decimalValue];
    }

    cout << "El valor en base 16 es: " << hexNumber << endl;

    return 0;
}