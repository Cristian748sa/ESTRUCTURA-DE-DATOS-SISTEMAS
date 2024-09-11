//Suma usando complemento a 2
#include <iostream>

using namespace std;

// Función para convertir un número decimal a binario con parte entera de 8 bits y parte fraccionaria de 4 bits
string decimalToBinary(double num) {
    string binary = "";
    int parte_entera = int(num);
    double parte_fraccionaria = num - parte_entera;

    // Convertir la parte entera a binario
    for (int i = 7; i >= 0; i--) {
        int bit = parte_entera & (1 << i) ? 1 : 0;
        binary += to_string(bit);
    }

    binary += "."; // Punto decimal entre parte entera y fraccionaria

    // Convertir la parte fraccionaria a binario
    for (int i = 0; i < 4; i++) {
        parte_fraccionaria *= 2;
        int bit = parte_fraccionaria >= 1 ? 1 : 0;
        parte_fraccionaria = parte_fraccionaria - bit;
        binary += to_string(bit);
    }

    return binary;
}

// Función para encontrar el complemento a 2 de un número binario
string findTwosComplement(string bin) {
    int n = bin.length();
    int i;
    string complemento = bin;

    for (i = n - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            break;
        }
    }

    if (i == -1) {
        complemento = '1' + complemento;
    } else {
        for (int j = i - 1; j >= 0; j--) {
            complemento[j] = (bin[j] == '1') ? '0' : '1';
        }
    }

    return complemento;
}

int main() {
    double num1, num2;
    cout<<"Ingrese el numero 1 : ";
    cin>>num1;
    cout<<"Ingrese el numero 2 : ";
    cin>>num2;
    
    // Convertir los números a su representación binaria
    string bin1 = decimalToBinary(num1);
    string bin2 = decimalToBinary(num2);

    // Realizar la suma en Complemento a 2 de los dos números
    double suma = num1 + num2;
    string bin_suma = decimalToBinary(suma);
    string complemento_suma = findTwosComplement(bin_suma);

    // Mostrar los resultados
    cout << "Binario de " << num1 <<" y Complemento a 2: "<< bin1 << endl;
    cout << "Binario de " << num2 <<" y Complemento a 2: "<< bin2 << endl;
    cout << "Resultado de la suma en Complemento a 2: " << complemento_suma << endl;

    return 0;
} 