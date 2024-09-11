//Ejer 3
#include <iostream>
using namespace std;

int main() {
    int n, z=0;
    cout<<"Ingrese n: "; 
    cin>>n;

    cout<<"Los números al cuadrado de la serie son: ";
    for(int i=1; i<=n; i++) {
        cout<<i*i<<" ";
        z+=i*i;
    }

    cout<<endl<<"La suma de los números al cuadrado es: "<<z;
    return 0;
}